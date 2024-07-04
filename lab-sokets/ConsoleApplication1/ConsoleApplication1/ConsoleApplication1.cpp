
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <vector>

#pragma comment(lib, "Ws2_32.lib")

using namespace std; 


int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru_RU");

	//Key constants
	// Введите IP-адрес локального сервера
	const char IP_SERV[] = "192.168.66.242";
	// Введите открытый порт рабочего сервера
	const int PORT_NUM = 1;				
	// Максимальный размер буфера для обмена информацией между сервером и клиентом
	const short BUFF_SIZE = 1024;			

	// Ключевые переменные для всей программы
	int erStat;		// Сохраняет статус ошибки сокета

	//IP-адрес в строковом формате преобразуется в числовой формат для функций сокета. 
	// Данные указаны в "ip_to_num".
	in_addr ip_to_num;
	erStat = inet_pton(AF_INET, IP_SERV, &ip_to_num);

	if (erStat <= 0) {
		cout << "Ошибка при переводе IP-адреса в специальный цифровой формат " << endl;
		return 1;
	}


	// Инициализация WinSock
	WSADATA wsData;

	erStat = WSAStartup(MAKEWORD(2, 2), &wsData);

	if (erStat != 0) {
		cout << " Ошибка при инициализации версии WinSock # ";
		cout << WSAGetLastError();
		return 1;
	}
	else
		cout << "Инициализация WinSock в порядке " << endl;

	//Инициализация серверного сокета
	SOCKET ServSock = socket(AF_INET, SOCK_STREAM, 0);

	if (ServSock == INVALID_SOCKET) {
		cout << "Ошибка инициализации сокета # " << WSAGetLastError() << endl;
		closesocket(ServSock);
		WSACleanup();
		return 1;
	}
	else
		cout << "Инициализация серверного сокета выполняется следующим образом- OK" << endl;

	//Привязка серверного сокета
	sockaddr_in servInfo;
	ZeroMemory(&servInfo, sizeof(servInfo));	// Инициализация структуры servInfo

	servInfo.sin_family = AF_INET;
	servInfo.sin_addr = ip_to_num;
	servInfo.sin_port = htons(PORT_NUM);

	erStat = bind(ServSock, (sockaddr*)&servInfo, sizeof(servInfo));

	if (erStat != 0) {
		cout << "Ошибка привязки сокета к информации о сервере. Ошибка # " << WSAGetLastError() << endl;
		closesocket(ServSock);
		WSACleanup();
		return 1;
	}
	else
		cout << "Привязка сокета к информации о сервере в порядке" << endl;

	//Начинаю прислушиваться к любым клиентам
	erStat = listen(ServSock, SOMAXCONN);

	if (erStat != 0) {
		cout << "Не могу начать слушать. Ошибка # " << WSAGetLastError() << endl;
		closesocket(ServSock);
		WSACleanup();
		return 1;
	}
	else {
		cout << "Прослушивание..." << endl;
	}

	//Создание и принятие клиентского сокета в случае подключения
	sockaddr_in clientInfo;
	ZeroMemory(&clientInfo, sizeof(clientInfo));	//Инициализация информационной структуры клиента 

	int clientInfo_size = sizeof(clientInfo);

	SOCKET ClientConn = accept(ServSock, (sockaddr*)&clientInfo, &clientInfo_size);

	if (ClientConn == INVALID_SOCKET) {
		cout << "Клиент обнаружен, но не может подключиться к нему. Ошибка # " << WSAGetLastError() << endl;
		closesocket(ServSock);
		closesocket(ClientConn);
		WSACleanup();
		return 1;
	}
	else {
		cout << "Соединение с клиентом успешно установлено" << endl;
		char clientIP[22];
		//Преобразуйте IP-адрес подключенного клиента в стандартный строковый формат
		inet_ntop(AF_INET, &clientInfo.sin_addr, clientIP, INET_ADDRSTRLEN);	

		cout << "Клиент, подключенный с IP-адреса " << clientIP << endl;

	}

	//Обмен текстовыми данными между сервером и Клиентом. Отключение, если клиент отправляет "xxx"

		//Создание буферов для отправки и получения данных
	vector <char> servBuff(BUFF_SIZE), clientBuff(BUFF_SIZE);

	// Размер отправляемого/принимаемого пакета в байтах
	short packet_size = 0;												
	while (true) {
		// Получение пакета от клиента. Программа ожидает (системная пауза) получения
		packet_size = recv(ClientConn, servBuff.data(), servBuff.size(), 0);					
		cout << "Сообщение клиента: " << servBuff.data() << endl;

		cout << "Твое (host) сообщение: ";
		fgets(clientBuff.data(), clientBuff.size(), stdin);

		// Проверьте, не хочет ли сервер прекратить общение в чате
		if (clientBuff[0] == 'x' && clientBuff[1] == 'x' && clientBuff[2] == 'x') {
			shutdown(ClientConn, SD_BOTH);
			closesocket(ServSock);
			closesocket(ClientConn);
			WSACleanup();
			return 0;
		}

		packet_size = send(ClientConn, clientBuff.data(), clientBuff.size(), 0);

		if (packet_size == SOCKET_ERROR) {
			cout << "Не удается отправить сообщение клиенту. Ошибка # " << WSAGetLastError() << endl;
			closesocket(ServSock);
			closesocket(ClientConn);
			WSACleanup();
			return 1;
		}

	}

	closesocket(ServSock);
	closesocket(ClientConn);
	WSACleanup();

	return 0;

}