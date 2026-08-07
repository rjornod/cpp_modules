#include <map>
#include <iostream>

class BitcoinExchange {
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& other);
		BitcoinExchange(const BitcoinExchange& other);
		
		void loadData(const std::string& file);
	private:
		std::map<std::string, float> m_dataBase;
};