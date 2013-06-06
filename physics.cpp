#include "physics.hpp"

void physics::physicsIteration(std::vector<Body> *objects, float timestep){
    //Kraefte berechnen
    for(std::vector<Body>::iterator i=objects->begin()+1; i!=objects->end(); i++){
        for(std::vector<Body>::iterator j=objects->begin(); j!=i; j++){
            vector3 rij = j->getPosition()-i->getPosition();
            float gmMr3 = gravityConstant * i->getMass() * j->getMass() / std::pow(len(rij), 3);
            vector3 impulseij = rij * (gmMr3 * timestep);
            i->applyImpulse(impulseij);
            j->applyImpulse(impulseij*(-1));
        }
    }
    //bewegen
    for(std::vector<Body>::iterator k=objects->begin(); k!=objects->end(); k++){
        k->move(timestep);
    }
}
