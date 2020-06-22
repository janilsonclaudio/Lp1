#ifndef FUCTIONS_H
#define FUCTIONS_H
#include <string>

struct diary{
    std::string date;
    std::string time;
    std::string mensage;
    void create_diary(); //função para criar o arquivo onde as mensagens são armazenadas
    void add(std::string text);
    void list();
    std::string format_current_date(const std::string& format);
    std::string get_current_date();
    std::string get_current_time();
};

#endif