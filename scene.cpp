#include "main.hpp"
#include "geometry.hpp"
#include "keys.hpp"
#include "physics.hpp"
#include "bodymanager.hpp"

int planet;
float timestep = 1e5;
BodyManager planets;

void
init_scene()
{
    glShadeModel(GL_SMOOTH);
    // glEnable(GL_LIGHTING);
    glDisable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    
    planet=glGenLists(1);
    
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
    glEndList();
}

void
tick_scene()
{
    if(key_released('q'))
    {
	exit(0); 
    }
    physics::physicsIteration(planets.getBodyList(), timestep);
}

void
render_scene()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-10, 0, 0, 0, 0, 0, 0, 1, 0);

    glCallList(planet);
}
