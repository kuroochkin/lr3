#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "letter.h"
#include "fio.h"
using namespace std;


void check(int& n)
{
	cin.ignore(cin.rdbuf()->in_avail());
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error, enter again:  " << endl;
		cin >> n;
		cin.ignore(cin.rdbuf()->in_avail());
	}
}

class mail // ����� �����(�������� �����)
{
public:
	letter Letter;
	letter* array;
	mail(int size)
	{
		array = new letter[size];
	}
	~mail()
	{
		delete[] array;
	}
};

int main()
{

	setlocale(LC_ALL, "Russian");
	mail Mail(100);
	Mail.Letter.read(Mail.array);
	while (true)
	{
		int menu;
		cout << "�������� ����� ����: " << endl;
		cout << "������� ����� ������ ........................................... 1" << endl;
		cout << "���������� ������ � ��������� ���� ............................. 2" << endl;
		cout << "����� ������ �� ������ ����������� ............................. 3" << endl;
		cout << "C���������� ������ �� ��������� ................................ 4" << endl;
		cout << "����� �� ��������� ............................................. 5" << endl;
		cin >> menu;
		check(menu);
		if (menu == 5)
		{
			break;
		}
		switch (menu)
		{
		case 1:
		{
			Mail.array[letter::count].add_new(Mail.array);
			(letter::count)++;
			break;
		}
		case 2:
		{
			Mail.array->print_header();
			Mail.array->print_info(Mail.array);
			cout << endl;
			break;
		}
		case 3:
		{
			Mail.array->find_letter(Mail.array);
			cout << endl;
			break;
		}
		case 4:
		{
			sort_price(Mail.array);
			break;
		}
		default:
		{
			cout << "���������� �����: " << endl;
			break;
		}

		}
	}
	Mail.Letter.save(Mail.array);

}