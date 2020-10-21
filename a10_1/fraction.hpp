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

 Fraction();
  post: The calling object has been created and initialized to 0/1.

 Fraction(int inNum, int inDenom);
  post: The calling object has been created and initialized so that the numerator is inNum,
        and the denominator is inDenom.
 
 Fraction addedTo(Fraction &frac);
  post: Returns the Fraction determined by adding the calling object with the paramenter "frac".
 
 Fraction subtract(Fraction &frac);
  post: Returns the Fraction determined by subtracting the parameter "frac" from the
        calling object.
 
 Fraction multipliedBy(Fraction &frac);
  post: Returns the Fraction determined by multiplying the calling object by the parameter
        "frac".
 
 Fraction dividedBy(Fraction &frac);
  post: Returns the Fraction determined by dividing the calling object by the parameter
        "frac".
 
 friend bool operator<(const Fraction &left, const Fraction &right);
  post: Returns true if the calling object (or integer) by the parameter "left" is less
        than the calling object (or integer) by the parameter "right". Otherwise, returns
        false.
 
 friend bool operator<=(const Fraction &left, const Fraction &right);
  post: Returns true if the calling object (or integer) by the parameter "left" is less
        than or equal to the calling object (or integer) by the parameter "right".
        Otherwise, returns false.
 
 friend bool operator>(const Fraction &left, const Fraction &right);
  post: Returns true if the calling object (or integer) by the parameter "left" is greater
        than the calling object (or integer) by the parameter "right". Otherwise, returns
        false.
 
 friend bool operator>=(const Fraction &left, const Fraction &right);
  post: Returns true if the calling object (or integer) by the parameter "left" is greater
        than or equal to the calling object (or integer) by the parameter "right".
        Otherwise, returns false.
 
 friend bool operator==(const Fraction &left, const Fraction &right);
  post: Returns true if the calling object (or integer) by the parameter "left" is equal to
        the calling object (or integer) by the parameter "right". Otherwise, returns false.
 
 friend bool operator!=(const Fraction &left, const Fraction &right);
  post: Returns true if the calling object (or integer) by the parameter "left" is not
        equal to the calling object (or integer) by the parameter "right". Otherwise,
        returns false.

 friend std::ostream &operator<<(std::ostream &out, const Fraction &right);
  post: The calling object has been printed to the console window in the formats of W,
        W+N/D or N/D.
         
*/

class Fraction
{
public:
    Fraction(int inNum = 0, int inDenom = 1);
    Fraction addedTo(const Fraction &frac) const;
    Fraction subtract(const Fraction &frac) const;
    Fraction multipliedBy(const Fraction &frac) const;
    Fraction dividedBy(const Fraction &frac) const;
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
