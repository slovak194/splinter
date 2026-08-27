#include <nanobind/nanobind.h>
#include <nanobind/ndarray.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/eigen/dense.h>
#include <Eigen/Dense>
#include <string>

#include "bspline.h"

namespace nb = nanobind;
using namespace SPLINTER;


#include <nlohmann/json.hpp>

NB_MODULE(splinternano, m) {
  m.doc() = "splinternano";

  nb::class_<BSpline>(m, "BSpline")
      .def("__init__", [](BSpline *self, const std::string &filename) {
         // Requires a placement new usage, meh, pybind11 was better in this.
              new (self) BSpline(BSpline::from_json(filename));
          })
      .def("get_description", &BSpline::get_description)
      .def("get_domain_upper_bound", &BSpline::get_domain_upper_bound)
      .def("get_domain_lower_bound", &BSpline::get_domain_lower_bound)
      .def("eval", nb::overload_cast<const DenseVector&>(&BSpline::eval, nb::const_))
      .def("eval_jacobian", nb::overload_cast<const DenseVector&>(&BSpline::eval_jacobian, nb::const_))
      ;
}
