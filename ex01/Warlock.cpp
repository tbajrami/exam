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

void    Warlock::learnSpell(ASpell *ref)
{
    for (std::vector<ASpell*>::iterator it = this->spells.begin() ; it != this->spells.end() ; it++)
    {
        if ((*it)->getName() == ref->getName())
            return ;
    }
    this->spells.push_back(ref);
}

void   Warlock::forgetSpell(std::string spell)
{
    std::vector<ASpell*>::iterator it = this->spells.begin();

    for (it = this->spells.begin() ; it != this->spells.end() ; it++)
    {
        if ((*it)->getName() == spell)
        {
            this->spells.std::vector<ASpell*>::erase(it);
            return ;
        }
    }
}

void  Warlock::launchSpell(std::string spell, ATarget &reff)
{
    std::vector<ASpell*>::iterator it;

    for (it = this->spells.begin() ; it != this->spells.end() ; it++)
    {
        if ((*it)->getName() == spell)
        {
            (*it)->launch(reff);
            return ;
        }
    }
}