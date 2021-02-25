#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {}

void SpellBook::learnSpell(ASpell *ref)
{
	std::vector<ASpell*>::iterator it;

	for (it = this->spells.begin() ; it != this->spells.end() ; it++)
	{
		if ((*it)->getName() == ref->getName())
			return ;
	}
	this->spells.push_back(ref->clone());
}

void SpellBook::forgetSpell(std::string const &ref)
{
	std::vector<ASpell*>::iterator it;

    for (it = this->spells.begin() ; it != this->spells.end() ; it++)
    {
        if ((*it)->getName() == ref)
        {
            this->spells.std::vector<ASpell*>::erase(it);
            return ;
        }
    }
}

ASpell* SpellBook::createSpell(std::string const &name)
{
    std::vector<ASpell *>::iterator it;

    for (it = this->spells.begin() ; it != this->spells.end() ; it++)
    {
        if ((*it)->getName() == name)
            return (*it);
    }
    return (NULL);
}