#pragma once

#include <MRChem/qmfunctions/Orbital.h>

namespace vampyr {
void orbitals(pybind11::module &m) {
    using namespace mrchem;
    namespace py = pybind11;
    using namespace pybind11::literals;

    py::class_<Orbital>(m, "Orbital")
        .def(py::init<int, int>(), "spin"_a, "occ"_ = -1);
}
} // namespace vampyr
