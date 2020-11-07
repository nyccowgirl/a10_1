/*
 Trang Hoang
 CS110B
 Dave Harden
 11/3/20
 fraction.cpp
 
 Assignment 10.1
 
 Modify program from Assignment 9.1 to handle negative, improper (larger numerator than
 denominator), or whole numbers (denominator of 1), using overload operators and friend
 functions.
 
 Created by nyccowgirl on 11/3/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#include <iostream>
#include <cassert>
#include "fraction.hpp"
using namespace std;

namespace cs_fraction {

/*
 
 Class Invariant: a Fraction object has 2 int data members: numerator, which stores the
 numerator, and denominator, which stores the denominator that cannot be 0. However, no
 effort is made to prevent the client from providing an invalid fraction.
    
*/

    Fraction::Fraction(int inNum, int inDenom) {
        assert(inDenom != 0);
        numerator = inNum;
        denominator = inDenom;
        simplify();
    }






    Fraction operator+(const Fraction &left, const Fraction &right) {
        int sum;
        Fraction temp;
        
        sum = (left.numerator * right.denominator) + (right.numerator * left.denominator);
        temp = Fraction(sum, (left.denominator * right.denominator));
        temp.simplify();
        return temp;
    }






    Fraction operator-(const Fraction &left, const Fraction &right) {
        int diff;
        Fraction temp;
        
        diff = (left.numerator * right.denominator) - (right.numerator * left.denominator);
        temp = Fraction(diff, (left.denominator * right.denominator));
        temp.simplify();
        return temp;
    }






    Fraction operator*(const Fraction &left, const Fraction &right) {
        Fraction temp;
        
        temp = Fraction((left.numerator * right.numerator),
                        (left.denominator * right.denominator));
        temp.simplify();
        return temp;
    }






    Fraction operator/(const Fraction &left, const Fraction &right) {
        Fraction temp;
        
        temp = Fraction((left.numerator * right.denominator),
                        (left.denominator * right.numerator));
        temp.simplify();
        return temp;
    }






    bool operator<(const Fraction &left, const Fraction &right) {
        return ((left.numerator * right.denominator) < (left.denominator *
                                                        right.numerator));
    }






    bool operator<=(const Fraction &left, const Fraction &right) {
        return ((left.numerator * right.denominator) <= (left.denominator *
                                                         right.numerator));
    }






    bool operator>(const Fraction &left, const Fraction &right) {
        return ((left.numerator * right.denominator) > (left.denominator *
                                                        right.numerator));
    }





    bool operator>=(const Fraction &left, const Fraction &right) {
        return ((left.numerator * right.denominator) >= (left.denominator *
                                                         right.numerator));
    }






    bool operator==(const Fraction &left, const Fraction &right) {
        return ((left.numerator * right.denominator) == (left.denominator *
                                                         right.numerator));
    }






    bool operator!=(const Fraction &left, const Fraction &right) {
        return ((left.numerator * right.denominator) != (left.denominator *
                                                         right.numerator));
    }






    Fraction Fraction::operator+=(const Fraction &right) {
        *this = *this + right;
        return *this;
    }






    Fraction Fraction::operator-=(const Fraction &right) {
        *this = *this - right;
        return *this;
    }






    Fraction Fraction::operator*=(const Fraction &right) {
        *this = *this * right;
        return *this;
    }






    Fraction Fraction::operator/=(const Fraction &right) {
        *this = *this / right;
        return *this;
    }
        





    Fraction Fraction::operator++() {
        *this += 1;
        return *this;
    }






    Fraction Fraction::operator++(int) {
        Fraction temp(*this);
        *this += 1;
        return temp;
    }






    Fraction Fraction::operator--() {
        *this -= 1;
        return *this;
    }






    Fraction Fraction::operator--(int) {
        Fraction temp(*this);
        *this -= 1;
        return temp;
    }






    istream &operator>>(istream &in, Fraction &right) {
        int temp, whole = 0, num = 0, den = 1;
        bool frac = false;
            
        do {
            in >> temp;

            if ((in.peek() == '+') || ((in.peek() == '\n') && !(frac))) {
                whole = temp;
                if (in.peek() == '+') {
                    in.ignore();
                }
            } else if (in.peek() == '/') {
                num = temp;
                frac = true;
                in.ignore();
            } else {
                den = temp;
            }

        } while (in.peek() != '\n');

        if (whole < 0) {
            right.numerator = (whole * den) - num;
        } else {
            right.numerator = (whole * den) + num;
        }
        right.denominator = den;
        right.simplify();
        return in;
    }






    ostream &operator<<(ostream &out, const Fraction &right) {
        if (right.denominator == 1) {
            out << right.numerator;
        } else if ((right.numerator < 0) && (abs(right.numerator) > right.denominator)) {
            out << "-" << (abs(right.numerator) / right.denominator) << "+";
            out << (abs(right.numerator) % right.denominator) << "/" << right.denominator;
        } else if (right.numerator > right.denominator) {
            out << (right.numerator / right.denominator) << "+";
            out << (right.numerator % right.denominator) << "/" << right.denominator;
        } else {
            out << right.numerator << "/" << right.denominator;
        }
        return out;
    }






    // This private member function reduces, and replaces numerator and denominator for
    // simplified fraction

    void Fraction::simplify() {
        int max;
        bool neg = false;
        
        // To address negative or zero fractions
        if (numerator < 0) {
            neg = !neg;
            numerator *= -1;
        } else if (numerator == 0) {
            denominator = 1;
        }
        
        if (denominator < 0) {
            neg = !neg;
            denominator *= -1;
        }
        
        // To reduce by common divisors
        if (numerator < denominator) {
            max = numerator;
        } else if (denominator < numerator) {
            max = denominator;
        } else {
            numerator = denominator = max = 1;
        }
        
        for (int i = max; i > 1; i--) {
            if ((numerator % i == 0) && (denominator % i == 0)) {
                numerator /= i;
                denominator /= i;
            }
        }
        
        // To put back as negative, if initial fraction was net negative
        if (neg) {
            numerator *= -1;
        }
    }
}
