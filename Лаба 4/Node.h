#define _CRT_SECURE_NO_DEPRECATE
#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
#include <cstdlib>
#include "List.h"

template<class T>
class Node
{
	friend class List;
	T data;
	Node* next;
	Node(T t = data, Node* n = nullptr)
	{
		data = t;
		next = n;
	}
};