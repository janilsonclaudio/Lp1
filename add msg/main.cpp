#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include "diary.cpp"
using namespace std;

int main(int argc, char *argv[]){
	string mensage;
	string a;
	string day;
	string date = get_current_date();
	string time = get_current_time();
	string time2 = "- ";
	ofstream file;
	string day3 = "# ";
	time2.append(time);
	day3.append(date);
	time2.append(" ");

	file.open("diary.md",ios::app);
	if(!file.is_open()){
		cerr << "arquivo não pode ser criado ou acessado";
		return 1;
	}
	file.close();
	
	if(argc == 1){ //caso o parametro add não tenha sido digitado
		cout << argv[0] << "Uso: add <'mensage'> or list" << endl; //mensagem enviada pelo programa para informar o usuario como o programa deve ser utilizado
		return 1;
 	}
	else if(argc == 2 && strcmp(argv[1],"add") == 0){
		cout << "Digite sua mensage: " << endl;
		getline(cin,mensage);
		add(day3, time2, mensage);
	}
	else if(argc == 3 && strcmp(argv[1],"add") == 0){
		add(day3, time2, argv[2]);
	}
	else if(argc == 2 && strcmp(argv[1],"list") == 0){
		list();
	}
	else{
		cout << argv[0] << "Uso: add <'mensage'> or list" << endl; //mensage enviada pelo programa para informar o usuario como o programa deve ser utilizado
		return 1;
	}
}
