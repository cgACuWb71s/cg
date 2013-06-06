#include "star.hpp"

int Star::numLights = 0;
int Star::maxLights = -1;

Star::Star():Body(){
    initLight();
}

Star::Star(float mass, float radius):Body(mass,radius){
    initLight();
}

Star::Star(vector3 position, vector3 speed, float mass, float radius)
    :Body(position, speed, mass, radius){
    initLight();
}

Star::Star(vector3 position, vector3 speed, float mass, float radius, std::vector<triangle> hull, float color[])
    :Body(position,speed,mass,radius,hull,color){
    initLight();
}

void Star::draw(){
    float black[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, black);
    glMaterialfv(GL_FRONT, GL_SPECULAR, black);
    glMaterialfv(GL_FRONT, GL_EMISSION, color);
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
    float pos[4] = {position.x, position.y, position.z, 1.0f};
    glLightfv(GL_LIGHT0+lightid, GL_POSITION, pos);
}

void Star::initLight(){
    if(maxLights == -1){
        glGetIntegerv(GL_MAX_LIGHTS, &maxLights);
    }
    if(numLights<maxLights){
        lightid = numLights;
        numLights++;
        glEnable(GL_LIGHT0+lightid);
        glLightfv(GL_LIGHT0+lightid,GL_DIFFUSE,color);
        glLightfv(GL_LIGHT0+lightid,GL_SPECULAR,color);
    }
}
