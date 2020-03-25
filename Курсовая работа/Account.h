#pragma once
using namespace std;
struct Users {
	string login;
	string parol;
};
struct Admins {
	string login;
	string parol;
};


void Guest();
void User();
void Admin();

void Managing_Users();
void Register_Users();
void Delete_Users();
bool Autorization_User(Users* users, int UsersAmount);
bool Autorization_Admin(Admins* admins, int AdminsAmount);
bool Check_vvoda(string login, string parol);
void Encryption(string &login, string &parol);
void Decryption(string &login, string &parol);

Users *read_users(Users* users, int &amount);
Users *AddStructUsers(Users* Obj, int amount);
Admins *read_admins(Admins* admin, int &amount);
Admins *AddStructAdmins(Admins* Obj, int amount);
