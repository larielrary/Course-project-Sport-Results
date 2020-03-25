#include <iostream>
#include <fstream> 
#include <string>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Account.h"
#include "Functions.h"

using namespace std;

void Guest()
{
	system("cls");
	char action = '1';
	while (action != '0')
	{
		Sportsmen* Sportsmen = 0;
		int SportsmenAmount = 0;
		Sportsmen = read_sportsmen(Sportsmen, SportsmenAmount);
		cout << "|----------------------------|" << endl;
		cout << "|   Добро пожаловать, гость  |" << endl;
		cout << "|----------------------------|" << endl;
		cout << "|1. Просмотр информации      |" << endl;
		cout << "|0. Выход                    |" << endl;
		cout << "|----------------------------|" << endl;
		action = _getch();
		switch (action)
		{
		case '1': Output(Sportsmen, SportsmenAmount); break;
		case '0': break;
		default: cout << "Некорректный ввод. Повторите попытку." << endl; system("pause"); system("cls"); break;
		}
		delete[]Sportsmen;
	}
	system("cls");
}
void User()
{
	system("cls");
	char action = '1';
	bool authorization;
	while (action != '0')
	{
		cout << "Добро пожаловать, пользователь. Авторизируйтесь, пожалуйста.\n \n";
		Users* Users = 0;
		int UsersAmount = 0;
		Users = read_users(Users, UsersAmount);
		authorization = Autorization_User(Users, UsersAmount);
		delete[]Users;
		system("cls");
		if (authorization == true)
		{
			while (action != '0')
			{
				Sportsmen* Sportsmen = 0;
				int SportsmenAmount = 0;
				Sportsmen = read_sportsmen(Sportsmen, SportsmenAmount);
				cout << "|--------------------------------------|" << endl;
				cout << "|   Добро пожаловать, пользователь:    |" << endl;
				cout << "|--------------------------------------|" << endl;
				cout << "|1. Просмотр данных                    |" << endl;
				cout << "|2. Добавление записи                  |" << endl;
				cout << "|3. Поиск данных                       |" << endl;
				cout << "|0. Выйти в меню                       |" << endl;
				cout << "|--------------------------------------|" << endl;
				action = _getch();
				switch (action)
				{
				case '1': Output(Sportsmen, SportsmenAmount); break;
				case '2': Input(Sportsmen, SportsmenAmount); break;
				case '3': Search(Sportsmen, SportsmenAmount); break;
				case '0': break;
				default: cout << "Некорректный ввод. Повторите попытку." << endl; system("pause"); break;
				}
				system("cls");
				delete[]Sportsmen;
			}
		}
		else
		{
			cout << "Пароль либо логин введены неверно! Повторите попытку." << endl;
			system("pause");
			system("cls");
		}
	}
	system("cls");
}
void Admin()
{
	system("cls");
	char action = '1';
	bool  authorization;
	while (action != '0')
	{
		cout << "Добро пожаловать, администратор. Авторизируйтесь, пожалуйста.\n \n";
		Admins* Admins = 0;
		int AdminsAmount = 0;
		Admins = read_admins(Admins, AdminsAmount);
		//authorization = Autorization_Admin(Admins, AdminsAmount);
		authorization = true;
		delete[]Admins;
		system("cls");
		if (authorization == true)
		{
			while (action != '0')
			{
				Sportsmen* Sportsmen = 0;
				int SportsmenAmount = 0;
				Sportsmen = read_sportsmen(Sportsmen, SportsmenAmount);
				cout << "|--------------------------------------|" << endl;
				cout << "|   Добро пожаловать, администратор:   |" << endl;
				cout << "|--------------------------------------|" << endl;
				cout << "|1. Просмотр данных                    |" << endl;
				cout << "|2. Добавление записи                  |" << endl;
				cout << "|3. Поиск данных                       |" << endl;
				cout << "|4. Сортировка данных                  |" << endl;
				cout << "|5. Редактирование данных              |" << endl;
				cout << "|6. Удаление данных                    |" << endl;
				cout << "|7. Управление пользователями          |" << endl;
				cout << "|8. Обмен записей                      |" << endl;
				cout << "|c. Архивация                          |" << endl;
				cout << "|d. Разархвивация                      |" << endl;
				cout << "|0. Выход из программы                 |" << endl;
				cout << "|f. Вывод по первому месту             |" << endl;
				cout << "|--------------------------------------|" << endl;
				action = _getch();

				switch (action)
				{
				case '1': Output(Sportsmen, SportsmenAmount); break;
				case '2': Input(Sportsmen, SportsmenAmount); break;
				case '3': Search(Sportsmen, SportsmenAmount); break;
				case '4': Sort(Sportsmen, SportsmenAmount); break;
				case '5': Changing_Data(Sportsmen, SportsmenAmount); break;
				case '6': Delete_Data(Sportsmen, SportsmenAmount); break;
				case '7': Managing_Users(); break;
				case '8': Swap_sportsmen(Sportsmen, SportsmenAmount); break;
				case 'c': compression(); cout << "***Файл успешко заархивирован***" << endl; system("timeout 5"); break;
				case 'd': decompression(); cout << "***Файл успешко разархивирован***" << endl; system("timeout 5"); break;
				case 'f': first(Sportsmen, SportsmenAmount); break;
				case '0': break;
				default: cout << "Некорректный ввод. Повторите попытку." << endl; system("pause"); break;
				}
				system("cls");
				delete[]Sportsmen;
			}
		}
		else
		{
			cout << "Пароль либо логин введены неверно! Повторите попытку." << endl;
			system("pause");
			system("cls");

		}
	}
	return;
}

