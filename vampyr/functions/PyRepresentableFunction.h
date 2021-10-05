/*
 *  \date Mar 16, 2018
 *  \author Magnar Bjørgve <magnar.bjorgve@uit.no> \n
 *          Hylleraas Centre for Quantum Molecular Sciences \n
 *          UiT - The Arctic University of Norway
 */
#pragma once

#include <pybind11/pybind11.h>

#include <MRCPP/core/FilterCache.h>
#include <MRCPP/core/MWFilter.h>
#include <MRCPP/functions/RepresentableFunction.h>
#include <MRCPP/functions/Polynomial.h>

namespace vampyr {

template <int D, typename FunctionBase = mrcpp::RepresentableFunction<D>>
class PyRepresentableFunction : public FunctionBase {
public:
    /* Inherit the constructors */
    using FunctionBase::FunctionBase;

    double evalf(const mrcpp::Coord<D> &r) const override { PYBIND11_OVERLOAD_PURE(double, FunctionBase, evalf, r); }
};

class ScalingFunction : public mrcpp::Polynomial {
public:
    ScalingFunction(const mrcpp::ScalingBasis &basis, int i, int l, int n)
        : Polynomial(basis.getFunc(i)) {
        this->rescale(n, l);
    }
};

class WaveletFunction : public mrcpp::RepresentableFunction<1> {
public:
    WaveletFunction(const mrcpp::ScalingBasis &basis, int i, int l, int n) {
        auto &lfilters = mrcpp::FilterCache<mrcpp::Legendre>::getInstance();
        auto &ifilters = mrcpp::FilterCache<mrcpp::Interpol>::getInstance();
        int k = basis.getScalingOrder();
        int type = basis.getScalingType();
        switch (type) {
            case mrcpp::Legendre:
                this->filter = &lfilters.get(k);
                break;
            case mrcpp::Interpol:
                this->filter = &ifilters.get(k);
                break;
            default:
                //MSG_ERROR("Invalid scaling basis selected.")
                break;
        }
    }

    double evalf(const mrcpp::Coord<1> &r) const override {

    }

private:
    int i, l, n;
    mrcpp::MWFilter *filter{nullptr};
    std::vector<mrcpp::Polynomial> poly;
};
} // namespace vampyr
