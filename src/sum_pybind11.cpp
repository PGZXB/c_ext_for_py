#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "sum.h"

namespace py = pybind11;

PYBIND11_MODULE(sum_from_pybind11, m) {
  m.def("my_sum", [](std::vector<int>& data) {
          int sum = 0;
          const int *c_arr = data.data();
          const int len = data.size();
          for (int i = 0; i < len; i++) {
            sum += c_arr[i];
          }
          return sum;
        }, "");
}
