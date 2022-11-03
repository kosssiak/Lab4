#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

#include "List.h"
#include "Node.h"
#include "Menu.h"

int menu() {
	int num_oper = 0;
	cout << "�������� ��������� ���:" << endl;
	cout << "1) �������� ������� � ������ ������" << endl;
	cout << "2) �������� ������� � ����� ������" << endl;
	cout << "3) ������� ������� � ������ ������" << endl;
	cout << "4) ������� ������� � ����� ������" << endl;
	cout << "5) �������� ��������� ������ � ������" << endl;
	cout << "6) �������� ��������� ������ � �����" << endl;
	cout << "7) ����� �������� � ������" << endl;
	cout << "8) ����� �������� � ������ �� �������" << endl;
	cout << "9) ������� ������ � ��������� �������� ������" << endl;
	cout << "10) ���������� ������ ���������" << endl;

	cin >> num_oper;
	if (num_oper <= 0 || num_oper > 10) {
		do {
			cout << "������� ������ �������� ������ ��������:" << endl;
			cin.clear();
			rewind(stdin);
			cin >> num_oper;
		} while (num_oper <= 0 || num_oper > 10);
	}

	return num_oper;
}