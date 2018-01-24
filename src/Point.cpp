//
// Created by Mats Otten on 12/09/2017.
// Source: http://sandbox.mc.edu/~bennet/cs220/codeex/cl0_cc.html
//

#include "Point.h"

Point::Point(double x, double y, double z) {
    xval = x;
    yval = y;
    zval = z;
}


double Point::x() {
    return this->xval;
}

double Point::y() {
    return this->yval;
}

double Point::z() {
    return this->zval;
}

double Point::dist(Point other) {
    double xd = xval - other.xval;
    double yd = yval - other.yval;
    return sqrt(xd*xd + yd*yd);
}

Point Point::add(Point b) {
    return Point(this->xval + b.xval, this->yval + b.yval);
}

Point Point::sub(Point b) {
    return Point(this->xval - b.xval, this->yval - b.yval);
}

void Point::move(double a, double b)  {
    xval += a;
    yval += b;
}

void Point::print(ostream &strm) {
    strm << "(" << xval << "," << yval << ")";
}

double Point::dotProduct(Point other) {
	return this->x() * other.x() + this->y() * other.y() + this->z() * other.z();
}

double Point::angle(double dotProduct, Point other) {

	double vDot = dotProduct / (this->length() * other.length());
	cout << "vDot " << vDot << endl;
	if(vDot < -1.0) vDot = -1.0;
	if(vDot > 1.0) vDot = 1.0;

	cout << "dotProduct " << dotProduct << endl;
	cout << "this->length() " << this->length() << endl;
	cout << "other.length() " << other.length() << endl;
	cout << "vDot " << vDot << endl;

	cout << " ±±±±±±±±±±± " << endl;

	return acos(vDot);
}

double Point::length() {
	return sqrt(sqrt(x()) + sqrt(y()) + sqrt(z()));
}

Point Point::cross(Point other) {
	return Point(this->y() * other.z() - this->z() * other.y(), this->z() * other.x() - this->x() * other.z(), this->x() * other.y() - this->y() * other.x());
}
