#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include "fio.h"

using namespace std;

class letter
{
	string address_A; // ����� �����������
	string address_B; // ����� ����������
	fio name_B; // ��� ����������
	double price; // ��������� ������

public:
	static int count; // ���-�� �����

	letter();
	~letter();
	void print_header();
	void print_info(letter* arr);
	void add_new(letter* arr);
	void find_letter(letter* arr);
	void read(letter* arr);
	void save(letter* arr);

	friend void sort_price(letter* arr);
	friend bool operator==(letter letter, fio fio);
	friend istream& operator>>(istream& out, letter& obj);

};

void sort_price(letter* arr);
bool operator==(letter letter, fio fio);
