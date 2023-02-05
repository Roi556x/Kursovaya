/**
* @file main.h
* @author Рогашевский А.В.
* @version 1.0
* @brief Пользователский интерфейс и работа программы
* @date 06.02.2023
* @copyright ИБСТ ПГУ
*/
#include <iostream>
#include <getopt.h>
#include <string>
#include <bitset>
#include <fstream>
#include "Client.h"
using namespace std;
int main(int argc, char *argv[]) 
{
Client conn;
setlocale(LC_ALL, "Rus");
     if (argc==1)
        {
            cout<<"            ПРОГРАММА КЛИЕНТА"<<endl;
            cout<<"__________________________________________________"<<endl;
            cout<<"Параметры запуска программы:"<<endl;
            cout<<"Файл с векторами: -s"<<endl;
            cout<<"Файл результата: -r"<<endl;
            cout<<"Имя пользователя: -u"<<endl;
            cout<<"Пароль пользователя: -p"<<endl;
            cout<<"Адресс сервера: -a"<<endl;
            cout<<"Порт сервера: -d"<<endl;
        }
    string portcon, ip_adr;

    int opt;
    while ((opt = getopt (argc, argv, "hr:s:u:p:a:d:")) != -1)
        {
        switch (opt) 
            {
                case'?':
                    throw error_client(string("Параметр задан неверно или он не существует"));
                break;
	    case 'h':
            cout<<"            ПРОГРАММА КЛИЕНТА"<<endl;
            cout<<"__________________________________________________"<<endl;
            cout<<"Параметры запуска программы:"<<endl;
            cout<<"Файл с векторами: -s"<<endl;
            cout<<"Файл результата: -r"<<endl;
            cout<<"Имя пользователя: -u"<<endl;
            cout<<"Пароль пользователя: -p"<<endl;
            cout<<"Адресс сервера: -a"<<endl;
            cout<<"Порт сервера: -d"<<endl;   
	    break;
             
            case 'r':
            conn.name_result_file=string(optarg);
            break;


           case 's': 
            conn.name_original_file=string(optarg);
            break;
            
            
            
            
            case 'u':
            if(optarg!=0)
            {
                conn.username= string(optarg);
                cout<<"Username is: "<<conn.username<<endl;
            }
            break;
            
            
            
            case 'p':
                if(optarg!=0)
                {
                    conn.password = string(optarg);
                    cout<<"Password is: "<<conn.password<<endl;
                }
            break;
            
            
            
            case 'a':
                if(optarg!=0)
                {
                    ip_adr= string(optarg);
                    cout<<"Adress is: "<<ip_adr<<endl;
                }
            break;
            
            
            
            case 'd':
            if (optarg!=0)
            {
                portcon = string(optarg);
                cout<<"Port is: "<<portcon<<endl;
                
            }
            break;
            
            
            }
             
        }
              
            conn.connection(ip_adr, portcon, conn.username, conn.password, conn.name_original_file, conn.name_result_file);
    }