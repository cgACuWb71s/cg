#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float
get_time();

void
error(char const*const what);

float
randf();

#define STR1(x) #x
#define STR2(x) STR1(x)
#define ERROR() error(__FILE__ " " STR2(__LINE__))
