#include "main.hpp"
#include "geometry.hpp"
#include "keys.hpp"
#include "physics.hpp"
#include "bodymanager.hpp"
#include "body.hpp"
#include "camera.hpp"

#include <iostream>

const float time_factor = 1.0f;
BodyManager planets;
Camera camera;

void
init_scene()
{
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    //glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
    //glDisable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    float yellow[4] = {1.0f,0.8f,0.2f,1.0f};
    planets.addBody(Body(
        vector3(1.0f, 0.0f, 0.0f),
        vector3(0.0f, 0.0f, 0.0f),
        10.0f, 0.3f,
        get_geometry(3,true),yellow, true));

    float blue[4] = {0.5f,0.5f,1.0f,1.0f};
    planets.addBody(Body(
        vector3(0.0f,5.0f,0.0f),
        vector3(0.0f,0.0f,1.0f),
        1.0f, 0.2f,
        get_geometry(1,true),blue, false));
    float white[4] = {1.0f,1.0f,1.0f,1.0f};
    planets.addBody(Body(
        vector3(30.0f,0.0f,0.0f),
        vector3(0.0f,0.0f,1.0f),
        1.0f, 0.2f,
        get_geometry(2,true), white, false));
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);
}

void
tick_scene()
{
    if(key_released('q'))
    {
	exit(0); 
    }
    physics::physicsIteration(planets.getBodyList(), time_factor*get_time());
    camera.tickControl();
}

void
render_scene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //vorlaefig
    //gluPerspective(45.0, 1.0, 1000.0, 1e11);
    //Body target = planets.getBodyList()->at(1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt(0.0, 1.1e7, 0.0, target.getPosition().x, target.getPosition().y, target.getPosition().z, 1.0, 0.0, 0.0);
    camera.setCamera();
    //Navigationsgitter
    glPushMatrix();
    glRotated(90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPopMatrix();
    glutWireSphere(500.0, 36, 18);
    planets.drawBodys();
}
