#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "body.hpp"
#include "vector3.hpp"

#include <vector>
#include <cmath>

namespace physics{
// m3/(kg*s2)
const float gravityConstant = 1.0f; //6.672e-11;

void physicsIteration(std::vector<Body> *objects, float timestep);
}

#endif // PHYSICS_HPP
