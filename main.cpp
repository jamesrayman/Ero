#include <iostream>
#include "geometry/vector3.h"
using namespace geo;

int main() {
    
    Vector3<> v (2, 3, 4);
    v = Vector3<> (5, 6, 7);
    std::cout << v.x << "\n";

    return 0;
}
