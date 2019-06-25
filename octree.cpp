#include "octree.h"

namespace TreeLib {

void Node::BuildTree()
{
    if (m_objects.size() < 2)
    {
        return;
    }

    TreeUtils::Vec3 dimensions = m_region.GetDimensions();

    if (dimensions.LengthSq() < 1)
    {
        return;
    }

    TreeUtils::Vec3 center = m_region.GetCenter();

    TreeUtils::BoundingBox octants[octCount];
    octants[0] = TreeUtils::BoundingBox(m_region.m_lowerLeft, center);
    octants[1] = TreeUtils::BoundingBox(TreeUtils::Vec3(center.x, m_region.m_lowerLeft.y, m_region.m_lowerLeft.z),
                                        TreeUtils::Vec3(m_region.m_upperRight.x, center.y, center.z));
    octants[2] = TreeUtils::BoundingBox(TreeUtils::Vec3(center.x, m_region.m_lowerLeft.y, center.z),
                                        TreeUtils::Vec3(m_region.m_upperRight.x, center.y, m_region.m_upperRight.z));
    octants[3] = TreeUtils::BoundingBox(TreeUtils::Vec3(m_region.m_lowerLeft.x, m_region.m_lowerLeft.y, center.z),
                                        TreeUtils::Vec3(center.x, center.y, m_region.m_upperRight.z));
    octants[4] = TreeUtils::BoundingBox(TreeUtils::Vec3(m_region.m_lowerLeft.x, center.y, m_region.m_lowerLeft.z),
                                        TreeUtils::Vec3(center.x, m_region.m_upperRight.y, center.z));
    octants[5] = TreeUtils::BoundingBox(TreeUtils::Vec3(center.x, center.y, m_region.m_lowerLeft.z),
                                        TreeUtils::Vec3(m_region.m_upperRight.x, m_region.m_upperRight.y, center.z));
    octants[6] = TreeUtils::BoundingBox(center, m_region.m_upperRight);
    octants[7] = TreeUtils::BoundingBox(TreeUtils::Vec3(m_region.m_lowerLeft.x, center.y, center.z),
                                        TreeUtils::Vec3(center.x, m_region.m_upperRight.y, m_region.m_upperRight.z));

    std::list<const TreeUtils::Object3D*> octObjects[octCount];

    std::list<const TreeUtils::Object3D*> delList;

    for (auto &object : m_objects)
    {
        if (object->m_aabb.m_lowerLeft != object->m_aabb.m_upperRight)
        {
            for (int i = 0; i < octCount; ++i)
            {
                if (octants[i].Containts(object->m_aabb))
                {
                    octObjects[i].push_front(object);
                    delList.push_front(object);
                    break;
                }
            }
        }
    }

    for (auto &object: delList)
    {
        m_objects.remove(object);
    }

    for (unsigned long long i = 0; i < octCount; ++i)
    {
        if (!octObjects[i].empty())
        {
            m_childs[i] = new Node(octObjects[i], octants[i]);
            m_childs[i]->m_parent = this;
            m_activeNodes |= static_cast<char>(1 << i);
            m_childs[i]->BuildTree();
        }
    }
}

Octree::Octree(const TreeUtils::BoundingBox &boundingBox)
{
    m_root = new Node(boundingBox);
}

void Octree::AddObject(const TreeUtils::Object3D *object)
{
    m_pendingObjects.push_back(object);
}

void Octree::UpdateTree()
{
    if (m_treeBuilt)
    {

    }
    else
    {
        while (m_pendingObjects.size() > 0)
        {
            m_root->m_objects.push_front(m_pendingObjects.back());
            m_pendingObjects.pop_back();
        }

        BuildTree();

        m_treeBuilt = true;
    }

    m_treeReady = true;
}

void Octree::BuildTree()
{
    m_root->BuildTree();
}


}
