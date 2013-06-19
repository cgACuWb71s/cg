#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <bodymanager.hpp>
#include <vector3.hpp>
#include <main.hpp>
#include <keys.hpp>

class Camera
{
public:
    Camera();
    void tickControl();
    void setCamera();
    void setBodyList(BodyManager *input);
private:
    unsigned int targetIndex;
    BodyManager *planets;
    vector3 position;
};

#endif // CAMERA_HPP
