# Proposal: add a complete real arithmetic system to Euclid

Real numbers can be used in any construction.

Real numbers are stored with the same precision as `Vector3`s. Special values (e.g. `NaN`, `inf`) are represented as `Null`. 

Add infix operators:
* `+` addition
* `-` subtraction
* `*` multiplication
* `/` division
* `//` integer division
* `%` remaninder or modulus
* `<` `>` `<=` `>=` `!=` `==` comparison
* `^` exponentiation

Add the following figure to real constructions:
* `length(alpha)` for a figure `alpha`
* `area(alpha)` for a figure `alpha`
* `volume(alpha)` for a figure `alpha`

Add the following real to real constructions:
* `sin`, `cos`, `tan`, `asin`, `acos`, `atan`, `atan2` trigometric functions
* `sqrt` square root
* `cbrt` cube root
* `hypot` square root of sum of squares of passed arguments
* `floor`, `ceil`, `round` rounding functions
* `exp` exponential function
* `log`, `log10`, `logb`, logarithms
* `abs` absolute value
* `min`, `max` minimum and maximum functions

Mathematical constants are not implemented. π can be represented as `acos(-1)` and e can be represented as `exp(1)`.

### Pros

* Real arithmetic would make Euclid easier to use.
* Adding real arithmetic does not complicate Euclid from the user's perspective.
* Real arithmetic allows for non-Euclidean constructions, such as squaring the circle and angle trisection.
* The use of real numbers also allows for other useful language features, such as a sophisticated tuple system.

### Cons

* The use of real numbers can be abused.
* Real numbers make Euclid more complicated from the implementer's perspective.
