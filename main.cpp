#include "octree.h"

struct ObjHolder
{
    ObjHolder() = default;
    ~ObjHolder()
    {
        for (auto& obj : objects)
        {
            delete obj;
        }
    }

    std::vector<TreeUtils::Object3D*> objects;
};

int main()
{
    ObjHolder objHolder;

    objHolder.objects.push_back(new TreeUtils::Object3D(TreeUtils::BoundingBox(TreeUtils::Vec3(-10, -7, -8),
                                                                               TreeUtils::Vec3(-9, -6, -7))));
    objHolder.objects.push_back(new TreeUtils::Object3D(TreeUtils::BoundingBox(TreeUtils::Vec3(-8, -7, -8),
                                                                               TreeUtils::Vec3(-7, -6, -7))));
    objHolder.objects.push_back(new TreeUtils::Object3D(TreeUtils::BoundingBox(TreeUtils::Vec3(6, 6, -3),
                                                                               TreeUtils::Vec3(8, 8, -1))));
    objHolder.objects.push_back(new TreeUtils::Object3D(TreeUtils::BoundingBox(TreeUtils::Vec3(-2, -2, -2),
                                                                               TreeUtils::Vec3(0, 0, 0))));
    objHolder.objects.push_back(new TreeUtils::Object3D(TreeUtils::BoundingBox(TreeUtils::Vec3(-10, -7, 7),
                                                                               TreeUtils::Vec3(-9, -6, 8))));
    objHolder.objects.push_back(new TreeUtils::Object3D(TreeUtils::BoundingBox(TreeUtils::Vec3(-8, -7, 7),
                                                                               TreeUtils::Vec3(-7, -6, 8))));
    objHolder.objects.push_back(new TreeUtils::Object3D(TreeUtils::BoundingBox(TreeUtils::Vec3(6, 6, 1),
                                                                               TreeUtils::Vec3(8, 8, 3))));
    objHolder.objects.push_back(new TreeUtils::Object3D(TreeUtils::BoundingBox(TreeUtils::Vec3(1, 1, 1),
                                                                               TreeUtils::Vec3(2, 2, 2))));

    TreeLib::Octree octree(TreeUtils::BoundingBox(TreeUtils::Vec3(-10, -10, -10),
                                                  TreeUtils::Vec3(10, 10, 10)));

    for (auto& obj: objHolder.objects)
    {
        octree.AddObject(obj);
    }

    octree.UpdateTree();

    objHolder.objects.push_back(new TreeUtils::Object3D(TreeUtils::BoundingBox(TreeUtils::Vec3(-8, 6, -8),
                                                                               TreeUtils::Vec3(-7, 7, -7))));
    objHolder.objects.push_back(new TreeUtils::Object3D(TreeUtils::BoundingBox(TreeUtils::Vec3(-8, 6, 1),
                                                                               TreeUtils::Vec3(-6, 8, 3))));

    octree.AddObject(objHolder.objects[objHolder.objects.size() - 1]);
    octree.AddObject(objHolder.objects[objHolder.objects.size() - 2]);

    octree.UpdateTree();

    return 0;
}
