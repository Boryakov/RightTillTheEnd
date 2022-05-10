
#include <iostream>
using namespace std;

struct Aud 
{
	int aud_id;
	unsigned int build_id;
	unsigned int chairs_count;
	bool desk;
	
};

bool operator==(Aud x, Aud y);

void print_Aud(Aud data);

Aud rand_Aud(int x = 0, int y = 0); // function which generate random audience and 
									// if necessary accepts parametrs build id and audience id

class List
{
private:


public:


	List(); // list constructor
	~List(); // list destructor

	void push_back(Aud data); // function which add audience to the end of the list

	Aud& operator[](const int index); // overloaded [] operator

	int GetSize() { return Size; }; // return size of list

	void print_list();
	
	Aud find_aud_by_key(int aud_id);

	Aud find_aud_by_index(int index);

	void delete_aud_by_index(int index);

	void pop_front();

	void clear_list();

	void push_front(Aud data);

private:

	class Element
	{
	public:
		Aud data;
		Element* next;
		Element(Aud data, Element* pnext = nullptr) // List item constructor
		{
			this->data = data;
			this->next = pnext;


		}
	};
	int Size; // count audiences in list
	Element* head;




};




