#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include "sum.h"

namespace nb = nanobind;

NB_MODULE(sum_from_nanobind, m) {
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
