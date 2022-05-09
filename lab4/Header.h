
#include <iostream>
using namespace std;

struct Aud
{
	unsigned int build_id;
	unsigned int aud_id;
	unsigned int chairs_count;
	bool desk;
};

Aud rand_Aud(int x = 0, int y = 0);


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




