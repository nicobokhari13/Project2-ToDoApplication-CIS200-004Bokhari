#include "ToDoList.h"
using namespace std;
void ToDoList::addItem(ToDo* item) {
	if (headPtr == NULL) {//if new list 
		headPtr = item;
		headPtr->nextItem = NULL; //ensures last ptr is NULL
		numItems++;
	}
	else {
		item->nextItem = headPtr;
		headPtr = item;
		numItems++;
	}
}
void ToDoList::editDes(string edit, int ID) {
	ToDo* traverse = new ToDo;
	traverse = headPtr;
	while (traverse != NULL) {
		if (traverse->getID() == ID) {
			traverse->setDes(edit);
			break;
		}
		traverse = traverse->nextItem;
	}
}
void ToDoList::editDue(Date* edit, int ID) {
	ToDo* traverse = new ToDo;
	traverse = headPtr;
	while (traverse != NULL) {
		if (traverse->getID() == ID) {
			traverse->setDue(edit);
			break;
		}
		traverse = traverse->nextItem;
	}
}
void ToDoList::editPri(int edit, int ID) {
	ToDo* traverse = new ToDo;
	traverse = headPtr;
	while (traverse != NULL) {
		if (traverse->getID() == ID) {
			traverse->setPri(edit);
			break;
		}
		traverse = traverse->nextItem;
	}
}
void ToDoList::editStat(Status edit, int ID) {
	ToDo* traverse = new ToDo;
	traverse = headPtr;
	while (traverse != NULL) {
		if (traverse->getID() == ID) {
			traverse->setStat(edit);
			break;
		}
		traverse = traverse->nextItem;
	}
}
void ToDoList::editTitle(string edit, int ID) {
	ToDo* traverse = new ToDo;
	traverse = headPtr;
	while (traverse != NULL) {
		if (traverse->getID() == ID) {
			traverse->setTitle(edit);
			break;
		}
		traverse = traverse->nextItem;
	}
}
void ToDoList::editType(Type edit, int ID) {
	ToDo* traverse = new ToDo;
	traverse = headPtr;
	while (traverse != NULL) {
		if (traverse->getID() == ID) {
			traverse->setType(edit);
			break;
		}
		traverse = traverse->nextItem;
	}
}
void ToDoList::editLastMod(Date* edit, int ID) {
	ToDo* traverse = new ToDo;
	traverse = headPtr;
	while (traverse != NULL) {
		if (traverse->getID() == ID) {
			traverse->setLastMod(edit);
			break;
		}
		traverse = traverse->nextItem;
	}
}
void ToDoList::deleteItem(int del) {
	ToDo* delPtr = new ToDo;
	ToDo* current = new ToDo;
	current = headPtr;
	if (current->getID() == del) {//if the first ToDo needs to be deleted
		delPtr = headPtr;
		headPtr = headPtr->nextItem;
	}
	else {//search for the item to delete
		while (current->nextItem->getID() != del) {//traverse the list until you find ToDo
			current = current->nextItem;
		}//when you do find the ToDo item, it is the one NEXT to current
		delPtr = current->nextItem; // set delPtr to the item to delete
		current->nextItem = current->nextItem->nextItem; //set the 
	}
	delete delPtr;
	numItems--;
}
void ToDoList::deleteByType(Type del) {
	ToDo* delPtr = new ToDo;
	ToDo* prev = new ToDo;
	ToDo* current = new ToDo;
	current = headPtr;
	if (current->getType() == del) {
		delPtr = headPtr;
		headPtr = headPtr->nextItem;
		current = current->nextItem;
		prev = headPtr;
		numItems--;
	}
	while (current != NULL) {
		if (current->getType() == del) {
			prev->nextItem = current->nextItem;//the next item would be the one after deleted;
			delPtr = current;//delPtr is the one with the Type
			current = current->nextItem;//iterate to the next item
			delete delPtr;//delete the item with the status
			delPtr = new ToDo;//create new memeory to store next deleted item
			numItems--;
		}
		else {
			prev = current;//save the spot we were at
			current = current->nextItem;//iterate to the next ToDo item
		}
		//current has iterated to the nextItem
		//it may or may not be NULL
		//if not NULL, it may have the Type
	}
}
void ToDoList::deleteByStatus(Status s) {
	ToDo* delPtr = new ToDo;
	ToDo* prev = new ToDo;
	ToDo* current = new ToDo;
	current = headPtr;
	if (current->getStatus() == s) { 
		delPtr = headPtr;
		headPtr = headPtr->nextItem; 
		current = current->nextItem;
		prev = headPtr;
		numItems--;//decrease numitems in list
	}
	while (current != NULL) {
		if (current->getStatus() == s) {
			prev->nextItem = current->nextItem;//the next item would be the one after deleted;
			delPtr = current;//delPtr is the one with the Status
			current = current->nextItem;//iterate to the next item
			delete delPtr;//delete the item with the status
			delPtr = new ToDo;//create new memeory to store next deleted item
			numItems--;
		}
		else {
			prev = current;//save the spot we were at
			current = current->nextItem;//iterate to the next ToDo item
		}
		//current has iterated to the nextItem
		//it may or may not be NULL
		//if not NULL, it may have the Status
	}
}
void ToDoList::writeFile(string fileName) {
	ofstream fileOut; 
	fileOut.open(fileName);
	ToDo* trav = new ToDo;
	trav = headPtr; 
	while (trav != NULL) {
		fileOut << trav->getID(); 
		fileOut << ", " << trav->getTitle();
		fileOut << ", " << trav->getPri();
		fileOut << ", " << trav->getType();
		fileOut << ", " << trav->getDes();
		fileOut << ", " << trav->getStatus();
		fileOut << ", " << trav->getDue();
		fileOut << ", " << trav->getCreation();
		fileOut << ", " << trav->getLastMod();
		fileOut << endl;
		trav = trav->nextItem;
	}
	fileOut.close();
}
void ToDoList::readFile(string fileName) {
	using namespace std; 
	ifstream file_obj; 
	file_obj.open(fileName);
	string read; 
	cout << "Contents of file: " << fileName << endl;
	while (getline(file_obj, read)) {//while something can be read, need #include string for getline & string
		cout << read << endl;
	}
}
void ToDoList::sortByPriority() {
	ToDo temp;
	ToDo* prev = new ToDo;
	ToDo* current = new ToDo;
	bool mustSwap = false; 
	int search = 1;
	do {
		mustSwap = false; 
		current = headPtr; 
		while (current->nextItem != NULL) {
			if (current->nextItem->getPri() < current->getPri()) {
				temp = *current->nextItem;
				*current->nextItem = *current; 
				*current = temp;
				mustSwap = true;
			}
			current = current->nextItem;
		}

	} while (mustSwap);
}
void ToDoList::sortByDue() {//returns a list with sorted items
	ToDo temp; 
	ToDo* current = new ToDo; 
	ToDo* prev = new ToDo; 
	bool mustSwap = false; 
	do {
		mustSwap = false; 
		current = headPtr;
		while (current->nextItem != NULL) {
			if (current->nextItem->getDue() < current->getDue()) {//if the next due date occurs first
				temp = *current->nextItem;//save info from next
				*current->nextItem = *current; //move later date forward
				*current = temp;//move earlier date back 
				mustSwap = true;//allows loop to continue
			}
			current = current->nextItem;
		}
		

	} while (mustSwap);
}
void ToDoList::sortByCreation() {
	ToDo temp;
	ToDo* current = new ToDo;
	ToDo* prev = new ToDo;
	bool mustSwap = false;
	do {
		mustSwap = false;
		current = headPtr;
		while (current->nextItem != NULL) {
			if (current->nextItem->getCreation() < current->getCreation()) {//if the next due date occurs first
				temp = *current->nextItem;//save info from next
				*current->nextItem = *current; //move later date forward
				*current = temp;//move earlier date back 
				mustSwap = true;//allows loop to continue
			}
			current = current->nextItem; 
		}

	} while (mustSwap);
}
void ToDoList::printAll(){
	ToDo* trav = new ToDo; 
	trav = headPtr; 
	cout << "ID, Title, Priority, Type, Description, Status, Due Date, Creation, LastMod" << endl;
	while (trav != NULL) {
		cout << trav->getID();
		cout << ", " << trav->getTitle();
		cout << ", " << trav->getPri();
		cout << ", " << trav->getType();
		cout << ", " << trav->getDes();
		cout << ", " << trav->getStatus();
		cout << ", " << trav->getDue();
		cout << ", " << trav->getCreation();
		cout << ", " << trav->getLastMod();
		cout << endl;
		trav = trav->nextItem;
	}
	cout << endl;
}
void ToDoList::printByType(Type t) {
	ToDo* trav = new ToDo;
	trav = headPtr; 
	cout << "ID, Title, Priority, Type, Description, Status, Due Date, Creation, LastMod" << endl;
	while (trav != NULL) {
		if (trav->getType() == t) {
			cout << trav->getID();
			cout << ", " << trav->getTitle();
			cout << ", " << trav->getPri();
			cout << ", " << trav->getType();
			cout << ", " << trav->getDes();
			cout << ", " << trav->getStatus();
			cout << ", " << trav->getDue();
			cout << ", " << trav->getCreation();
			cout << ", " << trav->getLastMod();
			cout << endl;
		}
		trav = trav->nextItem;
	}
}
void ToDoList::printByPri(int p) {
	ToDo* trav = new ToDo;
	trav = headPtr;
	cout << "ID, Title, Priority, Type, Description, Status, Due Date, Creation, LastMod" << endl;
	while (trav != NULL) {
		if (trav->getPri() == p) {
			cout << trav->getID();
			cout << ", " << trav->getTitle();
			cout << ", " << trav->getPri();
			cout << ", " << trav->getType();
			cout << ", " << trav->getDes();
			cout << ", " << trav->getStatus();
			cout << ", " << trav->getDue();
			cout << ", " << trav->getCreation();
			cout << ", " << trav->getLastMod();
			cout << endl;
		}
		trav = trav->nextItem;
	}
}
void ToDoList::printByItem(int ID) {
	ToDo* trav = new ToDo;
	trav = headPtr;
	cout << "ID, Title, Priority, Type, Description, Status, Due Date, Creation, LastMod" << endl;
	while (trav != NULL) {
		if (trav->getID() == ID) {
			cout << trav->getID();
			cout << ", " << trav->getTitle();
			cout << ", " << trav->getPri();
			cout << ", " << trav->getType();
			cout << ", " << trav->getDes();
			cout << ", " << trav->getStatus();
			cout << ", " << trav->getDue();
			cout << ", " << trav->getCreation();
			cout << ", " << trav->getLastMod();
			cout << endl;
			break;
		}
		trav = trav->nextItem;
	}
}
void ToDoList::merge(ToDoList adding) {
	ToDo* temp = new ToDo;
	ToDo* add = new ToDo;
	add = adding.headPtr;
	while (add->getPri() != 0) {
		*temp = *add;//set temp equal to an added item
		addItem(temp);//add item
		add = add->nextItem;//move to the next item
	}//the nextItem should be NULL
}





