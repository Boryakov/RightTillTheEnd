#include "Header.h"

Aud rand_Aud(int x , int y )
{
	unsigned int aud_id, build_id, chairs;
	bool desk;
	if (!x) { aud_id = rand() % 100; }
	else { aud_id = x; }
	if (!y) { build_id = rand() % 100; }
	else { build_id = y; }
	chairs = rand() % 100;
	desk = rand() % 2;
	Aud data{ aud_id,build_id,chairs,desk };
	return data;
};

List::List() {
	Size = 0;
	head = nullptr;
};

List::~List()

{
};

Aud& List::operator[](const int index)
{
	int n = 0;
	Element* current = this->head;
	while (current != nullptr)
	{
		if (n == index)
		{
			return current->data;
		}
		current = current->next;
		n++;
	}
};

void List::push_back(Aud data)
{
	if (head == nullptr)
	{
		head = new Element(data);
		Size++;
	}
	else
	{
		Element* current = this->head;

		while (current->next != nullptr)
		{
			current = current->next;

		}
		current->next = new Element(data);
		Size++;
	}
};