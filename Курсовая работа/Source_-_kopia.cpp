#include <string>
#include <cstring>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <math.h>
#include <iomanip>
#include <io.h>

using namespace std;

ofstream fout;
ifstream fin;

struct Admin {

	string login;
	string parol;
}	admin[100];

struct Users {

	string login;
	string parol;
}	user[100];


//функции 
void Rules();//правила
void Output();//вывод инфы
bool Check_vvoda(string login, string parol);//Проверка на введённые логин/пароль при авторизации/регистрации


//Типы пользователей
void Guest();//Функции гостя

void User();//Функции пользователя
bool Autorization_User();//вход usera
void Read_user(string login, string parol);//чтение из файла user.txt

void Admin();//Функци администратора
bool Autorization_Admin();//вход админов
void Read_admin(string login, string parol);//считывание из файла admin.txt
void Changing_accounts();//функция админа по управлению аккаунтами
int register_user();//ф-я админа по регистрации новых пользователей




int main()
{
	setlocale(LC_ALL, "russian");
	system("cls");
	char act = '1';



	while (act != '0')
	{

		cout << "|      Авторизируйтесь:     |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|1|          Гость          |" << endl;
		cout << "|_|_________________________|" << endl;
		cout << "|2|      Пользователь       |" << endl;
		cout << "|_|_________________________|" << endl;
		cout << "|3|      Администратор      |" << endl;
		cout << "|_|_________________________|" << endl;
		cout << "|4|Правила пользования базой|" << endl;
		cout << "|_|_________________________|" << endl;
		cout << "|0|          Выход          |" << endl;
		cout << "|_|_________________________|" << endl;
		act = _getch();

		switch (act)
		{
		case '1': Guest(); break;
		case '2': User(); break;
		case '3': Admin(); break;
		case '4': Rules(); break;
		case '0': break;
		default: cout << "Можно вводить только 1, 2, 3, 4 или 0" << endl; system("pause"); system("cls"); break;
		}

	}
	return 0;
}


//Пользователи    
void Guest()
{
	system("cls");
	char act = '1';
	while (act != '0')
	{

		cout << " ______________________________________" << endl;
		cout << "|         Добро пожаловать, гость      |" << endl;
		cout << "|______________________________________|" << endl;
		cout << "|1|         Просмотр информации        |" << endl;
		cout << "|_|____________________________________|" << endl;
		cout << "|2|           Просмотр правил          |" << endl;
		cout << "|_|____________________________________|" << endl;
		cout << "|0|               Выход                |" << endl;
		cout << "|_|____________________________________|" << endl;
		act = _getch();

		switch (act)
		{
		case '1': Output(); break;
		case '2': Rules(); break;
		case '0': break;
		default: cout << "Можно вводить только 1, 2или 0" << endl; system("pause"); system("cls"); break;
		}

	}
	system("cls");
	return ; 
}

void User()
{
	system("cls");
	char act = '1';
	bool aut = false;


	system("cls");
	cout << "Добро пожаловать, пользователь. Авторизируйтесь, пожалуйста.\n \n";
	while (!aut)
	{
		aut = Autorization_User();
		system("cls");
		if (aut == true)
		{
			while (act != '0')
			{
				cout << " ______________________________________" << endl;
				cout << "|   Вам доступны следующие действия:   |" << endl;
				cout << "|______________________________________|" << endl;
				cout << "|1|          Просмотр данных           |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|2|         Добавление записи          |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|3|            Поиск данных            |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|0|         Выход из программы         |" << endl;
				cout << "|_|____________________________________|" << endl;
				act = _getch();

				switch (act)
				{
				case '1': cout << " будет выведен просмотр данных Output();" << endl; break;
				case '2': cout << "будет доступен ввод данных Input();" << endl; break;
				case '3': cout << " будет доступен поиск Search()" << endl; break;
				case '0': break;
				default: cout << "Можно вводить только от 0 до 3, повторите попытку!" << endl; system("pause"); break;
				}
				system("cls");
			}
		}
		else
		{
			cout << " \n \t Пароль или логин неверен \n" << endl;
			system("pause");
			break;
		}
	}
	system("cls");
	return;
}

