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
    std::vector<ASpell *>::iterator it_begin = this->spells.begin();
    std::vector<ASpell *>::iterator it_end = this->spells.end();

    while (it_begin != it_end)
    {
        if ((*it_begin)->getName() == name)
            return (*it_begin);
        ++it_begin;
    }
    return (NULL);
}