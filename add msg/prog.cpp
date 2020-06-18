#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
	string mensage;
	if(argc == 1){ //caso o parametro add não tenha sido digitado
		cout << argv[0] << "Uso: add <'mensage'> or list" << endl; //mensage enviada pelo programa para informar o usuario como o programa deve ser utilizado
		return 1;
 	}
	else if(argc == 2 && strcmp(argv[1],"add") == 0){
		cout << "Digite sua mensage: " << endl;
		getline(cin, mensage);
		ofstream writer;
		writer.open("diary.txt",ios::app);
		if(!writer.is_open()){
			cerr << "arquivo não pode ser criado ou acessado";
			return 1;
		}
		writer << mensage << endl;
		writer.close();
		cout << "Mensagem Adicionada" << endl;
		return 0;
	}
	else if(argc == 3 && strcmp(argv[1],"add") == 0){
		mensage = argv[2];
		ofstream writer;
		writer.open("diary.txt",ios::app);
		if(!writer.is_open()){
			cerr << "arquivo não pode ser criado ou acessado";
			return 1;
		}
		writer << mensage << endl;
		writer.close();
		cout << "Mensagem Adicionada" << endl;
		return 0;
	}
	else if(argc == 2 && strcmp(argv[1],"list") == 0){
		string text;
		ifstream reader;
		reader.open("diary.txt");
		if(!reader.is_open()){
			cerr << "arquivo não pode ser acessado";
			return 1;
		}
		while(!reader.eof()){
			getline(reader, text);
			if(text.size() == 0){
				break;
			}
			cout << text << endl;
		}
		reader.close();
	}
	else{
		cout << argv[0] << "Uso: add <'mensage'> or list" << endl; //mensage enviada pelo programa para informar o usuario como o programa deve ser utilizado
		return 1;
	}
}