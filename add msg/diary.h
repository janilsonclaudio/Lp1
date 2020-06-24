#ifndef FUCTIONS_H
#define FUCTIONS_H
#include <string>
#include <ctime>

using namespace std;

void create_diary(); //função para criar o arquivo onde as mensagens são armazenadas
void add(string text);
void list();
string format_current_date(const string& format);
string get_current_date();
string get_current_time();


#endif
