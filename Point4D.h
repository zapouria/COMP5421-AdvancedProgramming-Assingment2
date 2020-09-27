//
// Created by Pouria on 2020-05-31.
//

#ifndef ASSIGNMENT2_POINT4D_H
#define ASSIGNMENT2_POINT4D_H

#include<array>

using namespace std;

class Point4D {

private:
    array<double, 4> point; //an array point consist of 4 doubles
    static double tolerance; //for equality checking
public:
    static void setTolerance(double tol); //function to set tolerance
    static double getTolerance(); //function to get the tolerance
    Point4D(double = 0, double = 0, double = 0, double = 0); //constructor with 4 parameters
    Point4D(const Point4D &); //copy constructor
    Point4D inverse() const; //inverse function
    double absValue() const; //absolute value function
    std::string toString() const; //Point4D string representation
    Point4D operator+(); //unary plus operator overload
    Point4D operator+=(const Point4D &); //addition compound operator overload
    Point4D operator+=(double); //addition compound operator overload
    Point4D operator-();//unary minus operator overload
    Point4D operator-=(const Point4D &); //subtraction compound operator overload
    Point4D operator-=(double); //subtraction compound operator overload
    Point4D operator*=(const Point4D &); //multiplication compound operator overload
    Point4D operator*=(double); //multiplication compound operator overload
    Point4D operator/=(const Point4D &); //division compound operator overload
    Point4D operator/=(double); //division compound operator overload
    Point4D operator++(); //prefix increment operator overload
    Point4D operator++(int); //postfix increment operator overload
    Point4D operator--(); //prefix decrement operator overload
    Point4D operator--(int); //postfix decrement operator overload
    bool operator==(const Point4D &) const; //equals to relational operator overload
    bool operator!=(const Point4D &) const; //not equals relational operator to overload
    bool operator<(const Point4D &) const; //less than relational operator overload
    bool operator>(const Point4D &) const; //greater than relational operator overload
    bool operator<=(const Point4D &) const; //less than or equal to relational operator overload
    bool operator>=(const Point4D &) const; //greater than or equal to relational operator overload
    double &operator[](int index); //subscript operator overload
    Point4D &operator=(const Point4D &); //assignment operator overload
    double operator()() const; //absolute value function: () operator overload.
    friend std::istream &operator>>(std::istream &is, Point4D &); //extraction >> operator overload
    virtual ~Point4D(); //destructor
};
std::ostream &operator<<(std::ostream &, const Point4D &); //insertion operator << overload
std::istream &operator>>(std::istream &is, Point4D &); //extraction operator >> overload
Point4D operator+(const Point4D &, const Point4D &); //binary addition operator overload
Point4D operator+(double, const Point4D &); //scalar addition operator overload
Point4D operator+(const Point4D &, double); //scalar addition operator overload
Point4D operator-(const Point4D &, const Point4D &); //binary subtraction operator overload
Point4D operator-(double, const Point4D &); //scalar subtraction operator overload
Point4D operator-(const Point4D &, double); //scalar subtraction operator overload
Point4D operator*(const Point4D &, const Point4D &); //binary multiplication operator overload
Point4D operator*(double, const Point4D &); //scalar multiplication operator overload
Point4D operator*(const Point4D &, double); //scalar multiplication operator overload
Point4D operator/(const Point4D &, const Point4D &); //binary division operator overload
Point4D operator/(double, const Point4D &); //scalar division operator overload
Point4D operator/(const Point4D &, double); //scalar division operator overload

#endif //ASSIGNMENT2_POINT4D_H
