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
    double xval, yval, zval;
public:
    // Constructor uses default arguments to allow calling with zero, one,
    // or two values.
    Point(double x = 0.0, double y = 0.0, double z = 0.0);
    double x();
    double y();
    double z();
    double dist(Point other);
    Point add(Point b);
    Point sub(Point b);
    void move(double a, double b);
    void print(ostream &strm);
    double dotProduct(Point other);
	double angle(Point other);
	Point cross(Point other);
	double length();
	void normalize(Point point);
	void normalize();
};


#endif //MOTION_VISION_POINT_H
