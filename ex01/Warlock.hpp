#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

#include "ATarget.hpp"
#include "ASpell.hpp"

class Warlock
{
private:

    std::string              name;
    std::string              title;
    std::vector<ASpell*>     spells;

    Warlock();
    Warlock(const Warlock &ref);
    Warlock &operator=(const Warlock &rhs);

public:

    Warlock(std::string name, std::string title);
    virtual ~Warlock();

    std::string const &getName() const;
    std::string const &getTitle() const;

    void    setTitle(const std::string &ref);
    void    introduce() const;
    void    learnSpell(ASpell *ref);
    void    forgetSpell(std::string spell);
    void    launchSpell(std::string spell, ATarget &reff);
};