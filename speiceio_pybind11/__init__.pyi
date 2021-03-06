# Manually-written Python type stubs to assist IDE's.
#
# Theoretically, because annotations are recorded as an `__annotations__` attribute,
# `pybind11` could generate this for us and the IDE/mypy could inspect it at runtime.
# However, as far as I can tell, neither of these things happen in practice.

def fibonacci_gil(n: int) -> int: ...
def fibonacci_nogil(n: int) -> int: ...
def recurse_unlock() -> None: ...
