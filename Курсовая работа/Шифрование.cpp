#include <iostream>
#include <cmath>
#include <fstream>
#include <conio.h>
#include <string>
using namespace std;

int main() {
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "RUS");
	/*
	unsigned char a, b, tmp, c1, c2;
	scanf_s("%c", &a); //������ ����
	scanf_s("%c", &c1); //������
	scanf_s("%c", &b); //������ ����
	scanf_s("%c", &c1); //������
	while (EOF != scanf_s("%c", &c1)) //���� �� �������� ������� ������
	{
		scanf_s("%c", &c2);
		tmp = round((c1 - b + 256 * c2)*1.0 / a);
		printf("%c", tmp);
	}
	return 0;
	/*/
	/*/
	ifstream fin;
	int line;
	fin.open("Encryption.txt");
	//while (!fin.eof()) {
		//getline(fin, line);
		//cout << line << endl;
	//}
	//fin.close();
	int c, a, b;
	scanf_s("%c", &a); //������ ����
	scanf_s("%c", &c); //������
	scanf_s("%c", &b); //������ ����
	scanf_s("%c", &c); //������
	while (!fin.eof()) //���� �� �������� ������� ������
	{
		fin >> line;
		cout << line << endl;
		cout << (line*a + b) % 256 << endl;
		system("pause");
		printf("������\n");
		printf("%c\n", (c*a + b) % 256);
		printf("������\n");
		printf("%c\n", (c*a + b) / 256);
		//cout << (line*a + b) % 256 << endl;
	}
		system("pause");
	return 0;
	*/
	unsigned char c, a, b;
	scanf_s("%c", &a); //������ ����
	scanf_s("%c", &c); //������
	scanf_s("%c", &b); //������ ����
	scanf_s("%c", &c); //������
	while (EOF != scanf_s("%c", &c)) //���� �� �������� ������� ������
	{
		printf("%c", (c*a + b) % 256);
		printf("%c", (c*a + b) / 256);
		ofstream fout("Encryption.txt", ios::app);
		fout << ((c*a + b) % 256) << " " << ((c*a + b) / 256) << endl;
	}
	system("pause");
	return 0;
	system("pause");


}