void Admin()
{
	char act = '1';
	bool  aut = false;

	system("cls");
	cout << "Добро пожаловать, администратор. \n";
	while (!aut)
	{
		aut = Autorization_Admin();
		system("cls");
		if (aut == true)
		{
			while (act != '0')
			{
				cout << " ______________________________________" << endl;
				cout << "|   Вам доступны следующие действия:   |" << endl;
				cout << "|______________________________________|" << endl;
				cout << "|1|          Просмотр данных           |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|2|         Добавление записи          |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|3|    Сортировка выводимых данных     |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|4|            Поиск данных            |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|5|       Редактирование данных        |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|6|          Вставка данных            |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|7|          Удаление данных           |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|8|      Управление пользовтелями      |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|9|               Обмен                |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|0|         Выход из программы         |" << endl;
				cout << "|_|____________________________________|" << endl;
				act = _getch();

				switch (act)
				{
				case '1': cout << "будет доступен  Output();<<" << endl; break;
				case '2': cout << "будет доступен Input();" << endl; break;
				case '3': cout << "будет достуна сортировка Sort();" << endl; break;
				case '4': cout << "будет доступен поиск Search();" << endl; break;
				case '5': cout << " Changing();" << endl; break;
				case '6': cout << "Insertion();" << endl; break;
				case '7': cout << "Delete();" << endl; break;
				case '8': Changing_accounts(); break;
				case '9': cout << " Exchange();" << endl; break;
				case '0': break;
				default: cout << "Можно вводить только от 1 до 9, повторите попытку!" << endl; system("pause"); break;
				}
				system("cls");
			}
		}
		else
		{
			cout << "\n \t Пароль или логин неверен \n" << endl;
			system("pause");
			system("cls");
			break; return;

		}
	}
	return;
}

bool Autorization_User()//авторизация пользователя
{
	bool flag = true;//флаг для ветвления
	
	string login;
	cout << "Введите логин:" << endl;
	getline(cin, login);
	fflush(stdin);

	string parol;
	cout << "Введите пароль:" << endl;
	getline(cin, parol);
	fflush(stdin);//пароль и логин введены как строки, с учётом пробелов, символов, регистра
	
	flag =Check_vvoda(login,parol);//запуск функции на проверку введённых строк

		//ветвление: если правила ввода не нарушены - проверяется совпадение с инфой из файла
	if (flag==true)
		{

				Read_user(login, parol);
				bool flag_vxod = false;//если будет найдено совпадение в файле флаг изменится на true
				for (int i = 0; i < 100; i++)
				{
					if (login == user[i].login && parol == user[i].parol)
					{
						flag_vxod = true;
						break;
					}
				}

				if (flag_vxod == true)return true; // если найдено совпадение - истина
		}
		
		return false;
	}
void Read_user(string login, string parol)
{


	ifstream fin("user.txt");
	for (int i = 0; i < 100; i++)
	{
		fin >> user[i].login >> user[i].parol;
	}
}

bool Autorization_Admin()																		//авторизация админа
{
	bool flag = true;//флаг для ветвления


	string login;
	cout << "Введите логин:" << endl;
	getline(cin, login);

	fflush(stdin);
	string parol;
	cout << "Введите пароль:" << endl;
	getline(cin, parol);
	fflush(stdin);

	flag = Check_vvoda(login, parol);//запуск функции на проверку введённых строк
	//ветвление: если не нарушены правила ввода- начинается сверка с данными из файла
	if (flag == true)
	{
		Read_admin(login, parol);
		bool flag_vxod = false;
		for (int i = 0; i < 100; i++)
			{
					if (login == admin[i].login && parol == admin[i].parol)
					{
						flag_vxod = true;
						break;
					}
			}

			if (flag_vxod == true)return true;
	}
	 return false;
}
void Read_admin(string login, string parol)
{


	ifstream fin("admin.txt");
	for (int i = 0; i < 100; i++)
	{
		fin >> admin[i].login >> admin[i].parol;

	}

}
void Changing_accounts()
{
	system("cls");
	char act = '1';
	while (act != '0')
	{

		cout << " ______________________________________" << endl;
		cout << "|       Выберите нужное действие       |" << endl;
		cout << "|______________________________________|" << endl;
		cout << "|1|  Регистрация нового пользователя   |" << endl;
		cout << "|_|____________________________________|" << endl;
		cout << "|0|               Выход                |" << endl;
		cout << "|_|____________________________________|" << endl;
		act = _getch();

		switch (act)
		{
		case '1': register_user(); break;
		case '0': break;
		default: cout << "Можно вводить только 1 или 0" << endl; system("pause"); system("cls"); break;
		}
	}
	return;
}
int register_user()
{
	bool flag_admin=true;
	bool flag_user=true;
	bool flag = true;
	string login, parol;
	cout << "Введите логин для нового аккаунта:" << endl;
	getline(cin, login);
	fflush(stdin);
	cout << "Введите пароль для нового аккаунта:" << endl;
	getline(cin, parol);
	fflush(stdin);

	flag=Check_vvoda(login, parol);													// проверка на введённые строки регистрации

//ветвление: если правила ввода не нарушены - проверяется совпадение с инфой из файла и дальнейшие действия
	if (flag==true)
	{
		Read_admin(login, parol);
		for (int i = 0; i < 100; i++)						// ПРОВЕРКА НА СУЩЕСТВОВАНИЕ АККАУНТОВ АДМИНОВ;
		{
			if (login == admin[i].login)
			{
				cout << "Пользователь(admin) с таким логином уже существует.\n Нельзя регистрировать пользователей с логином админов" << endl;
				flag_admin = false;
				system("pause");
			}
		}													// ПРОВЕРКА НА СУЩЕСТВОВАНИЕ АККАУНТОВ АДМИНОВ ЗАКОНЧЕНА;

		Read_user(login, parol);		// ПРОВЕРКА НА СУЩЕСТВОВАНИЕ АККАУНТОВ ПОЛЬЗОВАТЕЛЕЙ;
		for (int i = 0; i < 100; i++)
		{
			if (login == user[i].login)
			{
				cout << "Пользователь с таким логином уже существует" << endl;
				flag_user = false;
				system("pause");
			}
		}								// ПРОВЕРКА НА СУЩЕСТВОВАНИЕ АККАУНТОВ ПОЛЬЗОВАТЕЛЕЙ ЗАКОНЧЕНА;

		if (flag_user == true && flag_admin == true )
		{
			ofstream fout("user.txt", ios::app);
			fout << login << " " << parol << endl;
			cout << "Регистрация прошла успешно" << endl;
			system("pause");
		}
	}
	system("cls");
	return 0;
}

