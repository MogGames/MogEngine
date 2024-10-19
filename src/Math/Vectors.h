#ifndef VECTORS_H
#define VECTORS_H

#include <cmath>
#include <iostream>

struct Vector2 {
  float x, y;

  Vector2() : x(0), y(0) {}
  Vector2(float x, float y) : x(x), y(y) {}

  Vector2 operator+(const Vector2 other) const {
    return Vector2(x + other.x, y + other.y);
  }

  Vector2 operator-(const Vector2 &other) const {
    return Vector2(x - other.x, y - other.y);
  }

  Vector2 operator*(float scalar) const {
    return Vector2(x * scalar, y * scalar);
  }

  float dot(const Vector2 &other) const { return x * other.x + y * other.y; }

  float magnitude() const { return std::sqrt(x * x + y * y); }

  Vector2 normalize() const {
    float mag = magnitude();
    return Vector2(x / mag, y / mag);
  }

  void print() const { std::cout << "(" << x << ", " << y << ")" << std::endl; }
};

struct Vector3 {
  float x, y, z;

  // Constructors
  Vector3() : x(0), y(0), z(0) {}
  Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

  // Vector addition
  Vector3 operator+(const Vector3 &other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
  }

  // Vector subtraction
  Vector3 operator-(const Vector3 &other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
  }

  // Scalar multiplication
  Vector3 operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
  }

  // Dot product
  float dot(const Vector3 &other) const {
    return x * other.x + y * other.y + z * other.z;
  }

  // Cross product (specific to 3D vectors)
  Vector3 cross(const Vector3 &other) const {
    return Vector3(y * other.z - z * other.y, z * other.x - x * other.z,
                   x * other.y - y * other.x);
  }

  // Magnitude (length)
  float magnitude() const { return std::sqrt(x * x + y * y + z * z); }

  // Normalize (unit vector)
  Vector3 normalize() const {
    float mag = magnitude();
    return Vector3(x / mag, y / mag, z / mag);
  }

  // Print vector (for debugging)
  void print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
  }
};

#endif
