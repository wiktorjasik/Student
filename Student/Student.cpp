#include "Student.h"

Student::Student()
{
	name = "";
	surname = "";
	index = 0;
}

Student::Student(string n, string s, int i)
{
	name = n;
	surname = s;
	index = i;
}

Student::Student(const Student &s)
{
	name = s.name;
	surname = s.surname;
	index = s.index;
}

ostream& operator<<(ostream &out, const Student &s)
{
	out << "Imie: " << s.name << endl;
	out << "Nazwisko: " << s.surname << endl;
	out << "Nr indeksu: " << s.index << endl;
	return out;
}

istream& operator>>(istream &in, Student &s)
{
	cout << "Wpisz imie: ";
	in >> s.name;
	cout << "Wpisz nazwisko: ";
	in >> s.surname;
	cout << "Wpisz nr indeksu: ";
	in >> s.index;
	cout << endl;
	return in;
}

string Student::getName()
{
	return name;
}

string Student::getSurname()
{
	return surname;
}

int Student::getIndex()
{
	return index;
}

ofstream& operator << (ofstream &out, const Student &s)
{
	out << s.name << endl;
	out << s.surname << endl;
	out << s.index << endl;
	return out;
}

ifstream& operator >> (ifstream &in, Student &s)
{
	in >> s.name;
	in >> s.surname;
	in >> s.index;
	return in;
}
