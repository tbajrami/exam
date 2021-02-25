#include "TargetGenerator.hpp"
#include "BrickWall.hpp"
#include "Dummy.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget *ref)
{
	std::vector<ATarget*>::iterator it;

	for (it = this->list.begin() ; it != this->list.end() ; it++)
	{
		if ((*it)->getType() == ref->getType())
			return ;
	}
	this->list.push_back(ref->clone());
}

void TargetGenerator::forgetTargetType(std::string const &ref)
{
	std::vector<ATarget*>::iterator it;

    for (it = this->list.begin() ; it != this->list.end() ; it++)
    {
        if ((*it)->getType() == ref)
        {
            this->list.std::vector<ATarget*>::erase(it);
            return ;
        }
    }
}

ATarget* TargetGenerator::createTarget(std::string const &name)
{
    std::vector<ATarget *>::iterator it;

    for (it = this->list.begin() ; it != this->list.end() ; it++)
    {
        if ((*it)->getType() == name)
            return (*it);
    }
    return (NULL);
}