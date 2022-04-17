#ifndef LAB4_CIRCUIT_H
#define LAB4_CIRCUIT_H

#include "component.h"
#include <vector>
#include <unordered_map>

class circuit
{
    std::string name;
    std::unordered_map<std::string, double> connectionPoints;
    std::vector<component*> allComponents;
public:
    circuit (const std::string &name);
    void simulation (const int &iterations, const int &outputLines,
                     const double &timeStep);
    void newConnectionPoint (const std::string &point);
    void newComponent (component* component);
};


#endif //LAB4_CIRCUIT_H
