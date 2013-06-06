#include "main.hpp"
#include "geometry.hpp"
#include "keys.hpp"
#include "physics.hpp"
#include "bodymanager.hpp"
#include "body.hpp"
#include "star.hpp"

const float time_factor = 1e5;
BodyManager planets;

void
init_scene()
{
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    //glDisable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    vector3 zero(0.0f, 0.0f, 0.0f);
    float yellow[4] = {1.0f,1.0f,0.0f,1.0f};
    planets.addBody(Star(
        zero, zero,
        1e9, 1e6,
        get_geometry(0,true),yellow));

    float blue[4] = {0.5f,0.5f,1.0f,1.0f};
    planets.addBody(Star(
        vector3(0.0f,1e7,0.0f),
        vector3(0.0f,0.0f,1e4),
        1e7, 4e5,
        get_geometry(1,true),blue));
    float white[4] = {1.0f,1.0f,1.0f,1.0f};
    planets.addBody(Body(
        vector3(0.0f,-1e7,0.0f),
        vector3(0.0f,0.0f,-1e4),
        1e7, 4e5,
        get_geometry(2,true),white));
    
    /*planet=glGenLists(1);
    glNewList(planet, GL_COMPILE);
    glBegin(GL_TRIANGLES);
    std::vector<triangle> geom=get_geometry(get_num_geometries()-1, true);
    for(std::vector<triangle>::const_iterator i=geom.begin();
    	i!=geom.end();
    	++i)
    {
    	for(unsigned char c=0;c!=3;++c)
    	{
	    glColor4f(randf(), randf(), randf(), randf());
    	    glNormal3fv(i->norm[c].c);
	    glVertex3fv(i->pos[c].c);
    	}
    }
    glEnd();
    glEndList();*/
}

void
tick_scene()
{
    if(key_released('q'))
    {
	exit(0); 
    }
    physics::physicsIteration(planets.getBodyList(), time_factor*get_time());
}

void
render_scene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //vorlaefig
    gluPerspective(45.0, 1.0, 1000.0, 1e11);
    Body target = planets.getBodyList()->at(2);
    gluLookAt(0.0, 1.1e7, 0.0, target.getPosition().x, target.getPosition().y, target.getPosition().z, 1.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    planets.drawBodys();
}
