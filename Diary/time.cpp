#include "time.h"
#include <ctime>
#include <string>
using namespace std;

string format_current_date(const string& format)
{
time_t time = std::time(nullptr);
char result[1024];
strftime(result, sizeof(result), format.c_str(), localtime(&time));
return string(result);
}
string get_current_date()
{
return format_current_date("#%d/%m/%Y");
}
string get_current_time()
{
return format_current_date("- %H:%M:%S: ");
}
