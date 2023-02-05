
/**
 * @file Client.cpp
 * @brief Файл взаимодействие с сервером
 */
/**
* @file main.h
* @author Рогашевский А.В.
* @version 1.0
* @brief Описание класса Client
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
#include "md5.h"
#include "Client.h"
#include <bitset>
using namespace std;
 // тут ещё вычисление соли и хэша
void Exception(const string & why, const int exitCode ) // Исключения (возможные ошибки)
{
    cout << "ErrorCode:"<<exitCode <<endl<< why << endl;
    exit(exitCode);
}

 
    /// @brief описания функции подключения клиента к серверу
int Client::connection(string ip_adr, string portcon, string username, string password, string name_original_file, string name_result_file)
{
    /**
    * @brief подключение клиента к серверу и передача данных
    * @param ip_adr айпи по которому устанавливается соединение
    * @param portcon порт по которому устанавливается соединение
    * @param username логин клиента
    * @param password пароль клиента
    * @param name_original_file файл с векторами для передачи серверу на обработку
    * @param name_result_file файл для записи результатов обработки и отправки сервера клиенту
 
    *@details
 
  
 
    *утсановка порта по умолчанию
    *@code
    *if(portcon == "") {
    *    portcon = "33333";
    *}
    *@endcode
    *Инициализация айпи
    * @code
    *char* ip_chars = new char[ip_adr.length()];
    *ip_adr.copy(ip_chars, ip_adr.length());
    *ip_chars[ip_adr.length()] = '\0';
    * @endcode
    *Инициализируем переменную для порта
    * @code
    *unsigned int portik;
    *portik = stoi(portcon);
    *@endcode 
    * Создаём структуру с введённым адресом и портом
    * @code
    *sockaddr_in * selfAddr = new (sockaddr_in);
    *selfAddr->sin_family = AF_INET; // интернет протокол IPv4
    *selfAddr->sin_port = 0;
    *selfAddr->sin_addr.s_addr = 0;
    *
    *
    *sockaddr_in * remoteAddr = new (sockaddr_in);
    *remoteAddr->sin_family = AF_INET;     // интернет протокол IPv4
    *remoteAddr->sin_port = htons(portik);
    *remoteAddr->sin_addr.s_addr = inet_addr(ip_chars); //  адрес
    * @endcode
    * буфер для передачи и приема данных
    * @code
    *char *buffer = new char[4096];
    *strcpy(buffer,username.c_str());
    * @endcode
    *вычисляем длину строки
    * @code
    *int msgLen = strlen(buffer);      
    * @endcode
    *
    * создаём сокет
    * @code
    *int mySocket = socket(AF_INET, SOCK_STREAM, 0); //tcp протокол
    * @endcode
    *
    *связываем сокет с адрессом
    * @code
    *int rc = bind(mySocket,(const sockaddr *) selfAddr, sizeof(sockaddr_in));
    * @endcode
    *
    *установливаем соединение
    * @code
    *rc = connect(mySocket, (const sockaddr*) remoteAddr, sizeof(sockaddr_in));
    * @endcode
    *
    *Проверка соединения клиента с сервером
    * @code
    *if (rc == -1) {
    *cout << "Error: failed connect to server.\n";
    *close(mySocket);
    *return 1;
    *}
    *else cout<<"Connection is succesful"<<endl;
    * @endcode
    *Отправка логина серверу
    * @code
    *rc = send(mySocket, buffer, msgLen, 0);
    *if(rc==-1)
    *{
    *     throw error_client(string("Ошибка отправки логина"));
    *}
    *cout << "Мы отправляем логин: " << buffer << endl;
    * @endcode
    *
    * принимаем ответ в буффер
    * @code
    *rc = recv(mySocket, buffer, 4096, 0);
    *if(rc==-1)
    *{
    *     throw error_client(string("Ошибка получения ответа"));
    *}
    *string s1 = string(buffer);
    *buffer[rc] = '\0'; // конец принятой строки
    *
    *cout << "Мы получаем соль: " << buffer << endl; // вывод полученного сообщения от сервера
    * @endcode
    * 
    * Далее генерируется хэш и отправляется серверу
    * @code
    *
    *string s2;
    *string msg = s1 + password;
    *s2 = MD5_hash(msg);
    *
    *strcpy(buffer,s2.c_str());
    *rc = send(mySocket, buffer, s2.length(), 0);
    *cout << "Мы отправляем хэш: " << buffer << endl;
    * @endcode
    *
    *
    * Получене ответа об аутентификации
    * @code
    *rc = recv(mySocket, buffer, sizeof(buffer), 0);
    *buffer[rc] = '\0'; // конец принятой строки
    *if(rc==-1)
    *{
    *     throw error_client(string("Ошибка получения ответа"));
    *}
    *cout << "Мы получаем ответ: " << buffer << endl; // вывод полученного сообщения от сервера
    * @endcode
    *Открытие файла для записи результата 
    * @code
    *ofstream fout(name_result_file, ios::binary | ios::out | ios::app);
    *if(!fout)
    *{
    *    throw error_client(string("Ошибка открытия файла"));
    *}
    *endcode
    * Далее открывается файл с векторами для отправки
    * @code
    *uint32_t n;
    *FILE *f; //описываем файловую переменную
    *const char * c = name_original_file.c_str(); //конвертируем строку с названием файла с векторами в const char *
    *f=fopen(c, "rb");
    *if(f==NULL)
    *    {
    *        throw error_client(string("Ошибка открытия файла"));
    *   }
    * endcode
    *считываем из файла одyо целое число в переменную n которое является количеством векторов
    * @code
    *fread(&n, sizeof(uint32_t), 1, f);
    *@endcode
    *
    * отправка количества векторов на сервер
    * @code
    *rc = send(mySocket, &n, sizeof(n), 0);
    * @endcode
    *cout << "Мы отправляем кол-во векторов: " << n << endl; // вывод полученного сообщения от сервера
    *fout<<n<<endl;
    * далее идёт отправка количество чисел, содержащиеся в векторе
    * @code
    *for(int i=0; i<n; i++)
    *{
    *uint32_t size;
    *double d;
    *    fread(&size, sizeof(uint32_t), 1, f);
    *    uint32_t size1;
    *    size1=(4+size*sizeof(size));
    *    cout<<"Размер  "<<i+1<<"-го  вектора  "<<size1<<" байт"<<endl;
    *    send(mySocket, &size, sizeof(size), 0);//отправка размера вектора
    *    
    *@endcode
    *далее отправляются сами векторы массивом на сервер
    *@code
    *    double array[size]={0};
    *    cout<<"Векторы в строке  ";
    *    for(int j=0;j<size;j++)
    *    {
    *        fread(&d, sizeof(double), 1, f);
    *        array[j]=d;                 //заполнение вектора в массив
    *        cout<<d<<"   ";     //вывод вектора в строке
    *    }
    *    cout<<endl;
    *    send(mySocket, &array, sizeof(array), 0);
    *    cout << "Мы отправляем сам вектор: " << array << endl; // вывод полученного сообщения от сервера
    *    double sum = 0;
    *    recv(mySocket, &sum, sizeof(sum), 0);
    *    cout << "Мы получаем ответ: " << sum << endl; // вывод полученного сообщения от сервера
    *    fout <<sum<< endl;
    *@endcode
    *}
    * После обмена файлами закрываются сокет и файлы
    * @code
    *close(mySocket);
    * fout.close();
    * @endcode    
    * </p>
    *
    *return 0;
    */
}