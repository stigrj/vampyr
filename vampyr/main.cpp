#include <iostream>

#include "eval_func.h"

int main(int argc, char **argv) {

    auto f = [] (double x) -> double {
        return x*x;
    };

    double x = 2.0;

    double foo = eval_func(0, f, x);
    std::cout << "Output eval_func " << foo << "\n\n";

    double bar = eval_func(1, f, x);
    std::cout << "Output eval_func " << bar << "\n\n";

    return 0;
}
