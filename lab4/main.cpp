#include "Header.h"
int main()
{

	List lst;
	lst.push_back(rand_Aud());
	lst.push_back(rand_Aud()); 
	lst.push_back(rand_Aud());
	cout << lst[-1].aud_id;

}