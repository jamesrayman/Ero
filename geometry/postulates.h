#ifndef POSTULATES_H
#define POSTULATES_H

namespace geo {

    Figure intersect(const Figure& a, const Figure& b);

    Figure point_on(const Figure& a);

    Figure plane(const Figure& a, const Figure& b, const Figure& c);

    Figure sphere(const Figure& a, const Figure& b);

    Figure point(double x, double y, double z);

    Figure segment(const Figure& a, const Figure& b);

    Figure arc(const Figure& a, const Figure& b, const Figure& c);

    Figure null();

    Figure space();

}

#endif

