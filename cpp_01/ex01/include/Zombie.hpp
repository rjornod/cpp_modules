#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
# include <iostream>

class Zombie {
	private:
		std::string 	_name;

	public:
		void			announce(void );
		std::string		getName( void );
		void			setName( std::string name );
		Zombie(void);
		~Zombie(void);
	};
	Zombie* zombieHorde( int N, std::string name );

#endif