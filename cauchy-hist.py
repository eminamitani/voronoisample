# -*- coding: utf-8 -*-
"""
Created on Fri Jul 20 16:13:04 2018

@author: Emi Minamitani
"""

import math
import matplotlib.pyplot as plt
fvoro=open("cauchy.dat","r")

dist=[]
for i in fvoro:
    dist.append(float(i))

#print(dist)
plt.hist(dist,bins=50)


    