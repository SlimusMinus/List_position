#include "List.h"

void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}

int main()
{
	system("color F0");
	List l1;
	int pos, _data, ch = 0, active_menu = 0;
	const int size = 10, num_menu = 3;
	bool q;
	int ar[size] = { 3,6,7,8,9,0,1,2,4,5 };
	for (int i = 0; i < size; i++)
		l1.Add(ar[i]);
	do
	{
		bool exit = false;
		while (!exit)
		{

			show_menu();
			gotoxy(0, active_menu);
			ch = _getch();
			if (ch == 224) ch = _getch();
			switch (ch)
			{

			case 27: exit = true; break;
			case 72: active_menu--; break;
			case 80: active_menu++; break;
			case 13:

				if (active_menu == 0)
				{
					system("cls");
					l1.Print();
					cout << "****************************" << endl;
					cout << "Enter position for print" << endl;
					cin >> pos;
					l1.Print(pos);
					system("pause");
				}
				else if (active_menu == 1)
				{
					system("cls");
					l1.Print();
					cout << "****************************" << endl;
					cout << "Enter position for delete" << endl;
					cin >> pos;
					l1.Del_P(pos);
					l1.Print();
					system("pause");

				}
				else if (active_menu == 2)
				{
					system("cls");
					l1.Print();
					cout << "****************************" << endl;
					cout << "Enter position and value for add" << endl;
					cin >> pos;
					cin >> _data;
					l1.Add_pos(pos, _data);
					l1.Print();
					system("pause");

				}
				break;
			}
			if (active_menu < 0) active_menu = num_menu - 1;
			if (active_menu > num_menu - 1) active_menu = 0;

		}
		system("cls");
		cout << "If you wanna continue press 1, no 0" << endl;
		cin >> q;
		system("cls");
	} while (q == 1);
	system("cls");

}