# Higher-Order Functions
- To express certain general patterns as named concepts, we will need to construct functions that can accept other functions as arguments or return functions as values. Functions that manipulate functions are called **higher-order functions**. This section shows how higher-order functions can serve as powerful abstraction mechanisms, vastly increasing the expressive power of our language.

## Functions as argument
- We introduced user-defined functions as a mechanism for abstracting patterns of numerical operations so as to make them independent of the particular numbers involved.

```python
def summutation(n, term):
    total, k = 0, 1
    while k <= n:
        total, k = total + term(k), k + 1
    return total

def identity(x):
    return x

def square(x):
    return x*x

def cube(x):
    return x*x*x

def sum_cubes(n):
    return summutation(n, cube)

print(sum_cubes(3))
```

## Functions as General Methods
- With higher-order functions, we begin to see a more powerful kind of abstraction: some functions express general methods of computation, independent of the particular functions they call.
- Consider the following example, which implements a general method for iterative improvement and uses it to compute the golden ratio. The golden ratio, often called "phi", is a number near 1.6 that appears frequently in nature, art, and architecture.

```python
def improve(update, close, guess=1):
    while not close(guess):
        guess = update(guess)
    return guess

def golden_update(guess):
    return 1 / guess + 1

def close_to_phi(guess):
    return approx_eq(guess*guess, guess + 1)

def approx_eq(x, y, tolerance = 1e-15):
    return abs(x - y) < tolerance

print(improve(golden_update, close_to_phi))    
```

- This example illustrates two related big ideas in computer science. First, naming and functions allow us to abstract away a vast amount of complexity. Second, it is only by virtue of the fact that we have an extremely general evaluation procedure for the Python language that small components can be composed into complex processes.
- As always, our new general method improve needs a test to check its correctness.

```python
from math import sqrt
phi = 1/2 + sqrt(5)/2
def improve_test():
    approx_phi = improve(golden_update, close_to_phi)
    assert approx_eq(approx_phi, phi), 'phi differ from its approximation'

improve_test()
# For this test, no news is good news: improve_test returns None after its assert statement is executed successfully.
```

## Defining Functions III: Nested Definitions
- One negative consequence of the above examples is that **the global frame becomes cluttered with names of small functions**, which must all be unique.
- Another problem is that **we are constrained by particular function signatures**: the update argument to improve must take exactly one argument.
- Nested function definitions address both of these problems, but require us to enrich our environment model.
- **The solution to both of these issues is to place function definitions inside the body of other definitions.**

```python
def average(x, y):
    return (x + y)/2

def sqrt(a):
    def sqrt_update(x): # in sqrt frame
        return average(x, a/x)
    def sqrt_close(x): # in sqrt frame
        return approx_eq(x*x, a)
    return improve(sqrt_update, sqrt_close)
```

- Like local assignment, local def statements only affect the current local frame. These functions are only in scope while sqrt is being evaluated. Consistent with our evaluation procedure, these local def statements don't even get evaluated until sqrt is called.

## Functions as Returned Values
- An important feature of lexically scoped programming languages is that locally defined functions maintain their parent environment when they are returned. The following example illustrates the utility of this feature.

```python
def square(x):
    return x * x

def successor(x):
    return x + 1

def composel(f, g):
    def h(x):
        return f(g(x))
    return h

square_successor = composel(square, successor)

result = square_successor(12)
```

## Example: Newton's Method
- Newton's method is a classic iterative approach to finding the arguments of a mathematical function that yield a return value of 0. These values are called the zeros of the function. Finding a zero of a function is often equivalent to solving some other problem of interest, such as computing a square root.

```python
def newton_update(f, df):
    def update(x):
        return x - f(x) / df(x)
    return update

def find_zero(f, df):
    def near_zero(x):
        return approx_eq(f(x), 0)
    return improve(newton_update(f, df), near_zero)

def square_root_newton(a):
    def f(x):
        return x * x - a
    def df(x):
        return 2 * x
    return find_zero(f, df)

def power(x, n):
    """Return x * x * x * ... * x for x repeated n times."""
    product, k = 1, 0
    while k < n:
        product, k = product * x, k + 1
    return product

def nth_root_of_a(n, a):
    """
    >>> nth_root_of_a(2, 64)
    8.0
    >>> nth_root_of_a(3, 64)
    4.0
    >>> nth_root_of_a(6, 64)
    2.0
    """
    def f(x):
        return power(x, n) - a
    def df(x):
        return n * power(x, n-1)
    return find_zero(f, df)
```
- The approximation error in all of these computations can be reduced by changing the tolerance in approx_eq to a smaller number.
- As you experiment with Newton's method, be aware that it will not always converge. The initial guess of improve must be sufficiently close to the zero, and various conditions about the function must be met. Despite this shortcoming, Newton's method is a powerful general computational method for solving differentiable equations. Very fast algorithms for logarithms and large integer division employ variants of the technique in modern computers.

## Currying
- We can use higher-order functions to convert a function that takes multiple arguments into a chain of functions that each take a single argument. More specifically, given a function f(x, y), we can define a function g such that g(x)(y) is equivalent to f(x, y). Here, g is a higher-order function that takes in a single argument x and returns another function that takes in a single argument y. This transformation is called currying.

```python
def curried_pow(x):
    def n_pow(n):
        return pow(x, n)
    return n_pow

curried_pow(2)(3)
```