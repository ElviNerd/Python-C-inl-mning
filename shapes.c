#include "shapes.h"
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


double rectangle_area(double height, double width) {
    return height * width;
}

double rectangle_perimeter(double height, double width) {
    return 2 * (height + width);
}

double parallelogram_area(double base, double height) {
    return base * height;
}

double parallelogram_perimeter(double base, double side) {
    return 2 * (base + side);
}

double triangle_area(double base, double height) {
    return 0.5 * base * height;
}

double triangle_perimeter(double side1, double side2, double side3) {
    return side1 + side2 + side3;
}

double circle_area(double radius) {
    return M_PI * pow(radius, 2);
}

double circle_circumference(double radius) {
    return 2 * M_PI * radius;
}