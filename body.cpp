#include "body.hpp"

Body::Body()
{
    position = {0.0f, 0.0f, 0.0f};
    speed = {0.0f, 0.0f, 0.0f};
    mass = 1.0f;
    radius = 1.0f;
}

Body::Body(float mass, float radius){
    this->mass = mass;
    this->radius = radius;
    position = {0.0f, 0.0f, 0.0f};
    speed = {0.0f, 0.0f, 0.0f};
}

Body::Body(vector3 position, vector3 speed, float mass, float radius){
    this->position = position;
    this->speed = speed;
    this->mass = mass;
    this->radius = radius;
}

void Body::applyImpulse(vector3 impulse){
    speed += (impulse/mass);
}

void Body::move(float timestep){
    position += speed*timestep;
}

vector3 Body::getPosition(){
    return position;
}

void Body::setPosition(vector3 value){
    this->position = value;
}

vector3 Body::getSpeed(){
    return speed;
}

void Body::setSpeed(vector3 value){
    this->speed = value;
}

float Body::getMass() const
{
    return mass;
}

void Body::setMass(float value)
{
    mass = value;
}

float Body::getRadius() const
{
    return radius;
}

void Body::setRadius(float value)
{
    radius = value;
}
