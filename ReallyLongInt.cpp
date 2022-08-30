#include <iostream>
#include <math.h>
#include <string>
#include "ReallyLongInt.hpp"


ReallyLongInt::ReallyLongInt()
{
  size = 1;
  digits = new vector<bool>(size);
  (*digits)[0] = false;
  isNeg = false;
}

ReallyLongInt::ReallyLongInt(long long num)
{
  size = 0;
  
  if (num >= 0) {isNeg = false;}
  else {isNeg = true; num /= -1;}

  int length;
  if (num == 0) {
    length = 1;
    digits = new vector<bool>(length);
    (*digits)[size] = false;
    size++;
  }
  else {
    length = log2(num)+1;
    digits = new vector<bool>(length);
    while (num != 1){
      int current_digit = num % 2;
      num /= 2;

      if (current_digit == 0) {(*digits)[size] = false;}
      else {(*digits)[size] = true;}
      size++;
    }
    (*digits)[size] = true;
    size++;
  }
}

ReallyLongInt:: ReallyLongInt(const string& numStr)
{
  long long num = stoll(numStr);
  size = 0;
  
  if (num >= 0) {isNeg = false;}
  else {isNeg = true; num /= -1;}

  int length;
  if (num == 0) {
    length = 1;
    digits = new vector<bool>(length);
    (*digits)[size] = false;
    size++;
  }
  else {
    length = log2(num)+1;
    digits = new vector<bool>(length);
    while (num != 1){
      int current_digit = num % 2;
      num /= 2;

      if (current_digit == 0) {(*digits)[size] = false;}
      else {(*digits)[size] = true;}
      size++;
    }
    (*digits)[size] = true;
    size++;
  }
}

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other)
{
  size = other.size;
  isNeg = other.isNeg;
  digits = new vector<bool>(size);
  for (unsigned int i = 0; i < size; i++){
    (*digits)[i] = (*(other.digits))[i];
  }
}
 
ReallyLongInt::~ReallyLongInt()
{
  delete digits;
}

string ReallyLongInt::toString() const
{
  string RLI;
  long long num = 0;
  if (isNeg == true) {RLI += "-";}
  long long  power = 1;  
  for (unsigned i = 0; i < size; i++) {
    num += (*digits)[i] * power;
    power *= 2;
  }
  RLI += to_string(num);
  return RLI;
}

string ReallyLongInt::toStringBinary() const
{
  string RLI;
  if (isNeg == true) {RLI += "-";}
  for (unsigned i = size; i > 0; i--) {
    RLI += to_string((*digits)[i-1]);
  }
  return RLI;
}

bool ReallyLongInt::equal(const ReallyLongInt& other) const
{
  if(size != other.size) {return false;}
  else if(isNeg != other.isNeg) {return false;}
  for (unsigned int i = 0; i < size; i++){
      (*digits)[i] = (*(other.digits))[i];
  }
  return true;
}

bool ReallyLongInt::absGreater(const ReallyLongInt& other) const
{
  if (size > other.size) {return true;}
  else if (size < other.size) {return false;}
  for (unsigned int i = size; i > 0; i--){
    if ((*digits)[i - 1] > (*(other.digits))[i - 1]) {return true;}
    else if ((*digits)[i - 1] < (*(other.digits))[i - 1]) {return false;}
  } // can reduce to one return here, but this way is more catious.
  return false;
}

bool ReallyLongInt::greater(const ReallyLongInt& other) const
{
  if (isNeg == true && other.isNeg == false) {return false;}
  else if (isNeg == false && other.isNeg == true) {return true;}
  else if (isNeg == false && other.isNeg == false){
    if (size > other.size) {return true;}
    else if (size < other.size) {return false;}
    for (unsigned int i = size; i > 0; i--){
      if ((*digits)[i - 1] > (*(other.digits))[i - 1]) {return true;}
      else if ((*digits)[i - 1] < (*(other.digits))[i - 1]) {return false;}
    }
    return false;
  }
  else {
    if (size > other.size) {return false;}
    else if (size < other.size) {return true;}
    for (unsigned int i = size; i > 0; i--){
      if ((*digits)[i - 1] > (*(other.digits))[i - 1]) {return false;}
      else if ((*digits)[i - 1] < (*(other.digits))[i - 1]) {return true;}
    }
    return false;
  }
}

void ReallyLongInt::removeLeadingZeros(void)
{
  unsigned int idx = size - 1;
  while ((*digits)[idx] != 1){
    size--;
    idx--;
  }
  vector<bool> *newDigits = new vector<bool>(size);
  for (unsigned int i = 0; i < size; i++){
    (*newDigits)[i] = (*digits)[i];
  }
  digits = newDigits;
}

