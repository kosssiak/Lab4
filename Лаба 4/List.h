#define _CRT_SECURE_NO_DEPRECATE
#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
#include <cstdlib>
#include "Node.h"

template<class T>
class List
{
	Node<T>* head;
	Node<T>* iter;
	int size;
public:

	List()
	{
		size = 0;
		head = nullptr;
	}
	~List()		
	{
		while (size) popFront();
	}
	T enterNum() 
	{
		T num;
		cout << "������� ����� ��� ���������� � ������:" << endl;
		cin >> num;
		return num;
	}
	void pushFront(T value)
	{
		head = new Node(value, head);
		size++;
	}
	void pushBack(T value)
	{
		if (head == nullptr)
			head = new Node(value);
		else
		{
			for (Node* current = head; ; current = current->next)
				if (current->next == nullptr)
				{
					current->next = new Node(value);
					break;
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
		Node* current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		return current->data;
	}
	void popFront()
	{
		if (size <= 0) {
			cout << "������ ����" << endl;
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	void popBack()	
	{
		if (size <= 0) {
			cout << "������ ����" << endl;
			return;
		}
		removeIndex(size - 1);
	}
	void removeIndex(int index)
	{
		if (index == 0) popFront();
		else
		{
			Node* previous = head;
			for (int i = 0; i < index - 1; i++)
				previous = previous->next;
			Node* temp = previous->next;
			previous->next = temp->next;
			delete temp;
			size--;
		}
	}
	void showFront(List<T>& list)
	{
		if (list.getSize() <= 0) {
			cout << "������ ����" << endl;
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
			cout << "������ ����" << endl;
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
			cout << "������ ����" << endl;
			return;
		}

		cout << "������� ����� ��� ������ � ������:" << endl;
		cin >> num;

		for (int i = 0; i < list.getSize(); i++) {
			if (list[i] == num) {
				cout << "�������� ������� ������ � ������, ��� ������ " << i << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "�������� ������� �� ��� ������ � ������" << endl;
		}
	}
	void searchElemByIndex(List<T>& list)
	{
		int index;

		if (list.getSize() == 0) {
			cout << "������ ����" << endl;
			return;
		}

		cout << "������� ������ �������� ��� ������ � ������:" << endl;
		do {
			cin >> index;
			if (index < 0 || index > list.getSize() - 1) {
				cout << "������� ������ �������� ������� (�� 0 �� " << list.getSize() - 1 << ")" << endl;
			}
		} while (index < 0 || index > list.getSize() - 1);

		cout << "������� ��� ������� " << index << ": " << list[index] << endl;
	}
};