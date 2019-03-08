# Euclid

Euclid is a functional scripting language intended to describe and render Euclidean constructions in two or three dimensions. The Euclid language is inspired by _Elements_, an ancient geometry textbook by Euclid of Alexandria. As a result, the Euclid language does not focus on algebra or arithmetic. Rather, it relies on geometry as its main method of computation. Euclid is Turing complete (able to compute anything which is computable) and Euclid complete (able to construct any Euclidean construction), despite being built on a few basic constructions (which we will call "postulates") and a simple syntax.

### Table of Contents
1. [Basic Structure](#basic-structure)
1. [Data Types](#data-types)
1. [The Postulates](#the-postulates)
1. [Standard Library](#standard-library)

### Basic Structure

The basic building block of a Euclid program is a "statement." The Euclid syntax is specified in a way that it is always clear where a statement ends, so statement enders (like semicolons) are not implemented. Hashtags denote single line comments: anything on the same line after a hashtag will be ignored by the Euclid interpreter.

```
p = point_on(space)  # single line statement
q = p r = q          # multiple statements on one line
a, b, c              # multiline statement
 =
  p, q, r
# this is a comment
```

Block statements are a list of statements enclosed by braces (`{` and `}`) on either end.




### Data Types

The central data type of the is a figure: a set of points that exists in three dimensional space.

The following structures are all represented as figures.
* Point: just one point
* Line: 
* Segment: a line bounded by two endpoints
* Ray: a line bounded by one endpoint
* Plane: 
* Circle: the set of all points in a plane equidistant from a center
* Arc: a circle that is bounded by two endpoints
* Sphere: the set of all points in space equidistant from a center
* Null: no points
* Space: all points in three dimensional space

The non-figure types in Euclid are reals, strings, and constructions.

### The Postulates

Let the following be postulated:
1. `intersection`: To describe the intersection of two given figures.
1. `point_on`: To select a point on a given figure.
1. `plane`: To describe a plane given three points not on one line.
1. `sphere`: To describe a sphere given a center and a point on that sphere.
1. `point`: To define a given point.
1. `segment`: To define a line segment.
1. `null`: To create a null figure.
1. `space`: To create a space figure.
1. `arc`: To create a arc figure.

### Standard Library

There is a built in standard library with Euclid. It will be documented here.

### Issues
Should we include decisions other than `type_check`?

Should we generalize block statements?

How should global variables be implemented?


