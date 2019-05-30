#include "src/particle.h"
#include "src/cubic.h"
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace md;

CubicBox::CubicBox(int natom, double particle_density) : 
natom_(natom), density_(particle_density), length_(pow(natom, 1.0/3.0) + 0.5) {
  if (int(pow(length_, 3.0)) != natom) {
    // Currently assumes natom is a cubic number.
    cout << natom << length_ << endl;
    throw("Input atom number is not a cubic number"); 
  }
  coordinate_ = vector<Particle>(natom, Particle(0.0, 0.0, 0.0));
  double distance = pow(double(natom)/particle_density, 1.0/3.0) / length_;
  double initial_pos = -0.5 * distance * (length_ - 1);
  for(int ix = 0; ix < length_; ix++) {
    for (int iy = 0; iy < length_; iy++) {
      for (int iz = 0; iz < length_; iz++) {
        coordinate_[ix * length_ * length_ + iy * length_ + iz] = Particle(distance * ix + initial_pos, 
                                                        distance * iy + initial_pos, 
                                                        distance * iz + initial_pos);
      }
    }
  }
}

void CubicBox::print_coordinate() {
  for (int ix = 0; ix < length_; ix++) {
    for (int iy = 0; iy < length_; iy++) {
      for (int iz = 0; iz < length_; iz++) {
        int atomID = ix * length_ * length_ + iy * length_ + iz;
        cout << setw(6)  << atomID;
        cout << setw(8) << setprecision(4) << coordinate_[atomID].x();
        cout << setw(8) << setprecision(4) << coordinate_[atomID].y();
        cout << setw(8) << setprecision(4) << coordinate_[atomID].z();
        cout << endl; 
      }
    }
  }
}
