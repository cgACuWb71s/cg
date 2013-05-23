#include "physics.hpp"

void physics::physicsIteration(std::vector<Body> *objects, float timestep){
    //Kraefte berechnen
    for(unsigned int i=1; i<objects->size(); i++){
        for(unsigned int j=0; j<i; j++){
            vector3 rij = objects->at(j).getPosition()-objects->at(i).getPosition();
            float gmMr3 = gravityConstant * objects->at(i).getMass() * objects->at(j).getMass() / std::pow(len(rij), 3);
            vector3 impulseij = rij * (gmMr3 * timestep);
            objects->at(i).applyImpulse(impulseij);
            objects->at(j).applyImpulse(impulseij*(-1));
        }
    }
    //bewegen
    for(unsigned int k=0; k<objects->size(); k++){
        objects->at(k).move(timestep);
    }
}
