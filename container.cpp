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
#define SUBSCRIPT 11	 
#define	EXIT 12

using namespace std;

void Run();
void RunVector();
void RunList();

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
void SubscriptionTest();

void IsEmptyTestList();
void SizeTestList();
void InsertTestList();
void FirstTestList();
void LastTestList();
void FindTestList();
void RemoveTestList();
void RemoveAllTestList();
void RemoveAndDeleteTestList();
void RemoveAndDeleteAllTestList();
//void SubscriptionTestList();

TContainer<int, vector<int*> > g_cont;
TContainer<int, list<int*> > g_list;

int main()
{
	Run();
	
	return 0;
}

void Run()
{
	int choice;
	while(choice != 3)
	{
		cout << "1. Test vector 2. Test list 3. Exit" << endl;
		cin >> choice;		
		switch(choice)
		{
			case 1:
				RunVector();
				break;
			case 2:
				RunList();
				break;
			case 3:
				break;
			default:
				cout << "Invalid input" << endl;
				break;
		}
	}	
}

void RunVector()
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
			 << "11. Subscript" << endl
			 << "12. Exit" << endl << endl;
	
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
			case SUBSCRIPT:
				SubscriptionTest();
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
	g_cont.IsEmpty() ? cout << "Empty" << endl : cout << "Not empty" << endl;
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
	res ? cout << "Found" << endl : cout << "Not found" << endl;
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

void SubscriptionTest()
{
	int i;
	cout << "Enter index" << endl;
	cin >> i;
	int* res = (int*)g_cont[i];
	cout << "Integer: " << *res << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void RunList()
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
			 << "11. Subscript" << endl
			 << "12. Exit" << endl << endl;
	
		cin >> choice;

		switch(choice)
		{
			case IS_EMPTY:
				IsEmptyTestList();
				break;
			case SIZE:
				SizeTestList();
				break;
			case INSERT:
				InsertTestList();
				break;
			case FIRST:
				FirstTestList();
				break;
			case LAST:
				LastTestList();
				break;
			case FIND:
				FindTestList();
				break;
			case REMOVE:
				RemoveTestList();
				break;
			case REMOVE_ALL:
				RemoveAllTestList();
				break;
			case REMOVE_AND_DELETE:
				RemoveAndDeleteTestList();
				break;
			case REMOVE_AND_DELETE_ALL:
				RemoveAndDeleteAllTestList();
				break;
			case SUBSCRIPT:
				//SubscriptionTestList();
				break;
			case EXIT:
				break;
			default:
				cout << "Invalid input" << endl;
				break;

		}
	}
}

void IsEmptyTestList()
{
	g_list.IsEmpty() ? cout << "Empty" << endl : cout << "Not empty" << endl;
}

void SizeTestList()
{
	cout << "Size: " << g_list.Size() << endl;
}

void InsertTestList()
{
	int* num = new int();
	cout << "Enter integer" << endl;
	cin >> *num;
	g_list.Insert(num);	
	cout << "Success" << endl;
}

void FirstTestList()
{
	int* res = (int*)g_list.First();
	cout << "First: " << *res << endl;
}

void LastTestList()
{
	int* res = (int*)g_list.Last();
	cout << "Last: " << *res << endl;
}

void FindTestList()
{
	int num;
	cout << "Enter integer" << endl;
	cin >> num;
	int* res = (int*)g_list.Find(num);	
	res ? cout << "Found" << endl : cout << "Not found" << endl;
}

void RemoveTestList()
{
	int num;
	cout << "Enter integer" << endl;
	cin >> num;
	int* res = (int*)g_list.Remove(num);
	if(res)
	{
		cout << "Value: " << *res << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}	
}

void RemoveAllTestList()
{
	g_list.RemoveAll();
	cout << "Done" << endl;
}

void RemoveAndDeleteTestList()
{
	int num;
	cout << "Enter integer" << endl;
	cin >> num;
	if(g_list.RemoveAndDelete(num))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}	
}

void RemoveAndDeleteAllTestList()
{
	g_list.RemoveAndDeleteAll();
	cout << "Done" << endl;
}

/*void SubscriptionTestList()
{
	int i;
	cout << "Enter index" << endl;
	cin >> i;
	int* res = (int*)g_list[i];
	cout << "Integer: " << *res << endl;
}*/





































