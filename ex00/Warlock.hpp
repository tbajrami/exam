#ifndef WARLOCK_H
# define WARLOCK_H

# include <string>
# include <iostream>

class Warlock
{
private:

    std::string _name;
    std::string _title;
    Warlock();
    Warlock(const Warlock &ref);
    Warlock &operator=(const Warlock &rhs);

public:

    Warlock(std::string name, std::string title);
    virtual ~Warlock();

    std::string const &getName() const;
    std::string const &getTitle() const;

    void    setTitle(const std::string &ref);
    void    introduce() const;
};

#endif