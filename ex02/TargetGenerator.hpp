#ifndef TARGETGENERATOR_H
# define TARGETGENERATOR_H

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

# include "ATarget.hpp"

class TargetGenerator
{
private:

	TargetGenerator(const TargetGenerator &ref);
	TargetGenerator &operator=(const TargetGenerator &rhs);

	std::vector<ATarget*>	list;

public:

	TargetGenerator();
	virtual ~TargetGenerator();
	void learnTargetType(ATarget *ref);
	void forgetTargetType(std::string const &ref);
	ATarget *createTarget(std::string const &ref);
};

#endif