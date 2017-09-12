//
// Created by Mats Otten on 12/09/2017.
// Source: http://sandbox.mc.edu/~bennet/cs220/codeex/cl0_cc.html
//

#ifndef MOTION_VISION_POINT_H
#define MOTION_VISION_POINT_H


#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;

class Point {
private:
    double xval, yval;
public:
    // Constructor uses default arguments to allow calling with zero, one,
    // or two values.
    Point(double x = 0.0, double y = 0.0);
    double x();
    double y();
    double dist(Point other);
    Point add(Point b);
    Point sub(Point b);
    void move(double a, double b);
    void print(ostream &strm);


    // Distance to another point.  Pythagorean thm.
    double dist(Point other) {
        double xd = xval - other.xval;
        double yd = yval - other.yval;
        return sqrt(xd*xd + yd*yd);
    }

    // Add or subtract two points.
    Point add(Point b)
    {
        return Point(xval + b.xval, yval + b.yval);
    }
    Point sub(Point b)
    {
        return Point(xval - b.xval, yval - b.yval);
    }

    // Move the existing point.
    void move(double a, double b)
    {
        xval += a;
        yval += b;
    }

    // Print the point on the stream.  The class ostream is a base class
    // for output streams of various types.
    void print(ostream &strm)
    {
        strm << "(" << xval << "," << yval << ")";
    }
};


#endif //MOTION_VISION_POINT_H
