#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
#include <cstdlib>
#include "List.h"
#include "Node.h"
#include "Menu.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	List<int> list;
	int next_step = 0;
	while (next_step != 10) {
		next_step = menu();
		switch (next_step) {
		case 1:
			system("CLS");
			list.List::pushFront(list.List::enterNum());
			break;
		case 2:
			system("CLS");
			list.List::pushBack(list.List::enterNum());
			break;
		case 3:
			system("CLS");
			if (list.List::getSize() == 0) {
				cout << "Список пуст" << endl;
				break;
			}
			list.List::popFront();
			cout << "Элемент из начала списка был удалён" << endl;
			break;
		case 4:
			system("CLS");
			if (list.List::getSize() == 0) {
				cout << "Список пуст" << endl;
				break;
			}
			cout << "Элемент из конца списка был удалён" << endl;
			list.List::popBack();
			break;
		case 5:
			system("CLS");
			list.List::showFront(list);
			break;
		case 6:
			system("CLS");
			list.List::showBack(list);
			break;
		case 7:
			system("CLS");
			list.List::searchElem(list);
			break;
		case 8:
			system("CLS");
			list.List::searchElemByIndex(list);
			break;
		case 9:
			system("CLS");
			break;
		}
	}
	return 0;
}


