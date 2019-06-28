#ifndef UTILS_H
#define UTILS_H

namespace TreeUtils
{
enum class IntersectionResult
{
    Inside,
    Outside,
    Intersect
};

class Vec3
{
public:
    Vec3();
    Vec3(float x_, float y_, float z_);
    Vec3(const Vec3 &v);
    Vec3(Vec3 &&v);

    const Vec3& operator=(const Vec3 &v);
    const Vec3& operator=(Vec3 &&v);
    float operator[](unsigned int index);

    friend Vec3 operator+(const Vec3 &v1, const Vec3 &v2);
    Vec3& operator+=(const Vec3 &v);
    friend Vec3 operator-(const Vec3 &v1, const Vec3 &v2);
    Vec3& operator-=(const Vec3 &v);
    friend Vec3 operator/(const Vec3 &v, float val);
    Vec3& operator/=(float val);
    friend Vec3 operator*(const Vec3 &v, float val);
    Vec3& operator *=(float val);

    friend bool operator==(const Vec3 &v1, const Vec3 &v2);
    friend bool operator!=(const Vec3 &v1, const Vec3 &v2);

    float Length() const;
    float LengthSq() const;

public:
    union
    {
        float xyz[3];
        struct
        {
            float x;
            float y;
            float z;
        };
    };
};

class Vec4
{
public:
    Vec4();
    Vec4(float x_, float y_, float z_, float w_);
    Vec4(const Vec4 &v);
    Vec4(Vec4 &&v);

    const Vec4& operator=(const Vec4 &v);
    const Vec4& operator=(Vec4 &&v);
    float operator[](unsigned int index);

    friend Vec4 operator+(const Vec4 &v1, const Vec4 &v2);
    Vec4& operator+=(const Vec4 &v);
    friend Vec4 operator-(const Vec4 &v1, const Vec4 &v2);
    Vec4& operator-=(const Vec4 &v);
    friend Vec4 operator/(const Vec4 &v, float val);
    Vec4& operator/=(float val);
    friend Vec4 operator*(const Vec4 &v, float val);
    Vec4& operator *=(float val);

    friend bool operator==(const Vec4 &v1, const Vec4 &v2);
    friend bool operator!=(const Vec4 &v1, const Vec4 &v2);

    float Length() const;
    float LengthSq() const;

public:
    union
    {
        float xyzw[4];
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
    };
};

class Mat4
{
    Mat4();
    Mat4(const Mat4 &mat);
    Mat4(Mat4 &&mat);
    const Mat4& operator=(const Mat4 &mat);
    const Mat4& operator=(Mat4 &&mat);

    Mat4 operator*(const Mat4 &mat);
    const Mat4& operator*=(const Mat4 &mat);
    Vec4 operator*(const Vec4 &vec);

public:
    union
    {
        float matr2d[4][4];
        float matr1d[16];
        Vec4 vects[4];
    };
};

class BoundingBox
{
public:
    BoundingBox() {}
    BoundingBox(const Vec3 &ll, const Vec3 &ur);
    BoundingBox(const BoundingBox &aabb);
    BoundingBox(BoundingBox &&aabb);

    const BoundingBox& operator=(const BoundingBox &aabb);
    const BoundingBox& operator=(BoundingBox &&aabb);

    Vec3 GetCenter() const;

    Vec3 GetDimensions() const;

    void AddPoint(const Vec3 &point);

    bool Containts(const BoundingBox &bbox) const;
public:
    Vec3 m_lowerLeft = Vec3(0.0f, 0.0f, 0.0f);
    Vec3 m_upperRight = Vec3(0.0f, 0.0f, 0.0f);
};

class Object3D
{
public:
    Object3D() {}
    Object3D(const BoundingBox &aabb);
    Object3D(const Object3D &obj);
    Object3D(Object3D &&obj);

    const Object3D& operator=(const Object3D &obj);
    const Object3D& operator=(Object3D &&obj);

    const BoundingBox& GetBoundingBox() const;
public:
    BoundingBox m_aabb = BoundingBox();
};


struct Plane
{
    float a = 1.0f;
    float b = 0.0f;
    float c = 0.0f;
    float d = 0.0f;
};

class Frustum
{
    Frustum(){}
    Frustum(const Mat4 &viewProj);

    void GenerateFrustum(const Mat4 &viewProj);
public:
    Plane planes[6];
};

IntersectionResult FrustumAABBIntersect(const Frustum &frustum, const BoundingBox &aabb);
}

#endif // UTILS_H
