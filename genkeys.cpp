#include <iostream>
#include <fstream>
#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"

using namespace std;

int main(int argc, char** argv){
  if (argc != 5) {
    cout << "ERROR: unsufficient input" << endl;
    return 1;
  }
  ReallyLongInt p(atol(argv[1]));
  ReallyLongInt q(atol(argv[2]));
  if (p.isPrime() != true) {
    cout << "ERROR: p is not a prime number" << endl;
    return 1;
  }
  if (q.isPrime() != true) {
    cout << "ERROR: q is not a prime number" << endl;
    return 1;
  }
  ofstream publicKey(argv[3]);
  ofstream privateKey(argv[4]);
  ReallyLongInt zero(0);
  ReallyLongInt one(1);
  ReallyLongInt n = p * q;
  ReallyLongInt t = (p - one) * (q - one);
  ReallyLongInt e(2);
  ReallyLongInt d;
  bool checkPoint = true;
  
  while (checkPoint) {
    if ((e.greater(one)) != true || (t.greater(e)) != true) { 
      cout << "ERROR: e out of range" << endl;
      return 1;
    }
    ReallyLongInt zero1(0);
    ReallyLongInt zero2(0);
    ReallyLongInt* x = &zero1;
    ReallyLongInt* y = &zero2;
    ReallyLongInt gcd = extendedEuclid(t, e, x, y);
    if ((gcd.toString()) == "1") {
      checkPoint = false;
      d = *x;
      if (zero.greater(d)){
	d = d + t;
      }
    }
    else {e = e + one;}	
  }
  publicKey << (e.toString()) << " " << (n.toString()) << endl;
  privateKey << (d.toString()) << " " << (n.toString()) << endl;
  return 0;
}
