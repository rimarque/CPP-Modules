#include "Harl.hpp"

Harl::Harl(){
}

void Harl::debug( void ){
    std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info( void ){
    std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning( void ){
    std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error( void ){
    std::cout << "[ERROR]\nThis is unaCXXeptable! I want to speak to the manager now.\n";
}

void    Harl::complain(std::string level){
    int a = 4;
    std::string levels[4] = {"debug", "info", "warning", "error"};

    for(int i = 0; i < 4; i++){
        if(!levels[i].compare(level))
           a = i;
    }
    switch(a){
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
}

Harl::~Harl(){
}