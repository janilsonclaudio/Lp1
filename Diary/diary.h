#ifndef DIARY_H
#define DIARY_H
#include <string>
#include <ctime>

using namespace std;

void make_file(); //função para criar o arquivo onde as mensagens são armazenadas
void add(string day, string time, string text);
void list();

#endif
