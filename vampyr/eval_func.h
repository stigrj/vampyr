#include <functional>
#include <omp.h>

double eval_func(int rank, std::function<double (double)> func, double x) {
    double out = 0.0;
#pragma omp parallel shared(out)
{
    int thread_num = omp_get_thread_num();
    if (thread_num == rank) {
        std::cout << "Thread " << thread_num << " working\n";
        out = func(x);
    }
}
    return out;
}

