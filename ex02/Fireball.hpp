#ifndef FIREBALL_H
# define FIREBALL_H

# include "ASpell.hpp"

class Fireball : public ASpell
{
public:

    Fireball();
    virtual ~Fireball();
    virtual ASpell *clone() const;
};

#endif