#include "includes/BitcoinExchange.hpp"


MyException::MyException(const std::string& msg): _msg(msg) {}

const char* MyException::what() const throw(){
    return _msg.c_str();
}

MyException::~MyException() throw() {}

BitcoinExchange::BitcoinExchange() {
    _exchange_rate = file_to_map("data.csv", ',');
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
    _exchange_rate = copy._exchange_rate;
}

// Copy assignment operator overload
BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _exchange_rate = copy._exchange_rate;
    return *this;
}

/*If the date used in the input does not exist in your DB then you
must use the closest date contained in your DB. Be careful to use the
lower date and not the upper one.*/
float BitcoinExchange::convert(std::string key, float value){
    std::map<std::string, float>::iterator it = _exchange_rate.upper_bound(key);
    if(it == _exchange_rate.begin())
        return it->second * value;
    return (--it)->second * value;
}

BitcoinExchange::~BitcoinExchange() {}

bool isSpace(std::string &str){
    bool space;
    int i = 0;
    if(str[0] == ' '){
        space = true;
        i++;
    }
    else
        space = false;
    if(str[i] == '-')
        i++;
    str = str.substr(i);
    return space;
}

bool    hasNonNumericChar(std::string str)
{
  for (std::string::const_iterator i = str.begin(); i != str.end(); ++i) {
        if (!std::isdigit(*i))
            return true;
  }
  return false;
}

bool  isFloat(std::string str)
{
    bool    point = false;
    for (std::string::const_iterator i = str.begin(); i != str.end(); ++i){
        if (!std::isdigit(*i) && *i != '.')
            return false;
        //ponto n pode repetir; pode estar no inicio ou no fim
        if(*i == '.'){
            if (point == true)
                return false;
            point = true;
        }
    }
    if(point == true)
        return true;
    return false;
}

bool isNumber(std::string str){
    if(str.empty() || (hasNonNumericChar(str) == true && isFloat(str) == false))
        return false;
    long number = atol(str.c_str());
    if(number < INT_MIN || number > INT_MAX)
        return false;
    return true;
}

bool isInt(std::string str){
    if(str.empty() || (hasNonNumericChar(str) == true))
        return false;
    long number = atol(str.c_str());
    if(number < INT_MIN || number > INT_MAX)
        return false;
    return true;
}

bool valid_year(std::string str, int& year){
    if(!isInt(str))
        return false;
    year = atoi(str.c_str());
    if (year <  2009)
        return false;
    return true;
}

bool valid_month(std::string str, int& month){
    if(!isInt(str))
        return false;
    if(str.length() != 2)
        return false;
    month = atoi(str.c_str());
    if (month > 12 || month < 0)
        return false;
    return true;
}

bool is_leap_year(int year){
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return true;
    return false;
}

bool valid_day(std::string str, const char& delimiter, int year, int month){
    if(delimiter == '|'){
        if(str[str.length() - 1] == ' ')
            str = str.substr(0, str.length() - 1);
        else
            return false;
    }
    if(!isInt(str))
        return false;
    if(str.length() != 2)
        return false;
    int day = atoi(str.c_str());
    if(month == 2){
        if(is_leap_year(year) && (day < 1 || day > 29))
            return false;
        if(!is_leap_year(year) && (day < 1 || day > 28))
            return false;
    }
    else if(month < 8){
        if(month % 2 == 0 && (day < 1 || day > 30))
            return false;
        if(month % 2 != 0 && (day < 1 || day > 31))
            return false;
    }
    else{
        if(month % 2 == 0 && (day < 1 || day > 31))
            return false;
        if(month % 2 != 0 && (day < 1 || day > 30))
            return false;
    }
    return true;
}

bool valid_date(const std::string& date, const char& delimiter){
    std::istringstream input_date(date);
    std::string year, month, day;
    int n_year, n_month;

    std::getline(input_date, year, '-');
    if(valid_year(year, n_year) == false)
        return false;
    
    std::getline(input_date, month, '-');
    if(valid_month(month, n_month) == false)
        return false;
    std::getline(input_date, day);
    if(valid_day(day, delimiter, n_year, n_month) == false)
        return false;
    
    return true;
}

float getvalue(std::string value, std::string line, const char& delimiter){
    std::string original_value = value;

    if(delimiter == '|' && isSpace(value) == false)
        throw MyException ("Error: bad input => " + line);
    if(delimiter == ',' && isSpace(value) == true)
            throw MyException ("Error: bad input => " + line);
    if(isNumber(value) == false)
        throw MyException ("Error: bad input => " + line);
    float number = std::atof(original_value.c_str());
    if(delimiter == '|' && number < 0)
        throw MyException ("Error: not a positive number.");
    if(delimiter == '|' && number > 1000)
        throw MyException ("Error: too large a number.");
    return number;
}

std::map<std::string, float> file_to_map(const std::string& file, const char& delimiter){
    //Abrir o ficheiro
    std::ifstream input_file(file.c_str());
    if (!input_file.is_open())
        throw MyException("Error opening file: " + file);

    //Ver se o ficheiro está vazio e validar o header
    std::string line;
    std::getline(input_file, line);
    if(input_file.eof()){
        input_file.close();
        throw MyException("Error: empty file => " + file);
    }
    if(line != "date,exchange_rate"){
            input_file.close();
            throw MyException("Error: invalid header => " + file);
    }

    //Ler o ficheiro e guardar numa estrutura associativa (map<string, number>)
    std::map<std::string, float> result_map;
    while (std::getline(input_file, line)) {
        std::istringstream input_line(line);
        std::string key, value;
        std::getline(input_line, key, delimiter);
        //Linha sem delimitador
        if(input_line.eof() == true){
            input_file.close();
            throw MyException("Error: bad data file => " + key);
        }
        std::getline(input_line, value);
        try{
            //Nada após delimitador
            if(value.empty())
                throw MyException ("Error: bad data file => " + line);
            //Validar data
            if(valid_date(key, delimiter) == false)
                throw MyException ("Error: bad data file => " + line);
            //Validar valor
            float number = getvalue(value, line, delimiter);
            result_map[key] = number;
        }
        catch(std::exception& e){
            input_file.close();
            throw MyException("Error: bad data file => " + line);
        }
    }
    input_file.close();
    //print_map(result_map);
    return result_map;
}