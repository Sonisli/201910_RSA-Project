#include <iostream>
#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"

ReallyLongInt extendedEuclid(const ReallyLongInt& a, const ReallyLongInt& b, ReallyLongInt* x, ReallyLongInt* y)
{
  if ((b.toString()) == "0") {
    ReallyLongInt one(1);
    ReallyLongInt zero(0);
    *x = one;
    *y = zero; 
    return a;
  }
  else {
    ReallyLongInt newNum = extendedEuclid(b, a % b, x, y);
    ReallyLongInt oldX = *x;
    *x = *y;
    *y = oldX - *y * (a / b);
    return newNum;
  }
}
