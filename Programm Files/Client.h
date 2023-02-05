/**
* @file header.h
* @author Рогашевский А.В.
* @version 1.0
* @brief Описание классов, подключение библиотек и переменных
* @date 06.02.2023
* @copyright ИБСТ ПГУ
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //exit()
#include <cstring> // strpy()
#include <unistd.h> //close()
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
using namespace std;
 /// @brief Класс в котором находятся переменные и функция для подключения клиента к серверу
class Client
{
public:

    string name_original_file;
    string name_result_file;
    string name_auto_file;
    string username;
    string password;
    string ip_adr;
    int portcon;
    int connection(string ip_adr, string portcon, string username, string password, string name_original_file, string name_result_file);
};
///@brief Класс для обработки ошибок возникающих при работе клиента
class error_client:
    public invalid_argument
    {
public:
    explicit error_client (const string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit error_client (const char* what_arg):
        std::invalid_argument(what_arg) {}
};