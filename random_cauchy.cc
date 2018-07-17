#include <random>
#include <iostream>
#include <fstream>


double rndCauchy(double x){
    std::random_device rnd;
	std::mt19937 mt(rnd());
	std::cauchy_distribution<double> rndx(x, 0.5);

	bool flagx;
	flagx=false;

	double rx=-100.0;

	do{
		rx=rndx(mt);
		std::cout << rx << std::endl;
		if (0.0<=rx && rx<= 1.0){
			flagx=true;
		}
	}while(flagx==false);


	return rx;
}
int main()
{
	double test=rndCauchy(0.0);
	std::cout << test << std::endl;

}
