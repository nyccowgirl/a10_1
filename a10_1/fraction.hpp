/*
 Trang Hoang
 CS110B
 Dave Harden
 11/3/20
 fraction.hpp
 
 Assignment 10.1
 
 Modify program from Assignment 9.1 to handle negative, improper (larger numerator than
 denominator), or whole numbers (denominator of 1), using overload operators and friend
 functions.
 
 Created by nyccowgirl on 11/3/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#ifndef fraction_hpp
#define fraction_hpp

#include <iostream>
//#include <stdio.h>

namespace cs_fraction {

/*

 The Fraction class can be used to create objects that store a fraction, including numerator
 and denominator. The following functions are available:

 Fraction(int inNum, int inDenom);
  post: The calling object has been created and initialized so that the numerator is the
        inNum parameter (with default of 0), and the denominator is the inDenom
        parameter (with default of 1). If inDenom is 0, program is aborted.
 
 friend Fraction operator+(const Fraction &left, const Fraction &right);
  post: Returns the Fraction determined by adding the calling object (or integer) of the
        parameter "left" with the calling object (or integer) of the paramenter "right".
 
 friend Fraction operator-(const Fraction &left, const Fraction &right);
  post: Returns the Fraction determined by subtracting the calling object (or integer) of
        the parameter "right" from the calling object (or integer) of the parameter "left".
 
 friend Fraction operator*(const Fraction &left, const Fraction &right);
  post: Returns the Fraction determined by multiplying the calling object (or integer) of
        the parameter "left" by the calling object (or integer) of the parameter "right".
 
 friend Fraction operator/(const Fraction &left, const Fraction &right);
  post: Returns the Fraction determined by dividing the calling object (or integer) of the
        parameter "left" by the calling object (or integer) of the parameter "right".
 
 friend bool operator<(const Fraction &left, const Fraction &right);
  post: Returns true if the calling object (or integer) of the parameter "left" is less
        than the calling object (or integer) of the parameter "right". Otherwise, returns
        false.
 
 friend bool operator<=(const Fraction &left, const Fraction &right);
  post: Returns true if the calling object (or integer) of the parameter "left" is less
        than or equal to the calling object (or integer) of the parameter "right".
        Otherwise, returns false.
 
 friend bool operator>(const Fraction &left, const Fraction &right);
  post: Returns true if the calling object (or integer) of the parameter "left" is greater
        than the calling object (or integer) of the parameter "right". Otherwise, returns
        false.
 
 friend bool operator>=(const Fraction &left, const Fraction &right);
  post: Returns true if the calling object (or integer) of the parameter "left" is greater
        than or equal to the calling object (or integer) of the parameter "right".
        Otherwise, returns false.
 
 friend bool operator==(const Fraction &left, const Fraction &right);
  post: Returns true if the calling object (or integer) of the parameter "left" is equal to
        the calling object (or integer) of the parameter "right". Otherwise, returns false.
 
 friend bool operator!=(const Fraction &left, const Fraction &right);
  post: Returns true if the calling object (or integer) of the parameter "left" is not
        equal to the calling object (or integer) of the parameter "right". Otherwise,
        returns false.

 friend std::ostream &operator<<(std::ostream &out, const Fraction &right);
  post: The calling object has been printed to the console window in the formats of W,
        W+N/D or N/D.
         
*/

class Fraction
{
public:
    Fraction(int inNum = 0, int inDenom = 1);
    friend Fraction operator+(const Fraction &left, const Fraction &right);
//    Fraction addedTo(const Fraction &frac) const;
    friend Fraction operator-(const Fraction &left, const Fraction &right);
//    Fraction subtract(const Fraction &frac) const;
    friend Fraction operator*(const Fraction &left, const Fraction &right);
//    Fraction multipliedBy(const Fraction &frac) const;
    friend Fraction operator/(const Fraction &left, const Fraction &right);
//    Fraction dividedBy(const Fraction &frac) const;
    friend bool operator<(const Fraction &left, const Fraction &right);
    friend bool operator<=(const Fraction &left, const Fraction &right);
    friend bool operator>(const Fraction &left, const Fraction &right);
    friend bool operator>=(const Fraction &left, const Fraction &right);
    friend bool operator==(const Fraction &left, const Fraction &right);
//    bool isEqualTo(const Fraction &frac) const;
    friend bool operator!=(const Fraction &left, const Fraction &right);
//    void print() const;
    friend std::ostream &operator<<(std::ostream &out, const Fraction &right);

private:
    int numerator;
    int denominator;
    void simplify();
};
}

#endif /* fraction_hpp */


/*
 
 output
 
 */
