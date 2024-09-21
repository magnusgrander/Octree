#include "OctreeNode.h"

class Octree {
public:
    std::unique_ptr<OctreeNode> root;
    Octree(const glm::vec3& min, const glm::vec3& max);
    void insert(const glm::vec3& point);
    std::vector<glm::vec3> query(const glm::vec3& min, const glm::vec3& max);
};



