#include <algorithm>
#include <vector>

#include "../include/point.hpp"

namespace geometry {

std::vector<Point> monotoneChainHull(std::vector<Point> points) {
    int n = static_cast<int>(points.size());
    if (n <= 1) return points;

    std::sort(points.begin(), points.end());
    points.erase(std::unique(points.begin(), points.end()), points.end());
    n = static_cast<int>(points.size());
    if (n <= 1) return points;

    std::vector<Point> hull;
    hull.reserve(2 * n);

    for (int i = 0; i < n; ++i) {
        while (static_cast<int>(hull.size()) >= 2 &&
               crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    int lowerSize = static_cast<int>(hull.size());
    for (int i = n - 2; i >= 0; --i) {
        while (static_cast<int>(hull.size()) > lowerSize &&
               crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    if (!hull.empty()) {
        hull.pop_back();
    }
    return hull;
}

}