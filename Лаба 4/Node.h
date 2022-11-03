#pragma once

template<class T>
struct Node
{
	T data;
	Node* next;

	Node(T t, Node* n)
	{
		data = t;
		next = n;
	}

	Node(T t)
	{
		data = t;
	}
};

