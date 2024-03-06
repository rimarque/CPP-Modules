# include <iostream>
# include <string>
# include <cctype>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <iomanip> 
# include <cstdlib>
# define CLEAR_SCREEN "\033[2J\033[H"
# define RED "\033[1;31m"
# define RESET "\033[0m"

int main()
{
    std::string original = "HI THIS IS BRAIN";
    std::string *stringPTR = &original;
    std::string &stringREF = original;
    
    std::cout << "original: " << &original << std::endl;
    std::cout << "stringPTR: " << stringPTR << std::endl;
    std::cout << "stringREF: " << &stringREF << "\n\n";  

    std::cout << "original: " << original << std::endl;
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;
}

/*int main()
{
    std::string original = "HI THIS IS BRAIN";
    std::string *stringPTR = &original;
    std::string &stringREF = original;
    
    std::cout << "original: " << original << std::endl;
    std::cout << "string PTR: " << *stringPTR << std::endl;
    std::cout << "string REF: " << stringREF << std::endl;
    std::cout << "\nDKSGFUGAS\n\n";

    
    //stringPTR = &mama; //nao e possivel fazer na REF, e o ptr aponta para o endereco da mama;

    //stringREF = mama; //acedes a memoria e mudas o valor (original, ptr e ref); (altera o conteudo do objeto referenciado);
 
    //stringPTR = mama; //acedes a memoria e mudas o valor (original, ptr e ref);
    std::cout << "original: " << original << std::endl;
    std::cout << "string PTR: " << *stringPTR << std::endl;
    std::cout << "string REF: " << stringREF << std::endl;
}*/