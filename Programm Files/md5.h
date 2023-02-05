#include <iostream>
#include <vector>
#include <cryptopp/hex.h> // HexEncoder
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h> // MD%, для другого алгоритма - другой заголовочный файл
/**
* @brief Получение хэша по алгоритму md5
* @param hesh сообщения получаемое для хэширования
* @return Полученный хэш
*/

using namespace std;
string MD5_hash(string msg);