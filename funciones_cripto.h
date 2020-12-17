#include <bitset>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

/**
* @file cripto.cc
* @brief El programa encripta o desencripta ficheros que el usuario pase por línea de comandos
*        haciendo uso del encriptado xor o del encriptado césar, dependiendo de lo que
*        se quiera. El texto encriptado se crea en un fichero de texto de nombre el que
*        de el usuario. Para desencriptar hace falta conocer la palabra secreta en el caso
*        del encriptado xor o el número de encriptado en el caso del método César.
* @bug No hay bugs conocidos
* @file funciones_cripto.cc
* @brief Fichero donde están todas las definiciones de funciones a utilizar.
* @bug No hay bugs conocidos
* @file funciones_cripto.h
* @brief Fichero header donde están las declaraciones de las funciones  y la documentación del programa.
* @bug No hay bugs conocidos
* @author F.Javier Viña Rodríguez alu0101217536@ull.edu.es
* @date 17 Dec 2020
*/


void encrypDecryptCesar(std::string user_string,  std::string fichero_salida);                             ///función para encriptar con el método césar. Es distinta a void encrypDecryptCesar(std::string user_string, const int k, std::string fichero_salida), que es para desencriptar (pide el número secreto).
void encrypDecryptCesar(std::string user_string, const int k, std::string fichero_salida);                ///Desencriptado César
void encryptDecryptXor(std::string user_string,  std::string fichero_salida);                        ///es la función que permite encriptar o desencriptar texto mediante el método xor. En este caso no pide la palabra secreta directamente, sino que se pide en el main (cripto.cc).
void complete_program(std::string texto, std::string metodo_encriptado, std::string operacion,  std::string fichero_salida); ///es la unión de las 3 funciones anteriores. Dependiendo de los parámetros que de el usuario, va a ejecutar una de las 3. De esta manera creo que queda más limpio el fichero main.
std::string char_pointer_to_string(char* caracter, std::string to_store_string); ///es una función simple para pasar el argv[] a string, que es lo que piden las funciones anteriores.
void usage(int argc, char* argv[]); ///manual para la ejecución del programa.
void word_counter(std::string text_file);


