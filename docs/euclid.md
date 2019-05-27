# Euclid

Euclid is a functional scripting language intended to describe and render Euclidean constructions in two or three dimensions. The Euclid language is inspired by _Elements_, an ancient geometry textbook by Euclid of Alexandria. As a result, the Euclid language does not focus on algebra or arithmetic. Rather, it relies on geometry as its main method of computation, even though real arithmetic is still supported. Euclid is Turing complete (able to compute anything which is computable) and Euclid complete (able to construct any Euclidean construction). Euclid can also be used to create non-Euclidean constructions (such as an angle trisection and squaring the circle).

> For editing purposes, put comments and suggested changes in block quotes.

## Table of Contents

1. [Basic Structure](#basic-structure)
1. [Data Types](#data-types)
1. [Global Constants](#global-constants)
1. [Literals](#literals)
1. [Operators](#operators)
1. [Postulates](#postulates)
1. [Control Flow](#control-flow)
1. [Standard Library](#standard-library)
1. [Issues](#issues)

## Basic Structure

### File Format

A Euclid program is an ASCII text file with the extension "`.euclid`", or multiple of such files.

### Objects

In Euclid, an "object" is some piece of data that signifies something. For example the sphere with center (3, 4, 2) and radius 2 is an object. The real number -4.34 is also an object. Data types in Euclid are discussed in detail later.

### Expressions

An "expression" is an instruction on how to compute the value of an object. Simple literals like `-4.34` and `"Hello, world"` are considered expressions, as they specify how to create a real object and a string object, respectively. More complex expressions can be created through the use of constructions, or functions, along with operators. For example, `sqrt(x^2 + y^2 + z^2)` is an expression that computes the distance from the origin to point (`x`, `y`, `z`).

### Statements

A "statement" is an instruction on how to change the state of the program. A Euclid program is a list of statements. Upon program execution, these statements are run in order unless they are part of a control flow structure that states to do otherwise (like an `if` statement).

Statements are generally only one line long, so newlines, in most cases, end statements. Newlines do not end statements when a line ends in a backslash (`\`) or when a line ends in with an incomplete binary operator, an incomplete literal, unclosed parenthesis (`(` and `)`), or unclosed brackets (`[` and `]`). A semicolon (`;`) may be used to explicitly end a statement.

Euclid code samples thorughout this documentation is displayed like the sample below.

```text
# this is a comment

p = point_on(space)  # single line statement
q = p; r = q         # multiple statements on one line
a, b, c \            # multiline statement
 =                   # incomplete binary operator
  [p, q,             # incomplete brackets
   r]
```

A block statement is a list of statements enclosed by braces (`{` and `}`). Block statements are used in control flow. If a block statement is encountered outside of a control flow statement, every individual statement within the block is run in order as if the braces were never there.

Possibly the most frequent statement in Euclid is an assignment. The assignment operator is discussed in detail later. Below are some examples of assignment statements.

```text
a = b                   # the value of variable b is copied into variable a
a, b, c = p, q, r       # Python-like tuple-wise assignment
omega = radius(         # assignment with a complex expression
  sphere(
    point_on(space),
    point_on(space)))
```

#### `import` Statements

`import` statements are statements which run another Euclid file. These statements have the syntax `import name` where `name` is a string which contains the library or file path to import. Each library or file may only be imported once per execution. Duplicate imports are ignored and should not generate any warnings or errors. Below are some examples of imports.

```text
import "test.euclid"            # import a file
import "olympiad"               # import a library
import "folder/file.euclid"     # import from a different directory
import "test.euclid"            # this line does nothing since test.euclid has already been imported
```

If a name can refer to both a file and a library, the library is imported instead of a file. The standard Euclid libraries are discussed in detail later. Custom library implementation is not standardized.

## Data Types

The central data type of the is a figure: a set of points that exists in three dimensional space.

Below is a table of all figure types in Euclid.

| Figure  | Description                                                  |
|---------|--------------------------------------------------------------|
| Point   | a sigular point                                              |
| Line    | the set of all points on an infinitely long straight line    |
| Segment | a line bounded by two endpoints                              |
| Ray     | a line bounded by one endpoint                               |
| Plane   | the set of all points on an infinitely large flat surface    |
| Circle  | the set of all points in a plane equidistant from a center   |
| Arc     | a circle that is bounded by two endpoints                    |
| Sphere  | the set of all points in space equidistant from a center     |
| Null    | the set which contains no points                             |
| Space   | the set which contains all points in three dimensional space |

Note that Circles and Spheres, by definition, do not include the points on their interiors.

Below is a table of all non-figure types in Euclid.

| Type         | Description                                        |
|--------------|----------------------------------------------------|
| Real         | A real number (NaN, inf, etc. are not implemented) |
| Boolean      | Either `true` or `false`                           |
| Tuple        | A list of other objects (may be heterogeneous)     |
| String       | A tuple of integers interpreted as text            |
| Construction | A function                                         |
| Type         | Describes a type                                   |
| Reference    | Describes a variable                               |

References are non-assignable. That is, it is impossible for a variable in Euclid to be of type Reference.

The only implicit type conversion in Euclid is from Reference to another type, specifically, from a Reference to the value which it references. This is done when a Reference is used in any operation which does not explicitly take a reference as a parameter.

There are no custom types in Euclid.

As convention, compound geometric figures are represented as tuples of figures. Each standard convention is documented below.

| Compound figure | Description                                                                                                                         |
|-----------------|-------------------------------------------------------------------------------------------------------------------------------------|
| Angle           | a tuple of two rays with a common endpoint                                                                                          |
| Polyline        | a tuple of segments such that segments adjacent in the tuple share an endpoint                                                      |
| Polygon         | a tuple of segments all in the same plane such that segments adjacent in the tuple (including the first and last) share an endpoint |
| Polyhedron      | a tuple of polygons that enclose a region in space                                                                                  |

## Literals

Literals are straightforward specifications of objects, the simplest type of expression. Below is a list of all types of literals in Euclid.

### Real Literals

Real literals in Euclid are based off of decimal real literals in C. Real literals are strings of at least one decimal digit. A decimal point (`.`) may be inserted anywere in this literal. Scientific notation may also be used by appending `e` or `E`, followed by an optional sign, (`+` or `-`), followed by an integer representing the exponent.

Below are some examples of correct real literals.

```text
743
743.
34.59
56.000
.01
0034    # leading zeros are allowed
45e-3
45.E+3
3.460e3
.0003e02
```

Below are some examples of incorrect real literals.

```text
.       # no digits present
e03     # mantissa must contain at least one digit
.e03    # mantissa must contain at least one digit
54e 43  # literal may not contain spaces
```

Negative real literals technically do not exist in Euclid. Rather, a negation operator is applied to a real literal. The implications of this are minimal. For example, the expression `-4.5` evaluates to exactly what is expected, but it does include an operator call.

### String Literals

String literals may include any ASCII characters. Unicode is currently not supported, but may be added at a later time. Since strings are tuples of integers in Euclid, each character is converted into its character code and stored in the resultant string. There are two types of string literals: short and long.

#### Short String Literals

Short string literals begin and end with one unescaped quote character. The quote character used may be a single quote (`'`) or a double quote (`"`), but a single string literal can't use both. If a short string literal continues onto the next line, the previous line must end with a backslash (`\`), and the newline will not be included in the resultant string.

Below are some valid short string literals.

```text
"Hello, world!"

'print("Hello, world!")'

"This literal spa\
ns multi\
ple lines"          # equivalent to "This literal spans multiple lines"
```

The following literals are not valid.

```text
'Mismatched quotes"

'Can't use unescaped quotes'

"Multiple
lines"
```

#### Long String Literals

Long string literals begin and end with three consecutive unescaped quote characters. Again, either a single quote or a double quote may be used, but the quote character must be the same within a single string literal. Long string literals can span multiple lines without a backslash indicator, and newlines from continuation are preseved. Adding the backslash at the end of a line will remove the newline from the resultant string.

Below are some valid long string literals.

```text
'''Multiple
lines'''            # equivalent to 'Multiple\nlines"

'''\
'' \
'\'' \
''\
'''         # equivalent to "'' ''' ''", notice how the middle ''' was escaped
```

#### Escape Codes

Within a String literal, long or short, a backslash indicates that the next character should be interpreted as part of the String. For example `"\'\"\\"` signifies a String containing a single quote, a double quote, and a backslash. Certain lowercase letters, when escaped, signify a special escape code. For example `\n` signifies the newline character. A full list of escape codes is shown below.

| Escape code | Significance                                                 |
|-------------|--------------------------------------------------------------|
| `\t`        | tab                                                          |
| `\n`        | newline                                                      |
| `\x@@`      | hexadecimal character `@@`, where `@` is a hexadecimal digit |

### Reference Literals

Reference literals are strings of uppercase letters, lowercase letters, numbers, and underscores which are not keywords in Euclid. Also, Reference literals may not start with numbers. Each unique Reference literal points to a unique variable. Example Reference literals are `x`, `redCounter`, `var_3`, and `b324_nx04`.

### Tuple Literals

Tuple literals are comma seperated lists of objects. Note that References put into the Tuple literal are not dereferenced in the resultant Tuple. Tuple literals may be enclosed in brackets (`[` and `]`) to prevent ambiguity, or to create tuples with fewer than two elements, but this is not necessary in all cases. Tuple literals may span multiple lines as long as the literal is enclosed in brackets or the last token before a new line is a comma. Tuple literals have a precedence lower than all operators except assignment. Below are some example Tuple literals.

```text
45, "Hello", alpha

[5.6, 3.14
, "]}}", x]

43, 54,
43, 32

45, 32      # invalid multiline tuple literal
, 54, 43
```

## Global Constants

Global constants are global variables which may not be reassiged. The list of predefined global constants is shown below.

| Global constant | Significance                     |
|-----------------|----------------------------------|
| `space`         | The single possible Space figure |
| `null`          | The single possible Null figure  |
| `true`          | True boolean                     |
| `false`         | False boolean                    |

The following global constants all describe Type objects.

* `Point`
* `Line`
* `Segment`
* `Ray`
* `Plane`
* `Circle`
* `Arc`
* `Sphere`
* `Null`
* `Space`
* `Real`
* `Boolean`
* `Tuple`
* `String`
* `Construction`
* `Type`
* `Reference`

The following global constants are shorthand for Type expressions.

| Global constant | Significance                                                                               |
|-----------------|--------------------------------------------------------------------------------------------|
| `Figure`        | equivalent to `Point + Line + Segment + Ray + Circle + Arc + Sphere + Null + Space`        |
| `Singleton`     | equivalent to `Figure + Real + Boolean + String + Construction + Type + Reference`         |
| `Object`        | equivalent to `Tuple + Singleton`                                                          |

### Custom Global Constants

## Operators

Operators are constructions which are invoked through a special notation for the purpose of readability. For example, the addition of two real numbers, `x` and `y`, is done by `x + y` rather than by some construction call (such as `add(x, y)`). All operators in Euclid are prefix unary (e.g. `~x`), infix binary (e.g. `x ~ y`), a bracket operator (`x(y...)` or `x[y...]`), or the assignment operator (`x = y = z = ...`).

Unless otherwise stated, when a Reference is passed as an operand, it is dereferenced. Similarly, operators do not return References unless otherwise stated.

There are no custom operators in Euclid.

### Arithmetic

All arithmetic operators take reals as operands and evaluate to reals.

There are two unary arithmetic operators: `-x` and `+x`. `-x` returns the additive inverse of `x` while `+x` returns `x`.

The binary operators are: `x + y`, `x - y`, `x * y`, `x / y`, `x // y`, `x % y`, and `x ^ y`, which return the sum, difference, product, quotiont, integer quotient, remainder, and power of `x` and `y`, respectively. The integer quotient and remainder are defined as follows: `x % y` is the minimum nonnegative value such that `(x // y) * y + (x % y)` is equal to `x`, where `x // y` is an integer.

#### Disputed Definitions

Even though the definition of `0^0` is disputed, this expression is defined in Euclid and has a value of `1`. `0^x`, where `x` is positive, is equal to `0`.

For values of `x ^ y` where `y` is not an integer, the expression is equal to `exp(log(x) * y)`. The definitions of `exp` and `log` are discussed in detail later.

#### Undefined Expressions

The following expressions are all undefined. The errors which these expressions generate, if any, is discussed in detail later.

* `x / 0`, for all `x`
* `x // 0`, for all `x`
* `x % 0`, for all `x`
* `0 ^ x`, for all negative `x`
* `x ^ y`, for all negative `x` and non-integer `y`

### Logical

All logical operators take booleans as operands and evaluate to booleans.

There are two unary logical operators: `not x` which returns the boolean negation of `x`, and `+x`, which returns `x`.

There are three binary logical operators: `x and y`, `x or y`, and `x xor y`, which return the conjunction, disjunction, and exclusive disjunction of `x` and `y`, respectively.

Symbolic alternatives for logical operators are available.

| Logical operator | Symbolic equivalents |
|------------------|----------------------|
| `not x`          | `!x` and `-x`        |
| `x and y`        | `x && y` and `x * y` |
| `x or y`         | `x || y` and `x + y` |
| `x xor y`        | `x ^^ y` and `x @ y` |

Note that some of these symbolic equivalents have different precedences.

### Comparison

All comparison operators are binary and return booleans.

#### Equivalence

There are two equivalence operators: `x == y` and `x != y`, where `x` and `y` are any type. `x == y` returns `true` if and only if `x` and `y` are the same type and have "equal" values. Two non-tuple non-real values are considered "equal" if and only if they are exactly the same. Two tuples are considered "equal" if both have the same size and corresponding elements are "equal." Two reals are considered "equal" if and only if their absolute difference does not exceed a certain limit. This limit can be zero, but if floating points are used to represent reals, a nonzero limit is recommended to mitigate floating point error.

`x != y` is equivalent to `not (x == y)`.

#### Relational

There are four relational operators: `x < y`, `x <= y`, `x > y`, and `x >= y`, where `x` and `y` are the same type. `x < y` returns true if and only if `x` is "less than" `y`. If `x` is equal to `y`, then `x` is not "less than" `y`.

For reals, `x` is less than `y` under the standard mathematical definition.

Tuples are compared lexicographically. If `x` is a proper prefix of `y`, then `x` is less than `y`.

Strings are compared as if they were tuples of integers.

For every other type, including all Figures, relational operators are undefined.

All other relational operators can be written in terms of `==` and `<`.

| Relational operator | Equivalent                  |
|---------------------|-----------------------------|
| `x <= y`            | `(x < y) or (x == y)`       |
| `x > y`             | `not ((x < y) or (x == y))` |
| `x >= y`            | `not (x < y)`               |

### Tuple Operators

Below is a list of string operators. `x` and `y` are tuples and `i`, `j`, and `k` are integers.

| Operator   | Name                    | Notes                                                |
|------------|-------------------------|------------------------------------------------------|
| `x[i]`     | Index operator          |                                                      |
| `x[i:j]`   | Slice operator          | `i` or `j` (or both) may be excluded                 |
| `x[i:j:k]` | Extended slice operator | Any combination of `i` or `j` or `k` may be excluded |
| `x + y`    | Concatenation operator  |                                                      |
| `x * i`    | Repetition operator     | Commutative: can also be `i * x`                     |

#### Indexing and Slicing

`x[i]`, the index operator, returns a Reference to element at position `i` in `x`. The first element in `x` is at position `0`. Negative indexes and indexes greater than or equal to the size of the tuple are allowed. Indexes wrap around such that `x[i]` is always equivalent to `x[i % size(x)]`. For example, `x[-1]` returns a Reference to the last element of `x`.

`x[i:j]`, the slice operator, returns either a Reference or the value of the subtuple of `x` starting at position `i`, inclusive, and ending at position `j`, exclusive, wrapping around if necessary. `j` must be greater than or equal to `i`. The slice operator follows the same index conventions as the index operator. If the resultant subtuple includes the last and first indexes (in succession and in that order), the value of the subtuple is returned. Otherwise, a Reference to the subtuple is returned. A Reference returned by the slice operator may be assigned any tuple, including ones not of the same length. This is useful for inserting or deleting elements of a tuple, as shown in the examples below. The resultant subtuple will always have size `j-i`. If `i` is not given, the resultant subtuple will begin at the first element, inclusive, never wrapping around. If `j` is not given, the resultant subtuple will end at the last element, inclusive, never wrapping around.

`x[i:j:k]`, the extended slice operator, returns a tuple of either the values of or the references to the elements in the subtuple of `x` starting at position `i`, inclusive, and ending at position `j`, exclusive, skipping by `k` elements, wrapping around if necessary. `j` must be greater than or equal to `i`, and `k` must not be equal to zero. The extended slice operator follows the same index conventions as the index operator. A Reference is returned if and only if the resultant subtuple includes each index at most once. Note that since a tuple of References is returned (not a Reference itself), it may only be assigned with tuples of the same size. If `k` is not given, it defaults to `1`. If `i` is not given, the resultant subtuple will begin at the first element if `k` is positive, or the last element if `k` is negative, inclusive, never wrapping around. If `j` is not given, the resultant subtuple will be as large as possible without wrapping around.

Below are some examples of the use of the indexing and slicing operators.

```text
x = 1, 3, 0, 3      # Here are the contents of x after each statement
x[0] = 3            # 3, 3, 0, 3
x[-1] = 0           # 3, 3, 0, 0
x[-3] = 2           # 3, 2, 0, 0
x[2] = 2            # 3, 2, 2, 0
x[5] = 1            # 3, 1, 0, 0

x[2:4] = 4, 5       # 3, 1, 4, 5
x[1:3] = 1, 2, 3    # 3, 1, 2, 3, 5
x[0:2] = 0          # Illegal: right hand side is not a tuple
x[0:2] = [0]        # 0, 2, 3, 5
x[2:] = []          # 0, 2
x[1:1] = 1, 2       # 0, 1, 2, 2
x[:-2] = 1, 0       # 1, 0, 2, 2
x[:] = 1, 2, 3      # 1, 2, 3
x = x[1:7]          # 2, 3, 1, 2, 3, 1
x[1:10] = []        # Illegal: left hand side is not a Reference

x[0::2] = x[1::2]   # 3, 3, 2, 2, 1, 1
x[0::2] = 1, 2      # Illegal: tuples are not of the same size
x = x[::-1]         # 1, 1, 2, 2, 3, 3
x[0:3:] = x[::2]    # 1, 2, 3, 2, 3, 3
x[-3::] = 4, 5, 6   # 1, 2, 3, 4, 5, 6
x = x[2:10:3]       # 3, 6, 3
```

## Concatonation and Repetition

`x + y`, the concatonation operator, returns a tuple which is the elements of `x` followed by the elements of `y`, in the order which they appear in `x` and `y`.

`x * i`, the repetition operator, returns `x` concatonated to itself `i` times. `i` must be a nonnegative integer. The operator is commutative: `x * i` is equivalent to `i * x`. For example, `x * 1` is equivalent to `x`, and `x * 0` is equivalent to `[]`, the empty tuple.

### String Operators

Below is a list of string operators. `x` and `y` are strings and `i`, `j`, and `k` are integers.

| Operator   | Name                    | Notes                                                |
|------------|-------------------------|------------------------------------------------------|
| `x[i]`     | Index operator          |                                                      |
| `x[i:j]`   | Slice operator          | `i` or `j` (or both) may be excluded                 |
| `x[i:j:k]` | Extended slice operator | Any combination of `i` or `j` or `k` may be excluded |
| `x + y`    | Concatenation operator  |                                                      |
| `x * i`    | Repetition operator     | Commutative: can also be `i * x`                     |

These string operators are almost analogous to their respective tuple operators, as Strings are actually tuples of characters. There are some differences, however.

`x[i]` is equivalent to `x[i:i+1:1]`, so it returns a Reference to a string of length one, not a character (as there is no character type in Euclid), which can only be assigned with strings of length one.

### Construction Operators

```text
create construction
x(y)
x + y
```

### Type Operators

### Assignment

The assignment operator is `x = y`. It is the only operator which has no return value.

#### Ordinary Assignment

Ordinary assignment occurs when `x` is a Reference. The value of `y` is copied into the variable `x`.

Below are some examples of assignment.

```text
x = 5 + 2     # x now has a value of 7
y = x         # y now has the same value of x (that value is 7)
x = 3         # x is 3 and y is still 7
```

#### Chain Assignment

Chain assignment is shorthand way to carry out multiple assignments. Chain assignment has the form `x = y = ... = z` and is equivalent to `x = z; y = z; ...`. Parentheses may not enclose partial chain assignments. Below are some examples.

```text
x = y = 3               # x and y are both 3
p = q = r = s = t = 0   # all the variables are set to 0

x = (y = 4)             # syntax error
(x = y = 4)             # OK
```

#### Tuple-wise Assignment

If `x` is a tuple of References and `y` is a tuple of the same size, then assignment is carried out for corresponding elements of both tuples.

For example, every line below is equivalent.

```text
[a, b, c, d] = [2, 3, 2, 3]
a = 2; b = 3; c = 2; d = 3
a, b = c, d = 2, 3
```

### Compound Assignment

Compound assignment operators are shorthand for updating a variable. The full list of compound assignment operators is shown below.

| Operator  | Equivalent   |
|-----------|--------------|
| `x += y`  | `x = x + y`  |
| `x -= y`  | `x = x - y`  |
| `x *= y`  | `x = x * y`  |
| `x /= y`  | `x = x / y`  |
| `x //= y` | `x = x // y` |
| `x %= y`  | `x = x % y`  |
| `x ^= y`  | `x = x ^ y`  |

Compound assigment operators may not be used in chain assignment.

### Precedence

Below is a table containing the operator precedence in Euclid, sorted in order of decreasing precedence. Operators listed in the same group have the same precedence. Parenthesis override precedence in the expected manner.

| Operators | Group name | Associativity |
|---|---|---|
| | Postfix Unary | Not applicable |
| | Prefix Unary | Not applicable |
| `x ^ y` | Exponentiation | Right |
| `x * y`, `x / y`, `x // y`, `x % y` | Multiplication | Left |
| `x @ y` | Alternative Exclusive Disjunction | Left |
| `x + y`, `x - y` | Addition | Left |
| `x == y`, `x != y`, `x < y`, `x > y`, `x >= y`, `x <= y` | Comparison | Left |
| `x and y`, `x && y` | Conjunction | Left |
| `x xor y`, `x ^^ y` | Exclusive Disjunction | Left |
| `x or y`, `x \|\| y` | Disjunction | Left |
| `x = y`, `x += y`, `x -= y`, `x *= y`, `x /= y`, `x //= y`, `x %= y`, `x ^= y` | Assignment | Not applicable |

## Postulates

The postulates are the most basic constructions built into Euclid. Every other construction in Euclid can be written in terms of the postulates and operators.

### Figure Manipulation

#### `plane(alpha : Point, beta : Point, gamma : Point)`

Return the unique plane which contains points `alpha`, `beta`, and `gamma`. If there is no unique plane, return `null`.

#### `sphere(center : Point, p : Point)`

Return the unique sphere with center `center` such that `p` is a point on that circle. If `center` and `p` are the same point, return `null`.

#### `point(x : Real, y : Real, z: Real)`

Return the point with Cartesian coordinates (`x`, `y`, `z`).

#### `ray(endpoint : Point, p : Point)`

Return the unique ray with endpoint `endpoint` such that `p` is a point on that ray. If `center` and `p` are the same point, return `null`.

#### `arc(start : Point, p : Point, end : Point)`

Return the unique arc with endpoints `start` and `end` such that point `p` is a point on that arc. If the three points are collinear or not pairwise distcint, return `null`.

#### `intersections(alpha : Figure, beta : Figure, omega... : Figure[])`

Return a tuple of figures whose union represents the intersection of all the figures given in the input.

#### `point_on(alpha : Figure and not Null, seed : Real = 0, index : Real)`

Return a "random" point on `alpha`. This "random" point is uniquely determined from `seed` and `index`, which must both be integers. The default index is initiallized to zero and incremented after every time `point_on` is called without `index` given. `point_on` is continuous with respect to `alpha`. That is, for fixed `seed` and `index`, sufficiently small changes in `alpha` will result in arbitrarily small changes in `point_on(alpha)`.

#### `endpoints(alpha : Figure)`

Return a tuple of the "endpoints" of `alpha`. A ray has one endpoint. Arcs and segments each have two enpoints. The endpoint of a point is the point itself. All other figures have no endpoints. If `alpha` has no endpoints, return an empty tuple.

#### `distance(alpha : Point, beta : Point)`

Return the Euclidean distance between `alpha` and `beta`.

## Control Flow

```text
if x {

} else if y {

} else {

}
while x {

}
for x in y {

}
```

## Input and Output

Input and output in Euclid is done through "streams." A "stream" is a collection of objects that can be added to using the `write` construction and taken from using the `read` construction. Streams are identified using strings, but unique names do not need to correspond to unique streams. In other words, streams may be aliased. Also, some streams may be read-only and some may be write-only. Below is the documentation of the stream interface in Euclid.

### `read(stream : String)`

Read and return an object from the stream called `stream`.

### `read()`

Read and return an object from the default read stream. The default read stream is `"stdin"` unless set otherwise.

### `write(obj, stream : String)`

Write `obj` to the stream called `stream`.

### `write(obj)`

Write `obj` to the default write stream. The default write stream is `"stdout"` unless set otherwise.

### `read_from(stream : String)`

Change the default read stream to `stream`.

### `write_to(stream : String)`

Change the default write stream to `stream`.

### `default_read()`

Return the name of the current default read stream.

### `default_write()`

Return the name of the current default write stream.

### Stream Implementation

The specification of streams is intentionally vague to allow for versatility of the Euclid language. How objects are represented in streams, for example, is not standardized. It is recommended that either JSON or EON be used for representation. However, it is not necessary to follow this recommendation. EON is Euclid Object Notation, and it is documented in `eon.md`. The recommended structure of JSON representing Euclid objects is given in `json.md`

### Standard Streams

The following streams are recommended to be implemented or aliased in Euclid.

| Stream    | Description                                      |
|-----------|--------------------------------------------------|
| `stdin`   | default input stream                             |
| `stdout`  | default output stream                            |
| `error`   | stream for logging fatal errors                  |
| `warning` | stream for logging non-fatal errors and warnings |
| `log`     | stream for logging miscellaneous information     |

## Errors

## Standard Library

The Euclid standard library is a set of constructions which is standard in the Euclid language, but may be defined in terms of Euclid itself. However it is not necessary to define them in Euclid. In fact, it is recommended to implement standard constructions marked with an asterisk (`*`) outside of Euclid for efficiency and accuracy.

## Issues

How should compilation/running be done?

Implement capturing which creating constructions so constructions can modify themselves. Implement a different type of capturing when values from an outer scope need to be used in an inner construction.

## Notes

Undefined behavior (e.g. `1/0`) may be classified as a fatal error or a non-fatal error. In the non-fatal case, `null` is returned instead.
