#include "Header.h"

Aud rand_Aud(int x , int y ) 
{
	unsigned int aud_id, build_id, chairs;
	bool desk;
	if (!x) { aud_id = rand() % 100; } // if parametr wasn't set , generate random id
	else { aud_id = x; }
	if (!y) { build_id = rand() % 100; }
	else { build_id = y; }
	chairs = rand() % 100;
	desk = rand() % 2;
	Aud data{ aud_id,build_id,chairs,desk };
	return data;
};

void print_Aud(Aud data)
{
	cout << "Audience id:\t" << data.aud_id << endl
		<< "Build id:\t" << data.build_id << endl
		<< "Chairs count:\t" << data.chairs_count << endl;
	if (data.desk) { cout << "Desk in class:\t Yes" << endl << endl; }
	else { cout << "Desk in class:\t No" << endl << endl; }
}

List::List() { 
	Size = 0; 
	head = nullptr;
};

List::~List()

{
};

Aud& List::operator[](const int index)
{
	int n = 0; // counter of current element
	Element* current = this->head;  // 1 element pointer
	while (current != nullptr) 
	{
		if (n == index)
		{
			return current->data;  // if current index = input index, return data
		}
		current = current->next; // move to next element
		n++;
	}
};

void List::push_back(Aud data)
{
	if (head == nullptr) // if no objects in list , add current as first
	{
		head = new Element(data);
		Size++;
	}
	else
	{
		Element* current = this->head;

		while (current->next != nullptr) // finding last element
		{
			current = current->next;

		}
		current->next = new Element(data); // creating new last element
		Size++;
	}
};

void List::print_list()
{
	Element* current = this->head;
	for (int i = 0;i < Size;i++)
	{
		cout << "N" << i + 1 << endl;
		print_Aud(current->data);
		current = current->next;
	}
}

Aud List::find_aud_by_key(int aud_id)
{
	Element* current = this->head;
	for (int i = 0; i < Size; i++)
	{
		if (current->data.aud_id == aud_id)
		{
			return current->data;
		}
		current = current->next;
	}
	Aud x = { -1,0,0,0 };
	return x;
}

Aud List::find_aud_by_index(int index)
{
	Element* current = this->head;

	for (int i = 1; i <= Size; i++)
	{
		if (i==index)
		{
			return current->data;
		}
		current = current->next;
	}
	Aud x = { -1,0,0,0 };
	return x;
}

bool operator==(Aud x, Aud y)
{
	if (x.aud_id == y.aud_id && x.build_id == y.build_id && x.chairs_count == y.chairs_count && x.desk == y.desk)
	{
		return true;

	}
	else { return false; }

}