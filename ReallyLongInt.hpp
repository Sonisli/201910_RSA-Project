#ifndef RLI_HPP
#define RLI_HPP

#include <string>
#include <vector>
using namespace std;

class ReallyLongInt
{
public:
  ReallyLongInt();                           // represents the value 0
  ReallyLongInt(long long num);              // sets based on num
  ReallyLongInt(const string& numStr);
  //takes in a string representation and sets the private member variables.
  ReallyLongInt(const ReallyLongInt& other); // this is needed to make copies.
  ~ReallyLongInt();
  
  string toString() const;
  string toStringBinary() const;

  bool equal(const ReallyLongInt& other) const;
  bool greater(const ReallyLongInt& other) const;

  void removeLeadingZeros(void);
  ReallyLongInt & operator=(const ReallyLongInt& other);
  
  ReallyLongInt absAdd(const ReallyLongInt& other) const;
  ReallyLongInt add(const ReallyLongInt& other) const;
  ReallyLongInt absSub(const ReallyLongInt& other) const;
  ReallyLongInt sub(const ReallyLongInt& other) const;
  ReallyLongInt operator-() const;

  ReallyLongInt absMult(const ReallyLongInt& other) const;
  ReallyLongInt mult(const ReallyLongInt& other) const;
  void absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const;
  void div(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const;
  
  ReallyLongInt exp(const ReallyLongInt e);
  bool isPrime();
    
private:
  vector<bool> *digits;   // the binary digits
  unsigned int size;      // the number of digits
  bool isNeg;             // the sign of the number (true if negative)
  bool absGreater(const ReallyLongInt& other) const;
  void swap(ReallyLongInt other);
  void flipSign();
  bool isOdd() const;
};

ReallyLongInt operator+ (const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator- (const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator* (const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator/ (const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator% (const ReallyLongInt& x, const ReallyLongInt& y);
#endif
