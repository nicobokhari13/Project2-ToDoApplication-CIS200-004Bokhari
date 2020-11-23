#pragma once
#ifndef TODO_H
#define TODO_H
#include "Date.h"
#include <iostream>
#include <stdlib.h> //srand and rand for ID
#include <time.h>
using namespace std;
enum Type { UNASSIGNED = 0, SHOPPING = 1, CHORES, WORK, SCHOOL };
enum Status { UNKNOWN = 0, DONE = 100, INCOMPLETE = 50, PLANNED = 10 };
struct ToDo
{
public:
	ToDo() {//default
		ID = 0;
		setTitle("");
		setDes("");
		setPri(0);
		setType(UNASSIGNED);
		setStat(UNKNOWN);
		due.setDay(0);
		due.setMonth(0);
		due.setYear(0);
		creation.setDay(0);
		creation.setMonth(0);
		creation.setYear(0);
		lastMod.setDay(0);
		lastMod.setMonth(0);
		lastMod.setYear(0);
	}
	ToDo(string t, string d, Type tp) {
		setTitle(t);
		setDes(d);
		setType(tp);
		setID();
		setStat(UNKNOWN);
		due.setDay(0);
		due.setMonth(0);
		due.setYear(0);
		creation.setDay(0);
		creation.setMonth(0);
		creation.setYear(0);
		lastMod.setDay(0);
		lastMod.setMonth(0);
		lastMod.setYear(0);
	};
	ToDo(string t, Type tp, int p) {
		setTitle(t);
		setType(tp);
		setPri(p);
		setID();
		setDes("");
		setStat(UNKNOWN);
		due.setDay(0);
		due.setMonth(0);
		due.setYear(0);
		creation.setDay(0);
		creation.setMonth(0);
		creation.setYear(0);
		lastMod.setDay(0);
		lastMod.setMonth(0);
		lastMod.setYear(0);
	};
	ToDo(string t, Type tp, int p, Date* d) {
		setTitle(t);
		setType(tp);
		setPri(p);
		setDue(d);
		setID();
		creation.setDay(0);
		creation.setMonth(0);
		creation.setYear(0);
		lastMod.setDay(0);
		lastMod.setMonth(0);
		lastMod.setYear(0);
		setDes("");
		setStat(UNKNOWN);
	};
	~ToDo() {//deconstructor
	}
	void setID() {
		ID = rand() + 1;//ID is never 0
	}
	ToDo* nextItem;
	void setTitle(string t) { Title = t; setID(); }
	void setDes(string d) { des = d; }
	void setPri(int p) { priority = p; };
	void setType(Type t) { type = t; };
	void setStat(Status s) { status = s; };
	void setDue(Date* d) { due.copyDate(*d); };
	void setCreation(Date* c) { creation.copyDate(*c); };
	void setLastMod(Date* l) { lastMod.copyDate(*l); };
	int getID() { return ID; };
	void editID(int newID) {
		ID = newID;
	}
	string getTitle() { return Title; };
	string getDes() { return des; };
	Type getType() { return type; };
	int getPri() { return priority; };
	Status getStatus() { return status; };
	Date getDue() { return due; };
	Date getCreation() { return creation; }
	Date getLastMod() { return lastMod; };
	void operator=(ToDo copy) {
		editID(copy.getID());
		setTitle(copy.getTitle());
		setDes(copy.getDes());
		setPri(copy.getPri());
		setType(copy.getType());
		setStat(copy.getStatus());
		Date* edit = new Date();
		edit->copyDate(copy.getDue());
		setDue(edit);
		edit->copyDate(copy.getCreation());
		setCreation(edit);
		edit->copyDate(copy.getLastMod());
		setLastMod(edit);
	}
private:
	int ID;
	string Title;
	string des;
	Type type;
	int priority;
	Status status;
	Date creation;
	Date due;
	Date lastMod;

};
#endif
