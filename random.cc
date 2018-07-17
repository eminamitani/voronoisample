#include <random>
#include <iostream>
#include <fstream>
int main()
{
    std::random_device rnd; 
	std::mt19937 mt(rnd());
	std::cauchy_distribution<double> score(0.0,1.0);
	std::ofstream ofs("output.dat");
    for (int i = 0; i < 100; ++i) {
    	double val=score(mt);
        std::cout  << val << "\n";
        ofs << val << "\n";

    }
    ofs.close();
}
