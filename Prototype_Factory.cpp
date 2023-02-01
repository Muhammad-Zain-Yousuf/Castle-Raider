#include "Prototype_Factory.hpp"
#include "Treasure.hpp"
#include "Spikes.hpp"
#include "Treasure_key.hpp"
#include "Lever.hpp"
#include <map>

// Prototype* Prototype_Factory::prototypes[] = {NULL, 
//     new Treasure(), 
//     new Spikes(), 
//     new Treasure_key(),
//     new Lever()
//     };

std::map<std::string, Prototype*> Prototype_Factory::prototypes {
    {"Treasure", new Treasure()},
    {"Spikes", new Spikes()},
    {"T_key", new Treasure_key()},
    {"Lever", new Lever()},
    {"", NULL}
};

Prototype* Prototype_Factory::make_object(std::string choice) {

    return prototypes[choice]->clone();
}