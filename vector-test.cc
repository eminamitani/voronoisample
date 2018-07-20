/*
 * vector-test.cc
 *
 *  Created on: Jul 20, 2018
 *      Author: emi
 */

#include <algorithm>
#include <vector>

int main(){

std::vector<std::vector<double>> vec={{1.0,0.0},{0.0,0.2},{0.1,0.1},{1.0,0.0}};
std::sort(vec.begin(),vec.end());

auto itr= std::unique(vec.begin(),vec.end());


}

