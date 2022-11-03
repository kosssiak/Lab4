#pragma once

#include "Node.h"

template<class T>
class List
{
	Node<T>* head;
	Node<T>* iter;
	int size;
public:
	friend ostream& operator<< (ostream&, Node<T>*);
	Node<T>* operator+ (int index) {
		Node<T>* cur = iter;
		for (int i = 0; i < index; i++) {
			if (i >= size) {
				break;
			}
			iter = iter->next;
			cur = iter;
		}
		iter = head;
		return cur;
	}
	List()
	{
		size = 0;
		head = nullptr;
		iter = head;
	}
	~List()
	{
		while (size) popFront();
	}
	T enterNum()
	{
		cout << "Введите число для добавления в список:" << endl;
		T num;
		cin >> num;
		return num;
	}
	void pushFront(T value)
	{
		head = new Node<T>(value, head);
		iter = head;
		size++;
	}
	void pushBack(T value)
	{
		if (head == nullptr)
		{
			head = new Node<T>(value);
			iter = head;
		}
		else
		{
			for (Node<T>* current = head; ; current = current->next)
				if (current->next == nullptr)
				{
					break;
					current->next = new Node<T>(value);
				}
		}
		size++;
	}
	int getSize() const
	{
		return size;
	}
	T& operator[] (int index)
	{
		Node<T>* current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		return current->data;
	}
	void popFront()
	{
		if (size <= 0) {
			cout << "Список пуст!" << endl;
			return;
		}
		Node<T>* temp = head;
		head = head->next;
		iter = head;
		delete temp;
		size--;
	}
	void popBack()
	{
		if (size <= 0) {
			cout << "Список пуст!" << endl;
			return;
		}
		removeIndex(size - 1);
	}
	void removeIndex(int index)
	{
		if (index == 0) popFront();
		else
		{
			Node<T>* previous = head;
			for (int i = 0; i < index - 1; i++)
				previous = previous->next;
			Node<T>* temp = previous->next;
			previous->next = temp->next;
			delete temp;
			size--;
		}
	}
	void showFront(List<T>& list)
	{
		if (list.getSize() <= 0) {
			cout << "Список пуст!" << endl;
			return;
		}
		for (int i = 0; i < list.getSize(); i++) {
			cout << list[i] << "  ";
		}
		cout << endl;
	}
	void showBack(List<T>& list)
	{
		if (list.getSize() <= 0) {
			cout << "Список пуст!" << endl;
			return;
		}
		for (int i = list.getSize() - 1; i >= 0; i--) {
			cout << list[i] << "  ";
		}
		cout << endl;
	}
	void searchElem(List<T>& list)
	{
		int flag = 0;
		T num;

		if (list.getSize() == 0) {
			cout << "Список пуст!" << endl;
			return;
		}

		cout << "Введите число для поиска в списке:" << endl;
		cin >> num;

		for (int i = 0; i < list.getSize(); i++) {
			if (list[i] == num) {
				cout << "Введённый элемент найден в списке, его индекс: " << i << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "Введённый элемент не был найден в списке!" << endl;
		}
	}
	void searchElemByIndex(List<T>& list)
	{
		int index;

		if (list.getSize() == 0) {
			cout << "Список пуст!" << endl;
			return;
		}

		cout << "Введите индекс элемента для поиска в списке:" << endl;
		do {
			cin >> index;
			if (index < 0 || index > list.getSize() - 1) {
				cout << "Введите верное значение индекса (от 0 до " << list.getSize() - 1 << ")" << endl;
			}
		} while (index < 0 || index > list.getSize() - 1);

		cout << "Элемент под номером " << index << ": " << list[index] << endl;
	}
	void showFrontIter(List<T>& list) 
	{
		if (list.getSize() <= 0) {
			cout << "Список пуст!" << endl;
			return;
		}
		for (int i = 0; i < list.getSize(); i++) {
			cout << list + i << " ";
		}
		cout << endl;
	}
};

template<class T>
ostream& operator<< (ostream& out, Node<T>* node) {
	return out << node->data << " ";
}

