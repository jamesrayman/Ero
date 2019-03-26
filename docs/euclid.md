# Euclid

Euclid is a functional scripting language intended to describe and render Euclidean constructions in two or three dimensions. The Euclid language is inspired by _Elements_, an ancient geometry textbook by Euclid of Alexandria. As a result, the Euclid language does not focus on algebra or arithmetic. Rather, it relies on geometry as its main method of computation, even though real arithmetic is still supported. Euclid is Turing complete (able to compute anything which is computable) and Euclid complete (able to construct any Euclidean construction). Euclid can also be used to create non-Euclidean constructions (such as an angle trisection and squaring the circle).

## Table of Contents

1. [Basic Structure](#basic-structure)
1. [Data Types](#data-types)
1. [Global Constants](#global-constants)
1. [Literals](#literals)
1. [The Postulates](#the-postulates)
1. [Operators](#operators)
1. [Control Flow](#control-flow)
1. [Standard Library](#standard-library)
1. [Issues](#issues)

## Basic Structure

### Objects

In Euclid, an "object" is some piece of data that signifies something. For example the sphere with center (3, 4, 2) and radius 2 is an object. The real number -4.34 is also an object. Data types in Euclid are discussed in detail later.

### Expressions

An "expression" is an instruction on how to compute the value of an object. Simple literals like `-4.34` and `"Hello, world"` are considered expressions, as they specify how to create a real object and a string object, respectively. More complex expressions can be created through the use of constructions, or functions, along with operators. For example `sqrt(x^2 + y^2 + z^2)` is an expression that computes the distance from the origin to point (`x`, `y`, `z`).

### Statements

A "statement" on how to change the state of the program. A Euclid program is a list of statement. Upon program execution, these statements are run in order unless they are part of a control flow structure that states to do otherwise (like an `if` statement).

The Euclid syntax is specified in a way that it is always clear where a statement ends, so statement terminators (like semicolons) are not implemented. Hashtags denote single line comments: anything on the same line after a hashtag will be ignored by the Euclid interpreter.

Euclid code samples thorughout this documentation is displayed like the sample below:

```text
p = point_on(space)  # single line statement
q = p r = q          # multiple statements on one line
a, b, c              # multiline statement
 =
  p, q, r
# this is a comment
```

A block statement is a list of statements enclosed by braces (`{` and `}`) on either end. Block statements are used in control flow. If a block statement is encountered outside of a control flow statement, every individual statement within the block is run in order as if the braces were never there.

Possibly the most frequent statement in Euclid is an assignment. The assignment operator is discussed in detail later. Below are some examples of assignment statements:

```text
a = b                   # the value of variable b is copied into variable a
a, b, c = p, q, r       # Python-like tuple assignment
omega = radius(         # assignment with a complex expression
  sphere(
    point_on(space), 
    point_on(space)))
```

## Data Types

The central data type of the is a figure: a set of points that exists in three dimensional space.

Below is a list of all figure types in Euclid:

* Point: just one point
* Line: the set of all points on an infinitely long straight line
* Segment: a line bounded by two endpoints
* Ray: a line bounded by one endpoint
* Plane: the set of all points on an infinitely large flat surface
* Circle: the set of all points in a plane equidistant from a center
* Arc: a circle that is bounded by two endpoints
* Sphere: the set of all points in space equidistant from a center
* Null: no points
* Space: all points in three dimensional space

Note that Circles and Spheres, by definition, do not include the points on their interiors.

Below is a list of all non-figure types in Euclid:

* Real: A real number (NaN, inf, etc. are not implemented)
* Boolean: Either `true` or `false`
* Tuple: A list of other types
* String: A tuple of integers interpreted as text
* Construction: A function
* Type: Describes a type
* Reference: Describes a variable

References and Types are non-assignable. That is, no variable in Euclid is allowed to be of type Reference or Type. Using a Type object in an assignment (explicit or implicit) will result in an error.

The only implicit type conversion in Euclid is from Reference to another type, done when a Reference is used in any operation which does not explicitly take a reference as a parameter.

There are no custom types in Euclid.

As convention, compound geometric figures are represented as tuples of figures. Each standard convention is documented below:

* Angle: a pair of rays with a common endpoint
* Polyline: a tuple of segments such that segments adjacent in the tuple share an endpoint
* Polygon: a tuple of segments all in the same plane such that segments adjacent in the tuple (including the first and last) share an endpoint
* Polyhedron: a tuple of polygons that enclose a region in space

## Literals

Literals are straightforward specifications of objects, the simplest type of expression. Below is a list of all types of literals in Euclid:

### Real Literals

### String Literals

String literals may include any ASCII characters. Since strings are tuples of integers in Euclid, each character is converted into its character code and stored in the resultant string. There are two types of string literals: short and long.

#### Short String Literals

Short string literals begin and end with one unescaped quote character. The quote character used may be a single quote (`'`) or a double quote (`"`), but a single string literal can't use both. If a short string literal continues onto the next line, the previous line must end with a backslash (`\`), and the newline will not be included in the resultant string.

Below are some valid short string literals:

```text
"Hello, world!"

'print("Hello, world!")'

"This literal spa\
ns multi\
ple lines"          # equivalent to "This literal spans multiple lines"
```

The following literals are not valid:

```text
'Mismatched quotes"

'Can't use unescaped quotes'

"Multiple
lines"
```

#### Long String Literals

Long string literals begin and end with three consecutive unescaped quote characters. Again, either a single quote or a double quote may be used, but the quote character must be the same within a single string literal. Long string literals can span multiple lines without a backslash indicator, and newlines from continuation are preseved. Adding the backslash at the end of a line will remove the newline from the resultant string.

Below are some valid long string literals:

```text
'''Multiple
lines'''            # equivalent to 'Multiple\nlines"

'''\
'' \
'\'' \
''\
'''         # equivalent to "'' ''' ''"
            # notice how the middle ''' was escaped
```

#### Escape Codes

Within a String literal, long or short, a backslash indicates that the next character should be interpreted as part of the String. For example `"\'\"\\"` signifies a String containing a single quote, a double quote, and a backslash. Certain lowercase letters, when escaped, signify a special escape code. For example `\n` signifies the newline character. A full list of escape codes is shown below:

| Escape Code | Significance                                                 |
|-------------|--------------------------------------------------------------|
| `\t`        | tab                                                          |
| `\n`        | newline                                                      |
| `\x**`      | hexadecimal character `**`, where `*` is a hexadecimal digit |

### Reference Literals

Reference literals are strings of uppercase letters, lowercase letters, numbers, and underscores which are not keywords in Euclid. Also, Reference literals may not start with numbers. Each unique Reference literal points to a unique variable. Example Reference literals are `x`, `redCounter`, `var_3`, and `b324_nx04`.

### Tuple Literals

Tuple literals are comma seperated lists of objects. Note that References put into the Tuple literal are not dereferenced in the resultant Tuple. Tuple literals may be enclosed in brackets (`[` and `]`) to prevent ambiguity, but this is unnecessary in most cases. Below are some example Tuple literals:

```text
45, "Hello", alpha

[5.6, 3.14
, "]}}", x]
```

## Global Constants

Global constants are global variables which may not be reassiged. Custom global constants can't be created. The full list of global constants is shown below:

* `space`: The single possible Space figure
* `null`: The single possible Null figure
* `true`: True boolean
* `false`: False boolean

The following global constants all describe Type objects:

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

The following global constants are shorthand for Type expressions:

* `Figure`: equivalent to `Point + Line + Segment + Ray + Circle + Arc + Sphere + Null + Space`

## The Postulates

The postulates are the basis for figure manipulation in Euclid. They are implemented using the following constructions:

### `plane(alpha : Point, beta : Point, gamma : Point)`

### `sphere(center : Point, p : Point)`

### `point(x : Real, y : Real, z: Real)`

### `ray(endpoint : Point, p : Point)`

### `arc(start : Point, p : Point, end : Point)`

### `intersection(alpha : Figure, beta : Figure, ... : Figure)`

### `point_on(alpha : Figure and not Null, seed : Real, index : Real)`

### `endpoints(alpha : Figure)`

### `length(alpha : Figure)`

## Operators

Compound assignment operators, such as `+=` and `*=`, along with increment and decrement operators, i.e. `++` and `--`, are not supported in Euclid. -Issues: but should they?

## Control Flow

## Input/Output

Input and output in Euclid is done through "streams." A "stream" is a collection of objects that can be added to using the `write` construction and taken from using the `read` construction. Streams are identified using strings, but unique names need not correspond to unique streams. In other words, streams may be aliased. Below is the documentation of the stream interface in Euclid:

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

### Implementation

The specification of streams is intentionally vague to allow for versatility of the Euclid language. How objects are represented in streams, for example, is not standardized. It is recommended that either JSON or EON be used for representation (EON is Euclid Object Notation, which is documented in `eon.md`), but it is not necessary to follow this recommendation.

### Standard Streams

The following streams are recommended to be implemented or aliased in Euclid:

| Stream    | Function                                         |
|-----------|--------------------------------------------------|
| `stdin`   | default input stream                             |
| `stdout`  | default output stream                            |
| `error`   | stream for logging fatal errors                  |
| `warning` | stream for logging non-fatal errors and warnings |
| `log`     | stream for logging miscellaneous information     |

## Standard Library

The Euclid standard library is a set of constructions which is standard in the Euclid language, but may be defined in terms of Euclid itself. However it is not necessary to define them in Euclid. In fact, it is recommended to implement standard constructions marked with an asterisk (`*`) outside of Euclid for efficiency and accuracy.

## Issues

Tuple and string manipulation should be functional, but strict functional manipulation is too expensive.

Using ... as the variadic tuple is inconsistent.

How should we support unicode?
