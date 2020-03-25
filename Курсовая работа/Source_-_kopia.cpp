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


//������� 
void Rules();//�������
void Output();//����� ����
bool Check_vvoda(string login, string parol);//�������� �� �������� �����/������ ��� �����������/�����������


//���� �������������
void Guest();//������� �����

void User();//������� ������������
bool Autorization_User();//���� usera
void Read_user(string login, string parol);//������ �� ����� user.txt

void Admin();//������ ��������������
bool Autorization_Admin();//���� �������
void Read_admin(string login, string parol);//���������� �� ����� admin.txt
void Changing_accounts();//������� ������ �� ���������� ����������
int register_user();//�-� ������ �� ����������� ����� �������������




int main()
{
	setlocale(LC_ALL, "russian");
	system("cls");
	char act = '1';



	while (act != '0')
	{

		cout << "|      ���������������:     |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|1|          �����          |" << endl;
		cout << "|_|_________________________|" << endl;
		cout << "|2|      ������������       |" << endl;
		cout << "|_|_________________________|" << endl;
		cout << "|3|      �������������      |" << endl;
		cout << "|_|_________________________|" << endl;
		cout << "|4|������� ����������� �����|" << endl;
		cout << "|_|_________________________|" << endl;
		cout << "|0|          �����          |" << endl;
		cout << "|_|_________________________|" << endl;
		act = _getch();

		switch (act)
		{
		case '1': Guest(); break;
		case '2': User(); break;
		case '3': Admin(); break;
		case '4': Rules(); break;
		case '0': break;
		default: cout << "����� ������� ������ 1, 2, 3, 4 ��� 0" << endl; system("pause"); system("cls"); break;
		}

	}
	return 0;
}


