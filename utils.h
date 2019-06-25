#ifndef UTILS_H
#define UTILS_H

namespace TreeUtils
{
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
}

#endif // UTILS_H
