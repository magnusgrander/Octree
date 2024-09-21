#include "Octree.h"

int main() {
    Octree octree(glm::vec3(0, 0, 0), glm::vec3(100, 100, 100));
    octree.insert(glm::vec3(10, 10, 10));
    octree.insert(glm::vec3(20, 20, 20));
    octree.insert(glm::vec3(30, 30, 30));

    std::vector<glm::vec3> results = octree.query(glm::vec3(5, 5, 5), glm::vec3(25, 25, 25));
    for (const auto& point : results) {
        std::cout << "Found point: (" << point.x << ", " << point.y << ", " << point.z << ")\n";
    }

    return 0;
}
