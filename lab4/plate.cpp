#include "plate.h"
#include "vector3d.h"

Point::Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Plate::Plate(Point p, Vector3d a) {
    A = a.getX();
    B = a.getY();
    C = a.getZ();
    D = - A * p.x  - B * p.y - C * p.z;
}

Vector3d Plate::getNormale() {
    return Vector3d{A, B, C};
}

bool Plate::checkPointOnPlate(Point p) {
    if(A * p.x + B * p.y + C * p.z + D == 0)
        return true;
    return false;
}


