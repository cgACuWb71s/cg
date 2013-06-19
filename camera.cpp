#include "camera.hpp"
#include <iostream>
#include <cmath>

Camera::Camera()
{
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 0.0f;
    rotation.x = 0.0f;
    rotation.y = 0.0f;
    rotation.z = 0.0f;
    speed = 1.0f;
}

void Camera::setCamera(){
    gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);
    glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation.z, 0.0f, 0.0f, -1.0f);
    glTranslatef(position.x, position.y, position.z);
}

void Camera::tickControl(){
    if(key_down('y')){
        position.y += speed*get_time();
        //glTranslatef(0.0f, speed*get_time(), 0.0f);
        //std::cout << "new Position: " << position.x << ", " << position.y << ", " << position.z << "\n";
    }
    if(key_down('x')){
        position.y -= speed*get_time();
        //glTranslatef(0.0f, -speed*get_time(), 0.0f);
        //std::cout << "new Position: " << position.x << ", " << position.y << ", " << position.z << "\n";
    }
    if(key_down('a')){
        position.x += speed*get_time();
        //glTranslatef(speed*get_time(), 0.0f, 0.0f);
        //std::cout << "new Position: " << position.x << ", " << position.y << ", " << position.z << "\n";
    }
    if(key_down('d')){
        position.x -= speed*get_time();
        //glTranslatef(-speed*get_time(), 0.0f, 0.0f);
        //std::cout << "new Position: " << position.x << ", " << position.y << ", " << position.z << "\n";
    }
    if(key_down('w')){
        position.z += speed*get_time();
        //glTranslatef(0.0f, 0.0f, speed*get_time());
        //std::cout << "new Position: " << position.x << ", " << position.y << ", " << position.z << "\n";
    }
    if(key_down('s')){
        position.z -= speed*get_time();
        //glTranslatef(0.0f, 0.0f, -speed*get_time());
        //std::cout << "new Position: " << position.x << ", " << position.y << ", " << position.z << "\n";
    }

    if(key_down('k')){
        rotation.y += turnRate*get_time();
        while (rotation.y > 360.0f) {
            rotation.y -= 360.0f;
        }
        while (rotation.y < 0.0f) {
            rotation.y += 360.0f;
        }
        //glRotatef(turnRate*get_time(), 0.0f, 1.0f, 0.0f);
    }
    if(key_down('h')){
        rotation.y -= turnRate*get_time();
        while (rotation.y > 360.0f) {
            rotation.y -= 360.0f;
        }
        while (rotation.y < 0.0f) {
            rotation.y += 360.0f;
        }
        //glRotatef(-turnRate*get_time(), 0.0f, 1.0f, 0.0f);
    }
    if(key_down('j')){
        rotation.x += turnRate*get_time();
        while (rotation.x > 360.0f) {
            rotation.x -= 360.0f;
        }
        while (rotation.x < 0.0f) {
            rotation.x += 360.0f;
        }
        //glRotatef(turnRate*get_time(), 1.0f, 0.0f, 0.0f);
    }
    if(key_down('u')){
        rotation.x -= turnRate*get_time();
        while (rotation.x > 360.0f) {
            rotation.x -= 360.0f;
        }
        while (rotation.x < 0.0f) {
            rotation.x += 360.0f;
        }
        //glRotatef(-turnRate*get_time(), 1.0f, 0.0f, 0.0f);
    }
    if(key_down('m')){
        rotation.z += turnRate*get_time();
        while (rotation.z > 360.0f) {
            rotation.z -= 360.0f;
        }
        while (rotation.y < 0.0f) {
            rotation.z += 360.0f;
        }
        //glRotatef(turnRate*get_time(), 0.0f, 0.0f, 1.0f);
    }
    if(key_down('n')){
        rotation.z -= turnRate*get_time();
        while (rotation.z > 360.0f) {
            rotation.z -= 360.0f;
        }
        while (rotation.z < 0.0f) {
            rotation.z += 360.0f;
        }
        //glRotatef(-turnRate*get_time(), 0.0f, 0.0f, 1.0f);
    }
#if 0
    if(key_down('r')){
        speed += 2.0f*get_time();
    }
    if(key_down('e')){
        speed = 1.0f;
    }
#endif
}
