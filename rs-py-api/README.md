# rs-py-api

This is a sample Python package that includes a Rust extension module built using `PyO3` and `Maturin`.

## Module `rusty_py`

### Functions

- `add(a: int, b: int) -> int`: Adds two integers and returns the result.
- `sum_vector(numbers: List[float]) -> float`: Returns the sum of a list of floating-point numbers.
- `reverse_string(text: str) -> str`: Reverses a string and returns the result.
- `get_primes_up_to(n: int) -> List[int]`: Returns a list of prime numbers up to a given integer.

### Installation & Usage

Install `maturin` using pip3 (within any suitable python env)

```bash
pip3 install maturin
```

Then build and install the package using:

```bash
maturin develop
```

you can now use the `rusty_py` module in your Python code.
