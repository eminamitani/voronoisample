// Based on Voronoi calculation example code by Chris H.Rycroft
// E. Minamitani add the part to generate the sampling points
// whose distances from origin obeys Cauchy distribution
//

#include "voro++.hh"
#include <random>
#include <fstream>
#include <math.h>
using namespace voro;


// Set up constants for the container geometry
const double x_min=0,x_max=1;
const double y_min=0,y_max=1;
const double z_min=0,z_max=1;
const double r_min=0,r_max=1;
const double cvol=(x_max-x_min)*(y_max-y_min)*(x_max-x_min);
const double cwidth=0.05;

// Set up the number of blocks that the container is divided into
const int n_x=40,n_y=40,n_z=40;

// Set the number of particles using cauchy random distribution
const int cparticles=30000;
// number of particles purely gnerated by random agorithm
const int addparticles=20000;

// This function returns a random double between 0 and 1
double rnd() {return double(rand())/RAND_MAX;}

// random number generator obeys Cauchy distribution
// this part needs C++11 for random generator
double rndCauchy(double x, double min, double max, double width){
    std::random_device rnd;
	std::mt19937 mt(rnd());
	std::cauchy_distribution<double> rndx(x, width);

	bool flagx;
	flagx=false;

	double rx=-100000.0;

	do{
		rx=rndx(mt);
		if (min<=rx && rx<= max){
			flagx=true;
		}
	}while(flagx==false);


	return rx;
}

int main() {
	int i;
	double x,y,z,r;
	double tmpr;
	bool flagx;
	bool flagy;

	// Create a container with the geometry given above, and make it
	// periodic in each of the three coordinates. Allocate space for
	// eight particles within each computational block
	container con(x_min,x_max,y_min,y_max,z_min,z_max,n_x,n_y,n_z,
			true,true,true,80);

	// Randomly add particles into the container
	for(i=0;i<cparticles;i++) {
		tmpr=rndCauchy(0.0,r_min,r_max,cwidth);

		flagx=false;
		do{
		x=rnd();
		if (x*x<= tmpr*tmpr){
			flagx=true;
		}
		}while(flagx==false);

		flagy=false;
		do{
		y=rnd();
		if (y*y<= tmpr*tmpr-x*x){
			flagy=true;
		}
		}while(flagy==false);

		z=sqrt(tmpr*tmpr-x*x-y*y);
		con.put(i,x,y,z);
	}

	for (i=0; i<addparticles;i++){
		x=x_min+rnd()*(x_max-x_min);
		y=y_min+rnd()*(y_max-y_min);
		z=z_min+rnd()*(z_max-z_min);
		con.put(i,x,y,z);
	}

	// Sum up the volumes, and check that this matches the container volume
	double vvol=con.sum_cell_volumes();
	printf("Container volume : %g\n"
	       "Voronoi volume   : %g\n"
	       "Difference       : %g\n",cvol,vvol,vvol-cvol);

	// Output the particle positions in gnuplot format
	con.draw_particles("random_points_p.gnu");

	// Output the Voronoi cells in gnuplot format
	con.draw_cells_gnuplot("random_points_v.gnu");
	
	
	// Output the volume infor for each index
	// copied from find_voro_cell.cc
	c_loop_all vl(con);
	voronoicell c;
	FILE *f1=safe_fopen("find_voro_cell.vol","w");

	//file for EPW k-point list
	FILE *f2=safe_fopen("randompoint.dat","w");
	fprintf(f2,"%d  crystal\n", cparticles+addparticles);
	if(vl.start()) do if (con.compute_cell(c,vl)){
	   vl.pos(i,x,y,z,r);
	   fprintf(f1,"%d %g %g %g %g\n",i,x,y,z,c.volume());
	   fprintf(f2,"%g  %g  %g  %g\n",x,y,z,c.volume());
	   
	} while (vl.inc());
	fclose(f1);
}
