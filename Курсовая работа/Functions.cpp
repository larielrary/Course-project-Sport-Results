#include <iostream>
#include <fstream> 
#include <string>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Functions.h"
#include "Zip.h"

using namespace std;

Sportsmen *read_sportsmen(Sportsmen* Sportsmen, int &amount) {
	ifstream fin;
	char action = '1';
	fin.open("sportsmen.txt");
	if (!fin)
	{
		do
		{
			cout << "|~~~~~~~~~~~~~~~~~~ВНИМАНИЕ~~~~~~~~~~~~~~~~~~|" << endl;
			cout << "|        Файл с данными отсутствует.         |" << endl;
			cout << "|--------------------------------------------|" << endl;
			cout << "|              Выберите действие?            |" << endl;
			cout << "|--------------------------------------------|" << endl;
			cout << "|1. Создание файла для записи.               |" << endl;
			cout << "|2. Выход из программы.                      |" << endl;
			cout << "|--------------------------------------------|" << endl;
			action = _getch();
			switch (action)
			{
			case '1':
			{
				ofstream file("sportsmen.txt");
				file.close();
				break;
			}
			case '2':
			{
				exit(EXIT_FAILURE);
			}
			default:
				cout << "Некорректный ввод. Повторите попытку." << endl; system("pause"); system("cls"); break;
			}
		}while(action != '1');
		system("cls");
		fin.open("sportsmen.txt");
	}
	for (int i = 0; !(fin.eof()); i++) {
		Sportsmen = AddStruct(Sportsmen, amount);
		fin >> Sportsmen[i].Place >> Sportsmen[i].Organization >> Sportsmen[i].Surname >> Sportsmen[i].Name >> Sportsmen[i].Year_of_birth >> Sportsmen[i].Result >> Sportsmen[i].Num;
		amount++;
	}
	fin.close();
	return Sportsmen;
}
Sportsmen *AddStruct(Sportsmen* Obj, int amount)
{
	if (amount == 0) Obj = new Sportsmen[amount + 1]; 
	else
	{
		Sportsmen* tempObj = new Sportsmen[amount + 1];
		for (int i = 0; i < amount; i++) tempObj[i] = Obj[i]; 
		delete[] Obj;
		Obj = tempObj;
	}
	return Obj;
}

