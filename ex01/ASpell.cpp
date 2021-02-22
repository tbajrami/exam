#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) : name(name), effects(effects) {}

ASpell::~ASpell() {}

ASpell::ASpell(const ASpell &ref) : name(ref.name), effects(ref.effects) {}

ASpell &ASpell::operator=(const ASpell &rhs)
{
    this->name = rhs.name;
    this->effects = rhs.effects;
    return *this;
}

std::string ASpell::getName() const {return this->name;}

std::string ASpell::getEffects() const {return this->effects;}

void    ASpell::launch(const ATarget &ref) const
{
    ref.getHitBySpell(*this);
}