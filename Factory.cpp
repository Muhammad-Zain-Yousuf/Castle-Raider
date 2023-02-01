#include "Factory.hpp"
//#include <string>

Decoration* Factory::create(std::string obj, int x, int y) {

    if (obj == "Fire") 
        return new Fire(x, y);

    else if (obj == "Skull")
        return new Skull(x,y);

    else 
        return NULL;
}


Decoration* Factory::create(std::string obj, int x, int y, char c) {

    if (obj == "Drum") 
        return new Drums(x, y, c);

    else if (obj == "Pot")
        return new Pots(x,y,c);

    else 
        return NULL;
}

// Decoration* Factory::get_object() {

//     return object;
// }

// Factory::~Factory() {

//     if (object) {

//         delete object;
//         object = NULL;
//     }
// }