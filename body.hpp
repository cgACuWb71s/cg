#pragma once

//#ifndef BODY_HPP
//#define BODY_HPP

#include "vector3.hpp"

class Body
{
public:
    Body();
    Body(float mass, float radius);
    Body(vector3 position, vector3 speed, float mass, float radius);

    void applyImpulse(vector3 impulse);
    void move(float timestep);

    vector3 getPosition();
    void setPosition(vector3 value);

    vector3 getSpeed();
    void setSpeed(vector3 value);

    float getMass() const;
    void setMass(float value);

    float getRadius() const;
    void setRadius(float value);

private:
    // m
    vector3 position;
    // m/s
    vector3 speed;
    // kg
    float mass;
    // m
    float radius;
};

//#endif // BODY_HPP
