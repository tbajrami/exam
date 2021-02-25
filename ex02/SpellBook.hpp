#ifndef SPELLBOOK_H
# define SPELLBOOK_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "ASpell.hpp"

class SpellBook
{
private:

	SpellBook(const SpellBook &ref);
	SpellBook &operator=(const SpellBook &rhs);

	std::vector<ASpell*> spells;

public:

	SpellBook();
	virtual ~SpellBook();

	void learnSpell(ASpell *ref);
	void forgetSpell(std::string const &ref);
	ASpell *createSpell(std::string const &name);
};

#endif