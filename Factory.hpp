#pragma once

#include "Decoration.hpp"
#include "fire.hpp"
#include "Pots.hpp"
#include "Drums.hpp"
#include "Skull.hpp"

#include <string>

class Factory {

    //Decoration* object;

    public:

        Decoration* create(std::string obj, int x, int y);
        Decoration* create(std::string obj, int x, int y, char c);

        //Decoration* get_object();

        //~Factory();
};