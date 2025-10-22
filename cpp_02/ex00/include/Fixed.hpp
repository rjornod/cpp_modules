
class Fixed {
	private:
		int	_value;
		static const int _fract_bits = 8;
	public:
		int value;
		int age;
		Fixed() : _value(0){}; //default constructor. initializes _value to 0
		Fixed(const Fixed& copy){}; //copy constructor
		Fixed &operator=(const Fixed& overload){};
		~Fixed(void){};
};
