#include <random>
#include <iostream>
int main()
{
    std::random_device rnd;    
    for (int i = 0; i < 10; ++i) {
        std::cout  << rnd() << "\n";
    }
    getchar();
    return 0;
}