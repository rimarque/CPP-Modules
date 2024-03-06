#include "includes/Zombie.hpp"

int main()
{   
    std::string zombieNames[6] = {"Rita", "Diogo", "Jenny", "Asdrubal", "Redolfo", "Gaspar"};

    std::srand((unsigned int)(std::time(0))); //Seed the random number generator with the current time.
                                                        //Setta o valor inicial (semente) do rand (gerador de numeros aleatorio).
                                                            // Usar uma semente baseada no tempo faz com que esta mude cada vez que 
                                                                //o programa e executado, resultando em sequencias diferentes 
                                                                    //de numeros aleatorios
    int randIndex = std::rand() % 6; //para que seja sempre um numero de zero a 6
    randomChump(zombieNames[randIndex]);
    randIndex = std::rand() % 6;
    Zombie *zb = newZombie(zombieNames[randIndex]);
    delete zb;
}