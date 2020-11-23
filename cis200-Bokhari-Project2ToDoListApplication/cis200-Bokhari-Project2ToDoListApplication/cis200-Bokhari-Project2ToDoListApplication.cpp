
#include <iostream>
#include "ToDoList.h"
/*
enum Type { UNASSIGNED = 0, SHOPPING = 1, CHORES, WORK, SCHOOL };
enum Status { UNKNOWN = 0, DONE = 100, INCOMPLETE = 50, PLANNED = 10 };
*/
void printMenu();
void printAllLists(ToDoList* lists, int numLists);
int main()
{
	ToDoList* collection = new ToDoList[3];
	char input = ' ';
	string name = "";
	string words = "";
	int num = 0;
	int listID = 0;
	int itemID = 0;
	int month = 0;
	int day = 0;
	int year = 0;
	printMenu();
	do {
		cin >> input; 
		switch(input) {
		case 'a': 
			cout << "Enter name of the list: "; 
			cin >> name;
			for (int i = 0; i < 3; i++) {
				if (collection[i].name == "") {
					collection[i].name = name;
					break;
				}
			}
			break;
		case 'b':
			cout << "Enter the name of the list you want to add the item to: ";
			cin >> name; 
			for (int i = 0; i < 3; i++) {
				if (collection[i].name == name) {
					listID = i;
					break;
				}
			}
			collection[listID].addItem(new ToDo());
			cout << "Enter the name of the ToDo: ";
			cin >> words; 
			collection[listID].editTitle(words, collection[listID].headPtr->getID());
			cout << "Enter the description: ";
			cin >> words;
			collection[listID].editDes(words, collection[listID].headPtr->getID());
			cout << "Enter the priority between 1 and 5: "; 
			cin >> num;
			collection[listID].editPri(num, collection[listID].headPtr->getID());
			cout << "Enter the Type of ToDo Item: " << endl;
			cout << "UNASSIGNED = 0, SHOPPING = 1, CHORES = 2, WORK = 3, SCHOOL = 4" << endl;
			cin >> num;
			switch (num) {
			case 0:
				collection[listID].editType(UNASSIGNED, collection[listID].headPtr->getID());
				break;
			case 1: 
				collection[listID].editType(SHOPPING, collection[listID].headPtr->getID());
				break;
			case 2: 
				collection[listID].editType(CHORES, collection[listID].headPtr->getID());
				break;
			case 3: 
				collection[listID].editType(WORK, collection[listID].headPtr->getID());
				break;
			case 4: 
				collection[listID].editType(SCHOOL, collection[listID].headPtr->getID());
				break;
			}
			cout << "Enter the status of the ToDo item: " << endl;
			cout << "UNKNOWN = 0, DONE = 100, INCOMPLETE = 50, PLANNED = 10" << endl;
			cin >> num;
			switch (num) {
			case 0:
				collection[listID].editStat(UNKNOWN, collection[listID].headPtr->getID());
				break;
			case 100:
				collection[listID].editStat(DONE,collection[listID].headPtr->getID());
				break;
			case 50:
				collection[listID].editStat(INCOMPLETE, collection[listID].headPtr->getID());
				break;
			case 10:
				collection[listID].editStat(PLANNED, collection[listID].headPtr->getID());
				break;
			}
			cout << "Enter the Due Date's Month: ";
			cin >> month;
			cout << "Enter the Due Date's Day: ";
			cin >> day;
			cout << "Enter the Due Date's Year: ";
			cin >> year;
			collection[listID].editDue(new Date(month, day, year), collection[listID].headPtr->getID());
			cout << "Enter Today's Month: ";
			cin >> month;
			cout << "Enter Today's Day: ";
			cin >> day;
			cout << "Enter Today's Year: ";
			cin >> year;
			collection[listID].headPtr->setCreation(new Date(month, day, year));
			collection[listID].headPtr->setLastMod(new Date(month, day, year));
			break;
		case 'c':
			printAllLists(collection, 3);
			cout << "Which list has the item you want to edit: " << endl;
			cin >> name; 
			for (int i = 0; i < 3; i++) {
				if (collection[i].name == name) {
					listID = i;
					break;
				}
			}
			cout << "Enter the ID of the ToDo Item: ";
			cin >> itemID; 
			cout << "Enter Today's Month: ";
			cin >> month;
			cout << "Enter Today's Day: ";
			cin >> day;
			cout << "Enter Today's Year: ";
			cin >> year;
			collection[listID].editLastMod(new Date(month, day, year), itemID);
			cout << "Edit: " << endl;
			cout << "Title = 1, Description = 2, Priority = 3, Type = 4, Status = 5, Due = 6" << endl;
			cin >> num;
			switch (num) {
			case 1:
				cout << "Enter the name of the ToDo: ";
				cin >> words;
				collection[listID].editTitle(words, itemID);
				break;
			case 2:
				cout << "Enter the description: ";
				cin >> words;
				collection[listID].editDes(words, itemID);
				break;
			case 3:
				cout << "Enter the priority between 1 and 5: ";
				cin >> num; 
				collection[listID].editPri(num, itemID);
				break;
			case 4: 
				cout << "Enter the Type of ToDo Item: " << endl;
				cout << "UNASSIGNED = 0, SHOPPING = 1, CHORES = 2, WORK = 3, SCHOOL = 4" << endl;
				cin >> num;
				switch (num) {
				case 0:
					collection[listID].editType(UNASSIGNED, itemID);
					break;
				case 1:
					collection[listID].editType(SHOPPING, itemID);
					break;
				case 2:
					collection[listID].editType(CHORES, itemID);
					break;
				case 3:
					collection[listID].editType(WORK, itemID);
					break;
				case 4:
					collection[listID].editType(SCHOOL, itemID);
					break;
				}
				break;
			case 5: 
				cout << "Enter the status of the ToDo item: " << endl;
				cout << "UNKNOWN = 0, DONE = 100, INCOMPLETE = 50, PLANNED = 10" << endl;
				cin >> num;
				switch (num) {
				case 0:
					collection[listID].editStat(UNKNOWN, itemID);
					break;
				case 100:
					collection[listID].editStat(DONE, itemID);
					break;
				case 50:
					collection[listID].editStat(INCOMPLETE, itemID);
					break;
				case 10:
					collection[listID].editStat(PLANNED, itemID);
					break;
				}
				break;
			case 6: 
				cout << "Enter the Due Date's Month: ";
				cin >> month;
				cout << "Enter the Due Date's Day: ";
				cin >> day;
				cout << "Enter the Due Date's Year: ";
				cin >> year;
				collection[listID].editDue(new Date(month, day, year), itemID);
				break;
			}
			break;
		case 'd':
			cout << "1 - delete one item 2 - delete by Type 3 - delete by Status: "; 
			cin >> num;
			switch (num) {
			case 1:
				printAllLists(collection, 3);
				cout << "Enter the list's name: ";
				cin >> name; 
				for (int i = 0; i < 3; i++) {
					if (collection[i].name == name) {
						listID = i;
						break;
					}
				}
				cout << "Enter an item ID to delete: "; 
				cin >> itemID;
				collection[listID].deleteItem(itemID);
				break;
			case 2:
				printAllLists(collection, 3);
				cout << "Enter the list's name: ";
				cin >> name;
				for (int i = 0; i < 3; i++) {
					if (collection[i].name == name) {
						listID = i;
						break;
					}
				}
				cout << "Enter the type to delete " << endl;
				cout << "UNASSIGNED = 0, SHOPPING = 1, CHORES = 2, WORK = 3, SCHOOL = 4" << endl;
				cin >> num;
				switch (num) {
				case 0: 
					collection[listID].deleteByType(UNASSIGNED);
					break;
				case 1: 
					collection[listID].deleteByType(SHOPPING);
					break;
				case 2: 
					collection[listID].deleteByType(CHORES);
					break;
				case 3: 
					collection[listID].deleteByType(WORK);
					break;
				case 4: 
					collection[listID].deleteByType(SCHOOL);
					break;
				}
				break;
			case 3:
				printAllLists(collection, 3);
				cout << "Enter the list's name: ";
				cin >> name;
				for (int i = 0; i < 3; i++) {
					if (collection[i].name == name) {
						listID = i;
						break;
					}
				}
				cout << "Enter the status to delete " << endl;
				cout << "UNKNOWN = 0, DONE = 100, INCOMPLETE = 50, PLANNED = 10" << endl;
				cin >> num;
				switch (num) {
				case 0: 
					collection[listID].deleteByStatus(UNKNOWN);
					break;
				case 100: 
					collection[listID].deleteByStatus(DONE);
					break;
				case 50: 
					collection[listID].deleteByStatus(INCOMPLETE);
					break;
				case 10: 
					collection[listID].deleteByStatus(PLANNED);
					break;
				}
				break;

			}
			break;
		case 'e': 
			printAllLists(collection, 3);
			cout << "Enter the name of the list you want to write to file: "; 
			cin >> name; 
			for (int i = 0; i < 3; i++) {
				if (collection[i].name == name) {
					listID = i;
					break;
				}
			}
			cout << "Enter the name of the file: ";
			cin >> name; 
			collection[listID].writeFile(name);
			break;
		case 'f':
			cout << "Enter the name of the file to read: "; 
			cin >> name; 
			collection[0].readFile(name);
			break;
		case 'm':
			cout << "Enter the name of the list you want to add onto "; 
			cin >> name; 
			for (int i = 0; i < 3; i++) {
				if (collection[i].name == name) {
					listID = i;
					break;
				}
			}
			cout << "Enter the name of the list you want to merge onto the previous list :"; 
			cin >> name; 
			for (int i = 0; i < 3; i++) {
				if (collection[i].name == name) {
					num = i;
					break;
				}
			}
			collection[listID].merge(collection[num]);
			break;
		case 'p':
			cout << "Enter what you'd like to print: "; 
			cout << "1 = all of one list 2 = print one list by type 3 = print one list by priority 4 = print one item" << endl;
			cin >> num; 
			switch (num) {
			case 1: 
				cout << "Name of Lists" << endl;
				for (int i = 0; i < 3; i++) {
					cout << collection[i].name << endl;
				}
				cout << "Enter the name of the list you'd like to print: "; 
				cin >> name; 
				for (int i = 0; i < 3; i++) {
					if (collection[i].name == name) {
						listID = i;
						break;
					}
				}
				collection[listID].printAll();
				break;
			case 2: 
				cout << "Name of Lists" << endl;
				for (int i = 0; i < 3; i++) {
					cout << collection[i].name << endl;
				}
				cout << "Enter the name of the list you'd like to print: ";
				cin >> name;
				for (int i = 0; i < 3; i++) {
					if (collection[i].name == name) {
						listID = i;
						break;
					}
				}
				cout << "Enter the type to print: " << endl;
				cout << "UNASSIGNED = 0, SHOPPING = 1, CHORES = 2, WORK = 3, SCHOOL = 4" << endl;
				cin >> num;
				switch (num) {
				case 0: 
					collection[listID].printByType(UNASSIGNED);
					break;
				case 1: 
					collection[listID].printByType(SHOPPING);
					break;
				case 2:
					collection[listID].printByType(CHORES);
					break;
				case 3: 
					collection[listID].printByType(WORK);
					break;
				case 4: 
					collection[listID].printByType(SCHOOL);
					break;
				}
				break;
			case 3: 
				cout << "Name of Lists" << endl;
				for (int i = 0; i < 3; i++) {
					cout << collection[i].name << endl;
				}
				cout << "Enter the name of the list you'd like to print: ";
				cin >> name;
				for (int i = 0; i < 3; i++) {
					if (collection[i].name == name) {
						listID = i;
						break;
					}
				}
				cout << "Enter the priority between 1 and 5 to print: "; 
				cin >> num;
				collection[listID].printByPri(num);
				break;
			case 4: 
				cout << "Name of Lists" << endl;
				for (int i = 0; i < 3; i++) {
					cout << collection[i].name << endl;
				}
				cout << "Enter the name of the list you'd like to print: ";
				cin >> name;
				for (int i = 0; i < 3; i++) {
					if (collection[i].name == name) {
						listID = i;
						break;
					}
				}
				cout << "Enter the item's ID you want to print: "; 
				cin >> itemID; 
				collection[listID].printByItem(itemID);
				break;
			}
			break;
		case 's':
			cout << "Name of Lists" << endl;
			for (int i = 0; i < 3; i++) {
				cout << collection[i].name << endl;
			}
			cout << "Enter the name of the list you'd like to sort: ";
			cin >> name;
			for (int i = 0; i < 3; i++) {
				if (collection[i].name == name) {
					listID = i;
					break;
				}
			}
			cout << "1- sort by Due 2- sort by Priority 3 - sort by Creation" << endl;
			cin >> num; 
			switch (num) {
			case 1: 
				collection[listID].sortByDue();
				break;
			case 2: 
				collection[listID].sortByPriority();
				break;
			case 3: 
				collection[listID].sortByCreation();
				break;
			}
			break;
		}
	printMenu();
	} while (input != 'q');
	cout << "You have exited the application" << endl;
}
void printMenu() {
	cout << "*********MENU**********" << endl;
	cout << "a - Create a new list with a name" << endl;
	cout << "b - Add a ToDo Item to an existing list" << endl;
	cout << "c - edit a ToDo Item's Detail" << endl;
	cout << "d - delete item(s) from an existing list" << endl;
	cout << "e - write existing list to file" << endl;
	cout << "f - read a file with list information" << endl;
	cout << "m - merge an existing list to another list" << endl;
	cout << "s - sort a list" << endl;
	cout << "p - print" << endl;
	cout << "q - quit" << endl;
}
void printAllLists(ToDoList* lists, int numLists) {
	for (int i = 0; i < numLists; i++) {
		cout << "Contents of " << lists[i].name << endl;
		lists[i].printAll();
	}
}