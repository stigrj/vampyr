/*
 *  \date Mar 08, 2018
 *  \author Magnar Bjørgve <magnar.bjorgve@uit.no> \n
 *          Hylleraas Centre for Quantum Molecular Sciences \n
 *          UiT - The Arctic University of Norway
 */

#include "pybind11/pybind11.h"
#include "pybind11/functional.h"
#include "pybind11/stl.h"

#include "eval_func.h"

namespace py = pybind11;


PYBIND11_MODULE(vampyr, m) {
    m.def("eval_func", py::overload_cast<int, std::function<double (double)>, double>
         (&eval_func), py::arg("rank"), py::arg("function"), py::arg("x"));
}
