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
    std::vector<ATarget *>::iterator it_begin = this->list.begin();
    std::vector<ATarget *>::iterator it_end = this->list.end();

    while (it_begin != it_end)
    {
		std::cout << "type : " << (*it_begin)->getType() << std::endl;
        if ((*it_begin)->getType() == name)
		{
            return (*it_begin);
		}
        ++it_begin;
    }
    return (NULL);
}