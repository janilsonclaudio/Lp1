#include <iostream>
#include <string>
#include <string.h>

int main(int argc, char *argv[]){
	std::string mensagem;
	if(argc == 1){ //caso o parametro add não tenha sido digitado
		std::cout << argv[0] << "Uso: <add 'mensagem'>" << std::endl; //mensagem enviada pelo programa para informar o usuario como o programa deve ser utilizado
		return 1;
 	}
	else if(argc == 2 && strcmp(argv[1],"add") == 0){
		std::cout << "Digite sua mensagem: " << std::endl;
		std::getline(std::cin, mensagem);
		std::cout << "Mensagem Adicionada" << std::endl;
		return 0;
	}
	else if(argc == 3 && strcmp(argv[1],"add") == 0){
		mensagem = argv[2];
		std::cout << "Mensagem Adicionada" << std::endl;
		return 0;
	}
	else{
		std::cout << argv[0] << "Uso: <add 'mensagem'>" << std::endl; //mensagem enviada pelo programa para informar o usuario como o programa deve ser utilizado
		return 1;
	}
}