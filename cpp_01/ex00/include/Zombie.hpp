#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
# include <iostream>
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

class Zombie {
	private:
		std::string 	_name;
		Zombie(void);

	public:
		void			announce(void);
		std::string		getName(void);
		Zombie(std::string name);
		~Zombie(void);

};
Zombie*	newZombie(std::string name);
void 	randomChump(std::string name);

#endif