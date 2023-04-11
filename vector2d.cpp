#include "vector2d.h"

Vector2D::Vector2D() : x{ 0.0 }, y{ 0.0 }{};

Vector2D::Vector2D(double x, double y) : x{ x }, y{ y } {};

double Vector2D::X() const {
    return x;
}

double Vector2D::Y() const {
    return y;
}

Vector2D operator+(const Vector2D& l, const Vector2D& r) {
    return Vector2D(l.X() + r.X(), l.Y() + r.Y());
}

Vector2D operator-(const Vector2D& l, const Vector2D& r) {
    return Vector2D(l.X() - r.X(), l.Y() - r.Y());
}

Vector2D operator*(const Vector2D& l, const Vector2D& r) {
    return Vector2D(l.X() * r.X(), l.Y() * r.Y());
}

Vector2D operator/(const Vector2D& l, const Vector2D& r) {
    return Vector2D(l.X() / r.X(), l.Y() / r.Y());
}

Vector2D operator+(const Vector2D& l, double r) {
    return Vector2D(l.X() + r, l.Y() + r);
}

Vector2D operator-(const Vector2D& l, double r) {
    return Vector2D(l.X() - r, l.Y() - r);
}

Vector2D operator*(const Vector2D& l, double r) {
    return Vector2D(l.X() * r, l.Y() * r);
}

Vector2D operator/(const Vector2D& l, double r) {
    return Vector2D(l.X() / r, l.Y() / r);
}

Vector2D Limit(const Vector2D& v, double lower, double upper) {
    return Vector2D{
        fmin(fmax(v.X(), lower), upper),
        fmin(fmax(v.Y(), lower), upper)
    };
}

double Distance(const Vector2D& l, const Vector2D& r) {
    return sqrt(pow(l.X() - r.X(), 2.0) + pow(l.Y() - r.Y(), 2.0));
}