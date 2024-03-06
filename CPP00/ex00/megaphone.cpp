#include <iostream>
#include <stdint.h>

#define cout std::cout 

int main(int argc, char *argv[])
{
    if (argc == 1)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for(int i = 1; i < argc; i++){
        std::string str = argv[i];
        for (uint64_t j = 0; j < str.length(); j++)
                str[j] = toupper(str[j]); 
        cout << str;
    }
    cout << std::endl;
    return 0;
}
