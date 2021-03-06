// Copyright (c) 2013-2015 Commissariat à l'énergie atomique et aux énergies alternatives (CEA)
// Copyright (c) 2013-2015 Centre national de la recherche scientifique (CNRS)
// Copyright (c) 2019-2020 Simons Foundation
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You may obtain a copy of the License at
//     https://www.gnu.org/licenses/gpl-3.0.txt
//
// Authors: Olivier Parcollet, Nils Wentzell

#include "./array_test_common.hpp"

// alone because it is quite long to run ... (exception ....)

TEST(Array, BoundCheck) {

  array<long, 2> A(2, 3);

  EXPECT_THROW(A(0, 3), key_error);
  EXPECT_THROW(A(range(0, 4), 2), key_error);
  EXPECT_THROW(A(range(10, 14), 2), key_error);
  EXPECT_THROW(A(range(), 5), key_error);
  EXPECT_THROW(A(0, 3), key_error);
}
MAKE_MAIN;
