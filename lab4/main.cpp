#include "Header.h"
int main()
{
	List lst;
	lst.push_back(rand_Aud());
	lst.push_back(rand_Aud());
	lst.push_back(rand_Aud());
	lst.push_back(rand_Aud());
	lst.push_back(rand_Aud(34,22));
	lst.push_back(rand_Aud());
	lst.push_back(rand_Aud());
	lst.push_back(rand_Aud());
	lst.push_back(rand_Aud());
	print_Aud(lst.find_aud_by_index(5));
	return 0;
}