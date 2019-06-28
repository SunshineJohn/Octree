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
    float invVal = 1.0f / val;

    return Vec3(v.x * invVal, v.y * invVal, v.z * invVal);
}

Vec3& Vec3::operator/=(float val)
{
    float invVal = 1.0f / val;

    x *= invVal;
    y *= invVal;
    z *= invVal;

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

// Vec4's methods
Vec4::Vec4():
    x(0.0f),
    y(0.0f),
    z(0.0f),
    w(0.0f)
{

}

Vec4::Vec4(float x_, float y_, float z_, float w_):
    x(x_),
    y(y_),
    z(z_),
    w(w_)
{

}

Vec4::Vec4(const Vec4 &v):
    x(v.x),
    y(v.y),
    z(v.z),
    w(v.w)
{

}

Vec4::Vec4(Vec4 &&v):
    x(v.x),
    y(v.y),
    z(v.z),
    w(v.w)
{
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    v.w = 0.0f;
}

const Vec4& Vec4::operator=(const Vec4 &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;

    return *this;
}

const Vec4& Vec4::operator=(Vec4 &&v)
{
    x = v.x; v.x = 0.0f;
    y = v.y; v.y = 0.0f;
    z = v.z; v.z = 0.0f;
    w = v.w; v.w = 0.0f;

    return *this;
}

float Vec4::operator[](unsigned int index)
{
    return xyzw[index];
}

Vec4 operator+(const Vec4 &v1, const Vec4 &v2)
{
    return Vec4(v1.x + v2.x,
                v1.y + v2.y,
                v1.z + v2.z,
                v1.w + v2.w);
}

Vec4& Vec4::operator+=(const Vec4 &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;

    return *this;
}

Vec4 operator-(const Vec4 &v1, const Vec4 &v2)
{
    return Vec4(v1.x - v2.x,
                v1.y - v2.y,
                v1.z - v2.z,
                v1.w - v2.w);
}

Vec4& Vec4::operator-=(const Vec4 &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;

    return *this;
}

Vec4 operator/(const Vec4 &v, float val)
{
    float invVal = 1.0f / val;
    return Vec4(v.x * invVal,
                v.y * invVal,
                v.z * invVal,
                v.w * invVal);
}

Vec4& Vec4::operator/=(float val)
{
    float invVal = 1.0f / val;

    x *= invVal;
    y *= invVal;
    z *= invVal;
    w *= invVal;

    return *this;
}

Vec4 operator*(const Vec4 &v, float val)
{
    return Vec4(v.x * val,
                v.y * val,
                v.z * val,
                v.w * val);
}

Vec4& Vec4::operator*=(float val)
{
    x *= val;
    y *= val;
    z *= val;
    w *= val;

    return *this;
}

bool operator==(const Vec4 &v1, const Vec4 &v2)
{
    static constexpr float tolerance = 1e-5f;
    if (std::abs(v1.x - v2.x) < tolerance &&
        std::abs(v1.y - v2.y) < tolerance &&
        std::abs(v1.z - v2.z) < tolerance &&
        std::abs(v1.w - v2.w) < tolerance)
    {
        return true;
    }

    return false;
}

bool operator!=(const Vec4 &v1, const Vec4 &v2)
{
    return !(v1 == v2);
}

float Vec4::Length() const
{
    return std::sqrt(x * x + y * y + z * z + w * w);
}

float Vec4::LengthSq() const
{
    return x * x + y * y + z * z + w * w;
}

// Mat4's methods
Mat4::Mat4():
    vects{ Vec4(1.0f, 0.0f, 0.0f, 0.0f),
           Vec4(0.0f, 1.0f, 0.0f, 0.0f),
           Vec4(0.0f, 0.0f, 1.0f, 0.0f),
           Vec4(0.0f, 0.0f, 0.0f, 1.0f) }
{
}

Mat4::Mat4(const Mat4 &mat):
    vects{ mat.vects[0],
           mat.vects[1],
           mat.vects[2],
           mat.vects[3] }
{
}

Mat4::Mat4(Mat4 &&mat)
{
    vects[0] = std::move(mat.vects[0]);
    vects[1] = std::move(mat.vects[1]);
    vects[2] = std::move(mat.vects[2]);
    vects[3] = std::move(mat.vects[3]);
}

const Mat4& Mat4::operator=(const Mat4 &mat)
{
    vects[0] = mat.vects[0];
    vects[1] = mat.vects[1];
    vects[2] = mat.vects[2];
    vects[3] = mat.vects[3];

    return *this;
}

const Mat4& Mat4::operator=(Mat4 &&mat)
{
    vects[0] = std::move(mat.vects[0]);
    vects[1] = std::move(mat.vects[1]);
    vects[2] = std::move(mat.vects[2]);
    vects[3] = std::move(mat.vects[3]);

    return *this;
}

Mat4 Mat4::operator*(const Mat4 &mat)
{
    Mat4 result;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            result.matr2d[i][j] =
                    matr2d[i][0] * mat.matr2d[0][j] +
                    matr2d[i][1] * mat.matr2d[1][j] +
                    matr2d[i][2] * mat.matr2d[2][j] +
                    matr2d[i][3] * mat.matr2d[3][j];
        }
    }

    return result;

}