void Managing_Users()
{
	system("cls");
	char action = '1';
	while (action != '0')
	{
		cout << "|--------------------------------------|" << endl;
		cout << "|      Управление пользователями       |" << endl;
		cout << "|--------------------------------------|" << endl;
		cout << "|       Выберите нужное действие:      |" << endl;
		cout << "|--------------------------------------|" << endl;
		cout << "|1. Регистрация нового пользователя    |" << endl;
		cout << "|2. Удаление пользователя              |" << endl;
		cout << "|0. Выход                              |" << endl;
		cout << "|--------------------------------------|" << endl;
		action = _getch();

		switch (action)
		{
		case '1': Register_Users(); break;
		case '2': Delete_Users(); break;
		case '0': break;
		default: cout << "Некорректный ввод. Повторите попытку." << endl; system("pause"); system("cls"); break;
		}
	}
	system("cls");
}
void Register_Users()
{
	system("cls");
	bool flag_admin = true;
	bool flag_user = true;
	bool flag = true;
	string login, parol;

	Admins* Admins = 0;
	int AdminsAmount = 0;
	Admins = read_admins(Admins, AdminsAmount);

	Users* Users = 0;
	int UsersAmount = 0;
	Users = read_users(Users, UsersAmount);

	cout << "Введите логин для нового аккаунта:" << endl;
	fflush(stdin);
	getline(cin, login);
	cout << "Введите пароль для нового аккаунта:" << endl;
	fflush(stdin);
	getline(cin, parol);
	flag = Check_vvoda(login, parol);
	if (flag == true)
	{
		for (int i = 0; i < AdminsAmount; i++)
		{
			if (login == Admins[i].login)
			{
				cout << "Пользователь(admin) с таким логином уже существует.\n Нельзя регистрировать пользователей с логином админов" << endl;
				flag_admin = false;
				system("pause");
			}
		}
		for (int i = 0; i < UsersAmount; i++)
		{
			if (login == Users[i].login)
			{
				cout << "Пользователь с таким логином уже существует" << endl;
				flag_user = false;
				system("pause");
			}
		}
		if (flag_user == true && flag_admin == true)
		{
			ofstream fout("users.txt", ios::app);
			Encryption(login, parol);                                         //| Шифрование данных и запись их в файл
			fout << login << " " << parol << endl;
			cout << "Регистрация прошла успешно" << endl;
			fout.close();
			system("pause");
		}
	}
	delete[]Admins;
	delete[]Users;
	system("cls");

}
void Delete_Users()
{
	system("cls");

	bool flag_admin = true;
	bool flag_user = false;

	string login;
	int number;

	Admins* Admins = 0;
	int AdminsAmount = 0;
	Admins = read_admins(Admins, AdminsAmount);

	Users* Users = 0;
	int UsersAmount = 0;
	Users = read_users(Users, UsersAmount);

	cout << "Введите логин аккаунта, который хотите удалить: " << endl;
	fflush(stdin);
	getline(cin, login);
	if (login == "")
	{
		cout << "Некорректный ввод. Повторите попытку." << endl;
		system("pause");
		delete[]Admins;
		delete[]Users;
		system("cls");
		return;
	}

	for (int i = 0; i < AdminsAmount; i++)
	{
		if (login == Admins[i].login)
		{
			cout << "Данный логин принадлежит админу. Нельзя удалить админа." << endl;
			flag_admin = false;
			system("pause");
			delete[]Admins;
			delete[]Users;
			return;
		}
	}
	for (int i = 0; i < UsersAmount; i++)
	{
		if (login == Users[i].login)
		{
			flag_user = true;
			number = i;
			break;
		}
	}
	if (flag_user == false)
	{
		cout << "Аккаунт не найден." << endl;
	}
	if (flag_user == true && flag_admin == true)
	{
		for (int j = number; j < UsersAmount - 1; j++)
		{
			Users[j] = Users[j + 1];
		}

		UsersAmount = UsersAmount - 1;

		ofstream fout("users.txt", ios_base::out | ios_base::trunc);
		for (int i = 0; i < UsersAmount; i++) {
			if (Users[i].login == "" || Users[i].parol == "") continue;
			Encryption(Users[i].login, Users[i].parol);
			fout << Users[i].login << " " << Users[i].parol << endl;
		}
		cout << "Удаление прошло успешно" << endl;
		fout.close();
	}

	delete[]Admins;
	delete[]Users;
	system("pause");
	system("cls");
}
bool Autorization_User(Users* users, int UsersAmount) {
	string login, parol;
	char ch = 's';
	cout << "Введите логин:" << endl;
	fflush(stdin);
	getline(cin, login);
	cout << "Введите пароль:" << endl;
	fflush(stdin);                                                   //| Bместо пароля выводится '*'
	if (login.length() < 2) return false;
	while ((ch = _getch()) != '\r')
	{
		parol += ch;
		cout << '*';
	}
	for (int i = 0; i < UsersAmount; i++)
		if (login == users[i].login && parol == users[i].parol) return true;
	return false;
}
bool Autorization_Admin(Admins* admins, int AdminsAmount)
{
	string login, parol;
	char ch = 's';
	cout << "Введите логин:" << endl;
	fflush(stdin);
	getline(cin, login);
	cout << "Введите пароль:" << endl;
	fflush(stdin);
	if (login.length() < 2) return false;
	while ((ch = _getch()) != '\r')
	{
		parol += ch;
		cout << '*';
	}
	for (int i = 0; i < AdminsAmount; i++)
		if (login == admins[i].login && parol == admins[i].parol) return true;
	return false;
}
bool Check_vvoda(string login, string parol)
{
	bool flag_symbol_login = true;
	bool flag_symbol_parol = true;
	bool flag_length = true;

	if (login.length() > 20 || login.length() < 3 || parol.length() < 3 || parol.length() > 8)
	{
		flag_length = false;
	}
	for (unsigned int i = 0; i < login.length(); i++)
	{
		if (login[i] >= '0' && login[i] <= '9')
		{
			flag_symbol_login = true;
		}
		else if (login[i] >= 'A' && login[i] <= 'z')
		{
			flag_symbol_login = true;
		}
		else if (login[i] == ' ')
		{
			flag_symbol_login = false; break;
		}
		else {
			flag_symbol_login = false; break;
		}
	}
	for (unsigned int i = 0; i < parol.length(); i++)
	{
		if (parol[i] >= '0' && parol[i] <= '9')
		{
			flag_symbol_parol = true;
		}
		else if (parol[i] >= 'A' && parol[i] <= 'z')
		{
			flag_symbol_parol = true;
		}
		else if (parol[i] == ' ')
		{
			flag_symbol_parol = false; break;
		}
		else {
			flag_symbol_parol = false; break;
		}

	}
	if (flag_symbol_parol == false || flag_symbol_login == false) cout << "Вы ввели логин или пароль с недопустимыми символами." << endl;
	if (flag_length == false)
	{
		cout << "Вы ввели логин или пароль недопустимой длинны." << endl;
		cout << "Минимальная длина логина - 3, а максимальная - 20" << endl;
		cout << "Минимальная длина пароля - 3, а максимальная - 8" << endl;
		cout << "Длина логина = " << login.length() << " . Длина пароля = " << parol.length() << " ." << endl;
	}
	if (flag_symbol_login == false || flag_length == false || flag_symbol_parol == false) { system("pause"); return false; }
	return true;
}
void Encryption(string &login, string &parol)
{
	char LOGIN[20];
	char PAROL[8];
	char a = '*', b = '@';
	strcpy_s(LOGIN, login.c_str());
	strcpy_s(PAROL, parol.c_str());
	int LOGIN_length = strlen(LOGIN);
	int PAROL_length = strlen(PAROL);
	for (int i = 0; i<LOGIN_length; i++)
	{
		LOGIN[i] = (LOGIN[i] + a + b);
	}
	for (int i = 0; i<PAROL_length; i++)
	{
		PAROL[i] = (PAROL[i] + a + b);
	}
	login = string(LOGIN);
	parol = string(PAROL);
}
void Decryption(string &login, string &parol)
{
	char LOGIN[20];
	char PAROL[8];
	char a = '*', b = '@';
	strcpy_s(LOGIN, login.c_str());
	strcpy_s(PAROL, parol.c_str());
	int LOGIN_length = strlen(LOGIN);
	int PAROL_length = strlen(PAROL);
	for (int i = 0; i<LOGIN_length; i++)
	{
		LOGIN[i] = (LOGIN[i] - a - b);
	}
	for (int i = 0; i<PAROL_length; i++)
	{
		PAROL[i] = (PAROL[i] - a - b);
	}
	login = string(LOGIN);
	parol = string(PAROL);
}

