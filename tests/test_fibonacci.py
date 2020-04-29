import fibonacci


def test_fibonacci_50():
    assert fibonacci.pybind_gil(50) == 12586269025
    assert fibonacci.pybind_nogil(50) == 12586269025
