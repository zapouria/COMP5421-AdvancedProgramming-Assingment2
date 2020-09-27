#include "Point4D.h"
#include <iostream>
#include <sstream>
#include <cmath>

double Point4D::tolerance = 1.0E-6; //tolerance variable

//function to set tolerance
void Point4D::setTolerance(double tol) {
    tolerance = std::abs(tol);
}

//function to get the tolerance
double Point4D::getTolerance() {
    return tolerance;
}

//constructor with 4 parameters
Point4D::Point4D(double arg1 , double arg2 , double arg3, double arg4 ) {
    point[0] = arg1;
    point[1] = arg2;
    point[2] = arg3;
    point[3] = arg4;
}

//copy constructor
Point4D::Point4D(const Point4D &p1) = default;

//unary plus operator overload
Point4D Point4D::operator+() {
    return *this;
}

//binary addition operator overload
Point4D operator+(const Point4D &p1, const Point4D &p2) {
    Point4D temp = p1;
    temp += p2;
    return temp;
}

//scalar addition operator overload
Point4D operator+(double a, const Point4D &p1) {
    Point4D temp = p1;
    temp += a;
    return temp;
}

//scalar addition operator overload
Point4D operator+(const Point4D &p1, double a) {
    return a + p1;
}

//addition compound operator overload
Point4D Point4D::operator+=(const Point4D &p1) {
    this->point[0] = this->point[0] + p1.point[0];
    this->point[1] = this->point[1] + p1.point[1];
    this->point[2] = this->point[2] + p1.point[2];
    this->point[3] = this->point[3] + p1.point[3];
    return *this;
}

//addition compound operator overload
Point4D Point4D::operator+=(double a) {
    this->point[0] = this->point[0] + a;
    this->point[1] = this->point[1] + a;
    this->point[2] = this->point[2] + a;
    this->point[3] = this->point[3] + a;
    return *this;
}

//unary minus operator overload
Point4D Point4D::operator-() {
    return *this * -1;
}

//binary subtraction operator overload
Point4D operator-(const Point4D &p1, const Point4D &p2) {
    Point4D temp = p1;
    temp -= p2;
    return temp;
}

//scalar subtraction operator overload
Point4D operator-(double a, const Point4D &p1) {
    Point4D temp = p1;
    temp -= a;
    temp = -temp;
    return temp;
}

//scalar subtraction operator overload
Point4D operator-(const Point4D &p1, double a) {
    Point4D temp = p1;
    temp -= a;
    return temp;
}

//subtraction compound operator overload
Point4D Point4D::operator-=(const Point4D &p1) {
    this->point[0] = this->point[0] - p1.point[0];
    this->point[1] = this->point[1] - p1.point[1];
    this->point[2] = this->point[2] - p1.point[2];
    this->point[3] = this->point[3] - p1.point[3];

    return *this;
}

//subtraction compound operator overload
Point4D Point4D::operator-=(double a) {
    this->point[0] = this->point[0] - a;
    this->point[1] = this->point[1] - a;
    this->point[2] = this->point[2] - a;
    this->point[3] = this->point[3] - a;
    return *this;
}

//binary multiplication operator overload
Point4D operator*(const Point4D &p1, const Point4D &p2) {
    Point4D temp = p1;
    temp *= p2;
    return temp;
}

//scalar multiplication operator overload
Point4D operator*(double a, const Point4D &p1) {
    Point4D temp = p1;
    temp *= a;
    return temp;
}

//scalar multiplication operator overload
Point4D operator*(const Point4D &p1, double a) {
    return a * p1;
}

//multiplication compound operator overload
Point4D Point4D::operator*=(const Point4D &p1) {
    Point4D temp;
    temp.point[0] = this->point[0] * p1.point[0] + this->point[1] * p1.point[3];
    temp.point[1] = this->point[0] * p1.point[1] + this->point[1] * p1.point[2];
    temp.point[2] = this->point[3] * p1.point[1] + this->point[2] * p1.point[2];
    temp.point[3] = this->point[3] * p1.point[0] + this->point[2] * p1.point[3];
    *this = temp;
    return temp;
}

//multiplication compound operator overload
Point4D Point4D::operator*=(double a) {
    this->point[0] = this->point[0] * a;
    this->point[1] = this->point[1] * a;
    this->point[2] = this->point[2] * a;
    this->point[3] = this->point[3] * a;
    return *this;
}

