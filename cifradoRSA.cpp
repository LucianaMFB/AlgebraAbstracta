#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

long long inverso(long long a, long long mod) {
   long long m0 = mod, t, q;
   long long x0 = 0, x1 = 1;
   
   while (a > 1) {
      q = a / mod;
      t = mod;
      mod = a % mod;
      a = t;
      t = x0;
      x0 = x1 - q * x0;
      x1 = t;
   }
   
   if (x1 < 0) x1 += m0;
   return x1;
}

vector<int> coversionANumeros(string caracteres)
{
   string frase;
   vector<int> caracteresNum;
   
   cout << "Ingrese frase: ";
   cin >> frase;
   
   for (int i = 0; i < frase.length(); i++) {
      size_t pos = caracteres.find(frase[i]); 
      caracteresNum.push_back(pos);
   }
   
   return caracteresNum;
}

int calcular_e (int temp)
{
   int e = -1;
   cout << " Ingrese un numero entre 1 y " << temp << ": ";
   cin >> e;
   
   while ( gcd(e, temp) != 1 ) {
      cout << " No son COPRIMOS ingrese un numero entre 1 y " << temp << ": ";
      cin >> e;
   }
   
   return e;
}

int algoritmoExpoRapida(long long base, long long exponente, int modulo)
{
   long long resultado = 1;
   
   while (exponente > 0) {
      if (exponente % 2 != 0) {
         resultado *= base;
      }
      base *= base;
      exponente /= 2;
   }
   
   return resultado % modulo;
}

void print(vector<int> caracteresNum) {
   for (int j = 0; j < caracteresNum.size(); j++) {
      std::cout << caracteresNum[j] << " ";
   }
   std::cout << std::endl;
}

void cifradoRSA() {
   string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-*=!¡?¿$%,.;";
   int p = 317;
   int q = 197;
   int temp = (p - 1)*(q - 1);
   vector<int> caracteresNum = coversionANumeros(caracteres);
   print(caracteresNum);
   
   int n = p * q;                   // LLAVE PUBLICA
   int e = calcular_e (temp);       // LLAVE PUBLICA
   int d = inverso(e, temp);        // LLAVE PRIVADA
   
   
}

int main() {
   cifradoRSA();
   
   
   
   

   return 0;
}
