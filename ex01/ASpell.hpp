#ifndef ASPELL_H
# define ASPELL_H

# include <string>
# include <iostream>
# include "ATarget.hpp"
# include "Warlock.hpp"

class ATarget;
class Warlock;

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

    std::string getName() const;
    std::string getEffects() const;

    void        launch(const ATarget &ref) const; 

    virtual ASpell* clone() const = 0;
};

#endif