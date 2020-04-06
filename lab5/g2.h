#ifndef LAB5_G2_H
#define LAB5_G2_H

class Point{
private:
    double x;
    double y;
public:
    Point();
    Point(double x,  double y);

    double get_x();
    double get_y();
    bool operator == (const Point & obj) const;
    bool operator != (const Point & obj) const;
};

class Segment{
private:
    Point first;
    Point second;
public:
    Segment();
    Segment(Point first, Point second);
    Segment(double x1, double y1, double x2, double y2);

    Point get_first(){
        return first;
    }

    Point get_second(){
        return second;
    }

    bool check_point_on_segment(Point p);
    double calculate_distance(Point p);
};

class Line{
private:
    double A;
    double B;
    double C;
public:
    Line();
    explicit Line(Segment s);
    Line(double A, double B, double C);

    Line get_perpendicular(Point p);

    Point get_point(double x);
    Point get_crossing_point(Line line);




};

#endif //LAB5_G2_H
