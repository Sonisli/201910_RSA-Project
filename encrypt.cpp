#include <iostream>
#include <fstream>
#include <string>
#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"

using namespace std;

int main(int argc, char** argv){
  ifstream in(argv[1]);
  int e;
  int n;
  in >> e;
  in >> n;
  ReallyLongInt RLI_e(e);
  ReallyLongInt RLI_n(n);

  ifstream fin(argv[2]);
  ofstream fout(argv[3]);
  char x;
  while (fin.get(x)){
    int int_x = (int)x;
    ReallyLongInt RLI_x(int_x);
    ReallyLongInt RLI_y = (RLI_x.exp(RLI_e)) % RLI_n;
    int y = stoi(RLI_y.toString());
    fout << (char)y << endl;
  }
  return 0;
}
