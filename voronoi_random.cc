// Voronoi calculation example code
//
// Author   : Chris H. Rycroft (LBL / UC Berkeley)
// Email    : chr@alum.mit.edu
// Date     : August 30th 2011

#include "voro++.hh"
#include <random>
#include <fstream>
using namespace voro;


// Set up constants for the container geometry
const double x_min=-1,x_max=1;
const double y_min=-1,y_max=1;
const double z_min=-1,z_max=1;
const double cvol=(x_max-x_min)*(y_max-y_min)*(x_max-x_min);

// Set up the number of blocks that the container is divided into
const int n_x=6,n_y=6,n_z=6;

// Set the number of particles that are going to be randomly introduced
const int particles=20;

// This function returns a random double between 0 and 1
double rnd() {return double(rand())/RAND_MAX;}

double rndCauchy(double x, double y, double z){
    std::random_device rnd;
	std::mt19937 mt(rnd());
	std::cauchy_distribution<double> rndx(x, 0.5);
	std::cauchy_distribution<double> rndy(y, 0.5);
	std::cauchy_distribution<double> rndz(z, 0.5);

	bool flagx, flagy,flagz;
	flagx=false;
	flagy=false;
	flagz=false;



	do{
		double rx=rndx(mt);
		if (x_min<=rx && rx<= x_max){
			flagx=true;
		}
	}while(flagx==false);

	do{
		double ry=rndy(mt);
		if (y_min<=ry && ry<= y_max){
			flagy=true;
		}
	}while(flagy==false);

	do{
		double rz=rndz(mt);
		if (z_min<=rz && rz<= z_max){
			flagz=true;
		}
	}while(flagz==false);


}

int main() {
	int i;
	double x,y,z,r;

	// Create a container with the geometry given above, and make it
	// periodic in each of the three coordinates. Allocate space for
	// eight particles within each computational block
	container con(x_min,x_max,y_min,y_max,z_min,z_max,n_x,n_y,n_z,
			true,true,true,8);

	// Randomly add particles into the container
	for(i=0;i<particles;i++) {
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
	if(vl.start()) do if (con.compute_cell(c,vl)){
	   vl.pos(i,x,y,z,r);
	   fprintf(f1,"%d %g %g %g %g\n",i,x,y,z,c.volume());
	   
	} while (vl.inc());
	fclose(f1);
}
