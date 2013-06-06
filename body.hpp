#pragma once

//#ifndef BODY_HPP
//#define BODY_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "vector3.hpp"
#include "geometry.hpp"
#include <vector>

class Body
{
public:
    Body();
    Body(float mass, float radius);
    Body(vector3 position, vector3 speed, float mass, float radius);
    Body(vector3 position, vector3 speed, float mass, float radius, std::vector<triangle> hull, float color[4]);

    void applyImpulse(vector3 impulse);
    void move(float timestep);

    virtual void draw();

    vector3 getPosition();
    void setPosition(vector3 value);

    vector3 getSpeed();
    void setSpeed(vector3 value);

    float getMass() const;
    void setMass(float value);

    float getRadius() const;
    void setRadius(float value);

    std::vector<triangle> getHull() const;
    void setHull(const std::vector<triangle> &value);

    float* getColor();
    void setColor(float value[4]);

protected:
    // m
    vector3 position;
    // m/s
    vector3 speed;
    // kg
    float mass;
    // m
    float radius;

    std::vector<triangle> hull;

    float color[4];
};

//#endif // BODY_HPP
