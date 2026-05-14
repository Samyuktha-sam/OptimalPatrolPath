#ifndef OPTIMALPATROLPATH_UTILS_HPP
#define OPTIMALPATROLPATH_UTILS_HPP

#include <algorithm>
#include <vector>
#include "../include/point.hpp"

namespace geometry {

inline double polygonPerimeter(const std::vector<Point>& polygon) noexcept {
    int n = static_cast<int>(polygon.size());
    if (n < 2) return 0.0;

    double perimeter = 0.0;

    for (int i = 0; i < n; ++i) {
        perimeter += distanceBetweenPoints(polygon[i], polygon[(i + 1) % n]);
    }

    return perimeter;
}

inline std::vector<Point> axisAlignedRectangle(double x1, double y1, double x2, double y2) {
    double xmin = std::min(x1, x2);
    double xmax = std::max(x1, x2);
    double ymin = std::min(y1, y2);
    double ymax = std::max(y1, y2);

    return {
        {xmin, ymin},
        {xmin, ymax},
        {xmax, ymax},
        {xmax, ymin}
    };
}

}

#endif