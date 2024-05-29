#ifndef SCALARTYPE_HPP
# define SCALARTYPE_HPP

# include <iostream>
# include <string.h>
# include <unistd.h>
# include <cstdlib>
# include <ctime>
# include <cstring>
# include <climits>
# include <cfloat>
# include <string>
# include <iomanip>
#include <stdint.h>
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

class ScalarType {
public:
    ScalarType(); // Constructor
    ScalarType(char *str); // String Constructor
    ScalarType(const ScalarType& copy);//Copy constructor
    ScalarType& operator= (const ScalarType& copy); //Copy assignment constructor
    //Auxiliar to Detect type
    std::string getBeginNumber(std::string str);
    bool        checkFloatCriteria(std::string str);
    bool        hasNonNumericChar(std::string str);
    //Detect type
    int         detectType();
    bool        isChar();
    bool        isInt();
    bool        isFloat();
    bool        isDouble();

    //Getters
    char        *getStr() const;
    int         getType() const;
    int         getPrecision() const;

    //Convert
    void        convertToChar();
    void        convertToInt();
    void        convertToFloat();
    void        convertToDouble();

    //Print
    static void        printChar(int num);
    static void        printInt(long long int num);
    static void        printFloat(double num);
    ~ScalarType(); // Destructor

private:
    char        *_str;
    int         _type;
    int         _precision;
};

#endif // SCALARTYPE_HPP
