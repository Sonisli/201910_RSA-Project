#include <iostream>
#include <fstream>
#include <string>
#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"

using namespace std;

int main(int argc, char** argv){
  ifstream in(argv[1]);
  int d;
  int n;
  in >> d;
  in >> n;
  ReallyLongInt RLI_d(d);
  ReallyLongInt RLI_n(n);
  
  ofstream fout(argv[3]);
  ifstream fin(argv[2]);
  char y;
  while (!fin.eof()){
    fin >> y;
    int int_y = (int)y;
    ReallyLongInt RLI_y(int_y);
    ReallyLongInt RLI_x = (RLI_y.exp(RLI_d)) % RLI_n;
    int x = stoi(RLI_x.toString());
    fout << (char)x;
  }
  return 0;
}
