#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

class Student
{
private:
	string name, surname;
	int index;

public:
	Student();
	Student(string, string, int);
	Student(const Student&);
	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student&);
	string getName();
	string getSurname();
	int getIndex();
	friend ofstream& operator << (ofstream&, const Student&);
	friend ifstream& operator >> (ifstream&, Student&);
};