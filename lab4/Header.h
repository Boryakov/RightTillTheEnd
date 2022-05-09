
#include <iostream>
using namespace std;

struct Aud 
{
	unsigned int build_id;
	unsigned int aud_id;
	unsigned int chairs_count;
	bool desk;
};

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