ReallyLongInt& ReallyLongInt::operator=(const ReallyLongInt& other)
{
  swap(other);
  return *this;
}

void ReallyLongInt::swap(ReallyLongInt other)
{
  vector<bool> *thisDigits = digits;   
  unsigned int thisSize = size;      
  bool thisIsNeg = isNeg;

  digits = other.digits;
  size = other.size;
  isNeg = other.isNeg;

  other.digits = thisDigits;
  other.size = thisSize;
  other.isNeg = thisIsNeg;
}

ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const
{
  long long newNum = 0;
  unsigned int newSize;
  if (size >= other.size) {newSize = size + 1;} 
  else {newSize = other.size + 1;}
  unsigned int upgradeValue = 0;
  long long power = 1;
  for (unsigned int i = 0; i < newSize; i++) {
    int newDigit = (*digits)[i] + (*(other.digits))[i] + upgradeValue;
    if (newDigit / 2 == 1) {upgradeValue = 1;}
    else {upgradeValue = 0;} 
    newDigit %= 2;
    newNum += newDigit * power;
    power *= 2;
  }
  return ReallyLongInt(newNum);
}

ReallyLongInt ReallyLongInt::add(const ReallyLongInt& other) const
{
  ReallyLongInt newNum;
  if (isNeg == true) {
    if (other.isNeg == true) {newNum = this->absAdd(other);}
    else {newNum = this->absSub(other);}
    newNum.flipSign();
  }
  else {
    if (other.isNeg == true) {newNum = this->absSub(other);}
    else {newNum = this->absAdd(other);}
  }
  return newNum;
}

ReallyLongInt ReallyLongInt::absSub(const ReallyLongInt& other) const
{
  // implement absGreater
  bool thisIsGreater = this->absGreater(other);

  long long newNum = 0;
  unsigned int borrowValue = 0;
  long long power = 1;
  if (thisIsGreater == true) {
    for (unsigned int i = 0; i < size; i++) {
      int newDigit = (*digits)[i] - (*(other.digits))[i] - borrowValue;
      if (newDigit < 0) {borrowValue = 1;}
      else {borrowValue = 0;} 
      newDigit %= 2;
      if (newDigit < 0) {newDigit *= -1;}
      newNum += newDigit * power;
      power *= 2;
    }
  }
  else {
    for (unsigned int i = 0; i < other.size; i++) {
      int newDigit = (*(other.digits))[i] - (*digits)[i] - borrowValue;
      if (newDigit < 0) {borrowValue = 1;}
      else {borrowValue = 0;} 
      newDigit %= 2;
      if (newDigit < 0) {newDigit *= -1;}
      newNum += newDigit * power;
      power *= 2;
    }
    newNum *= -1;
  }
  return ReallyLongInt(newNum);
}

ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const
{
  ReallyLongInt newNum;
  if (isNeg == true) {
    if (other.isNeg == true) {newNum = this->absSub(other);}
    else {newNum = this->absAdd(other);}
    newNum.flipSign();

  }
  else {
    if (other.isNeg == true) {newNum = this->absAdd(other);}
    else {newNum = this->absSub(other);}
  }
  return newNum;
}

void ReallyLongInt::flipSign()
{
  if (size == 1 && (*digits)[0] == 0) {isNeg = false;}
  else if (isNeg == false) {isNeg = true;}
  else if (isNeg == true) {isNeg = false;}
  else {cout << "flipSign failed" << endl;}
}

ReallyLongInt ReallyLongInt::operator-() const
{
  ReallyLongInt newNum = ReallyLongInt(*this);
  newNum.flipSign();
  return newNum;
}


ReallyLongInt operator+ (const ReallyLongInt& x, const ReallyLongInt& y)
{
  ReallyLongInt newNum = x.add(y);
  return newNum;
}

ReallyLongInt operator- (const ReallyLongInt& x, const ReallyLongInt& y)
{
  ReallyLongInt newNum = x.sub(y);
  return newNum;
}

ReallyLongInt ReallyLongInt::absMult(const ReallyLongInt& other) const
{
  unsigned int maxSize = size + other.size;
  unsigned int tempArray[maxSize] = {};
  long long newNum = 0;
  long long power = 1;
  unsigned int digitNum = 0;
  
  for (unsigned int i = 0; i < other.size; i++) {
    unsigned int upgradeValue = 0;
    for (unsigned int j = 0; j < size; j++) {
      tempArray[i+j] += (*digits)[j] * (*(other.digits))[i] + upgradeValue;
      upgradeValue = tempArray[i+j] / 2;
      tempArray[i+j] %= 2;
      if (i == other.size-1 || j == 0) {
	newNum += tempArray[digitNum] * power;
	digitNum ++;
	power *= 2;
      }
    }
    tempArray[i+size] = upgradeValue;
  }
  newNum += tempArray[digitNum] * power;
  return ReallyLongInt(newNum);
}

