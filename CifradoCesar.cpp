#include <iostream>
#include <string>

std::string cifrar(std::string& cadena, const int & llave)
{
    int tam = cadena.length();
    std::cout << " MENSAJE ORIGINAL: " << cadena << std::endl;
    
    for(int i = 0; i < tam; i++)
    {
        char caracter = cadena[i];
        cadena[i] = caracter + llave;
        
        if(caracter == 122 || caracter == 90)
        {
            cadena[i] = caracter - 25 * llave;
        }
        
        else if (caracter == 32)
        {
            cadena[i] = caracter;
        }
    }

    std::cout << " MENSAJE CIFRADO: " << cadena << std::endl;

    return cadena;
}

std::string descifrar(std::string& cadena, const int & llave)
{
    int tam = cadena.length();
    
    for(int i = 0; i < tam; i++)
    {
        char caracter = cadena[i];
        cadena[i] = caracter - llave;
        
        if(caracter == 122 || caracter == 90)
        {
            cadena[i] = caracter + 25 * llave;
        }
        
        else if (caracter == 32)
        {
            cadena[i] = caracter;
        }
    }
    
    std::cout << " MENSAJE DESCIFRADO: " << cadena << std::endl;
    return cadena;
}

int main()
{
    std::string cadena("Buenos dias");
    cadena = cifrar(cadena, 1);
    descifrar(cadena,1);
    return 0;
}
