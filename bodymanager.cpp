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

BodyManager::~BodyManager(){
    delete bodyList;
}
