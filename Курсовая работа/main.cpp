#include <iostream>
#include <fstream> 
#include <string>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Account.h"


using namespace std;

int main() {
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "RUS");
	char action;
	do{
		cout << "|-----------------------------|" << endl;
		cout << "|         Здравствуйте        |" << endl;
		cout << "| Авторизируйтесь, пожалуйста:|" << endl;
		cout << "|-----------------------------|" << endl;
		cout << "|1. Гость                     |" << endl;
		cout << "|2. Пользователь              |" << endl;
		cout << "|3. Администратор             |" << endl;
		cout << "|0. Выход                     |" << endl;
		cout << "|-----------------------------|" << endl;

		action = _getch();
		switch (action)
		{
			case '1': Guest(); break;
			case '2': User(); break;
			case '3': Admin(); break;
			case '0': break;
			default: cout << "Некорректный ввод. Повторите попытку." << endl; system("pause"); system("cls"); break;
		}
	} while (action != '0');
	return 0;
}
