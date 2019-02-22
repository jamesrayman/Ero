#ifndef FIGURE_H
#define FIGURE_H
#include <string>

namespace geo {
    
    class Figure {
    public:
        virtual Figure intersect(Figure& other) const = 0;
        virtual Figure pointOn() const = 0;
    }
}

#endif

