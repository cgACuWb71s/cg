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
private:
    vector3 position;
    vector3 rotation;
    // m/s
    float speed;
    // Grad/s
    const float turnRate = 60.0f;
};

#endif // CAMERA_HPP
