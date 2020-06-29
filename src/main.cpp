#include <cstdint>
#include <pybind11/pybind11.h>

namespace py = pybind11;

inline std::uint64_t fibonacci(std::uint64_t n) {
  if (n <= 1) {
    return n;
  }

  std::uint64_t a = 0;
  std::uint64_t b = 1;
  std::uint64_t c = 0;

  c = a + b;
  for (std::uint64_t _i = 2; _i < n; _i++) {
    a = b;
    b = c;
    c = a + b;
  }

  return c;
}

std::uint64_t fibonacci_gil(std::uint64_t n) {
  // The GIL is held by default when entering C++ from Python, so we need no
  // manipulation here. Interestingly enough, re-acquiring a held GIL is a safe
  // operation (within the same thread), so feel free to scatter
  // `py::gil_scoped_acquire` throughout the code.
  return fibonacci(n);
}

std::uint64_t fibonacci_nogil(std::uint64_t n) {
  // Because the GIL is held by default, we need to explicitly release it here.
  // Note that like Cython, releasing the lock multiple times will crash the
  // interpreter.

  py::gil_scoped_release release;
  return fibonacci(n);
}

PYBIND11_MODULE(fibonacci, m) {

  m.def("fibonacci_gil", &fibonacci_gil, R"pbdoc(
        Calculate the Nth Fibonacci number while implicitly holding the GIL 
    )pbdoc");

  m.def("fibonacci_nogil", &fibonacci_nogil,
        R"pbdoc(
        Calculate the Nth Fibonacci number after explicitly unlocking the GIL
    )pbdoc");

#ifdef VERSION_INFO
  m.attr("__version__") = VERSION_INFO;
#else
  m.attr("__version__") = "dev";
#endif
}