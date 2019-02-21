#include "vector3.h"

namespace geo {

    template <typename Real>
    Vector3<Real>::Vector3(Real a, Real b, Real c) : x(a), y(b), z(c) {}

    template <typename Real>
    Vector3<Real> Vector3<Real>::operator + (const Vector3& other) const {
        return Vector3<Real>(x + other.x, y + other.y, z + other.z);
    }

    template <typename Real>
    Vector3<Real> Vector3<Real>::operator - (const Vector3& other) const {
        return Vector3<Real>(x - other.x, y - other.y, z - other.z);
    }

    template <typename T>
    Vector3<T> operator * (T scalar, const Vector3<T>& vec) {
        return Vector3<T>(vec.x * scalar, vec.y * scalar, vec.z * scalar);
    }

    template <typename Real>
    Vector3<Real> Vector3<Real>::operator / (Real scalar) const {
        return Vector3<Real>(x / scalar, y / scalar, z / scalar);
    }

    template <typename Real>
    bool Vector3<Real>::operator == (const Vector3<Real> other) const {
        return approx(x, other.x) && approx(y, other.y) && approx(z, other.z);
    }

}

