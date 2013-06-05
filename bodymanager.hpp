#ifndef BODYMANAGER_HPP
#define BODYMANAGER_HPP

#include <vector>
#include <body.hpp>
#include <main.hpp>

class BodyManager
{
public:
    BodyManager();

    std::vector<Body>* getBodyList();

    void addBody(Body newBody);

    void drawBodys();

    ~BodyManager();
private:
    std::vector<Body>* bodyList;

    void drawBody(Body& bdy);
};

#endif // BODYMANAGER_HPP
