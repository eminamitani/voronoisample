#include <random>
#include <iostream>
#include <fstream>


double rndCauchy(double x, double min, double max){
    std::random_device rnd;
	std::mt19937 mt(rnd());
	std::cauchy_distribution<double> rndx(x, 0.1);

	bool flagx;
	flagx=false;

	double rx=-10000.0;

	do{
		rx=rndx(mt);
		std::cout << rx << std::endl;
		if (min<=rx && rx<= max){
			flagx=true;
		}
	}while(flagx==false);


	return rx;
}
int main()
{
	std::ofstream ofs("cauchy.dat");
	double test=-10000000;

	for(int i=0;i<10000;++i){
	  test=rndCauchy(0.0, 0.0, 1.0);
	  std::cout << test << std::endl;
	  ofs << test << "\n";
	}

}
