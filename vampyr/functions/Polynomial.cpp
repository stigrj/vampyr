#include "pybind11/pybind11.h"

#include "PyRepresentableFunction.h"

#include "functions/Polynomial.h"

using namespace mrcpp;
namespace py = pybind11;
using namespace pybind11::literals;

namespace vampyr {

void polynomial(py::module &m, py::class_<RepresentableFunction<1>, PyRepresentableFunction<1>> &repfunc1d) {


py::class_<Polynomial>(m, "Polynomial", repfunc1d)
        .def(py::init<int, const double *, const double *>(), "order"_a, "a"_a = nullptr, "b"_a = nullptr)
        .def("evalf", py::overload_cast<double>(&Polynomial::evalf, py::const_))
        .def("setCoefs", &Polynomial::setCoefs)
        .def("normalize", &Polynomial::normalize)
        .def("getCoefs", py::overload_cast<>(&Polynomial::getCoefs))
        .def("size", &Polynomial::size);

}
} // namespace vampyr