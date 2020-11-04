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

namespace cs_fraction {

/*

 The Fraction class can be used to create objects that store a fraction, including numerator
 and denominator. The following functions are available:

 Fraction(int inNum, int inDenom);
  post: The calling object has been created and initialized so that the numerator is the
        inNum parameter (with default of 0), and the denominator is the inDenom
        parameter (with default of 1). If inDenom is 0, program is aborted.
 
 friend Fraction operator+(const Fraction &left, const Fraction &right);
  post: Returns the Fraction determined by adding the Fraction (or integer) of the
        parameter "left" with the Fraction (or integer) of the paramenter "right".
 
 friend Fraction operator-(const Fraction &left, const Fraction &right);
  post: Returns the Fraction determined by subtracting the Fraction (or integer) of
        the parameter "right" from the Fraction (or integer) of the parameter "left".
 
 friend Fraction operator*(const Fraction &left, const Fraction &right);
  post: Returns the Fraction determined by multiplying the Fraction (or integer) of
        the parameter "left" by the Fraction (or integer) of the parameter "right".
 
 friend Fraction operator/(const Fraction &left, const Fraction &right);
  post: Returns the Fraction determined by dividing the Fraction (or integer) of the
        parameter "left" by the Fraction (or integer) of the parameter "right".
 
 friend bool operator<(const Fraction &left, const Fraction &right);
  post: Returns true if the Fraction (or integer) of the parameter "left" is less
        than the Fraction (or integer) of the parameter "right". Otherwise, returns
        false.
 
 friend bool operator<=(const Fraction &left, const Fraction &right);
  post: Returns true if the Fraction (or integer) of the parameter "left" is less
        than or equal to the Fraction (or integer) of the parameter "right".
        Otherwise, returns false.
 
 friend bool operator>(const Fraction &left, const Fraction &right);
  post: Returns true if the Fraction (or integer) of the parameter "left" is greater
        than the Fraction (or integer) of the parameter "right". Otherwise, returns
        false.
 
 friend bool operator>=(const Fraction &left, const Fraction &right);
  post: Returns true if the Fraction (or integer) of the parameter "left" is greater
        than or equal to the Fraction (or integer) of the parameter "right".
        Otherwise, returns false.
 
 friend bool operator==(const Fraction &left, const Fraction &right);
  post: Returns true if the Fraction (or integer) of the parameter "left" is equal to
        the Fraction (or integer) of the parameter "right". Otherwise, returns false.
 
 friend bool operator!=(const Fraction &left, const Fraction &right);
  post: Returns true if the Fraction (or integer) of the parameter "left" is not
        equal to the Fraction (or integer) of the parameter "right". Otherwise,
        returns false.
 
 Fraction operator+=(const Fraction &right);
  post: Returns the Fraction determined by adding the calling object with the Fraction (or
        integer) of the parameter "right".
 
 Fraction operator-=(const Fraction &right);
  post: Returns the Fraction determined by subtracting the calling object with the Fraction
        (or integer) of the parameter "right".
 
 Fraction operator*=(const Fraction &right);
  post: Returns the Fraction determined by multiplying the calling object by the Fraction
        (or integer) of the parameter "right".
 
 Fraction operator/=(const Fraction &right);
  post: Returns the Fraction determined by dividing the calling object by the Fraction (or
        integer) of the parameter "right".
 
 Fraction operator++();
  post: Returns the Fraction determined by incrementing the calling object by 1
        (pre-increment operator).
 
 Fraction operator++(int);
  post: Returns the original calling object after incrementing it by 1 (post-increment
        operator).
 
 Fraction operator--();
  post: Returns the Fraction determined be decrementing the calling object by 1
        (pre-decrement operator).
 
 Fraction operator--(int);
  post: Returns the original calling object after decrementing it by 1 (post-decrement
        operator).
 
 friend std::istream &operator<<(std::istream &in, Fraction &right);
  post: Reads a line from file in formats of W, W+N/D or N/D, and converts it into a
        Fraction object.

 friend std::ostream &operator<<(std::ostream &out, const Fraction &right);
  post: The calling object has been printed to the console window in the formats of W,
        W+N/D or N/D.
         
*/

class Fraction
{
public:
    Fraction(int inNum = 0, int inDenom = 1);
    friend Fraction operator+(const Fraction &left, const Fraction &right);
    friend Fraction operator-(const Fraction &left, const Fraction &right);
    friend Fraction operator*(const Fraction &left, const Fraction &right);
    friend Fraction operator/(const Fraction &left, const Fraction &right);
    friend bool operator<(const Fraction &left, const Fraction &right);
    friend bool operator<=(const Fraction &left, const Fraction &right);
    friend bool operator>(const Fraction &left, const Fraction &right);
    friend bool operator>=(const Fraction &left, const Fraction &right);
    friend bool operator==(const Fraction &left, const Fraction &right);
    friend bool operator!=(const Fraction &left, const Fraction &right);
    Fraction operator+=(const Fraction &right);
    Fraction operator-=(const Fraction &right);
    Fraction operator*=(const Fraction &right);
    Fraction operator/=(const Fraction &right);
    Fraction operator++();
    Fraction operator++(int);
    Fraction operator--();
    Fraction operator--(int);
    friend std::istream &operator>>(std::istream &in, Fraction &right);
    friend std::ostream &operator<<(std::ostream &out, const Fraction &right);

private:
    int numerator;
    int denominator;
    void simplify();
};
}

