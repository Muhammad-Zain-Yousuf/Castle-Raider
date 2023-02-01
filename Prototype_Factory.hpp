#pragma once
#include "Prototype.hpp"
#include <map>

class Prototype_Factory {

    //static Prototype* prototypes[5];
    static std::map<std::string, Prototype*> prototypes;

    public:

    // typedef std::map<std::string, Prototype*> prototypes;
    // static prototypes pt;
    static Prototype* make_object(std::string choice);
};