#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
#include <Eigen/Dense>
#include <string>

#include "bspline.h"

namespace py = pybind11;
using namespace SPLINTER;


#include <nlohmann/json.hpp>

PYBIND11_MODULE(splinterpy11, m) {
  m.doc() = "splinterpy11";

  py::class_<BSpline>(m, "BSpline")
      .def(py::init(&BSpline::from_json))
      .def("eval", py::overload_cast<const DenseVector&>(&BSpline::eval, py::const_))
      .def("eval_jacobian", py::overload_cast<const DenseVector&>(&BSpline::eval_jacobian, py::const_))
      ;
}
