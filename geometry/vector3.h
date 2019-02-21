#include <cmath>

namespace geo {

    template <typename Real = long double>
    class Vector3 {
    public:
        Real x, y, z;
        Vector3(Real x = Real(), Real y = Real(), Real z = Real());
        Vector3 operator + (const Vector3& other) const;
        Vector3 operator - (const Vector3& other) const;
        template <typename T>
        friend Vector3<T> operator * (T scalar, const Vector3<T>& vec);
        // friend Vector3 operator * (const Vector3& vec, Real scalar);
        Vector3 operator / (Real scalar) const;
        bool operator == (const Vector3& other) const;
        bool operator != (const Vector3& other) const;
        Vector3& operator = (const Vector3& other) {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }
        Real magnitude() const;
        Real sqrMagnitude() const;
    };

    template <typename Real>
    Real dot (Vector3<Real> v, Vector3<Real> u);

    template <typename Real>
    Vector3<Real> cross(Vector3<Real> v, Vector3<Real> u);

    /* Begin implementation */
    template <typename Real>
    Vector3<Real>::Vector3(Real x, Real y, Real z) : x(x), y(y), z(z) {
    }
}
