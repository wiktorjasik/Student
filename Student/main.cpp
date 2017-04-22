#include "Student.h"
#include "List.h"

int main()
{
	List l;
	int k, choose;
	string n;
	cout << "START\n\n";
	cout << "Co chcesz zrobic?\n";
	cout << "1. Stworz nowa liste\n";
	cout << "2. Wczytaj liste z pliku\n\n";
	cout << "Twoj wybor: ";
	cin >> choose;
	if (choose == 1)
	{
		system("cls");
		cout << "Wpisz rozmiar listy: ";
		do
			cin >> k;
		while (k <= 0);
		for (int i = 0; i < k; i++)
			l.add();
		system("pause");
	}
	else
	{
		system("cls");
		l.load();
		system("pause");
	}

	for (;;)
	{
		system("cls");
		cout << "BAZA DANYCH STUDENTOW\n\n";
		cout << "Co chcesz zrobic?\n";
		cout << "1. Wyswietl baze (Rekordow w bazie: " << l.getSize() << ")\n";
		cout << "2. Dodaj element do bazy\n";
		cout << "3. Usun element z bazy\n";
		cout << "4. Sortuj baze wedlug nazwisk\n";
		cout << "5. Sortuj baze wedlug nr indeksow\n";
		cout << "6. Znajdz studenta (nazwisko)\n";
		cout << "7. Znajdz studenta (nr indeksu)\n";
		cout << "8. Zapisz baze do pliku\n";
		cout << "9. Wyjscie\n";
		cout << "Twoj wybor: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			system("cls");
			cout << l << endl;
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Ile rekordow chcesz dodac? ";
			do
				cin >> k;
			while (k <= 0);
			for (int i = 0; i < k; i++)
				l.add();
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "Ktory rekord chcesz usunac? ";
			do
				cin >> k;
			while ((k <= 0) || (k > l.getSize()));
			l.del(k);
			system("pause");
			break;
		case 4:
			system("cls");
			l.sortSurname();
			system("pause");
			break;
		case 5:
			system("cls");
			l.sortIndex();
			system("pause");
			break;
		case 6:
			system("cls");
			cout << "Wpisz nazwisko: ";
			cin >> k;
			l.findName(n);
			system("pause");
			break;
		case 7:
			system("cls");
			cout << "Wpisz numer indeksu: ";
			do
				cin >> k;
			while (k <= 0);
			l.findIndex(k);
			system("pause");
			break;
		case 8:
			system("cls");
			l.save();
			system("pause");
			break;
		case 9:
			system("cls");
			exit(0);
			break;
		default:
			system("cls");
			cout << "Niepoprawny wybor\n";
			system("pause");
			break;
		}
	}

	return 0;
}