#include "letter.h"
#include "fio.h"
#include <fstream>

ofstream fileout;
ifstream filein;
char files[] = "info.txt";
letter::letter() {

}
letter::~letter() {

}
double getValuedouble(double q, double w)
{
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		double a;
		cin >> a;

		if (cin.fail()) { // ���� ���������� ���������� ��������� ���������,
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cin.ignore(cin.rdbuf()->in_avail()); // � ������� �������� ����������� ����� �� �������� ������
			cout << "�� ����� ������������ �����! ���������� ��� ��� ";
		}
		else if (a >= q and a <= w) // ���� �� ������, �� ���������� a
			return a;
		else
		cout << "�� ����� ������������ �����! ���������� ��� ��� ";
	}
}

void check(double& n)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error, enter again:  " << endl;
		cin >> n;
	}
}

int letter::count = 0;

void letter::add_new(letter* arr) //���������� ������ ������
{
	cin >> arr[count]; // ������������� ���������� ��������� >>
}

void letter::print_header()
{
	cout << "|     ����� �����������       |       ����� ����������       |         ��� ����������          |   ��������� ������   |" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
}

void letter::print_info(letter* arr)
{
	for (int i = 0; i < count; i++)
	{
		cout << arr[i].address_A << arr[i].address_B << arr[i].name_B.surname << arr[i].name_B.name << arr[i].name_B.patronymic << arr[i].price << endl;
	}
		
}

void letter::find_letter(letter* arr) // ����� ������ �� ������ �����������
{
	int exit = 0;

	if (count == 0)
	{
		cout << "� ���� ��� �����";
	}
	else
	{
		cout << "������� ����� �����������: ";
		string address;
		getline(cin, address); getline(cin, address);

		for (int i = 0; i < count; i++)
		{
			if (arr[i].address_A == address)
			{
				if (exit == 0)
				{
					print_header();
					exit++;
				}
				print_info(arr);
			}

		}
	}
}

void sort_price(letter* arr)
{
	if (letter::count == 0)
	{
		cout << "� ���� ��� �����";
	}
	for (int i = 0; i < letter::count; i++)
	{
		for (int j = 0; j < letter::count - 1; j++)
		{
			if (arr[i].price > arr[j].price)
			{
				int swap = arr[i].price; // ������� �������������� ����������
				arr[i].price = arr[j].price; // ������ �������
				arr[j].price = swap;

				string Swap = arr[i].name_B.surname; // ������� �������������� ����������
				arr[i].name_B.surname = arr[j].name_B.surname; // ������ �������
				arr[j].name_B.surname = Swap;

				Swap = arr[i].name_B.name; // ������� �������������� ����������
				arr[i].name_B.name = arr[j].name_B.name; // ������ �������
				arr[j].name_B.name = Swap;

				Swap = arr[i].name_B.patronymic; // ������� �������������� ����������
				arr[i].name_B.patronymic = arr[j].name_B.patronymic; // ������ �������
				arr[j].name_B.patronymic = Swap;

				Swap = arr[i].address_A; // ������� �������������� ����������
				arr[i].address_A = arr[j].address_A; // ������ �������
				arr[j].address_A = Swap;

				Swap = arr[i].address_B; // ������� �������������� ����������
				arr[i].address_B = arr[j].address_B; // ������ �������
				arr[j].address_B = Swap;
			}
		}
	}
}

void letter::read(letter* arr)
{
	filein.open(files);
	if (!filein.is_open())
	{
		cout << "������ �������� ����" << endl;
	}
	else
	{
		filein >> (letter::count);

		for (int i = 0; i < (letter::count); i++)
		{
			filein >> arr[i].address_A;
			filein >> arr[i].address_B;

			filein >> arr[i].name_B.surname;
			filein >> arr[i].name_B.name;
			filein >> arr[i].name_B.patronymic;

			filein >> arr[i].price;
		}
	}
	filein.close();

}

void letter::save(letter* arr)
{
	fileout.open(files);
	if (!fileout.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		fileout << (letter::count) << endl;

		for (int i = 0; i < (letter::count); i++)
		{
			fileout << arr[i].address_A<<endl;
			fileout << arr[i].address_B << endl;

			fileout << arr[i].name_B.surname << endl;
			fileout << arr[i].name_B.name << endl;
			fileout << arr[i].name_B.patronymic << endl;

			fileout << arr[i].price << endl;
		}

	}
	fileout.close();
}

bool operator==(letter letter, fio fio) 
{
	return  (letter.name_B.surname == fio.surname && letter.name_B.name == fio.name && letter.name_B.patronymic == fio.patronymic);
}

istream& operator>>(istream& out, letter& obj)
{
	cout << "������� ����� �����������: ";
	out >> obj.address_A;
	cout << "������� ����� ����������: ";
	out >> obj.address_B;
	cout << "������� ����������: ";
	out >> obj.name_B.surname;
	cout << "��� ����������: ";
	out >> obj.name_B.name;
	cout << "�������� ����������: ";
	out >> obj.name_B.patronymic;
	cout << "������� ���� ������: ";
	out >> obj.price;
	while (obj.price < 50 || obj.price > 2000)
	{
		cout << "������. ������� ����� �� 50 �� 2000: ";
		cin >> obj.price;
	}
	check(obj.price);
	return out;
}
