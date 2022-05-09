
#include <iostream>
using namespace std;

struct Aud
{
	unsigned int build_id;
	unsigned int aud_id;
	unsigned int chairs_count;
	bool desk;
};

Aud rand_Aud(int x = 0, int y = 0)
{
	Aud data;
	if (!x) { data.aud_id = rand() % 100; }
	else { data.aud_id = x; }
	if (!y) { data.build_id = rand() % 100; }
	else { data.build_id = y; }
	data.chairs_count = rand() % 100;
	data.desk = rand() % 2;
	return data;
}

class List
{
private:


public:


	List();
	~List();

	void push_back(Aud data);
	Aud& operator[](const int index);

private:

	class Element
	{
	public:
		Aud data;
		Element* next;
		Element(Aud data, Element* pnext = nullptr)
		{
			this->data = data;
			this->next = pnext;


		}
	};
	int Size;
	Element* head;

	


};


List::List() {
	Size = 0;
	head = nullptr;
}

List::~List()

{
}

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
}

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
}

int main()
{

	List lst;
	lst.push_back(rand_Aud());
	lst.push_back(rand_Aud()); 
	lst.push_back(rand_Aud());
	cout << lst[1].aud_id;

}