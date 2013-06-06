#ifndef STAR_HPP
#define STAR_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <body.hpp>

class Star : public Body
{
public:
    Star();
    Star(float mass, float radius);
    Star(vector3 position, vector3 speed, float mass, float radius);
    Star(vector3 position, vector3 speed, float mass, float radius, std::vector<triangle> hull, float color[4]);
    void draw();
private:
    GLenum lightid;
    static int numLights;
    static int maxLights;
    void initLight();
};

#endif // STAR_HPP
