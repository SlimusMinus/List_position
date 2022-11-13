#include "List.h"

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	Dell_All();
}

void List::Add(int _data)
{
	Element* temp = new Element;
	temp->data = _data;
	temp->Next = NULL;
	if (Head != NULL)
	{
		Tail->Next = temp;
		Tail = temp;
	}
	else
		Head = Tail = temp;
	Count++;
}

void List::Add_pos(int pos, int _data)
{
	if (pos == 0)
	{
		cout << "Input position" << endl;
		cin >> pos;
	}
	if (pos < 1 || pos > Count + 1)
		cout << "Error" << endl;

	Element* temp = Head, * prev = nullptr;
	for (int i = 1; i < pos; ++i)
	{
		prev = temp;
		temp = temp->Next;
	}
	Element* newTemp = new Element;
	newTemp->data = _data;
	if (temp != Head)
		prev->Next = newTemp;
	else
		Head = newTemp;
	
	newTemp->Next = temp;
	Count++;
}

void List::Del()
{
	Element* temp = Head;
	Head = Head->Next;
	delete temp;
	Count--;
}


void List::Del_P(int pos)
{
	if (pos == 0)
	{
		cout << "Input position" << endl;
		cin >> pos;
	}
	if (pos < 1 || pos > Count)
		cout << "Error" << endl;
	Element* previous = this->Head;
	for (int i = 1; i < pos-1; i++)
		previous = previous->Next;
	Element* to_del = previous->Next;
	if (pos != 0 && Count != 1)
		previous->Next = to_del->Next;
	if (pos == Count)
		Tail = previous->Next;
	if (pos == 1)
		Head = to_del;
	Count--;
}
void List::Dell_All()
{
	while (Head != NULL)
		Del();
	Count = 0;
}

void List::Print()
{
	Element* tmp = Head;
	while (tmp != NULL)
	{
		cout << tmp->data << "  ";
		tmp = tmp->Next;
	}
	cout << endl << endl;
}

void List::Print(int pos)
{
	Element* temp;
	if (pos < 1 || pos > Count)
		cout << "Error" << endl;

	temp = Head;
	int i = 1;
	while (i < pos)
	{
		temp = temp->Next;
		i++;
	}
	cout <<"Position - " << pos << "    Value - " << temp->data << endl;
}


int List::GetCount()
{
	return Count;
}


void show_menu()
{
	system("cls");
	cout << "Print by position" << endl;
	cout << "Delete by position" << endl;
	cout << "Add by position" << endl;
	cout << "****************" << endl;
	cout << "Press ESC to exit" << endl;
}