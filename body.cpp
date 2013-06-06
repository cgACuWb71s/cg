#include "body.hpp"

Body::Body()
{
    position = vector3(0.0f, 0.0f, 0.0f);
    speed = vector3(0.0f, 0.0f, 0.0f);
    mass = 1.0f;
    radius = 1.0f;
    color[0] = 1.0;
    color[1] = 1.0;
    color[2] = 1.0;
    color[3] = 1.0;
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

Body::Body(vector3 position, vector3 speed, float mass, float radius, std::vector<triangle> hull, float color[4]){
    this->position = position;
    this->speed = speed;
    this->mass = mass;
    this->radius = radius;
    this->hull = hull;
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];
    this->color[3] = color[3];
}

void Body::applyImpulse(vector3 impulse){
    speed += (impulse/mass);
}

void Body::move(float timestep){
    position += speed*timestep;
}

void Body::draw(){
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
    float black[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_SPECULAR, black);
    glMaterialfv(GL_FRONT, GL_EMISSION, black);
    glPushMatrix();
    glScalef(radius, radius, radius);
    glTranslatef(position.x, position.y, position.z);
    glBegin(GL_TRIANGLES);
    for(std::vector<triangle>::const_iterator i=hull.begin(); i!=hull.end(); i++){
        glNormal3fv(i->norm[0].c);
        glVertex3fv(i->pos[0].c);
        glNormal3fv(i->norm[1].c);
        glVertex3fv(i->pos[1].c);
        glNormal3fv(i->norm[2].c);
        glVertex3fv(i->pos[2].c);
    }
    glEnd();
    glPopMatrix();
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
