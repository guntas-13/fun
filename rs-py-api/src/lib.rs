#[pyo3::pymodule]
mod rusty_py {
    use pyo3::prelude::*;

    #[pyfunction]
    fn add(a: i64, b: i64) -> i64 {
        a + b
    }

    #[pyfunction]
    fn sum_vector(numbers: Vec<f64>) -> f64 {
        numbers.iter().sum()
    }

    #[pyfunction]
    fn reverse_string(text: String) -> String {
        text.chars().rev().collect()
    }

    fn sieve_of_eratosthenes(n: u32) -> Vec<u32> {
        if n < 2 {
            return Vec::new();
        }
        
        let mut is_prime = vec![true; (n + 1) as usize];
        is_prime[0] = false;
        is_prime[1] = false;
        
        for i in 2..=((n as f64).sqrt() as u32) {
            if is_prime[i as usize] {
                for j in ((i * i)..=n).step_by(i as usize) {
                    is_prime[j as usize] = false;
                }
            }
        }
        
        (2..=n).filter(|&i| is_prime[i as usize]).collect()
    }

    #[pyfunction]
    fn get_primes_up_to(n: u32) -> Vec<u32> {
        sieve_of_eratosthenes(n)
    }
}

// Alternative way to define the module without the #[pyo3::pymodule] attribute

/*

use pyo3::prelude::*;

#[pyfunction]
fn add(a: i64, b: i64) -> i64 {
    a + b
}

#[pyfunction]
fn sum_vector(numbers: Vec<f64>) -> f64 {
    numbers.iter().sum()
}

#[pyfunction]
fn filter_positive(numbers: Vec<i32>) -> Vec<i32> {
    numbers.into_iter().filter(|&x| x > 0).collect()
}

#[pyfunction]
fn reverse_string(text: String) -> String {
    text.chars().rev().collect()
}

#[pymodule]
fn rusty_py(m: &Bound<'_, PyModule>) -> PyResult<()> {
    m.add_function(wrap_pyfunction!(add, m)?)?;
    m.add_function(wrap_pyfunction!(sum_vector, m)?)?;
    m.add_function(wrap_pyfunction!(filter_positive, m)?)?;
    m.add_function(wrap_pyfunction!(reverse_string, m)?)?;
    Ok(())
}

*/