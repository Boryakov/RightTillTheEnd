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
	else { cout << "Desk in class:\t No" << endl << endl; }  // just print audience structure one by one
}

Aud input_aud()
{
	int a_num;
	unsigned int b_num, quant_c;
	bool desk;

	cout << "Enter aud id: ";
	cin >> a_num;
	cout << "Enter build id: ";
	cin >> b_num;
	cout << "Enter quantity chairs: ";
	cin >> quant_c;
	cout << "Are the desk in audience (1 if true 0 if false) : ";
	cin >> desk;

	return Aud{a_num,b_num,quant_c,desk};
}

List::List() { // constructor initializases head of list and list size;
	Size = 0;  
	head = nullptr;
};

List::~List() // destructor , but idk what to insert here

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

void List::print_list() // print every audience one by one ,using print_aud function, from head 
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
		if (current->data.aud_id == aud_id) // if current audience id == input audience id -> return structure
		{
			return current->data;
		}
		current = current->next;
	}
	Aud x = { -1,0,0,0 }; // if audience wasn't found in list , return this audience like "false"
	return x;
}

Aud List::find_aud_by_index(int index) 
{
	if (index > Size)
	{
		Aud x = { -2,0,0,0 };
		return x;
	}
	Element* current = this->head;

	for (int i = 1; i <= Size; i++)
	{
		if (i==index)
		{
			return current->data; // if current index == input index-> return structure
		}
		current = current->next;
	}
	Aud x = { -1,0,0,0 }; // if audience wasn't found in list , return this audience like "false"
	return x;
}

void List::delete_aud_by_index(int index)
{
	if (index == 1) // if index = 1 , just use pop_front 
	{
		pop_front();
	}
	else
	{
		Element* previous = head;
		for (int i = 1; i < index-1;i++)
		{
			previous = previous->next;
		} // find index-1 element;
		Element* to_delete = previous->next; // creating tempoary variable to use his pointer on next obj and delete after
		previous->next = to_delete->next; // take pointer on index + 1 object 
		delete to_delete; // delete element from list by variable pointer
		Size--; // decrease list size
	}
	
}

void List::pop_front()
{
	Element* temp = head; 
	head = head->next; //rewrite head on next item
	delete temp; // delete first object
	Size--;  // decrease list size
}

void List::clear_list()
{
	while (Size != 0)
	{
		pop_front(); // delete first item in list one by one while list will not be empty 
	}
}

void List::push_front(Aud data) 
{
	head = new Element(data, head);// create new head with pointer on old head
	Size++;
}


bool operator==(Aud x, Aud y)
{
	if (x.aud_id == y.aud_id && x.build_id == y.build_id && x.chairs_count == y.chairs_count && x.desk == y.desk)
	{
		return true; // overload operator == , if all variables in structure are same , return true
					 // else return false
	}
	else { return false; } 

}