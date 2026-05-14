#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "../include/point.hpp"
#include "../src/monotone_chain.cpp"
#include "../src/graham_scan.cpp"

using namespace geometry;

using Clock = std::chrono::high_resolution_clock;
using Milliseconds = std::chrono::milliseconds;

std::vector<Point> createRandomPoints(int numberOfPoints) {
    std::vector<Point> points;
    points.reserve(numberOfPoints);

    std::mt19937 randomEngine(42);
    std::uniform_real_distribution<double> coordinateRange(-1000000.0, 1000000.0);

    for (int i = 0; i < numberOfPoints; ++i) {
        points.push_back({
            coordinateRange(randomEngine),
            coordinateRange(randomEngine)
        });
    }

    return points;
}

long long measureMonotoneChainTime(const std::vector<Point>& points) {
    auto startTime = Clock::now();

    auto hull = monotoneChainHull(points);

    auto endTime = Clock::now();

    return std::chrono::duration_cast<Milliseconds>(
        endTime - startTime
    ).count();
}

long long measureGrahamScanTime(const std::vector<Point>& points) {
    auto startTime = Clock::now();

    auto hull = grahamScanHull(points);

    auto endTime = Clock::now();

    return std::chrono::duration_cast<Milliseconds>(
        endTime - startTime
    ).count();
}

int main() {
    std::vector<int> inputSizes = {
        1000,
        10000,
        50000,
        100000,
        200000
    };

    std::cout << "Input Size\tMonotone Chain(ms)\tGraham Scan(ms)\n";
    std::cout << "--------------------------------------------------------\n";

    for (int size : inputSizes) {
        std::vector<Point> points = createRandomPoints(size);

        long long monotoneTime = measureMonotoneChainTime(points);
        long long grahamTime = measureGrahamScanTime(points);

        std::cout << size<< "\t\t"<< monotoneTime<< "\t\t\t"<< grahamTime << "\n";
    }

    return 0;
}