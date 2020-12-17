#include <bitset>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


void encrypDecryptCesar(std::string user_string,  std::string fichero_salida);                             //Encriptado César
void encrypDecryptCesar(std::string user_string, const int k, std::string fichero_salida);                //Desencriptado César
void encryptDecryptXor(std::string user_string,  std::string fichero_salida);                        //Encriptado/desencriptado XOR
void complete_program(std::string texto, std::string metodo_encriptado, std::string operacion,  std::string fichero_salida);
std::string char_pointer_to_string(char* caracter, std::string to_store_string);
void usage(int argc, char* argv[]);


