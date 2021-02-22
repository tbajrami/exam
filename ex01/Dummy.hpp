#ifndef DUMMY_H
# define DUMMY_H

# include "ATarget.hpp"

class Dummy : public ATarget
{
public:

    Dummy();
    virtual ~Dummy();
    virtual ATarget *clone() const;
};

#endif