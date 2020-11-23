#pragma once
#ifndef TODOLIST_H
#define TODOLIST_H
#include "ToDo.h"
#include <iostream>
#include <fstream>//for file reading and writing
#include <string>//for file reading and writing
using namespace std; 
class ToDoList
{
public:
	ToDo* headPtr;
	int numItems = 0;
	string name;
	ToDoList() {//default constructor
		headPtr = NULL;
		name = "";
	}
	ToDoList(const ToDoList& existing) {//copy constructor
		headPtr = new ToDo(); //instantiate the memory for the head pointer variable
		ToDo* location = new ToDo;
		location = existing.headPtr;//starts at the beginning of the paramter's ToDos
		ToDo* newItem = new ToDo;
		newItem = headPtr;//starts at the beginning of the
		while (location != NULL) {
			Date* copy = new Date();
			copy->copyDate(location->getCreation());
			newItem->setCreation(copy);
			newItem->setDes(location->getDes());
			copy->copyDate(location->getDue());
			newItem->setDue(copy);
			copy->copyDate(location->getLastMod());
			newItem->setLastMod(copy);
			newItem->setPri(location->getPri());
			newItem->setStat(location->getStatus());
			newItem->setTitle(location->getTitle());
			newItem->setType(location->getType());
			location = location->nextItem;
			newItem->nextItem = new ToDo();
			newItem = newItem->nextItem;
		}
	}
	//methods to edit attributes of a ToDo item
	void addItem(ToDo* item);
	void editDes(string edit, int ID);
	void editDue(Date* edit, int ID);
	void editPri(int edit, int ID);
	void editStat(Status edit, int ID);
	void editTitle(string edit, int ID);
	void editType(Type edit, int ID);
	void editLastMod(Date* edit, int ID);
	void deleteItem(int del);
	void deleteByType(Type del);
	void deleteByStatus(Status del);
	void writeFile(string fileName);
	void readFile(string fileName);
	void sortByPriority();
	void sortByDue();
	void sortByCreation();
	void printAll();
	void printByType(Type t);
	void printByPri(int p);
	void printByItem(int ID);
	void merge(ToDoList adding);

};
#endif


