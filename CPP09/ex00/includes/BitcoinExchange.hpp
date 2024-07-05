#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string.h>
# include <unistd.h>
# include <cstdlib>
# include <ctime>
# include <map>
# include <fstream>
# include <sstream>
# include <climits>
# include <stdexcept>
# define RED "\033[31m"
# define GREEN "\033[32m"
# define PURPLE "\033[35m"
# define YELLOW "\033[33m"
# define WHITE "\033[37m"
# define CYAN "\033[36m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_PURPLE "\033[1;35m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_WHITE 	"\033[1;37m"
# define BOLD_CYAN "\033[1;36m"
# define RESET "\033[0m"

class MyException: public std::exception {
    public:
        explicit MyException(const std::string& msg);
        virtual const char* what() const throw();
        virtual ~MyException() throw();
    private:
        std::string _msg;
};

class BitcoinExchange {
public:
    BitcoinExchange(); // Constructor
    BitcoinExchange(const std::string& file);
    BitcoinExchange(const BitcoinExchange& copy);//Copy constructor
    BitcoinExchange& operator= (const BitcoinExchange& copy); //Copy assignment constructor
    float convert(std::string date, float value);
    ~BitcoinExchange(); // Destructor

private:
    std::map<std::string, float> _exchange_rate;
};

template <typename K, typename V>
void print_map(const std::map<K, V>& map) {
    for (typename std::map<K, V>::const_iterator it = map.begin(); it != map.end(); ++it) {
        std::cout << it->first << ". => " << it->second << std::endl;
    }
}

std::map<std::string, float> file_to_map(const std::string& file, const char& delimiter);

bool isNumber(std::string str);

bool valid_date(const std::string& date, const char& delimiter);

float getvalue(std::string value, std::string line, const char& delimiter);

#endif // BITCOINEXCHANGE_HPP