//������������    
void Guest()
{
	system("cls");
	char act = '1';
	while (act != '0')
	{

		cout << " ______________________________________" << endl;
		cout << "|         ����� ����������, �����      |" << endl;
		cout << "|______________________________________|" << endl;
		cout << "|1|         �������� ����������        |" << endl;
		cout << "|_|____________________________________|" << endl;
		cout << "|2|           �������� ������          |" << endl;
		cout << "|_|____________________________________|" << endl;
		cout << "|0|               �����                |" << endl;
		cout << "|_|____________________________________|" << endl;
		act = _getch();

		switch (act)
		{
		case '1': Output(); break;
		case '2': Rules(); break;
		case '0': break;
		default: cout << "����� ������� ������ 1, 2��� 0" << endl; system("pause"); system("cls"); break;
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
	cout << "����� ����������, ������������. ���������������, ����������.\n \n";
	while (!aut)
	{
		aut = Autorization_User();
		system("cls");
		if (aut == true)
		{
			while (act != '0')
			{
				cout << " ______________________________________" << endl;
				cout << "|   ��� �������� ��������� ��������:   |" << endl;
				cout << "|______________________________________|" << endl;
				cout << "|1|          �������� ������           |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|2|         ���������� ������          |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|3|            ����� ������            |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|0|         ����� �� ���������         |" << endl;
				cout << "|_|____________________________________|" << endl;
				act = _getch();

				switch (act)
				{
				case '1': cout << " ����� ������� �������� ������ Output();" << endl; break;
				case '2': cout << "����� �������� ���� ������ Input();" << endl; break;
				case '3': cout << " ����� �������� ����� Search()" << endl; break;
				case '0': break;
				default: cout << "����� ������� ������ �� 0 �� 3, ��������� �������!" << endl; system("pause"); break;
				}
				system("cls");
			}
		}
		else
		{
			cout << " \n \t ������ ��� ����� ������� \n" << endl;
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
	cout << "����� ����������, �������������. \n";
	while (!aut)
	{
		aut = Autorization_Admin();
		system("cls");
		if (aut == true)
		{
			while (act != '0')
			{
				cout << " ______________________________________" << endl;
				cout << "|   ��� �������� ��������� ��������:   |" << endl;
				cout << "|______________________________________|" << endl;
				cout << "|1|          �������� ������           |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|2|         ���������� ������          |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|3|    ���������� ��������� ������     |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|4|            ����� ������            |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|5|       �������������� ������        |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|6|          ������� ������            |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|7|          �������� ������           |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|8|      ���������� �������������      |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|9|               �����                |" << endl;
				cout << "|_|____________________________________|" << endl;
				cout << "|0|         ����� �� ���������         |" << endl;
				cout << "|_|____________________________________|" << endl;
				act = _getch();

				switch (act)
				{
				case '1': cout << "����� ��������  Output();<<" << endl; break;
				case '2': cout << "����� �������� Input();" << endl; break;
				case '3': cout << "����� ������� ���������� Sort();" << endl; break;
				case '4': cout << "����� �������� ����� Search();" << endl; break;
				case '5': cout << " Changing();" << endl; break;
				case '6': cout << "Insertion();" << endl; break;
				case '7': cout << "Delete();" << endl; break;
				case '8': Changing_accounts(); break;
				case '9': cout << " Exchange();" << endl; break;
				case '0': break;
				default: cout << "����� ������� ������ �� 1 �� 9, ��������� �������!" << endl; system("pause"); break;
				}
				system("cls");
			}
		}
		else
		{
			cout << "\n \t ������ ��� ����� ������� \n" << endl;
			system("pause");
			system("cls");
			break; return;

		}
	}
	return;
}

bool Autorization_User()//����������� ������������
{
	bool flag = true;//���� ��� ���������
	
	string login;
	cout << "������� �����:" << endl;
	getline(cin, login);
	fflush(stdin);

	string parol;
	cout << "������� ������:" << endl;
	getline(cin, parol);
	fflush(stdin);//������ � ����� ������� ��� ������, � ������ ��������, ��������, ��������
	
	flag =Check_vvoda(login,parol);//������ ������� �� �������� �������� �����

		//���������: ���� ������� ����� �� �������� - ����������� ���������� � ����� �� �����
	if (flag==true)
		{

				Read_user(login, parol);
				bool flag_vxod = false;//���� ����� ������� ���������� � ����� ���� ��������� �� true
				for (int i = 0; i < 100; i++)
				{
					if (login == user[i].login && parol == user[i].parol)
					{
						flag_vxod = true;
						break;
					}
				}

				if (flag_vxod == true)return true; // ���� ������� ���������� - ������
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

bool Autorization_Admin()																		//����������� ������
{
	bool flag = true;//���� ��� ���������


	string login;
	cout << "������� �����:" << endl;
	getline(cin, login);

	fflush(stdin);
	string parol;
	cout << "������� ������:" << endl;
	getline(cin, parol);
	fflush(stdin);

	flag = Check_vvoda(login, parol);//������ ������� �� �������� �������� �����
	//���������: ���� �� �������� ������� �����- ���������� ������ � ������� �� �����
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
		cout << "|       �������� ������ ��������       |" << endl;
		cout << "|______________________________________|" << endl;
		cout << "|1|  ����������� ������ ������������   |" << endl;
		cout << "|_|____________________________________|" << endl;
		cout << "|0|               �����                |" << endl;
		cout << "|_|____________________________________|" << endl;
		act = _getch();

		switch (act)
		{
		case '1': register_user(); break;
		case '0': break;
		default: cout << "����� ������� ������ 1 ��� 0" << endl; system("pause"); system("cls"); break;
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
	cout << "������� ����� ��� ������ ��������:" << endl;
	getline(cin, login);
	fflush(stdin);
	cout << "������� ������ ��� ������ ��������:" << endl;
	getline(cin, parol);
	fflush(stdin);

	flag=Check_vvoda(login, parol);													// �������� �� �������� ������ �����������

//���������: ���� ������� ����� �� �������� - ����������� ���������� � ����� �� ����� � ���������� ��������
	if (flag==true)
	{
		Read_admin(login, parol);
		for (int i = 0; i < 100; i++)						// �������� �� ������������� ��������� �������;
		{
			if (login == admin[i].login)
			{
				cout << "������������(admin) � ����� ������� ��� ����������.\n ������ �������������� ������������� � ������� �������" << endl;
				flag_admin = false;
				system("pause");
			}
		}													// �������� �� ������������� ��������� ������� ���������;

		Read_user(login, parol);		// �������� �� ������������� ��������� �������������;
		for (int i = 0; i < 100; i++)
		{
			if (login == user[i].login)
			{
				cout << "������������ � ����� ������� ��� ����������" << endl;
				flag_user = false;
				system("pause");
			}
		}								// �������� �� ������������� ��������� ������������� ���������;

		if (flag_user == true && flag_admin == true )
		{
			ofstream fout("user.txt", ios::app);
			fout << login << " " << parol << endl;
			cout << "����������� ������ �������" << endl;
			system("pause");
		}
	}
	system("cls");
	return 0;
}

void Rules()
{
	cout << endl;
	cout << "������� ����������� ����������:" << endl;
	cout << "������o 1: ���������� ��������� � ����������." << endl;
	cout << "������o 2: ����� ������ � ������ ������������ �� ������ ��������� 10 ��������. ����������� ����� - 3 �������." << endl;
	cout << "������o 3: ����� � ������ �� ������ ��������� �������� � ��������, ����� ����, ���� � ����� �������������." << endl;
	cout << "������o 4: ������ �������������� ����� ������������� � ��� ������������ �������(��� � ������ ��� ������������). "<< endl;
	cout << "������o 5: " << endl;
	system("pause");
	system("cls");
	return;

}
void Output()
{
	system("cls");
	cout << "����� ������" << endl;
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
	if (flag_symbol_parol == false || flag_symbol_login == false) cout << "�� ����� ����� ��� ������ � ������������� ���������." << endl;
	if (flag_length == false)
	{
		cout << "�� ����� ����� ��� ������ ������������ ������." << endl;
		cout << "\t " << "����� ������ = " << login.length() << " . ����� ������ = " << parol.length() << " ." << endl;
	}
	if (flag_symbol_login == false || flag_length == false || flag_symbol_parol == false) { system("pause"); return false; }
	return true;
}

/*
void Check_vvoda(string login, string parol, bool flag_dlina, bool flag_symbol_login, bool flag_symbol_parol)
{

	if (login.length() > 10 || login.length() < 3 || parol.length() < 3 || parol.length() > 10) // �������� �� ������������ ����� ������ / ������
	{
		flag_dlina = false;
	}																							// �������� �� ������������ ����� ������ / ������


	for (int i = 0; i < login.length(); i++)												// �������� �� ���� �������� ������
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



	}																						// �������� �� ���� �������� ������ ��������
	for (int i = 0; i < parol.length(); i++)												// �������� �� ���� �������� ������
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

	}																						// �������� �� ���� �������� ������ ��������

	//���������, ���� �������� ������� �����
	if (flag_symbol_parol == false || flag_symbol_login == false) cout << "��� ����� ������/������ ���� ������� ������������ ������� (��. �������)." << endl << "���� �� ����� ��������." << endl;
	if (flag_dlina == false)
	{
		cout << "����� ��������� ������/������ �� ������������� ��������." << endl << "���� �� ����� ��������" << endl;
		cout << "����� ������ = " << login.length() << " . ����� ������ = " << parol.length() << " ." << endl;
	}
	if (flag_symbol_login == false || flag_dlina == false || flag_symbol_parol == false) system("pause");
	cout << "��������� ������ � ������� : login >>" << flag_symbol_login << " parol >>" << flag_symbol_parol << endl; system("pause");
	return;
} 
*/
