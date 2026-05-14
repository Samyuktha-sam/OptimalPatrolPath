#include <array>   
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "../include/point.hpp"
#include "../src/utils.hpp"
#include "../src/graham_scan.cpp"

using namespace geometry;

int passed = 0;
int failed = 0;

void check(const std::string& name, double got, double expected, double tol = 1e-6) {
    if (std::abs(got - expected) <= tol) {
        std::cout << "  [PASS] " << name << "\n";
        passed++;
    } else {
        std::cout << "  [FAIL] " << name << "  got=" << got << "  expected=" << expected << "\n";
        failed++;
    }
}

double run(std::vector<std::array<double,4>> rects) {
    std::vector<Point> pts;
    for (auto& r : rects) {
        auto c = axisAlignedRectangle(r[0], r[1], r[2], r[3]);
        for (auto& p : c) pts.push_back(p);
    }
    auto hull = grahamScanHull(pts);
    long double perimeter = 0.0L;
    int h = static_cast<int>(hull.size());
    for (int i = 0; i < h; ++i)
        perimeter += distance(hull[i], hull[(i + 1) % h]);
    return static_cast<double>(perimeter);
}

int main() {
    std::cout << "============================================\n";
    std::cout << " Graham Scan Test Suite\n";
    std::cout << "============================================\n";

    check("single 3x4 rect",       run({{ {0,0,3,4} }}),              14.0);

    check("inner rect ignored",     run({{ {0,0,4,4},{1,1,2,2} }}),    16.0);

    check("two rects with gap",     run({{ {0,0,1,1},{2,0,3,1} }}),     8.0);

    std::cout << "--------------------------------------------\n";
    std::cout << " Results: " << passed << " passed, " << failed << " failed\n";
    std::cout << "============================================\n";

    return failed > 0 ? 1 : 0;
}