#ifndef BODYMANAGER_HPP
#define BODYMANAGER_HPP

#include <vector>
#include <body.hpp>

class BodyManager
{
public:
    BodyManager();
    std::vector<Body>* getBodyList();
    void addBody(Body newBody);
    ~BodyManager();
private:
    std::vector<Body>* bodyList;
};

#endif // BODYMANAGER_HPP
