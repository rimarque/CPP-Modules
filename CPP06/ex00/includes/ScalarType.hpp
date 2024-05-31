#ifndef SCALARTYPE_HPP
# define SCALARTYPE_HPP

# include <iostream>
# include <string>
# include <unistd.h>
# include <cstdlib>
# include <ctime>
# include <cstring>
# include <climits>
# include <limits>
# include <cfloat>
# include <string>
# include <iomanip>
# include <stdint.h>
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

# include "MyException.hpp"

class ScalarType {
public:
    ScalarType(); // Constructor
    ScalarType(char *str); // String Constructor
    ScalarType(const ScalarType& copy);//Copy constructor
    ScalarType& operator= (const ScalarType& copy); //Copy assignment constructor

    //Auxiliar to Detect type
    std::string getBeginNumber();
    bool        hasNonNumericChar(std::string str);
    bool        checkFloatCriteria(std::string str);
    bool        checkDoubleCriteria(std::string str);

    //Detect type
    int         detectType();
    bool        isChar();
    bool        isInt();
    bool        isFloat();
    bool        isDouble();
    bool        isPseudoLiteralFloat();
    bool        isPseudoLiteral();

    //Getters
    std::string getStr() const;
    int         getType() const;
    int         getPrecision() const;
    int         getConversions() const;

    //Convert
    void        convertToChar();
    void        convertToInt();
    void        convertToFloat();
    void        convertToDouble();
    void        pseudoLiteralsFloat();
    void        pseudoLiterals();

    //Check limits
    static void        checkLimitsPrintChar(int num);
    static void        checkLimitsPrintInt(long long int num);
    static void        checkLimitsPrintFloat(double num, int precision);
    ~ScalarType();      // Destructor

private:
    std::string _str;
    int         _type;
    int         _precision;
    int         _conversions;
};

#endif // SCALARTYPE_HPP
