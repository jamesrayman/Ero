#ifndef VECTOR3_H
#define VECTOR3_H
#include <cmath>

namespace geo {

    template <typename Real = long double>
    class Vector3 {
    public:
        Real x, y, z;
        Vector3(Real x = Real(), Real y = Real(), Real z = Real());
        Vector3<Real> operator + (const Vector3<Real>& other) const;
        Vector3<Real> operator - (const Vector3<Real>& other) const;
        template <typename T>
        friend Vector3<T> operator * (T scalar, const Vector3<T>& vec);
        Vector3<Real> operator / (Real scalar) const;
        bool operator == (const Vector3<Real>& other) const;
        bool operator != (const Vector3<Real>& other) const;
        Vector3<Real>& operator = (const Vector3<Real>& other);
        Real sqrMagnitude() const;
        Real magnitude() const;
    };

    template <typename Real>
    Real dot (Vector3<Real>& u, Vector3<Real>& v);

    template <typename Real>
    Vector3<Real> cross(Vector3<Real>& u, Vector3<Real>& v);

}

#include "vector3.tpp"
#endif

