#include "Header.h"
int main()
{
	List lst;
	char c;
	do
	{
		system("cls");
		cout << "a. Add audience to start" << endl;
		cout << "s. Add audience to end" << endl;
		cout << "p. Print list." << endl;
		cout << "c. Clear list." << endl;
		cout << "d. Delete audience by index" << endl;
		cout << "f. Find audience in list by index" << endl;
		cout << "k. Find audience in list by key" << endl;
		cout << "r. Add five random audiences to the end of list." << endl;
		cout << "q. Quit." << endl;
		cout << "P.S. Indexation starts from 1 (NOT FROM 0!)" << endl;
		cin >> c;
		switch (c)
		{
		case 'a':
		{
			system("cls");
			Aud aud = input_aud();
			lst.push_front(aud);
			cout << "Audience was added to list."<<endl;
			break;
		}
		case 'p':
		{
			if (lst.GetSize() == 0) { cout << "list is clear" << endl;break; }
			system("cls");
			lst.print_list();
			break;
		}
		case 's':
		{
			system("cls");
			Aud aud = input_aud();
			lst.push_back(aud);
			cout << "Audience was added to list." << endl;
			break;
		}
		case 'c':
		{
			system("cls");
			lst.clear_list();
			cout << "List was cleared." << endl;
			break;
		}
		case 'd':
		{
			system("cls");
			unsigned int x;
			cout << "Enter your index:";
			cin >> x;
			if (x>lst.GetSize()||x<0)
			{
				cout << "Index is more than list size" << endl;
			}
			else
			{
				lst.delete_aud_by_index(x);
				cout << "Audience was deleted" << endl;
			}
			break;
		}
		case 'f':
		{
			system("cls");
			unsigned int x;
			cout << "Enter your index:";
			cin >> x;
			Aud y = lst.find_aud_by_index(x);
			if (y == Aud{ -1,0,0,0 })
			{
				cout << "Audience is not in list "<<endl;
			}
			else if (y == Aud{ -2,0,0,0 })
			{
				cout << "Input index is more than list size"<<endl;
			}
			else
			{
				system("cls");
				print_Aud(y);
			}
			break;
		}
		case 'k':
		{
			system("cls");
			unsigned int x;
			cout << "Enter your key:";
			cin >> x;
			Aud y = lst.find_aud_by_key(x);
			if (y == Aud{ -1,0,0,0 })
			{
				cout << "Audience is not in list "<<endl;
			}
			else if (y == Aud{ -2,0,0,0 })
			{
				cout << "Input index is more than list size"<<endl;
			}
			else
			{
				system("cls");
				print_Aud(y);
			}
			break;
		}
		case 'r':
		{
			system("cls");
			for (int i = 0;i < 5;i++) { lst.push_back(rand_Aud()); }
			cout << "5 random audiences was added to the end of list"<< endl;

			break;
		}
		case 'q':
		{
			exit(0);
			break;
		}
		default:;
		}
		system("pause");
	} while (true);
		
		system("pause");
		return 0;
}