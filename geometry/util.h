#ifndef UTIL_H
#define UTIL_H

const double EPS = 1e-6;

bool approx(float a, float b) {
    return fabs(a - b) < EPS;
}

#endif