void Output(Sportsmen* Sportsmen, int SportsmenAmount)
{
	system("cls");
	cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;
	std::cout << "|Место"
		<< std::setw(5) << "|Организация"
		<< std::setw(24) << "|Фамилия"
		<< std::setw(15) << "|Имя"
		<< std::setw(27) << "|Год рождения"
		<< std::setw(7) << "|Результат"
		<< std::setw(3) << "|№ записи|"
		<< std::endl;
	cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;

	for (int i = 0; i < SportsmenAmount - 1; i++) {
		if (Sportsmen[i].Place > 9)
		{
			cout.width(0);
			cout << "|" << right << Sportsmen[i].Place << " " << std::setw(3) << "|";
			cout.width(25);
			cout << left << Sportsmen[i].Organization << "  " << "|";
			cout.width(15);
			cout << left << Sportsmen[i].Surname << "   " << "|";
			cout.width(15);
			cout << left << Sportsmen[i].Name << "  " << "|";
			cout.width(12);
			cout << right << Sportsmen[i].Year_of_birth << "|";
			cout.width(9);
			cout << right << Sportsmen[i].Result << "|";
			cout.width(8);
			cout << right << Sportsmen[i].Num << "|" << '\n';
			cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;

		}
		else {
			cout.width(0);
			cout << "|" << right << Sportsmen[i].Place << "  " << std::setw(3) << "|";
			cout.width(25);
			cout << left << Sportsmen[i].Organization << "  " << "|";
			cout.width(16);
			cout << left << Sportsmen[i].Surname << "  " << "|";
			cout.width(15);
			cout << left << Sportsmen[i].Name << "  " << "|";
			cout.width(12);
			cout << right << Sportsmen[i].Year_of_birth << "|";
			cout.width(9);
			cout << right << Sportsmen[i].Result << "|";
			cout.width(8);
			cout << right << Sportsmen[i].Num << "|" << '\n';
			cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;
		}
	}
	system("pause");
	system("cls");
}
void Input(Sportsmen* &Sportsmen, int &SportsmenAmount)
{
	system("cls");
	int i;
	Sportsmen = AddStruct(Sportsmen, SportsmenAmount);
	i = SportsmenAmount;

	printf("Запись будет доступна под номером %d\n", i);
	Sportsmen[i].Num = i;

	printf("Введите фамилию(не более 15 символов): ");
	fflush(stdin);
	getline(cin, Sportsmen[i].Surname);
	if (Sportsmen[i].Surname.size() == 0 || Sportsmen[i].Surname.size()>15)
	{
		cout << "Данные введены неверно" << endl;
		system("pause");
		return;
	}

	printf("Введите имя(не более 15 символов): ");
	fflush(stdin);
	getline(cin, Sportsmen[i].Name);
	if (Sportsmen[i].Name.size() == 0 || Sportsmen[i].Name.size()>15)
	{
		cout << "Данные введены неверно" << endl;
		system("pause");
		return;
	}

	printf("Введите организацию(не более 25 символов): ");
	fflush(stdin);
	getline(cin, Sportsmen[i].Organization);
	if (Sportsmen[i].Organization.size() == 0 || Sportsmen[i].Organization.size()>25)
	{
		cout << "Данные введены неверно" << endl;
		system("pause");
		return;
	}

	printf("Введите год рождения в виде YYYY(диапозон от 1980 до 2000): ");
	fflush(stdin);
	cin >> Sportsmen[i].Year_of_birth;
	if (Sportsmen[i].Year_of_birth < 1980 || Sportsmen[i].Year_of_birth > 2000)
	{
		cout << "Данные введены неверно" << endl;
		cin.ignore();
		system("pause");
		return;
	}

	printf("Введите результат(диапозон от 0 до 100): ");
	fflush(stdin);
	cin >> Sportsmen[i].Result;
	if (Sportsmen[i].Result < 0 || Sportsmen[i].Result > 100)
	{
		cout << "Данные введены неверно" << endl;
		cin.ignore();
		system("pause");
		return;
	}

	printf("Введите место(диапозон от 1 до 25): ");
	fflush(stdin);
	cin >> Sportsmen[i].Place;
	if (Sportsmen[i].Place < 1 || Sportsmen[i].Place > 25)
	{
		cout << "Данные введены неверно" << endl;
		cin.ignore();
		system("pause");
		return;
	}
	cin.ignore();

	ofstream fout("sportsmen.txt", ios::app);
	if (Sportsmen[i].Place > 9) {
		fout << right << Sportsmen[i].Place << " ";
		fout.width(25);
		fout << left << Sportsmen[i].Organization << "  ";
		fout.width(15);
		fout << left << Sportsmen[i].Surname << "  ";
		fout.width(15);
		fout << left << Sportsmen[i].Name << "  ";
		fout.width(12);
		fout << right << Sportsmen[i].Year_of_birth << "  ";
		fout.width(9);
		fout << right << Sportsmen[i].Result << "  ";
		fout.width(8);
		fout << right << Sportsmen[i].Num << '\n';
	}
	else {
		fout << right << Sportsmen[i].Place << "  ";
		fout.width(25);
		fout << left << Sportsmen[i].Organization << "  ";
		fout.width(15);
		fout << left << Sportsmen[i].Surname << "  ";
		fout.width(15);
		fout << left << Sportsmen[i].Name << "  ";
		fout.width(12);
		fout << right << Sportsmen[i].Year_of_birth << "  ";
		fout.width(9);
		fout << right << Sportsmen[i].Result << "  ";
		fout.width(8);
		fout << right << Sportsmen[i].Num << '\n';
	}
	fout.close();
	system("pause");
	system("cls");
}
void Search(Sportsmen* Sportsmen, int SportsmenAmount)
{
	system("cls");
	string search_surname, search_name;
	cout << "Введите фамилию спортсмена: ";
	fflush(stdin);
	getline(cin, search_surname);
	cout << "Введите имя спортсмена: ";
	fflush(stdin);
	getline(cin, search_name);
	system("cls");
	bool findSportsmen = false;
	for (int i = 0; i < SportsmenAmount - 1; i++)
		if (Sportsmen[i].Surname == search_surname && Sportsmen[i].Name == search_name)
		{
			if (findSportsmen == false)
			{
				cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;
				std::cout << "|Место"
					<< std::setw(5) << "|Организация"
					<< std::setw(24) << "|Фамилия"
					<< std::setw(15) << "|Имя"
					<< std::setw(27) << "|Год рождения"
					<< std::setw(7) << "|Результат"
					<< std::setw(3) << "|№ записи|"
					<< std::endl;
				cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;
			}
			findSportsmen = true;
			if (Sportsmen[i].Place > 9) {
				cout.width(0);
				cout << "|" << right << Sportsmen[i].Place << " " << std::setw(3) << "|";
				cout.width(25);
				cout << left << Sportsmen[i].Organization << "  " << "|";
				cout.width(15);
				cout << left << Sportsmen[i].Surname << "   " << "|";
				cout.width(15);
				cout << left << Sportsmen[i].Name << "  " << "|";
				cout.width(12);
				cout << right << Sportsmen[i].Year_of_birth << "|";
				cout.width(9);
				cout << right << Sportsmen[i].Result << "|";
				cout.width(8);
				cout << right << Sportsmen[i].Num << "|" << '\n';
				cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;

			}
			else {
				cout.width(0);
				cout << "|" << right << Sportsmen[i].Place << "  " << std::setw(3) << "|";
				cout.width(25);
				cout << left << Sportsmen[i].Organization << "  " << "|";
				cout.width(16);
				cout << left << Sportsmen[i].Surname << "  " << "|";
				cout.width(15);
				cout << left << Sportsmen[i].Name << "  " << "|";
				cout.width(12);
				cout << right << Sportsmen[i].Year_of_birth << "|";
				cout.width(9);
				cout << right << Sportsmen[i].Result << "|";
				cout.width(8);
				cout << right << Sportsmen[i].Num << "|" << '\n';
				cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;
			}
		}
	if (findSportsmen == false) cout << "Спортсмен не найден" << endl;
	system("pause");
	system("cls");
}
void Sort(Sportsmen* Sportsmen, int SportsmenAmount)
{
	system("cls");
	int n = SportsmenAmount - 1;
	int *array_of_Year = new int[n];
	for (int i = 0; i < n; i++) array_of_Year[i] = Sportsmen[i].Year_of_birth;

	char action = '1';
	cout << "|------------------------------------|" << endl;
	cout << "|  Как хотите отсортировать данные?  |" << endl;
	cout << "|------------------------------------|" << endl;
	cout << "|1. По возрастанию                   |" << endl;
	cout << "|2. По убыванию                      |" << endl;
	cout << "|0. Выход                            |" << endl;
	cout << "|------------------------------------|" << endl;
	action = _getch();
	switch (action)
	{
	case '1':
	{
		system("cls");
		qsort1(array_of_Year, 0, n - 1);
		cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;
		std::cout << "|Место"
			<< std::setw(5) << "|Организация"
			<< std::setw(24) << "|Фамилия"
			<< std::setw(15) << "|Имя"
			<< std::setw(27) << "|Год рождения"
			<< std::setw(7) << "|Результат"
			<< std::setw(3) << "|№ записи|"
			<< std::endl;
		cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;

		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i<n; i++)
				if (array_of_Year[j] == Sportsmen[i].Year_of_birth) {
					if (Sportsmen[i].Place > 9)
					{
						cout.width(0);
						cout << "|" << right << Sportsmen[i].Place << " " << std::setw(3) << "|";
						cout.width(25);
						cout << left << Sportsmen[i].Organization << "  " << "|";
						cout.width(15);
						cout << left << Sportsmen[i].Surname << "   " << "|";
						cout.width(15);
						cout << left << Sportsmen[i].Name << "  " << "|";
						cout.width(12);
						cout << right << Sportsmen[i].Year_of_birth << "|";
						cout.width(9);
						cout << right << Sportsmen[i].Result << "|";
						cout.width(8);
						cout << right << Sportsmen[i].Num << "|" << '\n';
						cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;

					}
					else {
						cout.width(0);
						cout << "|" << right << Sportsmen[i].Place << "  " << std::setw(3) << "|";
						cout.width(25);
						cout << left << Sportsmen[i].Organization << "  " << "|";
						cout.width(16);
						cout << left << Sportsmen[i].Surname << "  " << "|";
						cout.width(15);
						cout << left << Sportsmen[i].Name << "  " << "|";
						cout.width(12);
						cout << right << Sportsmen[i].Year_of_birth << "|";
						cout.width(9);
						cout << right << Sportsmen[i].Result << "|";
						cout.width(8);
						cout << right << Sportsmen[i].Num << "|" << '\n';
						cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;
					}
					Sportsmen[i].Year_of_birth = -1;
				}
		}
		system("pause");
		break;
	}

	case '2':
	{
		system("cls");
		qsort2(array_of_Year, 0, n - 1);
		cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;
		std::cout << "|Место"
			<< std::setw(5) << "|Организация"
			<< std::setw(24) << "|Фамилия"
			<< std::setw(15) << "|Имя"
			<< std::setw(27) << "|Год рождения"
			<< std::setw(7) << "|Результат"
			<< std::setw(3) << "|№ записи|"
			<< std::endl;
		cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;

		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i<n; i++)
				if (array_of_Year[j] == Sportsmen[i].Year_of_birth) {
					if (Sportsmen[i].Place > 9)
					{
						cout.width(0);
						cout << "|" << right << Sportsmen[i].Place << " " << std::setw(3) << "|";
						cout.width(25);
						cout << left << Sportsmen[i].Organization << "  " << "|";
						cout.width(15);
						cout << left << Sportsmen[i].Surname << "   " << "|";
						cout.width(15);
						cout << left << Sportsmen[i].Name << "  " << "|";
						cout.width(12);
						cout << right << Sportsmen[i].Year_of_birth << "|";
						cout.width(9);
						cout << right << Sportsmen[i].Result << "|";
						cout.width(8);
						cout << right << Sportsmen[i].Num << "|" << '\n';
						cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;

					}
					else {
						cout.width(0);
						cout << "|" << right << Sportsmen[i].Place << "  " << std::setw(3) << "|";
						cout.width(25);
						cout << left << Sportsmen[i].Organization << "  " << "|";
						cout.width(16);
						cout << left << Sportsmen[i].Surname << "  " << "|";
						cout.width(15);
						cout << left << Sportsmen[i].Name << "  " << "|";
						cout.width(12);
						cout << right << Sportsmen[i].Year_of_birth << "|";
						cout.width(9);
						cout << right << Sportsmen[i].Result << "|";
						cout.width(8);
						cout << right << Sportsmen[i].Num << "|" << '\n';
						cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;
					}
					Sportsmen[i].Year_of_birth = -1;
				}
		}
		system("pause");
		break;
	}
	case '0': break;
	default: cout << "Некорректный ввод. Повторите попытку." << endl; system("pause"); break;
	}
	system("cls");
}
void Changing_Data(Sportsmen* Sportsmen, int SportsmenAmount)
{
	system("cls");
	string search_surname, search_name;
	cout << "Введите фамилию спортсмена: ";
	fflush(stdin);
	getline(cin, search_surname);
	cout << "Введите имя спортсмена: ";
	fflush(stdin);
	getline(cin, search_name);
	system("cls");
	int index_of_sportsmen;
	bool findSportsmen = false;
	for (int i = 0; i < SportsmenAmount - 1; i++)
		if (Sportsmen[i].Surname == search_surname && Sportsmen[i].Name == search_name)
		{
			findSportsmen = true;
			index_of_sportsmen = i;
		}
	if (findSportsmen == true)
	{
		char action = '1';
		int newPlace, newResult, newYear_of_birth;
		string newOrganization, newSurname, newName;
		do {
			cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;
			std::cout << "|Место"
				<< std::setw(5) << "|Организация"
				<< std::setw(24) << "|Фамилия"
				<< std::setw(15) << "|Имя"
				<< std::setw(27) << "|Год рождения"
				<< std::setw(7) << "|Результат"
				<< std::setw(3) << "|№ записи|"
				<< std::endl;
			cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;
			if (Sportsmen[index_of_sportsmen].Place > 9)
			{
				cout.width(0);
				cout << "|" << right << Sportsmen[index_of_sportsmen].Place << " " << std::setw(3) << "|";
				cout.width(25);
				cout << left << Sportsmen[index_of_sportsmen].Organization << "  " << "|";
				cout.width(15);
				cout << left << Sportsmen[index_of_sportsmen].Surname << "   " << "|";
				cout.width(15);
				cout << left << Sportsmen[index_of_sportsmen].Name << "  " << "|";
				cout.width(12);
				cout << right << Sportsmen[index_of_sportsmen].Year_of_birth << "|";
				cout.width(9);
				cout << right << Sportsmen[index_of_sportsmen].Result << "|";
				cout.width(8);
				cout << right << Sportsmen[index_of_sportsmen].Num << "|" << '\n';
				cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;
			}
			else {
				cout.width(0);
				cout << "|" << right << Sportsmen[index_of_sportsmen].Place << "  " << std::setw(3) << "|";
				cout.width(25);
				cout << left << Sportsmen[index_of_sportsmen].Organization << "  " << "|";
				cout.width(16);
				cout << left << Sportsmen[index_of_sportsmen].Surname << "  " << "|";
				cout.width(15);
				cout << left << Sportsmen[index_of_sportsmen].Name << "  " << "|";
				cout.width(12);
				cout << right << Sportsmen[index_of_sportsmen].Year_of_birth << "|";
				cout.width(9);
				cout << right << Sportsmen[index_of_sportsmen].Result << "|";
				cout.width(8);
				cout << right << Sportsmen[index_of_sportsmen].Num << "|" << '\n';
				cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;
			}
			cout << endl << endl;
			cout << "|-------------------------------|" << endl;
			cout << "|  Какие данные на0до изменить?  |" << endl;
			cout << "|-------------------------------|" << endl;
			cout << "|1. Место                       |" << endl;
			cout << "|2. Организация                 |" << endl;
			cout << "|3. Фамилия                     |" << endl;
			cout << "|4. Имя                         |" << endl;
			cout << "|5. Год рождения                |" << endl;
			cout << "|6. Результат                   |" << endl;
			cout << "|0. Выход                       |" << endl;
			cout << "|-------------------------------|" << endl;
			action = _getch();

			switch (action)
			{
			case '1':
			{
				cout << "Введите место(диапозон от 1 до 25): ";
				cin >> newPlace;
				if (newPlace < 1 || newPlace > 25)
				{
					cout << "Данные введены неверно" << endl;
					cin.ignore();
					system("pause");
					return;
				}
				else Sportsmen[index_of_sportsmen].Place = newPlace;
				cin.ignore();
				break;
			}
			case '2':
			{
				cout << "Введите организацию(не более 25 символов) ";
				fflush(stdin);
				getline(cin, newOrganization);
				if (newOrganization.size() == 0 || newOrganization.size()>25)
				{
					cout << "Данные введены неверно" << endl;
					system("pause");
					return;
				}
				else Sportsmen[index_of_sportsmen].Organization = newOrganization;
				break;
			}
			case '3':
			{
				cout << "Введите фамилию(не более 15 символов): ";
				fflush(stdin);
				getline(cin, newSurname);
				if (newSurname.size() == 0 || newSurname.size()>15)
				{
					cout << "Данные введены неверно" << endl;
					system("pause");
					return;
				}
				else Sportsmen[index_of_sportsmen].Surname = newSurname;
				break;
			}
			case '4':
			{
				cout << "Введите имя(не более 15 символов): ";
				fflush(stdin);
				getline(cin, newName);
				if (newName.size() == 0 || newName.size() > 15)
				{
					cout << "Данные введены неверно" << endl;
					system("pause");
					return;
				}
				else Sportsmen[index_of_sportsmen].Name = newName;
				break;
			}
			case '5':
			{
				cout << "Введите год рождения в виде YYYY(диапозон от 1980 до 2000): ";
				cin >> newYear_of_birth;
				if (newYear_of_birth < 1980 || newYear_of_birth > 2000)
				{
					cout << "Данные введены неверно" << endl;
					cin.ignore();
					system("pause");
					return;
				}
				else Sportsmen[index_of_sportsmen].Year_of_birth = newYear_of_birth;
				cin.ignore();
				break;
			}
			case '6':
			{
				cout << "Введите результат(диапозон от 0 до 100): ";
				cin >> newResult;
				if (newResult < 0 || newResult > 100)
				{
					cout << "Данные введены неверно" << endl;
					cin.ignore();
					system("pause");
					return;
				}
				else Sportsmen[index_of_sportsmen].Result = newResult;
				cin.ignore();
				break;
			}
			case '0': break;
			default: cout << "Некорректный ввод. Повторите попытку." << endl; system("pause"); break;
			}
			ofstream fout("sportsmen.txt", ios_base::out | ios_base::trunc);
			for (int i = 0; i < SportsmenAmount - 1; i++) {
				if (Sportsmen[i].Place > 9) {
					fout << right << Sportsmen[i].Place << " ";
					fout.width(25);
					fout << left << Sportsmen[i].Organization << "  ";
					fout.width(15);
					fout << left << Sportsmen[i].Surname << "  ";
					fout.width(15);
					fout << left << Sportsmen[i].Name << "  ";
					fout.width(12);
					fout << right << Sportsmen[i].Year_of_birth << "  ";
					fout.width(9);
					fout << right << Sportsmen[i].Result << "  ";
					fout.width(8);
					fout << right << Sportsmen[i].Num << '\n';
				}
				else {
					fout << right << Sportsmen[i].Place << "  ";
					fout.width(25);
					fout << left << Sportsmen[i].Organization << "  ";
					fout.width(15);
					fout << left << Sportsmen[i].Surname << "  ";
					fout.width(15);
					fout << left << Sportsmen[i].Name << "  ";
					fout.width(12);
					fout << right << Sportsmen[i].Year_of_birth << "  ";
					fout.width(9);
					fout << right << Sportsmen[i].Result << "  ";
					fout.width(8);
					fout << right << Sportsmen[i].Num << '\n';
				}
			}
			system("cls");
			fout.close();
		} while (action != '0');
	}
	else
	{
		cout << "Спортсмен не найден" << endl;
		system("pause");
	}
	system("cls");
}
void Delete_Data(Sportsmen* Sportsmen, int SportsmenAmount)
{
	system("cls");
	int delete_number;
	bool flag = false;
	cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;
	std::cout << "|Место"
		<< std::setw(5) << "|Организация"
		<< std::setw(24) << "|Фамилия"
		<< std::setw(15) << "|Имя"
		<< std::setw(27) << "|Год рождения"
		<< std::setw(7) << "|Результат"
		<< std::setw(3) << "|№ записи|"
		<< std::endl;
	cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;

	for (int i = 0; i < SportsmenAmount - 1; i++) {
		if (Sportsmen[i].Place > 9)
		{
			cout.width(0);
			cout << "|" << right << Sportsmen[i].Place << " " << std::setw(3) << "|";
			cout.width(25);
			cout << left << Sportsmen[i].Organization << "  " << "|";
			cout.width(15);
			cout << left << Sportsmen[i].Surname << "   " << "|";
			cout.width(15);
			cout << left << Sportsmen[i].Name << "  " << "|";
			cout.width(12);
			cout << right << Sportsmen[i].Year_of_birth << "|";
			cout.width(9);
			cout << right << Sportsmen[i].Result << "|";
			cout.width(8);
			cout << right << Sportsmen[i].Num << "|" << '\n';
			cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;

		}
		else {
			cout.width(0);
			cout << "|" << right << Sportsmen[i].Place << "  " << std::setw(3) << "|";
			cout.width(25);
			cout << left << Sportsmen[i].Organization << "  " << "|";
			cout.width(16);
			cout << left << Sportsmen[i].Surname << "  " << "|";
			cout.width(15);
			cout << left << Sportsmen[i].Name << "  " << "|";
			cout.width(12);
			cout << right << Sportsmen[i].Year_of_birth << "|";
			cout.width(9);
			cout << right << Sportsmen[i].Result << "|";
			cout.width(8);
			cout << right << Sportsmen[i].Num << "|" << '\n';
			cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;
		}
	}

	cout << "Введите номер записи, который хотите удалить: " << endl;
	cin >> delete_number;
	cin.ignore();
	for (int i = 0; i < (SportsmenAmount - 1); i++)
	{
		if (Sportsmen[i].Num == delete_number)
		{
			for (int j = i; j < (SportsmenAmount - 1); j++)
			{
				Sportsmen[j] = Sportsmen[j + 1];
				Sportsmen[j].Num--;
			}
			flag = true;
		}
	}
	if (flag == true) {
		SportsmenAmount--;
		Output(Sportsmen, SportsmenAmount);

		ofstream fout("sportsmen.txt", ios_base::out | ios_base::trunc);
		for (int i = 0; i < SportsmenAmount - 1; i++) {
			if (Sportsmen[i].Place > 9) {
				fout << right << Sportsmen[i].Place << " ";
				fout.width(25);
				fout << left << Sportsmen[i].Organization << "  ";
				fout.width(15);
				fout << left << Sportsmen[i].Surname << "  ";
				fout.width(15);
				fout << left << Sportsmen[i].Name << "  ";
				fout.width(12);
				fout << right << Sportsmen[i].Year_of_birth << "  ";
				fout.width(9);
				fout << right << Sportsmen[i].Result << "  ";
				fout.width(8);
				fout << right << Sportsmen[i].Num << '\n';
			}
			else {
				fout << right << Sportsmen[i].Place << "  ";
				fout.width(25);
				fout << left << Sportsmen[i].Organization << "  ";
				fout.width(15);
				fout << left << Sportsmen[i].Surname << "  ";
				fout.width(15);
				fout << left << Sportsmen[i].Name << "  ";
				fout.width(12);
				fout << right << Sportsmen[i].Year_of_birth << "  ";
				fout.width(9);
				fout << right << Sportsmen[i].Result << "  ";
				fout.width(8);
				fout << right << Sportsmen[i].Num << '\n';
			}
		}
		fout.close();
	}
	else {
		cout << "Нет записи с данным номером" << endl;
		system("pause");
	}
	system("cls");
}
void Swap_sportsmen(Sportsmen* Sportsmen, int SportsmenAmount)
{
	system("cls");
	int number_of_first, number_of_second;

	cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;
	std::cout << "|Место"
		<< std::setw(5) << "|Организация"
		<< std::setw(24) << "|Фамилия"
		<< std::setw(15) << "|Имя"
		<< std::setw(27) << "|Год рождения"
		<< std::setw(7) << "|Результат"
		<< std::setw(3) << "|№ записи|"
		<< std::endl;
	cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;

	for (int i = 0; i < SportsmenAmount - 1; i++) {
		if (Sportsmen[i].Place > 9)
		{
			cout.width(0);
			cout << "|" << right << Sportsmen[i].Place << " " << std::setw(3) << "|";
			cout.width(25);
			cout << left << Sportsmen[i].Organization << "  " << "|";
			cout.width(15);
			cout << left << Sportsmen[i].Surname << "   " << "|";
			cout.width(15);
			cout << left << Sportsmen[i].Name << "  " << "|";
			cout.width(12);
			cout << right << Sportsmen[i].Year_of_birth << "|";
			cout.width(9);
			cout << right << Sportsmen[i].Result << "|";
			cout.width(8);
			cout << right << Sportsmen[i].Num << "|" << '\n';
			cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;

		}
		else {
			cout.width(0);
			cout << "|" << right << Sportsmen[i].Place << "  " << std::setw(3) << "|";
			cout.width(25);
			cout << left << Sportsmen[i].Organization << "  " << "|";
			cout.width(16);
			cout << left << Sportsmen[i].Surname << "  " << "|";
			cout.width(15);
			cout << left << Sportsmen[i].Name << "  " << "|";
			cout.width(12);
			cout << right << Sportsmen[i].Year_of_birth << "|";
			cout.width(9);
			cout << right << Sportsmen[i].Result << "|";
			cout.width(8);
			cout << right << Sportsmen[i].Num << "|" << '\n';
			cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;
		}
	}


	cout << "Введите номер первого спортсмена" << endl;
	cin >> number_of_first;
	cin.ignore();
	if (number_of_first <= 0 || number_of_first >= SportsmenAmount)
	{
		cout << "Данные введены неверно" << endl;
		system("pause");
		return;
	}

	cout << "Введите номер второго спортсмена" << endl;
	cin >> number_of_second;
	cin.ignore();
	if (number_of_second <= 0 || number_of_second >= SportsmenAmount)
	{
		cout << "Данные введены неверно" << endl;
		system("pause");
		return;
	}

	int tmp;
	for (int i = 0; i < SportsmenAmount; i++)
	{
		if (number_of_first == i + 1)
		{
			for (int j = 0; j < SportsmenAmount; j++)
			{
				if (number_of_second == j + 1)
				{
					tmp = Sportsmen[i].Num;
					Sportsmen[i].Num = Sportsmen[j].Num;
					Sportsmen[j].Num = tmp;
					swap(Sportsmen[i], Sportsmen[j]);
				}
			}
		}
	}

	ofstream fout("sportsmen.txt", ios_base::out | ios_base::trunc);
	for (int i = 0; i < SportsmenAmount - 1; i++) {
		if (Sportsmen[i].Place > 9) {
			fout << right << Sportsmen[i].Place << " ";
			fout.width(25);
			fout << left << Sportsmen[i].Organization << "  ";
			fout.width(15);
			fout << left << Sportsmen[i].Surname << "  ";
			fout.width(15);
			fout << left << Sportsmen[i].Name << "  ";
			fout.width(12);
			fout << right << Sportsmen[i].Year_of_birth << "  ";
			fout.width(9);
			fout << right << Sportsmen[i].Result << "  ";
			fout.width(8);
			fout << right << Sportsmen[i].Num << '\n';
		}
		else {
			fout << right << Sportsmen[i].Place << "  ";
			fout.width(25);
			fout << left << Sportsmen[i].Organization << "  ";
			fout.width(15);
			fout << left << Sportsmen[i].Surname << "  ";
			fout.width(15);
			fout << left << Sportsmen[i].Name << "  ";
			fout.width(12);
			fout << right << Sportsmen[i].Year_of_birth << "  ";
			fout.width(9);
			fout << right << Sportsmen[i].Result << "  ";
			fout.width(8);
			fout << right << Sportsmen[i].Num << '\n';
		}
	}
	fout.close();


	system("cls");
	cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;
	std::cout << "|Место"
		<< std::setw(5) << "|Организация"
		<< std::setw(24) << "|Фамилия"
		<< std::setw(15) << "|Имя"
		<< std::setw(27) << "|Год рождения"
		<< std::setw(7) << "|Результат"
		<< std::setw(3) << "|№ записи|"
		<< std::endl;
	cout << "|*****|***************************|******************|*****************|************|*********|********|" << endl;

	for (int i = 0; i < SportsmenAmount - 1; i++) {
		if (Sportsmen[i].Place > 9)
		{
			cout.width(0);
			cout << "|" << right << Sportsmen[i].Place << " " << std::setw(3) << "|";
			cout.width(25);
			cout << left << Sportsmen[i].Organization << "  " << "|";
			cout.width(15);
			cout << left << Sportsmen[i].Surname << "   " << "|";
			cout.width(15);
			cout << left << Sportsmen[i].Name << "  " << "|";
			cout.width(12);
			cout << right << Sportsmen[i].Year_of_birth << "|";
			cout.width(9);
			cout << right << Sportsmen[i].Result << "|";
			cout.width(8);
			cout << right << Sportsmen[i].Num << "|" << '\n';
			cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;

		}
		else {
			cout.width(0);
			cout << "|" << right << Sportsmen[i].Place << "  " << std::setw(3) << "|";
			cout.width(25);
			cout << left << Sportsmen[i].Organization << "  " << "|";
			cout.width(16);
			cout << left << Sportsmen[i].Surname << "  " << "|";
			cout.width(15);
			cout << left << Sportsmen[i].Name << "  " << "|";
			cout.width(12);
			cout << right << Sportsmen[i].Year_of_birth << "|";
			cout.width(9);
			cout << right << Sportsmen[i].Result << "|";
			cout.width(8);
			cout << right << Sportsmen[i].Num << "|" << '\n';
			cout << "|-----|---------------------------|------------------|-----------------|------------|---------|--------|" << endl;
		}
	}

	system("pause");
}
void qsort1(int *arr, int l, int r)
{
	int tmp;
	int i, j;
	i = l;
	j = r;
	int middle = arr[(i + j) / 2];

	do
	{
		while (middle > arr[i]) i++;
		while (middle < arr[j]) j--;

		if (i <= j)
		{
			tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
			i++;
			j--;
		}
	} while (i < j);

	if (l<j) qsort1(arr, l, j);
	if (i<r) qsort1(arr, i, r);
}
void qsort2(int *arr, int l, int r)
{
	int tmp;
	int i, j;
	i = l;
	j = r;
	int middle = arr[(i + j) / 2];

	do
	{
		while (middle < arr[i]) i++;
		while (middle > arr[j]) j--;

		if (i <= j)
		{
			tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
			i++;
			j--;
		}
	} while (i < j);

	if (l<j) qsort2(arr, l, j);
	if (i<r) qsort2(arr, i, r);
}
void compression()
{
	char input_file[] = "sportsmen.txt", output_file[] = "sportsmen.a";
	encodef(input_file, output_file);
}
void decompression()
{
	char input_file[] = "sportsmen.a", output_file[] = "sportsmen.txt";
	decodef(input_file, output_file);
}

void  first(Sportsmen* Sportsmen, int SportsmenAmount)
	{
		int max = 0;
		int k = 0;
		int Year;
		int A;
		for (int i = 0; i < SportsmenAmount - 1; i++)
		{
			k = 0;
			Year = Sportsmen[i].Year_of_birth;
			for (int j = 0; j < SportsmenAmount - 1; j++)
			{
				if (Year == Sportsmen[j].Year_of_birth && Sportsmen[j].Place == 1)
				{
					k++;
				}
			}
			if (max < k) 
			{
				swap(max, k);
				A = i;
			}
		}
		cout << Sportsmen[A].Year_of_birth << " - " << max << " первых мест" << endl;
		system("pause");
	}
