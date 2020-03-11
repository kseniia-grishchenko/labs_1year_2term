#ifndef LAB4_PLATE_H
#define LAB4_PLATE_H

class Vector3d;
struct Point{
    double x;
    double y;
    double z;
    Point(double x, double y, double z);
};

class Plate{
private:
    double A;
    double B;
    double C;
    double D;
public:
    Plate(Point p, Vector3d a);
    Vector3d getNormale();
    bool checkPointOnPlate(Point p);
};


#endif //LAB4_PLATE_H
