# Euclid

Euclid is a functional scripting language intended to describe and render Euclidean constructions in two or three dimensions. The Euclid language is inspired by _Elements_, an ancient geometry textbook by Euclid of Alexandria. As a result, the Euclid language does not use any algebra or arithmetic. Rather, it relies on geometry as its main method of computation. Euclid is Turing complete (able to compute anything which is computable) and Euclid complete (able to construct any Euclidean construction) despite being built on four basic constructions (which we will call "postulates") and a simple syntax.

### Table of Contents
1. [Basic Structure](#basic-structure)
1. [Data Types](#data-types)
1. [The Four Postulates](#the-four-postulates)
1. [Standard Library](#standard-library)
1. [Suggestions](#suggestions)
1. [Examples](#examples)

### Basic Structure

The basic building block of a Euclid program is a "statement". Statements are normally one line long, ended by a newline. Statements may be explicitly ended by a semicolon. A backslash at the end of a line will cancel the statement ending, allowing statements to span multiple lines. Hashtags denote single line comments. Anything on the same line after a hashtag will be ignored by the Euclid interpreter.

```
p = point_on space    # single line statement
q = p; r = q          # multiple statements on one line
a b c \               # multiline statement
 = \
  p q r 
# backslashes do not work on comments \
this_is = not_a_comment
```


### Data Types



### The Four Postulates

Let the following be postulated:
1. To describe a plane given three points not on one line,
1. To describe a sphere given a center and a point on that sphere,
1. To describe the intersection of two given figures,
1. To select a point on a given figure.

### Standard Library


### Suggestions
Create a `given` function which will allow for the passing of points into Euclid, eliminating the use of numbers.
Should `##` be a multiline comment?
Deterministic `point_on` should be implemented somehow.

### Examples



