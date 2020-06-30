import speiceio_pybind11


def test_fibonacci_50():
    assert speiceio_pybind11.fibonacci_gil(50) == 12586269025
    assert speiceio_pybind11.fibonacci_nogil(50) == 12586269025
