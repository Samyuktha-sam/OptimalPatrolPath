#ifndef OPTIMALPATROLPATH_POINT_HPP
#define OPTIMALPATROLPATH_POINT_HPP

#include <cmath>

namespace geometry {

struct Point {
    double x = 0.0;
    double y = 0.0;
};

inline bool operator==(const Point& a, const Point& b) noexcept {
    return a.x == b.x && a.y == b.y;
}

inline bool operator<(const Point& a, const Point& b) noexcept {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

inline double distanceSquared(const Point& a, const Point& b) noexcept {
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return dx * dx + dy * dy;
}

inline double distance(const Point& a, const Point& b) noexcept {
    return std::sqrt(distanceSquared(a, b));
}

inline double distanceBetweenPoints(const Point& a, const Point& b) noexcept {
    return distance(a, b);
}

inline double crossProduct(const Point& o,
                           const Point& a,
                           const Point& b) noexcept {

    return (a.x - o.x) * (b.y - o.y)
         - (a.y - o.y) * (b.x - o.x);
}

}

#endif