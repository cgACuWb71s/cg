#include "bodymanager.hpp"

BodyManager::BodyManager()
{
    bodyList = new std::vector<Body>();
}

void BodyManager::addBody(Body newBody){
    bodyList->push_back(newBody);
}

std::vector<Body>* BodyManager::getBodyList(){
    return bodyList;
}

void BodyManager::drawBodys(){
    for(unsigned int i=0; i<bodyList->size(); i++){
        Body bdy = bodyList->at(i);
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, bdy.getColor());
        float r = bdy.getRadius();
        glPushMatrix();
        glScalef(r, r, r);
        vector3 pos = bdy.getPosition();
        glTranslatef(pos.x, pos.y, pos.z);
        //TODO triangle-Liste zeichnen
        glPopMatrix();
    }
}

BodyManager::~BodyManager(){
    delete bodyList;
}
