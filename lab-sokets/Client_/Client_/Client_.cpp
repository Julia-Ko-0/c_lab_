
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <inaddr.h>
#include <stdio.h>
#include <vector>
#pragma comment(lib, "ws2_32.lib")

using namespace std;
int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru_RU");
	//	//Ключевые константы
	//Введите IP-адрес локального сервера
	const char SERVER_IP[] = "192.168.66.242";				
	//	// Введите открытый порт рабочего сервера
	const short SERVER_PORT_NUM = 1;		
	//	// Максимальный размер буфера для обмена информацией между сервером и клиентом
	const short BUFF_SIZE = 1024;					
	//	//Ключевые переменные для всей программы
	int erStat;	// Сохраняет статус ошибки сокета
	//	//IP-адрес в строковом формате преобразуется в числовой формат для функций сокета. 
	//	// Данные указаны в "ip_to_num".
	in_addr ip_to_num;
	inet_pton(AF_INET, SERVER_IP, &ip_to_num);
	//	//Инициализация WinSock
	WSADATA wsData;
	erStat = WSAStartup(MAKEWORD(2, 2), &wsData);
	if (erStat != 0) {
		cout << " Ошибка при инициализации версии WinSock # ";
		cout << WSAGetLastError();
		return 1;
	}
	else
		cout << "Инициализация WinSock в порядке" << endl;

	//	// Инициализация клиентского сокета
	SOCKET ClientSock = socket(AF_INET, SOCK_STREAM, 0);

	if (ClientSock == INVALID_SOCKET) {
		cout << "Ошибка инициализации сокета # " << WSAGetLastError() << endl;
		closesocket(ClientSock);
		WSACleanup();
	}
	else
		cout << "Инициализация клиентского сокета выполнена успешно" << endl;

	//	// Привязка серверного сокета
	sockaddr_in servInfo;
	ZeroMemory(&servInfo, sizeof(servInfo)); // Инициализация структуры servInfo

	servInfo.sin_family = AF_INET;
	servInfo.sin_addr = ip_to_num;
	servInfo.sin_port = htons(SERVER_PORT_NUM);

	erStat = connect(ClientSock, (sockaddr*)&servInfo, sizeof(servInfo));

	if (erStat != 0) {
		cout << "Ошибка привязки сокета к серверу. Ошибка # " << WSAGetLastError() << endl;
		closesocket(ClientSock);
		WSACleanup();
		return 1;
	}
	else
		cout << "Привязка сокета к серверу в порядке. Вы можете отправить сообщение." << endl;


	//	//Обмен текстовыми данными между сервером и Клиентом. Отключение, если клиент отправляет "xxx"

	vector <char> servBuff(BUFF_SIZE), clientBuff(BUFF_SIZE);							//	//Создание буферов для отправки и получения данных
	short packet_size = 0;												//	//Размер отправляемого/принимаемого пакета в байтах

	while (true) {

		cout << "Ваше (Клиент) сообщение Серверу: ";
		fgets(clientBuff.data(), clientBuff.size(), stdin);

		// Проверка, что клиент перестал писать 
		if (clientBuff[0] == 'x' && clientBuff[1] == 'x' && clientBuff[2] == 'x') {
			shutdown(ClientSock, SD_BOTH);
			closesocket(ClientSock);
			WSACleanup();
			return 0;
		}

		packet_size = send(ClientSock, clientBuff.data(), clientBuff.size(), 0);

		if (packet_size == SOCKET_ERROR) {
			cout << "Не получается отправить сообщение серверу. Ошибка " << WSAGetLastError() << endl;
			closesocket(ClientSock);
			WSACleanup();
			return 1;
		}

		packet_size = recv(ClientSock, servBuff.data(), servBuff.size(), 0);

		if (packet_size == SOCKET_ERROR) {
			cout << "Не получается получить ответ от сервера. Ошибка " << WSAGetLastError() << endl;
			closesocket(ClientSock);
			WSACleanup();
			return 1;
		}
		else
			cout << "Сообщение сервера: " << servBuff.data() << endl;

	}

	closesocket(ClientSock);
	WSACleanup();

	return 0;
}
