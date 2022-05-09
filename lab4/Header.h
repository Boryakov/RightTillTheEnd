
#include <iostream>
using namespace std;

struct Aud 
{
	unsigned int build_id;
	unsigned int aud_id;
	unsigned int chairs_count;
	bool desk;
};

Aud rand_Aud(int x=0,int y = 0)
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

	
	List() {}
	

	void push_back(Aud data);


private:
	
	class Element 
	{
	public:
		Aud data;
		Element* next;
		Element(Aud data, Element* next = nullptr)
		{
			this->data = data;
			this->next = next;


		}
	};
	int Size;
	Element* head;

	

	
};


List::List() {
	Size = 0;
	head = nullptr;
}


void List::push_back(Aud data)
{
	if (head == nullptr)
	{
		head = new Element(data);

	}
	else
	{
		Element* current = this->head;

		while (current != nullptr)
		{
			current = current->next;

		}
		current->next = new Element(data);

	}
}

int main()
{
	List lst;
	lst.push_back(rand_Aud());
	lst.push_back(rand_Aud());
	lst.push_back(rand_Aud());
	
	

}