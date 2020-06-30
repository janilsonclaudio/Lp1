#include <iostream>
#include <string>
#include <cstring>
#include "time.h"
#include "time.cpp"
#include "diary.cpp"

int main(int argc, char* argv[]){
//não consegui entende bem como o usuario vai pegar o nome do arquivo, por isso fiz da seguinte forma: 
//argv[1]- nome do arquivo(com .md no final)
//argv[2]- função: add ou list
//argv[3]- caso a função seja add, deve ser colocada a mensagem desejada, se for list não tem nada
    string day = get_current_date();
    string time = get_current_time();
    string message;
    
    make_file(argv[1]);

	if(argc == 1){ //caso o parametro add não tenha sido digitado
		cout << argv[0] << "Uso: <'file_name.md'> add <'mensage'> or list" << endl; //mensagem enviada pelo programa para informar o usuario como o programa deve ser utilizado
		//delete[] 
        return 1;
 	}
	else if(argc == 3 && strcmp(argv[2],"add") == 0){
		cout << "Digite sua mensage: " << endl;
		getline(cin, message);
		add(day, time, message);
        return 0;
	}
	else if(argc == 4 && strcmp(argv[2],"add") == 0){
        add(day, time, argv[3]);
        return 0;
    }
	else if(argc == 3 && strcmp(argv[2],"list") == 0){
		list();
        //delete[] 
        return 0;
	}
	else{
		cout << argv[0] << "Uso: add <'mensage'> or list" << endl; //mensage enviada pelo programa para informar o usuario como o programa deve ser utilizado
		//delete[] 
        return 1;
	}
}