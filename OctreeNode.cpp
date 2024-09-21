#include "OctreeNode.h"

OctreeNode::OctreeNode(const glm::vec3& min, const glm::vec3& max) 
{
	 minBounds = min;
	 maxBounds = max;
}

bool OctreeNode::isLeaf() const {
     return children[0] == nullptr;
}

void OctreeNode::subdivide() {
        glm::vec3 mid = (minBounds + maxBounds) * 0.5f;
        children[0] = std::make_unique<OctreeNode>(minBounds, mid);
        children[1] = std::make_unique<OctreeNode>(glm::vec3(mid.x, minBounds.y, minBounds.z), glm::vec3(maxBounds.x, mid.y, mid.z));
        children[2] = std::make_unique<OctreeNode>(glm::vec3(minBounds.x, minBounds.y, mid.z), glm::vec3(mid.x, mid.y, maxBounds.z));
        children[3] = std::make_unique<OctreeNode>(glm::vec3(mid.x, minBounds.y, mid.z), glm::vec3(maxBounds.x, mid.y, maxBounds.z));
        children[4] = std::make_unique<OctreeNode>(glm::vec3(minBounds.x, mid.y, minBounds.z), glm::vec3(mid.x, maxBounds.y, mid.z));
        children[5] = std::make_unique<OctreeNode>(glm::vec3(mid.x, mid.y, minBounds.z), glm::vec3(maxBounds.x, maxBounds.y, mid.z));
        children[6] = std::make_unique<OctreeNode>(glm::vec3(minBounds.x, mid.y, mid.z), glm::vec3(mid.x, maxBounds.y, maxBounds.z));
        children[7] = std::make_unique<OctreeNode>(mid, maxBounds);
}

bool OctreeNode::insert(const glm::vec3& point) {
        if (point.x < minBounds.x || point.x > maxBounds.x ||
            point.y < minBounds.y || point.y > maxBounds.y ||
            point.z < minBounds.z || point.z > maxBounds.z) {
            return false;
        }

        if (points.size() < MAX_POINTS) {
            points.push_back(point);
            return true;
        }

        if (isLeaf()) {
            subdivide();
        }

        for (auto& child : children) {
            if (child->insert(point)) {
                return true;
            }
        }

        return false;
}

void OctreeNode::query(const glm::vec3& min, const glm::vec3& max, std::vector<glm::vec3>& foundPoints)
{
        if (max.x < minBounds.x || min.x > maxBounds.x ||
            max.y < minBounds.y || min.y > maxBounds.y ||
            max.z < minBounds.z || min.z > maxBounds.z) {
            return;
        }

        for (const auto& point : points) {
            if (point.x >= min.x && point.x <= max.x &&
                point.y >= min.y && point.y <= max.y &&
                point.z >= min.z && point.z <= max.z) {
                foundPoints.push_back(point);
            }
        }

        if (!isLeaf()) {
            for (const auto& child : children) {
                child->query(min, max, foundPoints);
            }
        }
}