const Mat4& Mat4::operator*=(const Mat4 &mat)
{
    Mat4 result;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            result.matr2d[i][j] =
                    matr2d[i][0] * mat.matr2d[0][j] +
                    matr2d[i][1] * mat.matr2d[1][j] +
                    matr2d[i][2] * mat.matr2d[2][j] +
                    matr2d[i][3] * mat.matr2d[3][j];
        }
    }

    vects[0] = std::move(result.vects[0]);
    vects[1] = std::move(result.vects[1]);
    vects[2] = std::move(result.vects[2]);
    vects[3] = std::move(result.vects[3]);

    return *this;
}

Vec4 Mat4::operator*(const Vec4 &vec)
{
    Vec4 result;

    for (int i = 0; i < 4; ++i)
    {
        result.xyzw[i] =
                matr2d[i][0] * vec.xyzw[0] +
                matr2d[i][1] * vec.xyzw[1] +
                matr2d[i][2] * vec.xyzw[2] +
                matr2d[i][3] * vec.xyzw[3];
    }

    return result;
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

Frustum::Frustum(const Mat4 &viewProj)
{
    GenerateFrustum(viewProj);
}

void Frustum::GenerateFrustum(const Mat4 &viewProj)
{
    static auto Normalize = [](Plane &plane)
    {
        float length = std::sqrt(plane.a * plane.a +
                                 plane.b * plane.b +
                                 plane.c * plane.c);

        plane.a /= length;
        plane.b /= length;
        plane.c /= length;
        plane.d /= length;
    };

    planes[0].a = viewProj.matr2d[0][3] + viewProj.matr2d[0][0];
    planes[0].b = viewProj.matr2d[1][3] + viewProj.matr2d[1][0];
    planes[0].c = viewProj.matr2d[2][3] + viewProj.matr2d[2][0];
    planes[0].d = viewProj.matr2d[3][3] + viewProj.matr2d[3][0];
    Normalize(planes[0]);

    planes[1].a = viewProj.matr2d[0][3] - viewProj.matr2d[0][0];
    planes[1].b = viewProj.matr2d[1][3] - viewProj.matr2d[1][0];
    planes[1].c = viewProj.matr2d[2][3] - viewProj.matr2d[2][0];
    planes[1].d = viewProj.matr2d[3][3] - viewProj.matr2d[3][0];
    Normalize(planes[1]);

    planes[2].a = viewProj.matr2d[0][3] - viewProj.matr2d[0][1];
    planes[2].b = viewProj.matr2d[1][3] - viewProj.matr2d[1][1];
    planes[2].c = viewProj.matr2d[2][3] - viewProj.matr2d[2][1];
    planes[2].d = viewProj.matr2d[3][3] - viewProj.matr2d[3][1];
    Normalize(planes[2]);

    planes[3].a = viewProj.matr2d[0][3] + viewProj.matr2d[0][1];
    planes[3].b = viewProj.matr2d[1][3] + viewProj.matr2d[1][1];
    planes[3].c = viewProj.matr2d[2][3] + viewProj.matr2d[2][1];
    planes[3].d = viewProj.matr2d[3][3] + viewProj.matr2d[3][1];
    Normalize(planes[3]);

    planes[4].a = viewProj.matr2d[0][2];
    planes[4].b = viewProj.matr2d[1][2];
    planes[4].c = viewProj.matr2d[2][2];
    planes[4].d = viewProj.matr2d[3][2];
    Normalize(planes[4]);

    planes[5].a = viewProj.matr2d[0][3] - viewProj.matr2d[0][2];
    planes[5].b = viewProj.matr2d[1][3] - viewProj.matr2d[1][2];
    planes[5].c = viewProj.matr2d[2][3] - viewProj.matr2d[2][2];
    planes[5].d = viewProj.matr2d[3][3] - viewProj.matr2d[3][2];
    Normalize(planes[5]);
}

IntersectionResult FrustumAABBIntersect(const Frustum &frustum, const BoundingBox &aabb)
{
    IntersectionResult res = IntersectionResult::Inside;

    TreeUtils::Vec3 min, max;
    for (int j = 0; j < 6; ++j)
    {
        // X coord
        if (frustum.planes[j].a > 0)
        {
            min.x = aabb.m_lowerLeft.x;
            max.x = aabb.m_upperRight.x;
        }
        else
        {
            max.x = aabb.m_lowerLeft.x;
            min.x = aabb.m_upperRight.x;
        }

        // Y coord
        if (frustum.planes[j].b > 0)
        {
            min.y = aabb.m_lowerLeft.y;
            max.y = aabb.m_upperRight.y;
        }
        else
        {
            max.y = aabb.m_lowerLeft.y;
            min.y = aabb.m_upperRight.y;
        }

        // Z coord
        if (frustum.planes[j].c > 0)
        {
            min.z = aabb.m_lowerLeft.z;
            max.z = aabb.m_upperRight.z;
        }
        else
        {
            max.z = aabb.m_lowerLeft.z;
            min.z = aabb.m_upperRight.z;
        }

        static auto dot = [](const TreeUtils::Plane &p, const TreeUtils::Vec3 &v)->float
        {
            return p.a * v.x + p.b * v.y + p.c * v.z;
        };

        if (dot(frustum.planes[j], min)  + frustum.planes[j].d > 0)
        {
            return IntersectionResult::Outside;
        }

        if (dot(frustum.planes[j], max)  + frustum.planes[j].d >= 0)
        {
            res = IntersectionResult::Intersect;
        }
    }

    return res;
}

}
