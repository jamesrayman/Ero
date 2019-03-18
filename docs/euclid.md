# Euclid

Euclid is a functional scripting language intended to describe and render Euclidean constructions in two or three dimensions. The Euclid language is inspired by _Elements_, an ancient geometry textbook by Euclid of Alexandria. As a result, the Euclid language does not focus on algebra or arithmetic. Rather, it relies on geometry as its main method of computation. Euclid is Turing complete (able to compute anything which is computable) and Euclid complete (able to construct any Euclidean construction), despite being built on a few basic constructions (which we will call "postulates") and a simple syntax.

## Table of Contents

1. [Basic Structure](#basic-structure)
1. [Data Types](#data-types)
1. [The Postulates](#the-postulates)
1. [Operators](#operators)
1. [Control Flow](#control-flow)
1. [Standard Library](#standard-library)

## Basic Structure

The basic building block of a Euclid program is a "statement." The Euclid syntax is specified in a way that it is always clear where a statement ends, so statement enders (like semicolons) are not implemented. Hashtags denote single line comments: anything on the same line after a hashtag will be ignored by the Euclid interpreter.

```text
p = point_on(space)  # single line statement
q = p r = q          # multiple statements on one line
a, b, c              # multiline statement
 =
  p, q, r
# this is a comment
```

Block statements are a list of statements enclosed by braces (`{` and `}`) on either end.

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

Note that circles and spheres, by definition, do not include the points on their interiors.

The non-figure types in Euclid are: reals, strings, booleans, references, tuples, and constructions.

## The Postulates

Let the following be postulated:

1. To describe the intersection of two given figures.
1. To select a point on a given figure.
1. To describe a plane given three points not on one line.
1. To describe a sphere given a center and a point on that sphere.
1. To describe a point given its coordinates.
1. To describe a ray given an endpoint and a point on that ray.
1. To describe an arc given its endpoints and a point on that arc.
1. To determine the type of a given object.

These postulates are implemented in Euclid using the following constructions:

### `intersection(alpha, beta, ...)`

### `point_on(alpha, seed, index)`

### `plane(alpha, beta, gamma)`

### `sphere(center, p)`

### `point(x, y, z)`

### `ray(endpoint, p)`

### `arc(start, p, end)`

### `type(alpha)`

## Global Constants

Global constants are like global variables, but they may not be reassiged. Custom global constants can't be created. The full list of global constants is shown below:

* `space`: The single possible Space figure
* `null`: The single possible Null figure
* `true`: True boolean
* `false`: False boolean

## Operators

## Control Flow

## Input/Output

## Standard Library

There is a built in standard library with Euclid. It will be documented here.
