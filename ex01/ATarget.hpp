#pragma once

#include <string>
#include <iostream>

class ASpell;

class ATarget
{
protected:

    std::string type;
    ATarget();

public:

    ATarget(std::string type);
    virtual ~ATarget();
    ATarget(const ATarget &ref);
    ATarget &operator=(const ATarget &rhs);

    std::string const &getType() const;
    void    getHitBySpell(const ASpell &ref) const;

    virtual ATarget* clone() const = 0;
};

#include "ASpell.hpp"