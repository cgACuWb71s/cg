#include "bodymanager.hpp"
#include <iostream>
#include "main.hpp"
#include "geometry.hpp"

BodyManager::BodyManager()
{
    bodyList = new std::vector<Body>();
}

void BodyManager::addBody(Body newBody){
    bodyList->push_back(newBody);
}

void BodyManager::addRandomBody(bool isStar){
    vector3 rPos(randf()*10.0f, randf()*10.0f, randf()*10.0f);
    vector3 rVel(randf(), randf(), randf());
    float rMass = randf()*0.5f;
    float rRad = randf()*0.5f+0.1f;
    float rColor[4] = {randf(), randf(), randf(), randf()};
    bodyList->push_back(Body(rPos,rVel,rMass,rRad, get_geometry(get_num_geometries()*randf(), true), rColor, isStar));
}

std::vector<Body>* BodyManager::getBodyList(){
    return bodyList;
}

void BodyManager::drawBodys(){
    for(std::vector<Body>::iterator i=bodyList->begin(); i!=bodyList->end(); i++){
        i->draw();
    }
}

BodyManager::~BodyManager(){
    delete bodyList;
}