Users *read_users(Users* users, int &amount) {

	ifstream fin;
	fin.open("users.txt");
	if (!fin)
	{
		ofstream file("users.txt");
		return 0;
	}
	for (int i = 0; !(fin.eof()); i++) {
		users = AddStructUsers(users, amount);
		fin >> users[i].login >> users[i].parol;
		Decryption(users[i].login, users[i].parol);
		amount++;
	}
	fin.close();
	return users;
}
Users *AddStructUsers(Users* Obj, int amount)
{
	if (amount == 0) Obj = new Users[amount + 1];
	else
	{
		Users* tempObj = new Users[amount + 1];
		for (int i = 0; i < amount; i++) tempObj[i] = Obj[i]; 
		delete[] Obj;
		Obj = tempObj;
	}
	return Obj;
}

Admins *read_admins(Admins* admin, int &amount) {

	ifstream fin_admin;
	fin_admin.open("admin.txt");
	if (!fin_admin)
	{
		ofstream file("admin.txt", ios::app);
		cout << "Резервный логин администратор:  admin" << endl;
		cout << "Резервный пароль администратор: admin" << endl;
		admin = AddStructAdmins(admin, amount);
		admin[0].login = "admin";
		admin[0].parol = "admin";
		Encryption(admin[0].login, admin[0].parol);
		file << admin[0].login << " " << admin[0].parol << endl;
		amount++;
		file.close();
		Decryption(admin[0].login, admin[0].parol);
		return admin;
	}
	for (int i = 0; !(fin_admin.eof()); i++) {
		admin = AddStructAdmins(admin, amount);
		fin_admin >> admin[i].login >> admin[i].parol;
		Decryption(admin[i].login, admin[i].parol);
		amount++;
	}
	fin_admin.close();
	return admin;
}
Admins *AddStructAdmins(Admins* Obj, int amount)
{
	if (amount == 0) Obj = new Admins[amount + 1]; 
	else
	{
		Admins* tempObj = new Admins[amount + 1];
		for (int i = 0; i < amount; i++) tempObj[i] = Obj[i]; 
		delete[] Obj;
		Obj = tempObj;
	}
	return Obj;
}

