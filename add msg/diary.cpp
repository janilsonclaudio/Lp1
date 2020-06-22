#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
using namespace std;

std::string format_current_date(const std::string& format){
	std::time_t time = std::time(nullptr);
	char result[1024];
	std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));
	return std::string(result);
}
std::string get_current_date(){
	return format_current_date("%d/%m/%Y");
}
std::string get_current_time(){
	return format_current_date("%H:%M:%S");
}

int main(int argc, char *argv[]){
	string mensage;
	string a;
	string day;
	string date = get_current_date();
	string time = get_current_time();
	string time2 = "- ";
	ofstream day1;
	string day3 = "# ";
	int tam;
	int x = 1;
	time2.append(time);
	day3.append(date);
	time2.append(" ");

	day1.open("diary.md",ios::app);
	if(!day1.is_open()){
		cerr << "arquivo não pode ser criado ou acessado";
		return 1;
	}
	day1.close();
	
	if(argc == 1){ //caso o parametro add não tenha sido digitado
		cout << argv[0] << "Uso: add <'mensage'> or list" << endl; //mensagem enviada pelo programa para informar o usuario como o programa deve ser utilizado
		return 1;
 	}
	else if(argc == 2 && strcmp(argv[1],"add") == 0){
		cout << "Digite sua mensage: " << endl;
		
		ifstream day2;
		day2.open("diary.md");
		if(!day2.is_open()){
			cerr << "arquivo não pode ser criado ou acessado";
			return 1;
		}
		while(!day2.eof()){
			getline(day2, day);
			if(day3.compare(day) == 0){
				x = 0;
				break;
			}
		}
		day2.close();
		ofstream writer;
		writer.open("diary.md",ios::app);
		if(!writer.is_open()){
			cerr << "arquivo não pode ser criado ou acessado";
			return 1;
		}
		if(x == 1){
			writer << day3 << endl;
		}
		getline(cin, mensage);
		writer << time2 << mensage << endl;
		writer.close();
		cout << "Mensagem Adicionada" << endl;
		return 0;
	}
	else if(argc == 3 && strcmp(argv[1],"add") == 0){
		string day3;
		ifstream day2;
		day2.open("diary.md");
		if(!day2.is_open()){
			cerr << "arquivo não pode ser criado ou acessado";
			return 1;
		}
		while(!day2.eof()){
			getline(day2, day);
			if(day3.compare(day) == 0){
				x = 0;
				break;
			}
		}
		day2.close();
		ofstream writer;
		writer.open("diary.md",ios::app);
		if(!writer.is_open()){
			cerr << "arquivo não pode ser criado ou acessado";
			return 1;
		}
		if(x == 1){
			writer << day3 << endl;
		}
		writer << time2 << argv[2] << endl;
		writer.close();
		cout << "Mensagem Adicionada" << endl;
		return 0;
	}
	else if(argc == 2 && strcmp(argv[1],"list") == 0){
		
		ifstream reader;
		reader.open("diary.md", ios::app);
		if(!reader.is_open()){
			cerr << "arquivo não pode ser acessado";
			return 1;
		}
		while(!reader.eof()){
			getline(reader, mensage);
			tam=mensage.size();
			a = mensage.front();
			if(a.compare("-") == 0){
				cout << mensage << endl;
			}
			if(mensage.size() == 0){
				break;
			}
		}
		reader.close();
	}
	else{
		cout << argv[0] << "Uso: add <'mensage'> or list" << endl; //mensage enviada pelo programa para informar o usuario como o programa deve ser utilizado
		return 1;
	}
}