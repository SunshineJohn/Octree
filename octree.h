#ifndef OCTREE_H
#define OCTREE_H

#include "utils.h"

#include <list>
#include <vector>

namespace TreeLib {

static constexpr short octCount = 8;

class Node
{
public:
    Node() = delete;
    Node(const std::list<const TreeUtils::Object3D*> &objects,
         const TreeUtils::BoundingBox &region):
        m_objects(objects),
        m_region(region)
    {
        m_childs.resize(octCount);
    }
    Node(const TreeUtils::BoundingBox &region):
        m_region(region)
    {
        m_childs.resize(octCount);
    }

    void BuildTree();
public:
    std::list<const TreeUtils::Object3D*> m_objects;

    TreeUtils::BoundingBox m_region = TreeUtils::BoundingBox();

    std::vector<Node*> m_childs;
    Node *m_parent = nullptr;

    static const short m_minSize = 1;

    char m_activeNodes = 0;
};

class Octree
{
public:
    Octree(const TreeUtils::BoundingBox &boundingBox);

    void AddObject(const TreeUtils::Object3D *object);

    void UpdateTree();
private:
    void BuildTree();

private:
    Node *m_root = nullptr;

    bool m_treeReady = false;
    bool m_treeBuilt = false;

    std::list<const TreeUtils::Object3D*> m_pendingObjects;
};
}

#endif // OCTREE_H
