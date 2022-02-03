//---------------------------------------------
//|             Sira� Petmez�iler             |
//|                1306190011                 |
//|                18.06.2020                 |
//|Development environment: Visual Studio 2019|
//---------------------------------------------
//This application helps you creating list for shopping.You can create a listand add its products as much as you want with 1st choice.
//You can edit your list with 2nd choice. You can add a product to an existing list, you can delete a product from your lists, you can mark or unmark a product and you can change your product's name or amount.
//You can delete your lists with 3rd choice.
//You can see your lists with 4th choice.
#include <iostream>
#include <map>
#include <string>
using namespace std;

class �r�n {
public:
	int miktar = 0;
	string isim;
	bool al�nd� = false;
};

class Liste {
public:
	string basl�k;
	map<int, �r�n> �r�nler;
};

int main() {
	int a = 0;
	map<int, Liste> Listeler;
	int listesayac = 0;
	cout << "--------------------------------" << endl;
	cout << "|   Welcome To Shopping List   |" << endl;
	cout << "--------------------------------" << endl;
	cout << endl;
	while (a != 9) {
		cout << "--------------------------" << endl;
		cout << "Choose your action:" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Create a new list(Create a new list and add its products)" << endl;
		cout << "2 - Edit a list(add extra product, delete a product,mark or unmark a product,change product's name or amount)" << endl;
		cout << "3 - Delete a list" << endl;
		cout << "4 - Show my lists" << endl;
		cout << "9 - Exit" << endl;
		cout << "--------------------------" << endl;
		cout << "Answer : ";
		cin >> a;
		system("cls");
		if (a != 1 && a != 2 && a != 3 && a != 4 && a != 9) {
			cout << "--------------------------" << endl;
			cout << "Action does not exist" << endl;
		}
		cout << "--------------------------" << endl;

		if (a == 1) {
			string listeAd�;
			int �r�nsayac;
			cout << "List name : ";
			cin.ignore();
			getline(cin, listeAd�);
			cout << "--------------------------" << endl;
			Listeler[listesayac].basl�k = listeAd�;
			cout << "How many products do you want to add : ";
			cin >> �r�nsayac;
			cout << "--------------------------" << endl;
			for (int i = 0; i < �r�nsayac;i++) {
				string �r�nAd�;
				int �r�nMiktar;
				cout << "Name of the product : ";
				cin.ignore();
				getline(cin, �r�nAd�);
				cout << "Amount of the product : ";
				cin >> �r�nMiktar;
				cout << "--------------------------" << endl;
				Listeler[listesayac].�r�nler[i].isim = �r�nAd�;
				Listeler[listesayac].�r�nler[i].miktar = �r�nMiktar;
				cout << "Added" << endl;
				cout << "--------------------------" << endl;
			}
			listesayac++;
			system("cls");
			cout << "--------------------------" << endl;
			cout << "List is created" << endl;
			cout << "--------------------------" << endl;
		}
		if (a == 2){

			cout << "Choose your action" << endl;
			cout << "--------------------------" << endl;
			cout << "1 - Add a product" << endl;
			cout << "2 - Delete a product" << endl;
			cout << "3 - Mark or unmark a product" << endl;
			cout << "4 - Edit a product" << endl;
			cout << "9 - Back" << endl;
			cout << "--------------------------" << endl;
			int f;
			cout << "Answer : ";
			cin >> f;
			system("cls");
			if (f != 1 && f != 2 && f != 3 && f != 4 && f != 9) {
				cout << "--------------------------" << endl;
				cout << "Action does not exist" << endl;
				continue;
			}
			cout << "--------------------------" << endl;
			if (f == 9) {
				continue;
			}
			cout << "Which list do you want to edit?" << endl;
			for (int i = 0;i < listesayac;i++) {
				cout << i + 1 << " - " << Listeler[i].basl�k << endl;
			}
			cout << "--------------------------" << endl;
			int n;
			cout << "Answer : ";
			cin >> n;
			system("cls");
			if (n > listesayac) {
				cout << "--------------------------" << endl;
				cout << "List dos not exist" << endl;
				continue;
			}
			cout << "--------------------------" << endl;
			if (f == 1) {
				int �r�nMiktar;
				string �r�nAd�;
				cout << "Name of the product : ";
				cin.ignore();
				getline(cin, �r�nAd�);
				cout << "Amount of the product : ";
				cin >> �r�nMiktar;
				cout << "--------------------------" << endl;
				Listeler[n - 1].�r�nler[Listeler[n - 1].�r�nler.size()].isim = �r�nAd�;
				Listeler[n - 1].�r�nler[Listeler[n - 1].�r�nler.size()-1].miktar = �r�nMiktar;
				system("cls");
				cout << "--------------------------" << endl;
				cout << "Added" << endl;
			}
			if (f == 2) {
				map<int, �r�n>::iterator it;
				int j = 0;
				cout << "which product do you want to delete :" << endl;
				cout << "--------------------------" << endl;
				for (it = Listeler[n-1].�r�nler.begin();it != Listeler[n-1].�r�nler.end();it++) {
					string x = "";
					if (Listeler[n - 1].�r�nler[j].al�nd� == true) {
						x = "(+)";
					}
					cout << j+1 <<" - " << Listeler[n-1].�r�nler[j].miktar << " " << Listeler[n-1].�r�nler[j].isim << " " << x << endl;
					j++;
				}
				cout << "--------------------------" << endl;
				int t;
				cout << "Answer : ";
				cin >> t;
				system("cls");
				if (t > Listeler[n-1].�r�nler.size()) {
					cout << "--------------------------" << endl;
					cout << "Product does not exist" << endl;
					continue;
				}
				cout << "--------------------------" << endl;
				for (int i = t - 1;i < Listeler[n - 1].�r�nler.size();i++) {
					if (i == Listeler[n - 1].�r�nler.size() - 1) {
						Listeler[n - 1].�r�nler.erase(i);
					}
					else
					{
						Listeler[n - 1].�r�nler[i] = Listeler[n - 1].�r�nler[i + 1];
					}
				}
				cout << "Deleted" << endl;
			}
			if (f == 3) {
				map<int, �r�n>::iterator it;
				int j = 0;
				cout << "which product do you want to mark or unmark :" << endl;
				cout << "--------------------------" << endl;
				for (it = Listeler[n - 1].�r�nler.begin();it != Listeler[n - 1].�r�nler.end();it++) {
					string x = "";
					if (Listeler[n - 1].�r�nler[j].al�nd� == true) {
						x = "(+)";
					}
					cout << j + 1 << " - " << Listeler[n - 1].�r�nler[j].miktar << " " << Listeler[n - 1].�r�nler[j].isim << " " << x << endl;
					j++;
				}
				cout << "--------------------------" << endl;
				int t;
				cout << "Answer : ";
				cin >> t;
				system("cls");
				if (t > Listeler[n-1].�r�nler.size()) {
					cout << "--------------------------" << endl;
					cout << "Product does not exist" << endl;
					continue;
				}
				cout << "--------------------------" << endl;
				if (Listeler[n - 1].�r�nler[t-1].al�nd� == true) {
					Listeler[n - 1].�r�nler[t-1].al�nd� = false;
					cout << "Product is unmarked" << endl;
				}
				else if (Listeler[n - 1].�r�nler[t - 1].al�nd� == false) {
					Listeler[n - 1].�r�nler[t - 1].al�nd� = true;
					cout << "Product is marked" << endl;
				}
			}
			if (f == 4) {
				map<int, �r�n>::iterator it;
				int j = 0;
				cout << "which product do you want to edit:" << endl;
				cout << "--------------------------" << endl;
				for (it = Listeler[n - 1].�r�nler.begin();it != Listeler[n - 1].�r�nler.end();it++) {
					string x = "";
					if (Listeler[n - 1].�r�nler[j].al�nd� == true) {
						x = "(+)";
					}
					cout << j + 1 << " - " << Listeler[n - 1].�r�nler[j].miktar << " " << Listeler[n - 1].�r�nler[j].isim << " " << x << endl;
					j++;
				}
				cout << "--------------------------" << endl;
				int t;
				cout << "Answer : ";
				cin >> t;
				system("cls");
				if (t > Listeler[n - 1].�r�nler.size()) {
					cout << "--------------------------" << endl;
					cout << "Product does not exist" << endl;
					continue;
				}
				cout << "--------------------------" << endl;
				cout << "which operation do you want" << endl;
				cout << "--------------------------" << endl;
				cout << "1 - Change product's name" << endl;
				cout << "2 - Change product's amount" << endl;
				cout << "--------------------------" << endl;
				int y;
				cout << "Answer : ";
				cin >> y;
			    system("cls");
				if (y != 1 && y != 2) {
					cout << "--------------------------" << endl;
					cout << "Operation does not exist" << endl;
				}
				cout << "--------------------------" << endl;
				if (y == 1) {
					cout << "Please enter a new name" << endl;
					cout << "--------------------------" << endl;
					string name;
					cout << "New name : ";
					cin.ignore();
					getline(cin, name);
					system("cls");
					cout << "--------------------------" << endl;
					Listeler[n - 1].�r�nler[t - 1].isim = name;
					cout << "Name changed" << endl;
				}
				if (y == 2) {
					cout << "Please enter a new amount" << endl;
					cout << "--------------------------" << endl;
					int m;
					cout << "New amount : ";
					cin >> m;
					system("cls");
					cout << "--------------------------" << endl;
					Listeler[n - 1].�r�nler[t - 1].miktar = m;
					cout << "Amount changed" << endl;
				}
			}
			cout << "--------------------------" << endl;
		}
		if (a == 3) {
			cout << "which list do you want to delete:" << endl;
			cout << "--------------------------" << endl;
			for (int i = 0;i < listesayac;i++) {
				cout << i + 1 << " - " << Listeler[i].basl�k << endl;
			}
			cout << "--------------------------" << endl;
			int t;
			cout << "Answer : ";
			cin >> t;
			system("cls");
			if (t > listesayac) {
				cout << "--------------------------" << endl;
				cout << "List does not exist" << endl;
				continue;
			}
			cout << "--------------------------" << endl;
			for (int i = t - 1;i < Listeler.size();i++) {
				if (i == Listeler.size() - 1) {
					Listeler.erase(i);
				}
				else
				{
					Listeler[i] = Listeler[i + 1];
				}
			}
			listesayac--;
			cout << "Deleted" << endl;
			cout << "--------------------------" << endl;

		}
		if (a == 4) {
			cout << "Which list do you want to see:" << endl;
			cout << "--------------------------" << endl;
			for (int s = 0;s <= listesayac;s++) {
				if (s == listesayac) {
					cout << s + 1 << " - " << "All lists" << endl;
				}
				else {
					cout << s + 1 << " - " << Listeler[s].basl�k << endl;
				}
			}
			cout << "--------------------------" << endl;
			int t;
			cout << "Answer : ";
			cin >> t;
			system("cls");
			if (t > listesayac + 1) {
				cout << "--------------------------" << endl;
				cout << "List does not exist" << endl;
				continue;
			}
			cout << "--------------------------" << endl;
			if (t == listesayac+1) {
				map<int, �r�n>::iterator it;
				for (int i = 0;i < listesayac;i++) {
					cout << "List's Title : " << Listeler[i].basl�k << endl;
					cout << endl;
					cout << "Amount" << " - " << "Name" << " - " << "+/-" << endl;
					cout << "--------------------------" << endl;
					int j = 0;
					for (it = Listeler[i].�r�nler.begin();it != Listeler[i].�r�nler.end();it++) {
						string x = "";
						if (Listeler[i].�r�nler[j].al�nd� == true) {
							x = "(+)";
						}
						cout << "   " << Listeler[i].�r�nler[j].miktar << "   - " << Listeler[i].�r�nler[j].isim << "   " << x << endl;
						j++;
					}
					cout << "--------------------------" << endl;
				}
			}
			else {
				map<int, �r�n>::iterator it;
				cout << "List's Title : " << Listeler[t-1].basl�k << endl;
				cout << endl;
				cout << "Amount" << " - " << "Name" << " - " << "Mark" << endl;
				cout << "--------------------------" << endl;
				int j = 0;
				for (it = Listeler[t-1].�r�nler.begin();it != Listeler[t-1].�r�nler.end();it++) {
					string x = "";
					if (Listeler[t-1].�r�nler[j].al�nd� == true) {
						x = "(+)";
					}
					cout << "   " << Listeler[t-1].�r�nler[j].miktar << "   - " << Listeler[t-1].�r�nler[j].isim << "   " << x << endl;
					j++;
				}
				cout << "--------------------------" << endl;
			}
		}
	}
}