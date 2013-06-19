#include "bodymanager.hpp"
#include <iostream>

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
    for(std::vector<Body>::iterator i=bodyList->begin(); i!=bodyList->end(); i++){
        i->draw();
    }
}

BodyManager::~BodyManager(){
    delete bodyList;
}
