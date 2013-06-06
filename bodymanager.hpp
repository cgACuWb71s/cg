#ifndef BODYMANAGER_HPP
#define BODYMANAGER_HPP

#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <body.hpp>

class BodyManager
{
public:
    BodyManager();

    std::vector<Body>* getBodyList();

    void addBody(Body newBody);

    void drawBodys();

    ~BodyManager();
private:
    std::vector<Body>* bodyList;
};

#endif // BODYMANAGER_HPP
