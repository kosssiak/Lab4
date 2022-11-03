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

int main()
{
	setlocale(LC_ALL, "Rus");
	List<int> list;
	int next_step = 0;
	while (next_step != 10) {
		next_step = menu();
		system("CLS");
		switch (next_step) {
	
		case 1:
			list.List::pushFront(list.List::enterNum());
			break;
		case 2:
			list.List::pushBack(list.List::enterNum());
			break;
		case 3:
			if (list.List::getSize() == 0) {
				cout << "Список пуст" << endl;
				break;
			}
			list.List::popFront();
			cout << "Элемент из начала списка был удалён" << endl;
			break;
		case 4:
			if (list.List::getSize() == 0) {
				cout << "Список пуст" << endl;
				break;
			}
			cout << "Элемент из конца списка был удалён" << endl;
			list.List::popBack();
			break;
		case 5:
			list.List::showFront(list);
			break;
		case 6:
			list.List::showBack(list);
			break;
		case 7:
			list.List::searchElem(list);
			break;
		case 8:
			list.List::searchElemByIndex(list);
			break;
		case 9:
			list.List::showFrontIter(list);
			break;
		default:
			cout << "Произошла ошибка! Повторите ввод!" << endl;
			break;
		}
	}
	return 0;
}


