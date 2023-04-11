#pragma once

#include <math.h>

class Vector2D {
public:
    Vector2D();
    Vector2D(double x, double y);
    double X() const;
    double Y() const;
private:
    double x, y;
};

Vector2D Limit(const Vector2D& v, double lower, double upper);
double Distance(const Vector2D& l, const Vector2D& r);

Vector2D operator+(const Vector2D& l, const Vector2D& r);
Vector2D operator-(const Vector2D& l, const Vector2D& r);
Vector2D operator*(const Vector2D& l, const Vector2D& r);
Vector2D operator/(const Vector2D& l, const Vector2D& r);
Vector2D operator+(const Vector2D& l, double r);
Vector2D operator-(const Vector2D& l, double r);
Vector2D operator*(const Vector2D& l, double r);
Vector2D operator/(const Vector2D& l, double r);

