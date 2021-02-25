#pragma once

#include <string>
#include <iostream>

class ATarget;

class ASpell
{
protected:

    std::string name;
    std::string effects;

public:

    ASpell();
    ASpell(std::string name, std::string effects);
    virtual ~ASpell();
    ASpell(const ASpell &ref);
    ASpell &operator=(const ASpell &rhs);

    std::string getName() const;
    std::string getEffects() const;

    void        launch(const ATarget &ref) const; 

    virtual ASpell* clone() const = 0;
};

#include "ATarget.hpp"