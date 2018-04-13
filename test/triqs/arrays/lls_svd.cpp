/*******************************************************************************
 *
 * TRIQS: a Toolbox for Research in Interacting Quantum Systems
 *
 * Copyright (C) 2018 by N. Wentzell
 *
 * TRIQS is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * TRIQS is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * TRIQS. If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/

#include <triqs/gfs.hpp>
#include <triqs/test_tools/arrays.hpp>
#include <triqs/arrays/blas_lapack/gelss.hpp>
#include <triqs/arrays/blas_lapack/gesvd.hpp>
#include <iostream>
#include <complex>

using namespace triqs::gfs;
using namespace triqs::arrays;
using namespace triqs::arrays::blas;
using namespace triqs::clef;

using value_type = std::complex<double>;

struct gelss_cache {

  private:
  size_t M, N;
  matrix<value_type> V_x_InvS_x_UT;

  public:
  vector<double> S_vec;

  gelss_cache(matrix_const_view<value_type> _A) : M{get_n_rows(_A)}, N{get_n_cols(_A)}, V_x_InvS_x_UT{N, M}, S_vec(std::min(M, N)) {

    matrix<value_type> A{_A, FORTRAN_LAYOUT};
    matrix<value_type> U{M, M, FORTRAN_LAYOUT};
    matrix<value_type> VT{N, N, FORTRAN_LAYOUT};

    lapack::gesvd(A, S_vec, U, VT);

    matrix<double> S_inv{N, M, FORTRAN_LAYOUT};
    S_inv() = 0.;
    for (int i : range(std::min(M, N))) S_inv(i, i) = 1.0 / S_vec(i);
    V_x_InvS_x_UT = VT.transpose() * S_inv * U.transpose();
  }

  matrix<value_type> operator()(matrix_const_view<value_type> B) const {
    return V_x_InvS_x_UT * B;
  }
};

TEST(blas_lapack, svd) {

  auto A = matrix<value_type>{{{1, 1, 1}, {2, 3, 4}, {3, 5, 2}, {4, 2, 5}, {5, 4, 3}}, FORTRAN_LAYOUT};
  int M = get_n_rows(A);
  int N = get_n_cols(A);

  auto U  = matrix<value_type>(M, M, FORTRAN_LAYOUT);
  auto VT = matrix<value_type>(N, N, FORTRAN_LAYOUT);

  auto S  = vector<double>(std::min(M, N));

  lapack::gesvd(A, S, U, VT);

  auto S_Mat = A;
  S_Mat()    = 0.0;
  for (int i : range(std::min(M, N))) S_Mat(i, i) = S(i);

  EXPECT_ARRAY_NEAR(A, U * S_Mat * VT, 1e-14);
}

TEST(blas_lapack, gelss) {

  // Cf. http://www.netlib.org/lapack/explore-html/d3/d77/example___d_g_e_l_s__colmajor_8c_source.html
  auto A = matrix<value_type>{{{1, 1, 1}, {2, 3, 4}, {3, 5, 2}, {4, 2, 5}, {5, 4, 3}}, FORTRAN_LAYOUT};
  auto B = matrix<value_type>{{{-10, -3}, {12, 14}, {14, 12}, {16, 16}, {18, 16}}, FORTRAN_LAYOUT};
  
  int M    = get_n_rows(A);
  int N    = get_n_cols(A);
  int NRHS = get_n_cols(B);

  auto S = vector<double>(std::min(M, N));

  auto gelss_new = gelss_cache{A};
  auto x_1       = gelss_new(B);

  int i;
  lapack::gelss(A, B, S, 1e-18, i);
  auto x_2 = B(range(N), range(NRHS));

  auto x_exact = matrix<value_type>{{{2, 1}, {1, 1}, {1, 2}}, FORTRAN_LAYOUT};

  EXPECT_ARRAY_NEAR(x_exact, x_1, 1e-14);
  EXPECT_ARRAY_NEAR(x_exact, x_2, 1e-14);
}

MAKE_MAIN;
