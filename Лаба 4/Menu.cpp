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
	cout << "Выберите следующий шаг:" << endl;
	cout << "1) Добавить элемент в начало списка" << endl;
	cout << "2) Добавить элемент в конец списка" << endl;
	cout << "3) Удалить элемент с начала списка" << endl;
	cout << "4) Удалить элемент с конца списка" << endl;
	cout << "5) Просмотр элементов списка с начала" << endl;
	cout << "6) Просмотр элементов списка с конца" << endl;
	cout << "7) Поиск элемента в списке" << endl;
	cout << "8) Поиск элемента в списке по индексу" << endl;
	cout << "9) Вывести первый и последний элементы списка" << endl;
	cout << "10) Завершение работы программы" << endl;

	cin >> num_oper;
	if (num_oper <= 0 || num_oper > 10) {
		do {
			cout << "Введите верное значение номера операции:" << endl;
			cin.clear();
			rewind(stdin);
			cin >> num_oper;
		} while (num_oper <= 0 || num_oper > 10);
	}

	return num_oper;
}