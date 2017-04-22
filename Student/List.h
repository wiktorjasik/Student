#pragma once
#include "Student.h"

class List : public Student
{
private:
	int size;
	Student *list;

public:
	List();
	~List();
	List(int);
	List(const List&);
	List& operator = (const List&);
	friend ostream& operator<<(ostream&, const List&);
	friend istream& operator>>(istream&, List&);
	Student& List::operator [](int) const;
	void add();
	void del(int);
	void sortSurname();
	void sortIndex();
	void save();
	void load();
	void findIndex(int);
	void findName(string);
	int getSize();
};