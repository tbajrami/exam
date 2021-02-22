#include "ATarget.hpp"

ATarget::ATarget(std::string type) : type(type) {}

ATarget::~ATarget() {}

ATarget::ATarget(const ATarget &ref) : type(ref.type) {}

ATarget &ATarget::operator=(const ATarget &rhs)
{
    this->type = rhs.type;
    return *this;
}

std::string const &ATarget::getType() const {return this->type;}

void    ATarget::getHitBySpell(const ASpell &ref) const
{
    std::cout << this->type << " has been " << ref.getEffects() << "!\n";
}