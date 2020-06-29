import fibonacci


def test_fibonacci_50():
    assert fibonacci.fibonacci_gil(50) == 12586269025
    assert fibonacci.fibonacci_nogil(50) == 12586269025
