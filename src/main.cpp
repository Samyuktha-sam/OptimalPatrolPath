#include <iomanip>
#include <iostream>
#include <vector>

#include "../include/point.hpp"
#include "utils.hpp"
#include "monotone_chain.cpp"
#include "graham_scan.cpp"

using namespace geometry;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int rectangleCount;
    std::cout << "Enter number of rectangles: ";
    std::cin >> rectangleCount;

    std::vector<Point> allPoints;

    for (int i = 0; i < rectangleCount; ++i)
    {
        std::cout << "Enter coordinates for rectangle " << (i + 1) << " (x1 y1 x2 y2): ";
        double x1, y1, x2, y2;

        std::cin >> x1 >> y1 >> x2 >> y2;

        std::vector<Point> rectangle =
            axisAlignedRectangle(x1, y1, x2, y2);

        allPoints.insert(
            allPoints.end(),
            rectangle.begin(),
            rectangle.end());
    }

    int algorithmChoice;
    std::cout << "Select algorithm (0 for Monotone Chain, 1 for Graham Scan): ";
    std::cin >> algorithmChoice;
    std::vector<Point> hull =
        (algorithmChoice == 0) ? monotoneChainHull(allPoints) : grahamScanHull(allPoints);

    double perimeter =
        polygonPerimeter(hull);

    std::cout << std::fixed << std::setprecision(10) << perimeter << std::endl;

    return 0;
}