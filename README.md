# voronoisample
test code to generate Volonoi sampling for EPW input


The main program is "voronoi_random.cc".
The sampling points generate with normal random sampling and cauchy distribution is determined by
```
// Set the number of particles using cauchy random distribution
const int cparticles=10000;
// number of particles purely gnerated by random agorithm
const int addparticles=10000;
```
Here, 10000 points are generated from normal random distribution and 10000 points are generated along the cauchy distribution.
The histgram of the distribution of the point can be checked by "histgram.py"
The 3d plot of sampling point can be visualized by gnuplot using the following command

```
splot 'random_points_p.gnu' u 2:3:4 with points
```
Volo++ use std+11 thus, in some Linux system, you may need to activate devtool-set2 by 

```
scl enable devtoolset-2 bash
```
