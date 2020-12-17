#include "funciones_cripto.h"


int main(int argc, char* argv[]){

  usage(argc, argv);

  std::string text_file;
  std::string fichero_entrada = char_pointer_to_string(argv[1], text_file);
  std::string metodo_encriptado = char_pointer_to_string(argv[3], text_file);
  std::string fichero_salida = char_pointer_to_string(argv[2], text_file);
  std::string password = char_pointer_to_string(argv[4], text_file);
  std::string operacion = char_pointer_to_string(argv[5], text_file);

  if (argc == 6){
    if(metodo_encriptado == "cesar" && password == "2" || metodo_encriptado == "xor" && password == "alfa"){
      complete_program(fichero_entrada, metodo_encriptado, operacion, fichero_salida);
      std::cout << std::endl;
    }
  }

  return 0;

}

