"""
module: rusty_py
functions:
- add(a: int, b: int) -> int
- sum_vector(numbers: List[float]) -> float
- reverse_string(text: str) -> str
- get_primes_up_to(n: int) -> List[int]
"""

import rusty_py

print(rusty_py.add(3, 5))
print(rusty_py.sum_vector([1, 2.5, 3.5, -5.3, 8]))
print(rusty_py.reverse_string("hello"))
print(rusty_py.get_primes_up_to(100))