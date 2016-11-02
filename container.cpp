#include "tContainer_t.h"
#include <iostream>

#define IS_EMPTY 1 
#define	SIZE 2
#define	INSERT 3
#define FIRST 4
#define	LAST 5	
#define	FIND 6
#define	REMOVE 7
#define	REMOVE_ALL 8
#define	REMOVE_AND_DELETE 9 
#define	REMOVE_AND_DELETE_ALL 10	 
#define	EXIT 11

using namespace std;

void Run();

void IsEmptyTest();
void SizeTest();
void InsertTest();
void FirstTest();
void LastTest();
void FindTest();
void RemoveTest();
void RemoveAllTest();
void RemoveAndDeleteTest();
void RemoveAndDeleteAllTest();

TContainer<int, vector<int*> > g_cont;

int main()
{
	Run();
	
	return 0;
}

/*void Run()
{
	int choice;
	while(choice != 3)
	{
		cout << "1. Test list 2. Test array 3. Exit" << endl;
		cin >> choice;		
		switch(choice)
		{
			case 1:
				g_array = new Dlist_t<int>();
				ContRun();
				delete g_array;
				break;
			case 2:
				g_array = new Array_t<int>();
				ContRun();
				delete g_array;
				break;
			case 3:
				cout << "Invalid input" << endl;
				break;
		}
	}	
}*/

void Run()
{
	int choice = 1;
	while(choice != EXIT)
	{	
		cout << "1. IsEmpty" << endl 
			 << "2. Size" << endl
			 << "3. Insert" << endl
			 << "4. First" << endl
			 << "5. Last" << endl
			 << "6. Find" << endl 
			 << "7. Remove" << endl
			 << "8. RemoveAll" << endl
			 << "9. RemoveAndDelete" << endl
			 << "10. RemoveAndDeleteAll" << endl
			 << "11. Exit" << endl << endl;
	
		cin >> choice;

		switch(choice)
		{
			case IS_EMPTY:
				IsEmptyTest();
				break;
			case SIZE:
				SizeTest();
				break;
			case INSERT:
				InsertTest();
				break;
			case FIRST:
				FirstTest();
				break;
			case LAST:
				LastTest();
				break;
			case FIND:
				FindTest();
				break;
			case REMOVE:
				RemoveTest();
				break;
			case REMOVE_ALL:
				RemoveAllTest();
				break;
			case REMOVE_AND_DELETE:
				RemoveAndDeleteTest();
				break;
			case REMOVE_AND_DELETE_ALL:
				RemoveAndDeleteAllTest();
				break;
			case EXIT:
				break;
			default:
				cout << "Invalid input" << endl;
				break;

		}
	}
}

void IsEmptyTest()
{
	g_cont.IsEmpty() ? cout << "Empty" : cout << "Not empty";
}

void SizeTest()
{
	cout << "Size: " << g_cont.Size() << endl;
}

void InsertTest()
{
	int* num = new int();
	cout << "Enter integer" << endl;
	cin >> *num;
	g_cont.Insert(num);	
	cout << "Success" << endl;
}

void FirstTest()
{
	int* res = (int*)g_cont.First();
	cout << "First: " << *res << endl;
}

void LastTest()
{
	int* res = (int*)g_cont.Last();
	cout << "Last: " << *res << endl;
}

void FindTest()
{
	int num;
	cout << "Enter integer" << endl;
	cin >> num;
	int* res = (int*)g_cont.Find(num);	
	res ? cout << "Empty" : cout << "Not empty";
}

void RemoveTest()
{
	int num;
	cout << "Enter integer" << endl;
	cin >> num;
	int* res = (int*)g_cont.Remove(num);
	if(res)
	{
		cout << "Value: " << *res << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}	
}

void RemoveAllTest()
{
	g_cont.RemoveAll();
	cout << "Done" << endl;
}

void RemoveAndDeleteTest()
{
	int num;
	cout << "Enter integer" << endl;
	cin >> num;
	if(g_cont.RemoveAndDelete(num))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}	
}

void RemoveAndDeleteAllTest()
{
	g_cont.RemoveAndDeleteAll();
	cout << "Done" << endl;
}









































