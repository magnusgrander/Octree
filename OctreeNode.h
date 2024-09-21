#include <iostream>
#include <vector>
#include <memory>
#include <glm/glm.hpp>

class OctreeNode {
public:
    glm::vec3 minBounds;
    glm::vec3 maxBounds;
    std::vector<glm::vec3> points;
    std::unique_ptr<OctreeNode> children[8];
    static const int MAX_POINTS = 10;

    OctreeNode(const glm::vec3& min, const glm::vec3& max);
    bool isLeaf() const; 
    void subdivide();
    bool insert(const glm::vec3& point);
    void query(const glm::vec3& min, const glm::vec3& max, std::vector<glm::vec3>& foundPoints); 
};
