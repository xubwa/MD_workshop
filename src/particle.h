#ifndef _PARTICLE_H
#define _PARTICLE_H

#include <stdlib.h>

namespace md {
class Particle {
protected:
  double x_;
  double y_;
  double z_;

public:
  Particle(double x, double y, double z) : x_(x), y_(y), z_(z) {}
  const double x() { return x_; }
  const double y() { return y_; }
  const double z() { return z_; }
};
} // namespace md

#endif