#include <algorithm>
#include <vector>

#include "../include/point.hpp"

namespace geometry {

std::vector<Point> grahamScanHull(std::vector<Point> points) {
    int n = static_cast<int>(points.size());
    if (n < 3) return points;

    int ymin = 0;
    for (int i = 1; i < n; ++i) {
        if ((points[i].y < points[ymin].y) ||
            (points[i].y == points[ymin].y && points[i].x < points[ymin].x)) {
            ymin = i;
        }
    }

    std::swap(points[0], points[ymin]);
    Point base = points[0];

    std::sort(points.begin() + 1, points.end(), [&](Point const& p1, Point const& p2) {
        double orient = crossProduct(base, p1, p2);
        if (orient == 0.0) {
            return distanceSquared(base, p1) < distanceSquared(base, p2);
        }
        return orient > 0.0;
    });

    std::vector<Point> hull;
    hull.reserve(n);
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);

    for (int i = 3; i < n; ++i) {
        while (hull.size() >= 2 &&
               crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}

}