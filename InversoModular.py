from math import gcd

numero = 7
modulo = 90

if gcd(numero, modulo) != 1:
  print("MCD =", gcd(numero, modulo) , "  No son primos :(")

else:
  inverso = pow(numero, -1, modulo)
  print("INVERSO =",inverso)
