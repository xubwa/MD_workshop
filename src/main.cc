#include <src/cubic.h>
#include <src/particle.h>
#include <iostream>
#include <memory>

using namespace std;
using namespace md;

int main(int argc, char** argv) {
  // Default particle density and number of atoms.
  double density = 0.8;
  int natom = 1000;

  if (argc == 1) {
    cout << "No atom number given, use default value 1000" << endl;
  }
  else if (argc == 2) {
    natom = atoi(argv[1]);
  }
  else if (argc == 3) {
    natom   = atoi(argv[1]);
    density = atof(argv[2]);
  }
  else {
    natom   = atoi(argv[1]);
    density = atof(argv[2]);
    cout << "Warning: too much arguments given, only the first two are taken.";
  }

  shared_ptr<CubicBox> box = make_shared<CubicBox>(natom, density);
  box -> print_coordinate();
 
  return 0;
}