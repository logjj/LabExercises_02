// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int Molecules, int Deonminator)
{
    if(Deonminator <= 0)//分母小于等于0
        Deonminator = 1;
        numerator = Molecules;//分子
    denominator = Deonminator;
}
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */

// overloaded + operator
RationalNumber RationalNumber::operator + (const RationalNumber &another)const
{
    RationalNumber temp;
    temp.numerator = numerator * another.denominator + denominator * another.numerator;
    temp.denominator = denominator *another.denominator;
    temp.reduction();
    return temp;

}
/* Write definition for overloaded operator + */

// overloaded - operator
RationalNumber RationalNumber::operator - (const RationalNumber &another) const
{
    RationalNumber temp;
    temp.numerator = numerator * another.denominator - denominator * another.numerator;
    temp.denominator = another.denominator * denominator;
    temp.reduction();
     return temp;
}
/* Write definition for overloaded operator - */

// overloaded * operator
RationalNumber RationalNumber::operator * (const RationalNumber &another) const
{
    RationalNumber temp;
    temp.numerator = numerator * another.numerator;
    temp.denominator = denominator * another.denominator;
    temp.reduction();
     return temp;
}
/* Write definition for overloaded operator * */

// overloaded / operator
RationalNumber RationalNumber::operator / (const RationalNumber &another) const
{
    RationalNumber temp;
    if(another.numerator!= 0)
    {
    temp.numerator = numerator * another.denominator;
    temp.denominator = denominator * another.numerator;
    temp.reduction();
    }
    else
        cout << another.numerator;
        return temp;
}

/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */

// overloaded > operator
bool RationalNumber::operator > (const RationalNumber &another) const
{

    if(numerator * another.denominator > denominator * another.numerator)
    {
        return true;
    }
    else
        return false;
}
/* Write definition for operator > */

// overloaded < operator
bool RationalNumber::operator < (const RationalNumber &another) const
{
    if(numerator * another.denominator < denominator * another.numerator)
    {
        return true;
    }
    else
        return false;
}
/* Write definition for operator < */

// overloaded >= operator
bool RationalNumber::operator >= (const RationalNumber &another) const
{
    if(numerator * another.denominator >= denominator * another.numerator)
    {
        return true;
    }
    else
        return false;
}
/* Write definition for operator >= */

// overloaded <= operator
bool RationalNumber::operator <= (const RationalNumber &another) const
{
    if(numerator * another.denominator <= denominator * another.numerator)
    {
        return true;
    }
    else
        return false;
}
/* Write definition for operator <= */

// overloaded == operator
bool RationalNumber::operator == (const RationalNumber &another) const
{
    if(numerator * another.denominator == denominator * another.numerator)
    {
        return true;
    }
    else
        return false;
}
/* Write definition for operator == */

// overloaded != operator
bool RationalNumber::operator != (const RationalNumber &another) const
{
    if(numerator * another.denominator != denominator * another.numerator)
    {
        return true;
    }
    else
        return false;
}
/* Write definition for operator != */

// function printRational definition
void RationalNumber::printRational() const
{
   if ( numerator == 0 ) // print fraction as zero
      cout << numerator;
   else if ( denominator == 1 ) // print fraction as integer
      cout << numerator;
   else
      cout << numerator << '/' << denominator;
} // end function printRational

// function reduction definition
void RationalNumber::reduction()
{
   int largest, gcd = 1;  // greatest common divisor;

   largest = ( numerator > denominator ) ? numerator: denominator;

   for ( int loop = 2; loop <= largest; loop++ )
       if ( numerator % loop == 0 && denominator % loop == 0 )
          gcd = loop;

   numerator /= gcd;
   denominator /= gcd;
} // end function reduction


/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
