# Octree algorithm
GLM fast position based Octree
All coordinates stored in a GLM::Vec3 node will be stored into an octree with adaptive depth. As the name implies, each node can have a maximum of eight successors. The nodes in this tree are representing cubic fractions of space. An intermediate node divides his cube into eight subcubes with the same size by halving the sides. This means the (max 8) successors of the intermediate node are representing subcubes of the cube of this node. The cube parameters are not stored explicit in the nodes, they are definitly defined by the parameters of the superior cube and the index of the successor pointer to this cube. A cube defined by a leaf node contains exactly one coordinate. The insert algorithm creates automatically intermediate nodes if two coordinates would fall into the same cube.

Each node has an array of pointers to it's successors. As shown in the picture above an intermediate node divides his cube into eight subcubes. A subnode of this node with index i represents a subcube with this index as shown in the left half of the picture. Each leaf node contains exactly one coordinate. So if two coordinates would fall into the same cube, this cube must be divided into subcubes using an intermediate node. In the example in the picture above such an intermediate is shown. The node has two subnodes (in this case leaf nodes) defining two subcubes 0 and 3 which are containing a coordinate.

# OpenGL Mathematics (GLM)
GLM is a C++ mathematics library for graphics software based on the OpenGL Shading Language (GLSL) specification.
GLM provides classes and functions designed and implemented with the same naming conventions and functionalities than GLSL so that when a programmer knows GLSL, he knows GLM as well which makes it really easy to use.
This project isn't limited by GLSL features. An extension system, based on the GLSL extension conventions, provides extended capabilities: matrix transformations, quaternions, half-based types, random numbers, etc... 

# How to use
```
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
```



