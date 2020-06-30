#include "diary.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void make_file(char* o){
    ofstream arquivo;
    arquivo.open(o ,ios::app);
	if(!arquivo.is_open()){
		cout << "arquivo não pode ser criado ou acessado";
	}
	arquivo.close();
}
void add(string day1, string time, string text){
    ifstream dayfile;
    string day;
    int x =1;
	dayfile.open("diary.md");
	if(!dayfile.is_open()){
		cerr << "arquivo não pode ser criado ou acessado";
	}
	while(!dayfile.eof()){
		getline(dayfile, day);
		if(day1.compare(day) == 0){
			x = 0;
			break;
		}
	}
	dayfile.close();
	ofstream writer;
	writer.open("diary.md",ios::app);
	if(!writer.is_open()){
		cerr << "arquivo não pode ser criado ou acessado";
	}
	if(x == 1){
		writer << day1 << endl;
	}
	writer << time << text << endl;
	writer.close();
	cout << "Mensagem Adicionada" << endl;
}
void list(){
    ifstream reader;
    string a;
    string text;
	reader.open("diary.md", ios::app);
	if(!reader.is_open()){
		cerr << "arquivo não pode ser acessado";
	}
	while(!reader.eof()){
		getline(reader, text);
		a = text.front();
		if(a.compare("-") == 0){
			cout << text << endl;
		}
		if(text.size() == 0){
			break;
		}
	}
	reader.close();
}
