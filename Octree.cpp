#include "Octree.h"

Octree::Octree(const glm::vec3& min, const glm::vec3& max) {
        root = std::make_unique<OctreeNode>(min, max);
}

void Octree::insert(const glm::vec3& point) {
        root->insert(point);
}

std::vector<glm::vec3>Octree::query(const glm::vec3& min, const glm::vec3& max) {
        std::vector<glm::vec3> foundPoints;
        root->query(min, max, foundPoints);
        return foundPoints;
}