void Rules()
{
	cout << endl;
	cout << "Правила пользования программой:" << endl;
	cout << "Правилo 1: Аккуратное обращение с программой." << endl;
	cout << "Правилo 2: Длина пароля и логина пользователя не должна превышать 10 символов. Минимальная длина - 3 символа." << endl;
	cout << "Правилo 3: Логин и пароль не должны содержать пробелов и символов, кроме букв, цифр и знака подчёркивания." << endl;
	cout << "Правилo 4: Нельзя регистрировать новых пользователей с уже существующим логином(как у админа или пользователя). "<< endl;
	cout << "Правилo 5: " << endl;
	system("pause");
	system("cls");
	return;

}
void Output()
{
	system("cls");
	cout << "Вывод данных" << endl;
	system("pause");
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
	for (int i = 0; i < login.length(); i++)												
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
		else{
			flag_symbol_login = false; break;
		}
	}																						
	for (int i = 0; i < parol.length(); i++)												
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
		cout << "\t " << "Длина логина = " << login.length() << " . Длина пароля = " << parol.length() << " ." << endl;
	}
	if (flag_symbol_login == false || flag_length == false || flag_symbol_parol == false) { system("pause"); return false; }
	return true;
}

/*
void Check_vvoda(string login, string parol, bool flag_dlina, bool flag_symbol_login, bool flag_symbol_parol)
{

	if (login.length() > 10 || login.length() < 3 || parol.length() < 3 || parol.length() > 10) // проверка на правильность длины логина / пароля
	{
		flag_dlina = false;
	}																							// проверка на правильность длины логина / пароля


	for (int i = 0; i < login.length(); i++)												// проверка на ввод символов логина
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

		else   {
			flag_symbol_login = false; break;
		}



	}																						// проверка на ввод символов логина окончена
	for (int i = 0; i < parol.length(); i++)												// проверка на ввод символов пароля
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

		else   {
			flag_symbol_parol = false; break;
		}

	}																						// проверка на ввод символов пароля окончена

	//сообщения, если нарушены правила ввода
	if (flag_symbol_parol == false || flag_symbol_login == false) cout << "При вводе логина/пароля были найдены недопустимые символы (см. правила)." << endl << "Вход не будет выполнен." << endl;
	if (flag_dlina == false)
	{
		cout << "Длина введённого логина/пароля не соответствует правилам." << endl << "Вход не будет выполнен" << endl;
		cout << "Длина логина = " << login.length() << " . Длина пароля = " << parol.length() << " ." << endl;
	}
	if (flag_symbol_login == false || flag_dlina == false || flag_symbol_parol == false) system("pause");
	cout << "состояние флагов в функции : login >>" << flag_symbol_login << " parol >>" << flag_symbol_parol << endl; system("pause");
	return;
} 
*/