ReallyLongInt ReallyLongInt::mult(const ReallyLongInt& other) const
{
  ReallyLongInt newNum = this->absMult(other);
  if (isNeg != other.isNeg) {newNum.flipSign();}
  return newNum;
}

ReallyLongInt operator* (const ReallyLongInt& x, const ReallyLongInt& y)
{
  ReallyLongInt newNum = x.mult(y);
  return newNum;
}

void ReallyLongInt::absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const
{
  long long q = 0;
  long long r = 0;

  if (other.size == 1) {
    if ((*(other.digits))[0] == 1) {
      // implement from string, get the numerical form of this
      long long  power = 1;  
      for (unsigned i = 0; i < size; i++) {
        q += (*digits)[i] * power;
	power *= 2;
      }
      ReallyLongInt temp_q(q);
      ReallyLongInt temp_r(r);
      quotient = temp_q;
      remainder = temp_r;
    }
    else if ((*(other.digits))[0] == 0) {cout << "divisor is zero" << endl;}
    else {cout << "divisor error" << endl;}
  }

  else if (other.size > size) {
    long long  power = 1;
    for (unsigned i = 0; i < size; i++) {
      r += (*digits)[i] * power;
      power *= 2;
    }
    ReallyLongInt temp_q(q);
    ReallyLongInt temp_r(r);
    quotient = temp_q;
    remainder = temp_r;
  }

  else {
    ReallyLongInt two(2);
    ReallyLongInt temp_r(r);
    for (unsigned int i = size; i > 0; i--) {
      long long num = (*digits)[i-1];
      ReallyLongInt currentDigit(num);
      temp_r = temp_r.absMult(two);
      temp_r = temp_r.absAdd(currentDigit);
      long long d = 0;
      if (other.absGreater(temp_r) == 0) {
	temp_r = temp_r.absSub(other);
	d++;
      }
      q *= 2;
      q += d;
    }
    ReallyLongInt temp_q(q);
    quotient = temp_q;
    remainder = temp_r; 
  }
}

void ReallyLongInt::div(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const
{
  this->absDiv(other, quotient, remainder);
  if (isNeg == true && other.isNeg == true) {
    remainder.flipSign();
  }
  else if (isNeg == true && other.isNeg == false){
    quotient.flipSign();
    remainder.flipSign();
  }
  else if (isNeg == false && other.isNeg == true) {
    quotient.flipSign();
  }
}

ReallyLongInt operator/ (const ReallyLongInt& x, const ReallyLongInt& y)
{
  ReallyLongInt remainder;
  ReallyLongInt quotient;
  x.div(y, quotient, remainder);
  return quotient;
}

ReallyLongInt operator% (const ReallyLongInt& x, const ReallyLongInt& y)
{
  ReallyLongInt remainder;
  ReallyLongInt quotient;
  x.div(y, quotient, remainder);
  return remainder;
}

bool ReallyLongInt::isOdd() const
{
  if ((*digits)[0] == 1) {return true;}
  else {return false;}
}

ReallyLongInt ReallyLongInt::exp(const ReallyLongInt e)
{
  // case when base is 0 or 1
  if (this->size == 1) {return *this;}
  else {
    if (e.size == 0) {
      cout << "ERROR: the size of e is 0" << endl;
      ReallyLongInt zero(0);
      return zero;
    }
    if (e.size == 1) {
      if ((*(e.digits))[0] == 0) {
	ReallyLongInt one(1);
	return one;
      }
    }
    ReallyLongInt two(2);
    ReallyLongInt newE = e/two;
    if (e.isOdd() == true) {return *this * exp(newE) * exp(newE);}
    else {return exp(newE) * exp(newE);}
  }
}

bool ReallyLongInt::isPrime()
{
  if (this->size == 1) {return false;}
  if ((*digits)[0] == 0) {
    if (this->size == 2) {
      return true;
    }
    return false;
  }
  ReallyLongInt divisor(2);
  ReallyLongInt one(1);
  while (this->absGreater(divisor)) {
    ReallyLongInt num = *this % divisor;
    if (num.size == 1 && (*(num.digits))[0] == 0) {return false;}
    divisor = divisor + one;
  }
  return true;
}

