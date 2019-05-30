#ifndef _CUBIC_H_
#define _CUBIC_H_

#include "src/particle.h"
#include <vector>

using namespace std;

namespace md {
class CubicBox {
protected:
  const int natom_;
  const int length_;
  const double density_;
  vector<md::Particle> coordinate_;

public:
  CubicBox(int natom, double particle_density);
  void print_coordinate();
  ~CubicBox() = default;
};
} // namespace md

#endif