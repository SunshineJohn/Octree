#include "utils.h"

#include <utility>
#include <math.h>

namespace TreeUtils
{

// Vector's method
Vec3::Vec3():
    x(0.0f),
    y(0.0f),
    z(0.0f)
{
}

Vec3::Vec3(float x_, float y_, float z_):
    x(x_),
    y(y_),
    z(z_)
{
}

Vec3::Vec3(const Vec3 &v):
    x(v.x),
    y(v.y),
    z(v.z)
{

}

Vec3::Vec3(Vec3 &&v):
    x(v.x),
    y(v.y),
    z(v.z)
{
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
}

const Vec3& Vec3::operator=(const Vec3 &v)
{
    x = v.x;
    y = v.y;
    z = v.z;

    return *this;
}

const Vec3& Vec3::operator=(Vec3 &&v)
{
    x = v.x; v.x = 0.0f;
    y = v.y; v.y = 0.0f;
    z = v.z; v.z = 0.0f;

    return *this;
}

float Vec3::operator[](unsigned int index)
{
    return xyz[index];
}

Vec3 operator+(const Vec3 &v1, const Vec3 &v2)
{
    return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vec3& Vec3::operator+=(const Vec3 &v)
{
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

Vec3 operator-(const Vec3 &v1, const Vec3 &v2)
{
    return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vec3& Vec3::operator-=(const Vec3 &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
}

Vec3 operator/(const Vec3 &v, float val)
{
    return Vec3(v.x / val, v.y / val, v.z / val);
}

Vec3& Vec3::operator/=(float val)
{
    x /= val;
    y /= val;
    z /= val;

    return *this;
}

Vec3 operator*(const Vec3 &v, float val)
{
    return Vec3(v.x * val, v.y * val, v.z * val);
}

Vec3& Vec3::operator*=(float val)
{
    x *= val;
    y *= val;
    z *= val;

    return *this;
}

bool operator==(const Vec3 &v1, const Vec3 &v2)
{
    static constexpr float tolerance = 1e-5f;
    if (std::abs(v1.x - v2.x) < tolerance &&
        std::abs(v1.y - v2.y) < tolerance &&
        std::abs(v1.z - v2.z) < tolerance)
    {
        return true;
    }

    return false;
}

bool operator!=(const Vec3 &v1, const Vec3 &v2)
{
    return !(v1 == v2);
}

float Vec3::Length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

float Vec3::LengthSq() const
{
    return x * x + y * y + z * z;
}

// AABB's methods
BoundingBox::BoundingBox(const Vec3 &ll, const Vec3 &ur):
    m_lowerLeft(ll),
    m_upperRight(ur)
{
}

BoundingBox::BoundingBox(const BoundingBox &aabb):
    m_lowerLeft(aabb.m_lowerLeft),
    m_upperRight(aabb.m_upperRight)
{
}

BoundingBox::BoundingBox(BoundingBox &&aabb):
    m_lowerLeft(std::move(aabb.m_lowerLeft)),
    m_upperRight(std::move(aabb.m_upperRight))
{
}

const BoundingBox& BoundingBox::operator=(const BoundingBox &aabb)
{
    m_lowerLeft = aabb.m_lowerLeft;
    m_upperRight = aabb.m_upperRight;

    return *this;
}

const BoundingBox& BoundingBox::operator=(BoundingBox &&aabb)
{
    m_lowerLeft = std::move(aabb.m_lowerLeft);
    m_upperRight = std::move(aabb.m_upperRight);

    return *this;
}

Vec3 BoundingBox::GetCenter() const
{
    return (m_lowerLeft + m_upperRight) * 0.5f;
}

Vec3 BoundingBox::GetDimensions() const
{
    return (m_upperRight - m_lowerLeft);
}

void BoundingBox::AddPoint(const Vec3 &point)
{
    if (point.x < m_lowerLeft.x)
        m_lowerLeft.x = point.x;
    else if (point.x > m_upperRight.x)
        m_upperRight.x = point.x;

    if (point.y < m_lowerLeft.y)
        m_lowerLeft.y = point.y;
    else if (point.y > m_upperRight.y)
        m_upperRight.y = point.y;

    if (point.z < m_lowerLeft.z)
        m_lowerLeft.z = point.z;
    else if (point.z > m_upperRight.z)
        m_upperRight.z = point.z;
}

bool BoundingBox::Containts(const BoundingBox &bbox) const
{
    if (m_lowerLeft.x >= bbox.m_lowerLeft.x ||
        m_lowerLeft.y >= bbox.m_lowerLeft.y ||
        m_lowerLeft.z >= bbox.m_lowerLeft.z ||
        m_upperRight.x <= bbox.m_upperRight.x ||
        m_upperRight.y <= bbox.m_upperRight.y ||
        m_upperRight.z <= bbox.m_upperRight.z)
    {
        return false;
    }

    return true;
}

// Object3D's methods
Object3D::Object3D(const BoundingBox &aabb):
    m_aabb(aabb)
{
}

Object3D::Object3D(const Object3D &obj):
    m_aabb(obj.m_aabb)
{
}

Object3D::Object3D(Object3D &&obj):
    m_aabb(std::move(obj.m_aabb))
{
}

const Object3D& Object3D::operator=(const Object3D &obj)
{
    m_aabb = obj.m_aabb;

    return *this;
}

const Object3D& Object3D::operator=(Object3D &&obj)
{
    m_aabb = std::move(obj.m_aabb);

    return *this;
}

const BoundingBox& Object3D::GetBoundingBox() const
{
    return m_aabb;
}

}
