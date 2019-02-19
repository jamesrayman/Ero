#include <cmath>

template <typename Real = long double>
class Vector3 {
public:
    const Real x, y, z;
    Vector3(Real x = Real(), Real y = Real(), Real z = Real());
    Vector3 operator + (const Vector3& other) const;
    Vector3 operator - (const Vector3& other) const;
};
