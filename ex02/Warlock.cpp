#include "Warlock.hpp"
#include "ASpell.hpp"

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << name << ": This look like another boring day." << std::endl;
}

Warlock::~Warlock() {std::cout << this->_name << ": My job here is done!" << std::endl;}

std::string const &Warlock::getName() const {return this->_name;}

std::string const &Warlock::getTitle() const {return this->_title;}

void    Warlock::setTitle(const std::string &ref) {this->_title = ref;}

void    Warlock::introduce() const
{
    std::cout << this->_name;
    std::cout << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void   Warlock::learnSpell(ASpell *ref) {this->spellbook.learnSpell(ref);}

void   Warlock::forgetSpell(std::string spell) {this->spellbook.forgetSpell(spell);}

void   Warlock::launchSpell(std::string spell, ATarget const &reff)
{
    ASpell *tmp = spellbook.createSpell(spell);

    if (tmp)
        tmp->launch(reff);
}