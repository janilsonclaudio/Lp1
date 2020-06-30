#ifndef TIME_H
#define TIME_H
#include <ctime>
#include <string>
using namespace std;

string format_current_date(const string& format);
string get_current_date();
string get_current_time();

#endif