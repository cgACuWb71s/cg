#include "main.hpp"
#include "keys.hpp"
#include "geometry.hpp"
#include "scene.hpp"

#include <cstdlib>
#include <iostream>

namespace
{
    bool in_main_loop=false;
    
    float tick_time=0;
    int old_time=0;

    void
    display_func()
    {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	render_scene();
	glutSwapBuffers();
    }
    
    void
    idle_func()
    {
	if(!old_time)
	{
	    old_time=glutGet(GLUT_ELAPSED_TIME);
	}
	else
	{
	    int const i=glutGet(GLUT_ELAPSED_TIME);
	    tick_time=(i-old_time)/1000.0f;
	    old_time=i;
	}

	tick_scene();
	tick_keys();
	
	glutPostRedisplay();
    }

    void
    reshape_func(int const w, int const h)
    {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    //gluPerspective(30, static_cast<float>(w)/h, 1.0, 100.0);
    gluPerspective(45.0, static_cast<float>(w)/h, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    }
}

float
randf()
{
    return std::abs(std::rand())/static_cast<float>(RAND_MAX);
}

float
get_time()
{
    return tick_time;
}

int main(int argc, char** argv)
{
    srand(time(0));
    
    glutInitWindowSize(800, 600);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE /*| GLUT_ALPHA */| GLUT_DEPTH| GLUT_ALPHA);

    glutCreateWindow("Planeten");
    glutSetCursor(GLUT_CURSOR_NONE);

    init_keys();
    init_geometry();
    init_scene();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
    glutReshapeFunc(reshape_func);
    glutIdleFunc(idle_func);
    glutDisplayFunc(display_func);
    // glutCloseFunc gibts hier nicht :(

    in_main_loop=true;
    glutMainLoop();
}

void
error(char const*const what)
{
    std::cerr << what << std::endl;

    // glutLeaveMainLoop gibts hier auch nicht :(
    exit(0);
}