#endif /* fraction_hpp */


/*

 ----- Testing basic Fraction creation & printing
 (Fractions should be in reduced form, and as mixed numbers.)
 Fraction [0] = 1/2
 Fraction [1] = -5/7
 Fraction [2] = 10
 Fraction [3] = -4
 Fraction [4] = 0
 Fraction [5] = 4+2/3
 Fraction [6] = 0

 ----- Now reading Fractions from file
 Read Fraction = 1/3
 Read Fraction = 1/2
 Read Fraction = 3/4
 Read Fraction = -4/5
 Read Fraction = 6
 Read Fraction = 5
 Read Fraction = -8
 Read Fraction = 1+2/5
 Read Fraction = -16+2/3
 Read Fraction = 1+1/4
 Read Fraction = 2
 Read Fraction = -4+1/4
 Read Fraction = -10+5/6

 ----- Testing relational operators between Fractions
 Comparing 1/2 to -1/2
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing -1/2 to 1/2
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing 1/2 to 1/10
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing 1/10 to 0
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing 0 to 0
     Is left < right? false
     Is left <= right? true
     Is left > right? false
     Is left >= right? true
     Does left == right? true
     Does left != right ? false

 ----- Testing relations between Fractions and integers
 Comparing -1/2 to 2
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing -3 to 1/4
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true

 ----- Testing binary arithmetic between Fractions
 1/6 + 1/3 = 1/2
 1/6 - 1/3 = -1/6
 1/6 * 1/3 = 1/18
 1/6 / 1/3 = 1/2
 1/3 + -2/3 = -1/3
 1/3 - -2/3 = 1
 1/3 * -2/3 = -2/9
 1/3 / -2/3 = -1/2
 -2/3 + 5 = 4+1/3
 -2/3 - 5 = -5+2/3
 -2/3 * 5 = -3+1/3
 -2/3 / 5 = -2/15
 5 + -1+1/3 = 3+2/3
 5 - -1+1/3 = 6+1/3
 5 * -1+1/3 = -6+2/3
 5 / -1+1/3 = -3+3/4

 ----- Testing arithmetic between Fractions and integers
 -1/2 + 4 = 3+1/2
 -1/2 - 4 = -4+1/2
 -1/2 * 4 = -2
 -1/2 / 4 = -1/8
 3 + -1/2 = 2+1/2
 3 - -1/2 = 3+1/2
 3 * -1/2 = -1+1/2
 3 / -1/2 = -6

 ----- Testing shorthand arithmetic assignment on Fractions
 1/6 += 4 = 4+1/6
 4+1/6 -= 4 = 1/6
 1/6 *= 4 = 2/3
 2/3 /= 4 = 1/6
 4 += -1/2 = 3+1/2
 3+1/2 -= -1/2 = 4
 4 *= -1/2 = -2
 -2 /= -1/2 = 4
 -1/2 += 5 = 4+1/2
 4+1/2 -= 5 = -1/2
 -1/2 *= 5 = -2+1/2
 -2+1/2 /= 5 = -1/2

 ----- Testing shorthand arithmetic assignment using integers
 -1/3 += 3 = 2+2/3
 2+2/3 -= 3 = -1/3
 -1/3 *= 3 = -1
 -1 /= 3 = -1/3

 ----- Testing increment/decrement prefix and postfix
 Now g = -1/3
 g++ = -1/3
 Now g = 2/3
 ++g = 1+2/3
 Now g = 1+2/3
 g-- = 1+2/3
 Now g = 2/3
 --g = -1/3
 Now g = -1/3
 Program ended with exit code: 0
 
 */
