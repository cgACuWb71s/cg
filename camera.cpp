#include "camera.hpp"
#include <iostream>

Camera::Camera()
{
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 1.0f;
    targetIndex = 0;
    planets = NULL;
}

void Camera::setCamera(){
    if(planets != NULL){
        if(targetIndex >= planets->getBodyList()->size()){
            targetIndex = 0;
        }
        vector3 look = planets->getBodyList()->at(targetIndex).getPosition();
        gluLookAt(position.x, position.y, position.z, look.x, look.y, look.z, 1.0, 0.0, 0.0);
    }
}

void Camera::tickControl(){
    if(key_released('e')){
        targetIndex++;
        if(targetIndex >= planets->getBodyList()->size()){
            targetIndex = 0;
        }
        //std::cout << "new Index: " << targetIndex << "\n";
    }
    float speed = len(position - planets->getBodyList()->at(targetIndex).getPosition())/2.0f;
    if(key_down('w')){
        position.y += speed*get_time();
        //std::cout << "new Position: " << position.x << ", " << position.y << ", " << position.z << "\n";
    }
    if(key_down('s')){
        position.y -= speed*get_time();
        //std::cout << "new Position: " << position.x << ", " << position.y << ", " << position.z << "\n";
    }
    if(key_down('d')){
        position.x += speed*get_time();
        //std::cout << "new Position: " << position.x << ", " << position.y << ", " << position.z << "\n";
    }
    if(key_down('a')){
        position.x -= speed*get_time();
        //std::cout << "new Position: " << position.x << ", " << position.y << ", " << position.z << "\n";
    }
    if(key_down('x')){
        position.z += speed*get_time();
        //std::cout << "new Position: " << position.x << ", " << position.y << ", " << position.z << "\n";
    }
    if(key_down('y')){
        position.z -= speed*get_time();
        //std::cout << "new Position: " << position.x << ", " << position.y << ", " << position.z << "\n";
    }
}

void Camera::setBodyList(BodyManager *input){
    planets = input;
}
