#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : name(name), title(title)
{std::cout << name << ": This look like another boring day." << std::endl;}

Warlock::~Warlock()
{std::cout << this->name << ": My job here is done!" << std::endl;}

std::string const &Warlock::getName() const {return this->name;}

std::string const &Warlock::getTitle() const {return this->title;}

void    Warlock::setTitle(const std::string &ref) {this->title = ref;}

void    Warlock::introduce() const
{
    std::cout << this->name;
    std::cout << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}