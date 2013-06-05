#include "body.hpp"

Body::Body()
{
    position = vector3(0.0f, 0.0f, 0.0f);
    speed = vector3(0.0f, 0.0f, 0.0f);
    mass = 1.0f;
    radius = 1.0f;
}

Body::Body(float mass, float radius){
    this->mass = mass;
    this->radius = radius;
    position = vector3(0.0f, 0.0f, 0.0f);
    speed = vector3(0.0f, 0.0f, 0.0f);
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

std::vector<triangle> Body::getHull() const
{
    return hull;
}

void Body::setHull(const std::vector<triangle> &value)
{
    hull = value;
}

float* Body::getColor(){
    return color;
}

void Body::setColor(float value[4]){
    color[0] = value[0];
    color[1] = value[1];
    color[2] = value[2];
    color[3] = value[3];
}
