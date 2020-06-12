#pragma once
#include <triqs/gfs/block/map.hpp>
/*
   File is generated by vim.
   To regenerate the file,
     1- load the vim function by (or add this to your .vim ?)
        source vimexpand.vim
     2- all it
      call VimExpandSimple()


   It is better than C macro, it gives a cleaner code
   (for error messages, no preproc, doc generation : otherwise no doc string ...)

  ----  normal mapping -------
  
    VIMEXPAND inverse reinterpret_scalar_valued_gf_as_matrix_valued make_gf_from_fourier make_gf_from_inverse_fourier
    ///
    template <typename M, typename T, int A> auto @(block_gf<M, T, A> &g) {
      auto l = [](auto &&x) { return @(x); };
      return map_block_gf(l, g);
    }
    ///
    template <typename M, typename T, int A> auto @(block_gf<M, T, A> const &g) {
      auto l = [](auto &&x) { return @(x); };
      return map_block_gf(l, g);
    }
    ///  
    template <typename M, typename T, int A, bool C> auto @(block_gf_view<M, T, A, C> g) {
      auto l = [](auto &&x) { return @(x); };
      return map_block_gf(l, g);
    }

*/

namespace triqs::gfs {

  // --- VIMEXPAND_START  --DO NOT EDIT BELOW --

  ///
  template <typename M, typename T, int A> auto inverse(block_gf<M, T, A> &g) {
    auto l = [](auto &&x) { return inverse(x); };
    return map_block_gf(l, g);
  }
  ///
  template <typename M, typename T, int A> auto inverse(block_gf<M, T, A> const &g) {
    auto l = [](auto &&x) { return inverse(x); };
    return map_block_gf(l, g);
  }
  ///
  template <typename M, typename T, int A, bool C> auto inverse(block_gf_view<M, T, A, C> g) {
    auto l = [](auto &&x) { return inverse(x); };
    return map_block_gf(l, g);
  }

  ///
  template <typename M, typename T, int A> auto reinterpret_scalar_valued_gf_as_matrix_valued(block_gf<M, T, A> &g) {
    auto l = [](auto &&x) { return reinterpret_scalar_valued_gf_as_matrix_valued(x); };
    return map_block_gf(l, g);
  }
  ///
  template <typename M, typename T, int A> auto reinterpret_scalar_valued_gf_as_matrix_valued(block_gf<M, T, A> const &g) {
    auto l = [](auto &&x) { return reinterpret_scalar_valued_gf_as_matrix_valued(x); };
    return map_block_gf(l, g);
  }
  ///
  template <typename M, typename T, int A, bool C> auto reinterpret_scalar_valued_gf_as_matrix_valued(block_gf_view<M, T, A, C> g) {
    auto l = [](auto &&x) { return reinterpret_scalar_valued_gf_as_matrix_valued(x); };
    return map_block_gf(l, g);
  }

  ///
  template <typename M, typename T, int A> auto make_gf_from_fourier(block_gf<M, T, A> &g) {
    auto l = [](auto &&x) { return make_gf_from_fourier(x); };
    return map_block_gf(l, g);
  }
  ///
  template <typename M, typename T, int A> auto make_gf_from_fourier(block_gf<M, T, A> const &g) {
    auto l = [](auto &&x) { return make_gf_from_fourier(x); };
    return map_block_gf(l, g);
  }
  ///
  template <typename M, typename T, int A, bool C> auto make_gf_from_fourier(block_gf_view<M, T, A, C> g) {
    auto l = [](auto &&x) { return make_gf_from_fourier(x); };
    return map_block_gf(l, g);
  }

  ///
  template <typename M, typename T, int A> auto make_gf_from_inverse_fourier(block_gf<M, T, A> &g) {
    auto l = [](auto &&x) { return make_gf_from_inverse_fourier(x); };
    return map_block_gf(l, g);
  }
  ///
  template <typename M, typename T, int A> auto make_gf_from_inverse_fourier(block_gf<M, T, A> const &g) {
    auto l = [](auto &&x) { return make_gf_from_inverse_fourier(x); };
    return map_block_gf(l, g);
  }
  ///
  template <typename M, typename T, int A, bool C> auto make_gf_from_inverse_fourier(block_gf_view<M, T, A, C> g) {
    auto l = [](auto &&x) { return make_gf_from_inverse_fourier(x); };
    return map_block_gf(l, g);
  }

} // namespace triqs::gfs