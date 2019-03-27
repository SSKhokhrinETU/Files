#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

const short SPEC_KEY = 224;
const short UP_ARROW_KEY = 72;
const short DOWN_ARROW_KEY = 80;
const short LEFT_ARROW_KEY = 75;
const short RIGHT_ARROW_KEY = 77;
const short ENTER_KEY = 13;
const short ESC_KEY = 27;
const short SPACE_KEY = 32;
const short BACKSPACE_KEY = 8;
const short NUM_0_KEY = 48;
const short NUM_1_KEY = 49;
const short NUM_2_KEY = 50;
const short NUM_3_KEY = 51;
const short NUM_4_KEY = 52;
const short NUM_5_KEY = 53;
const short NUM_6_KEY = 54;
const short NUM_7_KEY = 55;
const short NUM_8_KEY = 56;
const short NUM_9_KEY = 57;
FILE *pFile;

struct Node
{
	short int nodeIndex;
	short int data;
	Node *next;
	Node *prev;
};

Node * addNode(Node *ptr, short int index, short int data)
{
	ptr = new Node();
	ptr->nodeIndex = index;
	ptr->data = data;
	return ptr;
}

Node * addElement(Node *ptr)
{
	Node *tmp, *p;
	short int position = 0, newData = 0;

	p = ptr;
	while (true)
	{
		system("cls");
		cout << "Number of new element: ";
		cin >> position;
		if (cin.good())
		{
			cin.ignore(1000, '\n');
			break;
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}

	while (true)
	{
		system("cls");
		cout << "Value of new element: ";
		cin >> newData;
		if (cin.good())
		{
			cin.ignore(1000, '\n');
			break;
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}
	if (position == 1)
	{
		tmp = ptr;
		ptr = new Node();
		ptr->nodeIndex = 1;
		ptr->data = newData;
		ptr->next = tmp;
		ptr->prev = NULL;
		ptr->next->prev = ptr;
		if (tmp != NULL)
		{
			short int i = 0;
			while (tmp != NULL)
			{
				tmp->nodeIndex = position + 1 + i++;
				tmp = tmp->next;
			}
		}
		return ptr;
	}
	if (position < 1)
	{
		cout << "\nError: wrong number" << endl;
		return ptr;
	}
	while (p->nodeIndex <= position - 2)
	{
		if (p->next == NULL)
		{
			cout << "\nError: wrong number" << endl;
			return ptr;
		}
		p = p->next;
	}
	tmp = p->next;
	p->next = addNode(p, position, newData);
	p->next->prev = p;
	p = p->next;
	p->next = tmp;
	if (tmp != NULL)
	{
		tmp->prev = p;
		short int i = 0;
		while (tmp != NULL)
		{
			tmp->nodeIndex = position + 1 + i++;
			tmp = tmp->next;
		}
	}
	position = 0;
	newData = 0;
	return ptr;
}

Node * removeNode(Node *ptr)
{
	Node *tmp, *p;
	short int position = 0;
	bool wrongNumber = false;

	p = ptr;


	while (true)
	{
		system("cls");
		cout << "Number of element to remove it: ";
		cin >> position;
		if (cin.good())
		{
			cin.ignore(1000, '\n');
			break;
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}
	if (position < 1)
	{
		cout << "\nError: wrong number" << endl;
		return ptr;
	}
	if (position == 1)
	{
		tmp = ptr->next;
		delete(ptr);
		ptr = tmp;
		if (tmp != NULL)
		{
			ptr->prev = NULL;
			short int i = 0;
			while (tmp != NULL)
			{
				tmp->nodeIndex = position + i++;
				tmp = tmp->next;
			}
		}
		return ptr;
	}
	while (p->nodeIndex <= position - 2)
	{
		if (p->next == NULL)
		{
			cout << "\nError: wrong number" << endl;
			wrongNumber = true;
			break;
		}
		p = p->next;
	}
	if (wrongNumber || (p->next == NULL))
	{
		if (!wrongNumber)
			cout << "\nError: wrong number" << endl;
		wrongNumber = false;
		return ptr;
	}
	if (p->next != NULL)
		tmp = p->next->next;
	else
		tmp = NULL;
	if (p->next->next != NULL)
		p->next->next->prev = p;
	delete(p->next);
	p->next = tmp;
	if (tmp != NULL)
	{
		short int i = 0;
		while (tmp != NULL)
		{
			tmp->nodeIndex = position + i++;
			tmp = tmp->next;
		}
	}
	position = 0;
	return ptr;
}

Node * removeSeveralElements(Node *ptr)
{
	Node *tmp, *p;
	short int firstElementPosition = 0, secondElementPosition = 0;
	bool wrongNumber = false;

	tmp = p = ptr;



	while (true)
	{
		system("cls");
		cout << "Number of first element: ";
		cin >> firstElementPosition;
		if (cin.good())
		{
			cin.ignore(1000, '\n');
			break;
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}


	while (true)
	{
		system("cls");
		cout << "Number of second element: ";
		cin >> secondElementPosition;
		if (cin.good())
		{
			cin.ignore(1000, '\n');
			break;
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}

	if ((firstElementPosition < 1) || (secondElementPosition < 1))
	{
		cout << "\nError: wrong number" << endl;
		return ptr;
	}
	if (firstElementPosition > secondElementPosition)
	{
		firstElementPosition += secondElementPosition;
		secondElementPosition = firstElementPosition - secondElementPosition;
		firstElementPosition -= secondElementPosition;
	}
	if ((firstElementPosition == 1) && (ptr->next == NULL))
	{
		delete(ptr);
		ptr = NULL;
		return ptr;
	}
	if ((firstElementPosition == 1) && (secondElementPosition == 1))
	{
		tmp = ptr->next;
		ptr = ptr->next;
		delete(ptr->prev);
		ptr->prev = NULL;
		if (tmp != NULL)
		{
			short int i = 1;
			while (tmp != NULL)
			{
				tmp->nodeIndex = i++;
				tmp = tmp->next;
			}
		}
		return ptr;
	}
	while (p->nodeIndex <= secondElementPosition - 2)
	{
		if (p->next == NULL)
		{
			cout << "\nError: wrong number" << endl;
			wrongNumber = true;
			break;
		}
		p = p->next;
	}
	if (wrongNumber || (p->next == NULL))
	{
		if (!wrongNumber)
			cout << "\nError: wrong number" << endl;
		wrongNumber = false;
		return ptr;
	}
	if (firstElementPosition == secondElementPosition)
	{
		if (p->next != NULL)
			tmp = p->next->next;
		else
			tmp = NULL;
		delete(p->next);
		p->next = tmp;
		if (tmp != NULL)
		{
		short int i = 0;
		while (tmp != NULL)
		{
			tmp->nodeIndex = firstElementPosition + i++;
			tmp = tmp->next;
		}
		}
		return ptr;
	}
	p = ptr;
	Node *prevTmp, *nextTmp;
	prevTmp = nextTmp = NULL;
	while (p->nodeIndex != firstElementPosition)
		p = p->next;
	prevTmp = p->prev;
	p = p->next;
	tmp = p->next;
	delete(p->prev);
	while (p->nodeIndex != secondElementPosition)
	{
		nextTmp = p->next;
		delete(p);
		p = nextTmp;
	}
	nextTmp = p->next;
	delete(p);
	if ((prevTmp == NULL) && (nextTmp == NULL))
		return NULL;
	if (prevTmp == NULL)
	{
		nextTmp->prev = NULL;
		ptr = nextTmp;
	}
	else if (nextTmp != NULL)
		nextTmp->prev = prevTmp;
	if (nextTmp == NULL)
		prevTmp->next = NULL;
	else if (prevTmp != NULL)
		prevTmp->next = nextTmp;
	tmp = nextTmp;
	if (tmp != NULL)
	{
		short int i = 0;
		while (tmp != NULL)
		{
			tmp->nodeIndex = firstElementPosition + i++;
			tmp = tmp->next;
		}
	}
	return ptr;
}

Node * addList(Node *ptr, short int data)
{
	ptr = addNode(ptr, 1, data);
	return ptr;
}

Node * removeList(Node *ptr)
{
	Node *tmp, *p;
	while (ptr->next != NULL)
	{
		tmp = p = ptr;
		while (p->next != NULL)
		{
			tmp = p;
			p = p->next;
		}
		if (p->nodeIndex != 1)
			delete(p);
		tmp->next = NULL;
	}
	delete(ptr);
	return NULL;
}

Node * saveList(Node *ptr)
{
	Node *p = ptr;
	pFile = fopen("D:\\Temp\\Files\\List.txt", "w");
	
	while (p != NULL)
	{
		fprintf(pFile, "%i\n", p->data);
		p = p->next;
	}
	fclose(pFile);
	return ptr;
}

Node * readList(Node *ptr)
{
	ptr = new Node();
	ptr->nodeIndex = 0;
	ptr->prev = NULL;
	Node *p = ptr, *tmp = NULL;
	short int index = 1;
	pFile = fopen("D:\\Temp\\Files\\List.txt", "r");
	while (fscanf(pFile, "%i", &(p->data)) != EOF)
	{
		p->nodeIndex = index++;
		p->next = new Node();
		p->next->prev = p;
		tmp = p;
		p = p->next;
	}
	fclose(pFile);
	if (ptr->nodeIndex == 0)
	{
		delete(ptr);
		return NULL;
	}
	delete(p);
	tmp->next = NULL;
	return ptr;
}

void displayList(Node *ptr)
{
	if (ptr == NULL)
		cout << "List is empty" << "\n\n\n\n";
	else
	{
		Node *p = ptr;
		cout << "List:" << '\n' << "Index:  ";
		while (p->next != NULL)
		{
			cout << p->nodeIndex << '\t';
			p = p->next;
		}
		cout << p->nodeIndex << '\t';
		p = ptr;
		cout << endl << "Data:   ";
		while (p->next != NULL)
		{
			cout << p->data << '\t';
			p = p->next;
		}
		cout << p->data << '\t' << "\n\n";
	}
}

short int menu(short int num1, short int num2, short int arrow)
{
	if (num1 == SPEC_KEY)
	{
		if (num2 == UP_ARROW_KEY)
			if (arrow > NUM_1_KEY)
				num1 = --arrow;
			else
				num1 = NUM_6_KEY;
		else if (num2 == DOWN_ARROW_KEY)
			if (arrow < NUM_6_KEY)
				num1 = ++arrow;
			else
				num1 = NUM_1_KEY;
		else
			num1 = arrow;
	}

	cout << '\n' << "Add element             ";
	if (num1 == NUM_1_KEY)
		cout << "<--";
	cout << '\n' << "Remove element          ";
	if (num1 == NUM_2_KEY)
		cout << "<--";
	cout << '\n' << "Remove several elements ";
	if (num1 == NUM_3_KEY)
		cout << "<--";
	cout << '\n' << "Add list                ";
	if (num1 == NUM_4_KEY)
		cout << "<--";
	cout << '\n' << "Remove list             ";
	if (num1 == NUM_5_KEY)
		cout << "<--";
	cout << '\n' << "Save list               ";
	if (num1 == NUM_6_KEY)
		cout << "<--";
	cout << "\n\n" << "Press Esc to exit";
	return num1;
}

int main()
{
	short int choose = 0, tempChoose = 0, arrowControl = NUM_1_KEY;
	short int newData = 0;
	Node *head = NULL;
	FILE *in, *out;
	pFile = fopen("D:\\Temp\\Files\\List.txt", "r");  //были изменены настройки препроцессора
	fclose(pFile);

	if (pFile != NULL)
		head = readList(head);

	displayList(head);
	cout << '\n' << "Add element             <--";
	cout << '\n' << "Remove element          ";
	cout << '\n' << "Remove several elements ";
	cout << '\n' << "Add list                ";
	cout << '\n' << "Remove list             ";
	cout << '\n' << "Save list               ";
	cout << "\n\n" << "Press Esc to exit";

	while (choose != ESC_KEY)
	{
		do
		{
			choose = _getch();
			if (choose == SPEC_KEY)
				tempChoose = _getch();
		} while ((choose != ESC_KEY) && (choose != NUM_1_KEY) && (choose != NUM_2_KEY) && (choose != NUM_3_KEY)
			&& (choose != NUM_4_KEY) && (choose != NUM_5_KEY) && (choose != NUM_6_KEY) && (choose != SPEC_KEY) && (choose != ENTER_KEY));

		if (choose == ENTER_KEY)
		{
			system("cls");
			switch (arrowControl)
			{
			case NUM_1_KEY:
				if (head == NULL)
				{
					cout << "There is no list to add new element" << endl;
					break;
				}
				head = addElement(head);
				break;
			case NUM_2_KEY:
				if (head != NULL)
					head = removeNode(head);
				break;
			case NUM_3_KEY:
				if (head != NULL)
					head = removeSeveralElements(head);
				break;
			case NUM_4_KEY:
				if (head == NULL)
				{
					while (true)
					{
						system("cls");
						cout << "Value of first element: ";
						cin >> newData;
						if (cin.good())
						{
							cin.ignore(1000, '\n');
							break;
						}
						cin.clear();
						cin.ignore(1000, '\n');
					}
					head = addList(head, newData);
					head->next = NULL;
					head->prev = NULL;
				}
				else
					cout << "List already exists" << "\n\n";
				break;
			case NUM_5_KEY:
				if (head != NULL)
					head = removeList(head);
				else
					cout << "There is no list to remove it" << "\n\n";
				break;
			case NUM_6_KEY:
				pFile = fopen("D:\\Temp\\Files\\List.txt", "w");
				if (pFile != NULL)
					head = saveList(head);
				else
					cout << "Ther is no save file" << "\n\n";
			}
			cout << "Press any key";
			_getch();
			choose = arrowControl;
		}
		system("cls");
		displayList(head);
		arrowControl = menu(choose, tempChoose, arrowControl);
	}

	return 0;
}