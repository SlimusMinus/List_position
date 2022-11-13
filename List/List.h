#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
using namespace std;

struct Element
{
	int data;
	Element* Next;
};
class List
{
	Element* Head, *Tail;
	int Count;
public:
	List();
	~List();
	void Add(int _data);
	void Add_pos(int pos, int _data);
	void Del();
	void Del_P(int pos);
	void Dell_All();
	void Print();
	void Print(int pos);
	int GetCount();
};
void show_menu();

