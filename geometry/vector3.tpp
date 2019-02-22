#include "vector3.h"
#include "util.h"
#include <cmath>

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
    bool Vector3<Real>::operator == (const Vector3<Real>& other) const {
        return approx(x, other.x) && approx(y, other.y) && approx(z, other.z);
    }

    template <typename Real>
    bool Vector3<Real>::operator != (const Vector3<Real>& other) const {
        return !(*this == other);
    }

    template <typename Real>
    Vector3<Real>& Vector3<Real>::operator = (const Vector3<Real>& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    template <typename Real>
    Real Vector3<Real>::sqrMagnitude() const {
        return x * x + y * y + z * z;
    }

    template <typename Real>
    Real Vector3<Real>::magnitude() const {
        return sqrt(sqrMagnitude());
    }

    template <typename Real>
    Real dot(Vector3<Real>& u, Vector3<Real>& v) {
        return u.x * v.x + u.y * v.y + u.z * v.z;
    }

    template <typename Real>
    Vector3<Real> cross(Vector3<Real>& u, Vector3<Real>& v) {
        return Vector3<Real>(u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x);
    }

}

