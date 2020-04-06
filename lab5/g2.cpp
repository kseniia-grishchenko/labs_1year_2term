#include "g2.h"
#include <cmath>
#include <algorithm>

double Point::get_x() {
    return x;
}

double Point::get_y() {
    return y;
}

bool Point::operator == (const Point & obj) const {
    return x == obj.x && y == obj.y;
}

bool Point::operator != (const Point & obj) const {
    return x != obj.x || y != obj.y;
}

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}


Segment::Segment() {
    first = Point{};
    second = Point{};
}

Segment::Segment(Point first, Point second) {
    this->first = first;
    this->second = second;

}

Segment::Segment(double x1, double y1, double x2, double y2) {
    first = Point{x1, y1};
    second = Point{x2, y2};
}

double distance_between_points(Point p1, Point p2){
    return sqrt(pow(p1.get_x() - p2.get_x(), 2) + pow(p1.get_y() - p2.get_y(), 2));
}

bool Segment::check_point_on_segment(Point p) {
    const double E = 0.001;
    if(fabs(distance_between_points(first, p) + distance_between_points(second, p) - distance_between_points(first, second)) < E) {
        return true;
    }
    return false;
}

double Segment::calculate_distance(Point p) {
    double distance = 0;
    if(check_point_on_segment(p)){
        return 0;
    }
    Line line{*this};
    Line perpendicular = line.get_perpendicular(p);
    Point crossing_point = line.get_crossing_point(perpendicular);
    if(check_point_on_segment(crossing_point)){
        return distance_between_points(crossing_point, p);
    }
    double distance1 = distance_between_points(first, p);
    double distance2 = distance_between_points(second, p);
    return  std::min(distance1, distance2);
}


Line::Line() {
    A = 0;
    B = 0;
    C = 0;
}

Line::Line(Segment s) {
    A = s.get_first().get_y() - s.get_second().get_y();
    B = s.get_second().get_x() - s.get_first().get_x();
    C = s.get_first().get_x() * s.get_second().get_y() - s.get_second().get_x() * s.get_first().get_y();
}

Line::Line(double A, double B, double C) {
    this->A = A;
    this->B = B;
    this->C = C;
}

Line Line::get_perpendicular(Point p) {
    return Line{B, -A, -B * p.get_x() + A * p.get_y()};
}

Point Line::get_point(double x) {
    return Point{x, - (A*x)/B -C/B};
}

Point Line::get_crossing_point(Line line) {
    if(this->A == 0 && line.B == 0){
        return Point{-line.C / line.A, -this->C / this->B};
    }
    if(this->B == 0 && line.A == 0){
        return Point{-this->C / this->A, -line.C / line.B};
    }
    Point p1 = this->get_point(0);
    Point p2 = this->get_point(1);
    Point p3 = line.get_point(0);
    Point p4 = line.get_point(1);

    return Point{((p1.get_x()*p2.get_y() - p1.get_y()*p2.get_x())*(p3.get_x() - p4.get_x()) - (p1.get_x() - p2.get_x())*(p3.get_x()*p4.get_y() - p3.get_y()*p4.get_x())/((p1.get_x() - p2.get_x())*(p3.get_y() - p4.get_y()) - (p1.get_y() - p2.get_y())*(p3.get_x() - p4.get_x()))), ((p1.get_x()*p2.get_y() - p1.get_y()*p2.get_x()) * (p3.get_y() - p4.get_y()) - (p1.get_y() - p2.get_y()) * (p3.get_x()*p4.get_y() - p3.get_y()*p4.get_x())) / ((p1.get_x() - p2.get_x()) * (p3.get_y() - p4.get_y()) - (p1.get_y() - p2.get_y()) * (p3.get_x() - p4.get_x()))};
}






