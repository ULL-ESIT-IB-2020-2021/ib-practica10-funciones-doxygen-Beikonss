#include "funciones_cripto.h"

std::vector <char> general_vector_for_output{};
char key = '128';
std::string key_2 = "alfa";
std::vector<char> encrypt_storer{};

std::string kHelpText = "./cripto --Cifrado de ficheros\nModo de uso: ./cripto fichero_entrada fichero_salida método password operación\nfichero_entrada: Fichero a codificar\nfichero_salida:  Fichero codificado\nmétodo:          Indica el método de encriptado\n                   1:xor\n                   2:cesar\npassword:        Palabra secreta en el caso de método 1, Valor de K en el método 2\noperación:       Operación a realizar en el fichero\n              +: encriptar el fichero\n               -: desencriptar el fichero";

void encryptDecryptXor(std::string user_string, std::string fichero_salida) {           //Función para encriptado/desencriptado XOR (cogí la palabra de ejemplo, alfa (key_2), como base).  
  std::vector<char> final_encrypt_storer{};                                             //key es el '128' del enunciado, y lo que se usa para encriptar y desencriptar todo lo demás 
  std::ofstream user_file(fichero_salida);

  for (int i = 0; i < key_2.length(); i++) {                    //va a ser la encriptación de key_2 xor 128
	  key_2[i] = key_2[i] ^ key;
	  encrypt_storer.push_back((key_2[i]));
	}

  for (int j = 0, l = 0; j < user_string.length(); j++, l++) {
	  user_string[j] = user_string[j] ^ encrypt_storer[l];
	    if (l == key_2.length() - 1) {
	      l = 0;
	    }
	  final_encrypt_storer.push_back(user_string[j]);
    user_file << (user_string[j]);
  }
std::cout << "Ejecución lista";  
}


void encrypDecryptCesar(std::string user_string, std::string fichero_salida) {      
  std::ofstream user_file(fichero_salida);                              //Función para el encriptado (César). La constate k es 2
  const int k = 2;
  std::vector <char> abecedario{};
  std::vector <char> abecedario_mayusculas{};
  std::vector <char> encrypt_storer{};
  for (char i = 'a', j = 'A'; i <= 'z'; i++, j++) {
	  abecedario.push_back(i);
	  abecedario_mayusculas.push_back(j);
  }
	
  for (int i = 0; i < user_string.length(); i++){
	  for (int j = 0; j <= abecedario.size(); j++) {
	    if (user_string[i] == abecedario[j]) {
		    if (j == abecedario.size()) {
		      j = 0;
		    }
	      user_string[i] = abecedario[j + k];
	      encrypt_storer.push_back(user_string[i]);
        user_file << (user_string[i]);
		    break;
	    }
	    if (user_string[i] == abecedario_mayusculas[j]) {
		    if (j == abecedario_mayusculas.size()) {
		      j = 0;
		    }
		    user_string[i] = abecedario_mayusculas[j + k];
		    encrypt_storer.push_back(user_string[i]);
        user_file << (user_string[i]);
		    break;
	    }
      if (user_string[i] == ' '){
        encrypt_storer.push_back('!');
        user_file << ('!');
        break;
      }

	}
      
}

std::cout << "Ejecución lista";  

    
}


void encrypDecryptCesar(std::string user_string, const int k, std::string fichero_salida) {            //Función para desencriptado (César)

  std::ofstream user_file(fichero_salida);

  std::vector <char> abecedario{};
  std::vector <char> abecedario_mayusculas{};
  std::vector <char> encrypt_storer{};
  for (char i = 'a', j = 'A'; i <= 'z'; i++, j++) {
    abecedario.push_back(i);
	  abecedario_mayusculas.push_back(j);
  }

  for (int i = 0; i < user_string.length(); i++){
	  for (int j = 0; j <= abecedario.size(); j++){
	    if (user_string[i] == abecedario[j]) {
		    if (j == abecedario.size()){
		      j = 0;
		    }
		  user_string[i] = abecedario[j - k];
		  encrypt_storer.push_back(user_string[i]);
      user_file << user_string[i];
		  break;
	    }
	    if (user_string[i] == abecedario_mayusculas[j]) {
		    if (j == abecedario_mayusculas.size()) {
		      j = 0;
		    }
		  user_string[i] = abecedario_mayusculas[j - k];
		  encrypt_storer.push_back(user_string[i]);
      user_file << user_string[i];
		  break;
	    }
      if (user_string[i] == '!'){
        encrypt_storer.push_back(' ');
        user_file << (' ');
        break;
      }
	  }
  }


 
}


void complete_program(std::string texto, std::string metodo_encriptado, std::string operacion, std::string fichero_salida){   //Union de los metodos de desencriptado en una funcion solo, dependiendo del input del usuario

  std::vector<std::string> vector_to_encrypt{};
  std::string line;
  std::ifstream myfile (texto);

  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      vector_to_encrypt.push_back(line);
    }
    myfile.close();
  }

  else std::cout << "Unable to open file"; 

  if(metodo_encriptado == "xor" && operacion == "+" || operacion == "-"){
    for (int i = 0; i<vector_to_encrypt.size(); i++){
      encryptDecryptXor(vector_to_encrypt[i], fichero_salida);
      
    }
  }

  if (metodo_encriptado == "cesar" && operacion == "+"){ 
    for (int i = 0; i<vector_to_encrypt.size(); i++){
      encrypDecryptCesar(vector_to_encrypt[i], fichero_salida);
      
    }
  }

  if (metodo_encriptado == "cesar" && operacion == "-"){ 
    for (int i = 0; i<vector_to_encrypt.size(); i++){
      encrypDecryptCesar(vector_to_encrypt[i], 2, fichero_salida);
      
    }
  }
}



std::string char_pointer_to_string(char* caracter, std::string to_store_string){

char* pStr = caracter;
to_store_string = pStr;

return to_store_string;

}


void usage(int argc, char* argv[]) {        //Función para imprimerle al usuario el uso del programa 

  if (argv[1]){
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << kHelpText << std::endl;
      exit(EXIT_SUCCESS);
    }
  }

  
  if (argc != 6 && argv[1] != "--help" || argc < 1) {
    std::cout << argv[0] << ": --Cifrado de ficheros" << std::endl << "Modo de uso: ./cripto fichero_entrada fichero_salida metodo_encriptado password operacion" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }

}

void word_counter(std::string textfile){

  std::vector<std::string> vector_to_analise{};
  std::string line;
  std::ifstream myfile (textfile);
  int numero_letras = 0;

  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      vector_to_analise.push_back(line);
    }
    myfile.close();
  }

  for (int i = 0; i<vector_to_analise.size(); i++){
    for (int j = 0; j<vector_to_analise[i].length(); j++){
      if(vector_to_analise[i][j] == 'u'){
        numero_letras = numero_letras +1;
      }
    }
  }
  std::cout << "El numero de letras U que hay es de : " << numero_letras;


}