//binary division operator overload
Point4D operator/(const Point4D &p1, const Point4D &p2) {
    try {
        return p1 * (p2.inverse());
    }
    catch (const std::exception& e) {
        std::cout << e.what() << endl;
    }
}

//scalar division operator overload
Point4D operator/(double a, const Point4D &p1) {
    try {
        return a * (p1.inverse());
    }
    catch (const std::exception& e) {
        std::cout << e.what() << endl;
    }
}

//scalar division operator overload
Point4D operator/(const Point4D &p1, double a) {
    return p1 * (1 / a);
}

//division compound operator overload
Point4D Point4D::operator/=(const Point4D &p1) {
    try {
        *this *= p1.inverse();
        return *this;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << endl;
    }
}

//division compound operator overload
Point4D Point4D::operator/=(double a) {
    *this *= 1 / a;
    return *this;
}

//prefix increment operator overload
Point4D Point4D::operator++() {
    *this = 1 + *this;
    return *this;
}

//postfix increment operator overload
Point4D Point4D::operator++(int) {
    try {
        Point4D temp = *this;
        *this = *this + 1;
        return temp;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << endl;
    }
}

//prefix decrement operator overload
Point4D Point4D::operator--() {
    *this = *this - 1;
    return *this;
}

//postfix decrement operator overload
Point4D Point4D::operator--(int) {
    Point4D temp = *this;
    *this = --*this;
    return temp;
}

//equals to relational operator overload
bool Point4D::operator==(const Point4D &p1) const {
    Point4D temp;
    temp.point[0] = this->point[0] - p1.point[0];
    temp.point[1] = this->point[1] - p1.point[1];
    temp.point[2] = this->point[2] - p1.point[2];
    temp.point[3] = this->point[3] - p1.point[3];
    return temp() <= tolerance;
}

//not equals relational operator to overload
bool Point4D::operator!=(const Point4D &p1) const {
    return !(*this == p1);
}

//less than relational operator overload
bool Point4D::operator<(const Point4D &p1) const {
    return ((*this != p1) && this->operator()() < p1());
}

//greater than relational operator overload
bool Point4D::operator>(const Point4D &p1) const {
    return (p1 < *this);
}

//less than or equal to relational operator overload
bool Point4D::operator<=(const Point4D &p1) const {
    return !(*this > p1);
}

//greater than or equal to relational operator overload
bool Point4D::operator>=(const Point4D &p1) const {
    return !(*this < p1);
}

//subscript operator overload
double &Point4D::operator[](int index) {
    if (index < 1 || index > 4) {
        throw std::out_of_range("index out of bounds");
    }
    return (this->point[--index]);
}

//absolute value function: () operator overload.
double Point4D::operator()() const {
    return this->absValue();
}

//insertion operator << overload
std::ostream &operator<<(std::ostream &sout, const Point4D &p1) {
    sout << p1.toString();
    return sout;
}

//extraction operator >> overload
std::istream &operator>>(std::istream &is, Point4D &p1) {
    is >> p1.point[0] >> p1.point[1] >> p1.point[2] >> p1.point[3];
    return is;
}

//assignment operator overload
Point4D &Point4D::operator=(const Point4D &) = default;

//absolute value function
double Point4D::absValue() const {
    double absvalue = std::abs(this->point[0]) + std::abs(this->point[1])+ std::abs(this->point[2]) + std::abs(this->point[3]);
    return absvalue;
}

//inverse function
Point4D Point4D::inverse() const {
    Point4D temp;
    double beta = this->point[0] * this->point[2] - this->point[1] * this->point[3];
    if (std::abs(beta) < getTolerance())
    {
        throw std::overflow_error("Encountered division by zero while inverting a Point4D");
    }
    beta = 1 / beta;
    temp.point[0] = this->point[2] * beta;
    temp.point[1] = -this->point[1] * beta;
    temp.point[2] = this->point[0] * beta;
    temp.point[3] = -this->point[3] * beta;
    return temp;
}

//Point4D string representation
std::string Point4D::toString() const {

    stringstream temp;
    temp << "[" << point[0] << "," << point[1] << "," << point[2] << "," << point[3] << "]";
    return temp.str();
}

//destructor
Point4D::~Point4D() = default;
