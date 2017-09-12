//
// Created by Mats Otten on 12/09/2017.
// Source: http://sandbox.mc.edu/~bennet/cs220/codeex/cl0_cc.html
//

#include "Point.h"

Point::Point(double x, double y) {
    xval = x;
    yval = y;
}

double Point::x() {
    return xval;
}

double Point::y() {
    return yval;
}

double Point::dist(Point other) {
    double xd = xval - other.xval;
    double yd = yval - other.yval;
    return sqrt(xd*xd + yd*yd);
}

Point Point::add(Point b) {
    return Point(xval + b.xval, yval + b.yval);
}

Point Point::sub(Point b) {
    return Point(xval - b.xval, yval - b.yval);
}

void Point::move(double a, double b)  {
    xval += a;
    yval += b;
}

void Point::print(ostream &strm) {
    strm << "(" << xval << "," << yval << ")";
}