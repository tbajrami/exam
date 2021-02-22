#ifndef ASPELL_H
# define ASPELL_H

# include <string>
# include <iostream>

class ATarget;

class ASpell
{
protected:

    std::string name;
    std::string effects;
    ASpell();

public:

    ASpell(std::string name, std::string effects);
    virtual ~ASpell();
    ASpell(const ASpell &ref);
    ASpell &operator=(const ASpell &rhs);

    std::string const &getName() const;
    std::string const &getEffects() const;

    void        launch(const ATarget &ref) const; 

    virtual ASpell* clone() const = 0;
};

#include "ATarget.hpp"

#endif