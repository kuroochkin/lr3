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
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		double a;
		cin >> a;

		if (cin.fail()) { // если предыдущее извлечение оказалось неудачным,
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(cin.rdbuf()->in_avail()); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Вы ввели некорректное число! Попробуйте еще раз ";
		}
		else if (a >= q and a <= w) // если всё хорошо, то возвращаем a
			return a;
		else
		cout << "Вы ввели некорректное число! Попробуйте еще раз ";
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

void letter::add_new(letter* arr) //добавление нового письма
{
	cin >> arr[count]; // использование перегрузки оператора >>
}

void letter::print_header()
{
	cout << "|     Адрес отправителя       |       Адрес получателя       |         Имя получателя          |   Стоимость письма   |" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
}

void letter::print_info(letter* arr)
{
	for (int i = 0; i < count; i++)
	{
		cout << arr[i].address_A << arr[i].address_B << arr[i].name_B.surname << arr[i].name_B.name << arr[i].name_B.patronymic << arr[i].price << endl;
	}
		
}

void letter::find_letter(letter* arr) // поиск письма по адресу отправителя
{
	int exit = 0;

	if (count == 0)
	{
		cout << "В базе нет писем";
	}
	else
	{
		cout << "Введите адрес отправителя: ";
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
		cout << "В базе нет писем";
	}
	for (int i = 0; i < letter::count; i++)
	{
		for (int j = 0; j < letter::count - 1; j++)
		{
			if (arr[i].price > arr[j].price)
			{
				int swap = arr[i].price; // создали дополнительную переменную
				arr[i].price = arr[j].price; // меняем местами
				arr[j].price = swap;

				string Swap = arr[i].name_B.surname; // создали дополнительную переменную
				arr[i].name_B.surname = arr[j].name_B.surname; // меняем местами
				arr[j].name_B.surname = Swap;

				Swap = arr[i].name_B.name; // создали дополнительную переменную
				arr[i].name_B.name = arr[j].name_B.name; // меняем местами
				arr[j].name_B.name = Swap;

				Swap = arr[i].name_B.patronymic; // создали дополнительную переменную
				arr[i].name_B.patronymic = arr[j].name_B.patronymic; // меняем местами
				arr[j].name_B.patronymic = Swap;

				Swap = arr[i].address_A; // создали дополнительную переменную
				arr[i].address_A = arr[j].address_A; // меняем местами
				arr[j].address_A = Swap;

				Swap = arr[i].address_B; // создали дополнительную переменную
				arr[i].address_B = arr[j].address_B; // меняем местами
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
		cout << "Ошибка открытия файл" << endl;
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
		cout << "Ошибка открытия файла!" << endl;
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
	cout << "Введите адрес отправителя: ";
	out >> obj.address_A;
	cout << "Введите адрес получателя: ";
	out >> obj.address_B;
	cout << "Фамилия получателя: ";
	out >> obj.name_B.surname;
	cout << "Имя получателя: ";
	out >> obj.name_B.name;
	cout << "Отчество получателя: ";
	out >> obj.name_B.patronymic;
	cout << "Введите цену билета: ";
	out >> obj.price;
	while (obj.price < 50 || obj.price > 2000)
	{
		cout << "Ошибка. Введите число от 50 до 2000: ";
		cin >> obj.price;
	}
	check(obj.price);
	return out;
}
