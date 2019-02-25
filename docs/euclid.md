# Euclid

Euclid is a functional scripting language intended to describe and render Euclidean constructions in two or three dimensions. The Euclid language is inspired by _Elements_, an ancient geometry textbook by Euclid of Alexandria. As a result, the Euclid language does not use any algebra or arithmetic. Rather, it relies on geometry as its main method of computation. Euclid is Turing complete (able to compute anything which is computable) and Euclid complete (able to construct any Euclidean construction) despite being built on four basic constructions (which we will call "postulates") and a simple syntax.

### Table of Contents
1. [Basic Structure](#basic-structure)
1. [Data Types](#data-types)
1. [The Postulates](#the-postulates)
1. [Standard Library](#standard-library)
1. [Issues](#issues)
1. [Examples](#examples)

### Basic Structure

The basic building block of a Euclid program is a "statement." Statements are normally one line long, ended by a newline. Statements may be explicitly ended by a semicolon. A backslash at the end of a line will cancel the statement ending, allowing statements to span multiple lines. Hashtags denote single line comments. Anything on the same line after a hashtag will be ignored by the Euclid interpreter.

```
p = point_on(space)   # single line statement
q = p; r = q          # multiple statements on one line
a b c \               # multiline statement
 = \
  p q r
# backslashes do not work on comments \
this_is = not_a_comment
```





### Data Types

The Euclid language has a core data type which is called a figure.

The following structures are all represented as figures.
* Line
* Point
* Plane
* Space
* Null
* Circle
* Sphere
* Segment
* Arc

The non-figure types in Euclid are reals, strings, and constructions.

### The Postulates

Let the following be postulated:
1. `intersection` To describe the intersection of two given figures.
1. `point_on` To select a point on a given figure.
1. `plane` To describe a plane given three points not on one line.
1. `sphere` To describe a sphere given a center and a point on that sphere.
1. `point` To define a given point.
1. `segment` To define a line segment.
1. `null` To create a null figure.
1. `space` To create a space figure.
1. `arc` To create a arc figure.

### Standard Library

There is a built in standard library with Euclid.

### Issues
What is our viewpoint on abuse of the language? Should the language be allowed to be abused, like C++? Or should abuse be completely disabled?

Deterministic `point_on` should be implemented somehow. We could possibly use a point_on function that seeds the randomness to make it consistently give the same point?

How should we handle real numbers? Should we allow the passing of numerical properties out of Euclid, such as area? Should we include a complete arithmetic system?

What is a complete list of figure types we want? What about non-figure types? To what extent are non-figure types usable in Euclid?

How mobile should constructions be? Should constructions be reassignable within the same scope? Within other scopes? Should constructions be allowed as parameters?

Should we include decisions other than `type_check`?

Should we generalize block statements?

Should a more sophisticated tuple system be implemented?

Should the extremities of a solid (e.g. the surface of a sphere, the edges of a polygon) be distinguished from the interior?

Should we put commas between elements in a tuple?

Which of the following figure types should be implemented?
* Polygon
* Polyline
* Polyarc
* Ray
* Angle
* Solid angle
* Polyhedron

Should we add booleans?


