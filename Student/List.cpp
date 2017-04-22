#include "List.h"

List::List()
{
	size = 0;
	list = NULL;
}

List::~List()
{
	delete[]list;
	list = NULL;
}

List::List(int s)
{
	size = s;
	list = new Student[size];
}

List::List(const List &l)
{
	size = l.size;
	for (int i = 0; i < size; i++)
		list[i] = l.list[i];
}

List& List::operator = (const List &l)
{
	if (this == &l)
		return *this;
	delete[]this->list;
	this->size = l.size;
	list = new Student[size];
	for (int i = 0; i < size; i++)
		this->list[i] = l.list[i];
	return *this;
}

ostream& operator << (ostream &out, const List &l)
{
	for (int i = 0; i < l.size; i++)
		out << l.list[i] << endl;
	return out;
}

istream& operator >> (istream &in, List &l)
{
	for (int i = 0; i < l.size; i++)
		in >> l.list[i];
	return in;
}

Student& List::operator [](int index) const
{
	return list[index];
}

void List::add()
{
	Student *temp = new Student[size + 1];
	cin >> temp[size];
	for (int i = 0; i < size; i++)
		temp[i] = list[i];
	delete[]list;
	size++;
	list = new Student[size];
	for (int i = 0; i < size; i++)
		list[i] = temp[i];
	delete[]temp;
	cout << endl;
}

void List::del(int x)
{
	if (size == 0)
	{
		cout << "Lista jest pusta" << endl;
		return;
	}
	if ((x<0) || (x>size))
	{
		cout << "Nieprawidlowy numer" << endl;
		return;
	}
	Student *temp = new Student[size - 1];
	int l = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (l != (x - 1))
		{
			temp[i] = list[l];
			l++;
		}
		else
		{
			l++;
			i--;
		}
	}
	delete[]list;
	size--;
	list = new Student[size];
	for (int i = 0; i < size; i++)
		list[i] = temp[i];
	delete[]temp;
	cout << endl;
}

void List::sortSurname()
{
	if (size == 0)
	{
		cout << "Lista jest pusta" << endl;
		return;
	}
	vector<string>names;
	vector<Student>students;
	for (int i = 0; i < size; i++)
	{
		names.push_back(list[i].getSurname());
		students.push_back(list[i]);
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < (size - 1); j++)
		{
			if (names[j] > names[j + 1])
			{
				swap(students[j], students[j + 1]);
				swap(names[j], names[j + 1]);
			}
			else
				continue;
		}
	}
	for (int i = 0; i < students.size(); i++)
	{
		list[i] = students[i];
	}
	cout << "Pomyslnie posortowano\n";
}

void List::sortIndex()
{
	if (size == 0)
	{
		cout << "Lista jest pusta" << endl;
		return;
	}
	vector<int>index;
	vector<Student>students;
	for (int i = 0; i < size; i++)
	{
		index.push_back(list[i].getIndex());
		students.push_back(list[i]);
	}
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (index[j] > index[j + 1])
			{
				swap(students[j], students[j + 1]);
				swap(index[j], index[j + 1]);
			}
		}
	}
	for (int i = 0; i < students.size(); i++)
	{
		list[i] = students[i];
	}
	cout << "Pomyslnie posortowano\n";
}

void List::save()
{
	if (size == 0)
	{
		cout << "Lista jest pusta" << endl;
		return;
	}
	cout << "Pomyslnie zapisano lista do pliku" << endl;
	ofstream plik;
	plik.open("list.txt", ios::out);
	plik << size << endl;
	plik << endl;
	for (int i = 0; i < size; i++)
		plik << list[i] << endl;
	plik.close();
}

void List::load()
{
	ifstream plik;
	plik.open("list.txt", ios::in);
	plik >> size;
	list = new Student[size];
	for (int i = 0; i < size; i++)
		plik >> list[i];
	plik.close();
	cout << "Pomyslnie wczytano liste\n";
}

void List::findIndex(int ind)
{
	bool search = false;
	int s = 0;
	for (int i = 0; i < size; i++)
	{
		if (ind == list[i].getIndex())
		{
			search = true;
			s = i;
		}
	}
	if (search)
		cout << list[s] << endl;
	else
		cout << "Nie znaleziono studenta o indeksie " << ind << endl;
}

void List::findName(string x)
{
	if (size == 0)
	{
		cout << "Lista jest pusta" << endl;
		return;
	}
	vector<Student>students;
	for (int i = 0; i < size; i++)
	{
		size_t znalezionaPozycja = (list[i].getSurname()).find(x);
		if (znalezionaPozycja == std::string::npos)
			continue;
		do
		{
			znalezionaPozycja = (list[i].getSurname()).find(x, znalezionaPozycja + x.size());
			students.push_back(list[i]);
		} while (znalezionaPozycja != std::string::npos);
	}
	cout << "Studenci o nazwisku \"" << x << "\"" << endl;
	for (int i = 0; i < students.size(); i++)
		cout << students[i] << endl;
}

int List::getSize()
{
	return size;
}