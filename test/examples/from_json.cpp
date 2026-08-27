/*
 * This file is part of the SPLINTER library.
 * Copyright (C) 2012 Bjarne Grimstad (bjarne.grimstad@gmail.com).
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include <Catch.h>
#include <bspline_builders.h>
#include "utilities.h"
#include <iostream>

#include <nlohmann/json.hpp>

using namespace SPLINTER;
using std::cout;
using std::endl;

#define COMMON_TAGS "[examples][json]"

TEST_CASE("From json example", COMMON_TAGS)
{
    auto spline = bspline_from_json("/home/slovak/splinter/python/splinterpy11/test.json");

    Eigen::Matrix<double, 2, 1> p;
    p << 0.7, -0.1;

    auto y = spline.eval(p);

    CHECK(assert_near(y(0), 0.5646270834036826));
    CHECK(assert_near(y(1), 0.696689837482913));
    CHECK(assert_near(y(2), 0.7350330225547118));

    auto j = spline.eval_jacobian(p);

    CHECK(assert_near(j(0, 0), 0.825391660));
    CHECK(assert_near(j(1, 0), -0.717294728));
    CHECK(assert_near(j(2, 0), -21.848808401));

    CHECK(assert_near(j(0, 1), 0.825285147));
    CHECK(assert_near(j(1, 1), 0.717304488));
    CHECK(assert_near(j(2, 1), -18.357403040));

}
