# -*- coding: utf-8 -*-
"""
Created on Fri Jul 20 15:57:09 2018

@author: Emi Minamitani
checling the output of Voronoi + Cauchy distribution
"""
import math
import matplotlib.pyplot as plt
fvoro=open("find_voro_cell.vol","r")

dist=[]
for i in fvoro:
    tmp=i.split()
    #print(tmp)
    x=float(tmp[1])
    y=float(tmp[2])
    z=float(tmp[3])
    r=math.sqrt(x*x+y*y+z*z)
    dist.append(r)

#print(dist)
plt.hist(dist,bins=100)


    