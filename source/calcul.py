from sympy import *
import sympy
import math
import matplotlib.pyplot as plt
import numpy as np


with open('f(x).txt',"r") as fil:
     f= fil.readline()
     a = int(fil.readline())
     r = int(fil.readline())
      

qq = Symbol("x")

#f = input("enter f : ")
#a = input("enter a : ")
#r = input("enter r :  ")

f= sympy.sympify(f)



s = str(int(f.subs([(qq,a)]).evalf()))


for l in range(1,int(r)+1):
  fprim = diff(f,qq,l)
  kk= (qq-int(a))**int(l)
  s += "+(" + str(fprim)+")*("+str(sympy.sympify(kk))+")/("+ str(math.factorial(l)) + ")"
  o = sympy.sympify(s)
with open("f(x)'.txt","w") as file:
        file.write(s)







with open("f(x)'.txt","r") as file:
        fx = file.readline()


fx =sympy.sympify(fx)


v=0.0


x = str(f).find("log(x)")
if (x >-1) :
        if (float(a)-5 <=0 ):
                v=0.1
        else:
                v=float(float(a)-5)
else:
  v=float(float(a)-5)

with open("point fx prime.txt","w") as file:
       
      
       for i in range(1 , 110):
          
           ii="{:.2f}".format(float(fx.subs([(qq,v)])))
           if (len(str(ii)) < 7):
            file.writelines(str( ii + "\n"))
           v+=0.1
####################################################################
with open("a.txt","w") as file:
        file.write(str(a))



###############################################
x = str(f).find("log(x)")
if (x >-1) :
        if (float(a)-5 <=0 ):
                v=0.1
        else:
                v=float(float(a)-5)
                print(v)
else:
                      v=float(float(a)-5)              
       
with open("point fx .txt","w") as file:
       
       
       for i in range(1 , 110):
               idi="{:.2f}".format(float(f.subs([(qq,v)])))
               file.writelines(str( idi + "\n"))
               v+=0.1
               




x = str(f).find("log(x)")
if (x >-1) :
        if (float(a)-5 <=0 ):
                v=0.1
        else:
                v=float(float(a)-5)
else:
                      v=float(float(a)-5)
with open("f x point.txt","w") as file:
       
       
       for i in range(1 , 110):
               
               file.writelines(str( str(round(v,2)) + "\n"))
               v+=0.1
               print(v)

print(a)
with open("f a point.txt","w") as filte:
   op="{:.2f}".format(float(f.subs([(qq,a)])))
   filte.write(str(op))
   print(op)




