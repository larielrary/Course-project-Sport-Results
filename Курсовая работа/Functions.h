#pragma once
using namespace std;
struct Sportsmen {
	string Organization;
	string Surname;
	string Name;
	int Year_of_birth;
	int Result;
	int Place;
	int Num;
};

Sportsmen *read_sportsmen(Sportsmen* Obj, int &amount);
Sportsmen *AddStruct(Sportsmen* Obj, int amount);

void Output(Sportsmen* Sportsmen, int SportsmenAmount);
void Input(Sportsmen* &Sportsmen, int &SportsmenAmount);
void Search(Sportsmen* Sportsmen, int SportsmenAmount);
void Sort(Sportsmen* Sportsmen, int SportsmenAmount);
void Changing_Data(Sportsmen* Sportsmen, int SportsmenAmount);
void Delete_Data(Sportsmen* Sportsmen, int SportsmenAmount);
void qsort1(int *a, int l, int r);
void qsort2(int *a, int l, int r);
void Swap_sportsmen(Sportsmen* Sportsmen, int SportsmenAmount);
void compression();
void decompression();
void first(Sportsmen* Sportsmen, int SportsmenAmount);
