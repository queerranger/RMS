#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;
void menu();
void login();
void billing();
void order();
string orders[20];
int order_prices[20];
int bill;
int TotalOrders = 0;
int num;

int main() {

	login();
	system("cls");
	menu();
}

void login() {
	
	
	int opt;
	cout << "Press [1] to signup\nPress [2] to login\n";
	cin >> opt;
	cin.ignore();
	system("cls");
	/*string username = "ranger123";
	int pass = 12345;
	string ent_user;
	int ent_pass;

	do {
		cout << "\nEnter username: ";
		cin >> ent_user;
		cout << "Enter password: ";
		cin >> ent_pass;
		if (ent_user != username || ent_pass != pass)
			cout << "\nWrong username or pass";
	} while (ent_user != username || ent_pass != pass);*/
	ofstream obj;
	switch (opt) {
	case 1:
		cout << "Welcome to signup\n";
		obj.open("accounts.txt", ios::app);
		if (obj.is_open()) {
			string username;
			string password;

			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;

			obj << username << endl;
			obj << password << endl;
			obj.close();
		}
		else
			cout << "Error: couldn't access file.\n";
		system("cls");

	case 2:
		int counter = 0;
		do{cout << "Enter credentials.\n";
		string ent_usr;
		string ent_pass;
		string array[20];
		ifstream file;
		file.open("accounts.txt");
		cout << "Enter username: ";
		cin >> ent_usr;
		cout << "Enter password: ";
		cin >> ent_pass;
		
		if (file.is_open())
		{
			for (int i = 0;i < 20;i++) {
				file >> array[i];
				if (ent_usr == array[i])
					counter++;
				
				if (ent_pass == array[i])
					counter++;
				if (counter == 2)
					break;
			}
			if (counter == 2)
				cout << "Login successful.\n";
			else
				cout << "Wrong credentials.\n";
			file.close();
		}

		else
			cout << "Error\n";

		} while (counter != 2);
				break;
			
		}





}

void menu()

{//menu items
	string menu_items[4] = { "[Appetizers]","[Soups]", "[Maincourse]","[Desserts]" };
	string appetizer[3] = { "[Garlic Bread]","[Chicken Wings]","[Nachos with cheese]" };
	string soups[3] = { "[Corn Soup]","[Hot n Sour]","[Yakhni]" };
	string maincourse[3] = { "[Lache wala Paratha]","[Nihari]","[Daal]" };
	string desserts[2] = { "[Kheer]","[Sohan Halwa]" };
	//menu prices
	int apt_price[3] = { 100,200,300 };
	int soup_price[3] = { 100,200,300 };
	int mainc_price[3] = { 100,200,300 };
	int dsrt_price[2] = { 100,200 };

label:
	cout << "Press:" << endl;
	cout << "[A] for Appetizers" << endl;
	cout << "[B] for Soups" << endl;
	cout << "[C] for MainCourse]" << endl;
	cout << "[D]for  Desserts" << endl;
	char option;
	cin >> option;

	switch (option) {

	case 'a':
		system("cls");
		cout << "----------[Appetizers]----------" << endl;
		for (int i = 0; i < 3; i++)
		{

			cout << appetizer[i] << "    Rs." << apt_price[i] << "(Press [" << i + 1 << "] to order)";
			cout << endl;

		}
		char option_a;
		do {
			cout << "\nEnter index: ";
			cin >> num;
			orders[TotalOrders] = appetizer[num - 1];
			order_prices[TotalOrders] = apt_price[num - 1];
			TotalOrders++;
			bill += 100;
			cout << "Do you want to order more from appetizers? Y/N: ";
			cin >> option_a;
			if (option_a == 'N')
				break;
		} while (option_a == 'Y');

		break;
	case 'A':
		system("cls");
		cout << "----------[Appetizers]----------" << endl;
		for (int i = 0; i < 3; i++)
		{

			cout << appetizer[i] << "    Rs." << apt_price[i] << "(Press [" << i + 1 << "] to order)";
			cout << endl;

		}
		char option_A;
		do {
			cout << "\nEnter index: ";
			cin >> num;
			orders[TotalOrders] = appetizer[num - 1];
			order_prices[TotalOrders] = apt_price[num - 1];
			TotalOrders++;
			bill += 100;
			cout << "Do you want to order more from appetizers? Y/N: ";
			cin >> option_A;
			if (option_A == 'N')
				break;
		} while (option_A == 'Y');

		break;
	case 'b':
		system("cls");
		cout << "----------[Soups]----------" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << soups[i] << "    Rs." << soup_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}
		char option_s;
		do {
			cout << "\nEnter index: ";
			cin >> num;
			orders[TotalOrders] = soups[num - 1];
			order_prices[TotalOrders] = soup_price[num - 1];
			TotalOrders++;
			bill += 100;
			cout << "Do you want to order more from maincourse? Y/N: ";
			cin >> option_s;
			if (option_s == 'N')
				break;
		} while (option_s == 'Y');



		break;
	case 'B':
		system("cls");
		cout << "----------[Soups]----------" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << soups[i] << "    Rs." << soup_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}
		char option_S;
		do {
			cout << "\nEnter index: ";
			cin >> num;
			orders[TotalOrders] = soups[num - 1];
			order_prices[TotalOrders] = soup_price[num - 1];
			TotalOrders++;
			bill += 100;
			cout << "Do you want to order more from maincourse? Y/N: ";
			cin >> option_S;
			if (option_S == 'N')
				break;
		} while (option_S == 'Y');



		break;

	case 'c':
		system("cls");
		cout << "----------[MainCourse]----------" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << maincourse[i] << "    Rs." << mainc_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}

		char option_m;

		do {
			cout << "\nEnter index: ";
			cin >> num;
			orders[TotalOrders] = maincourse[num - 1];
			order_prices[TotalOrders] = { mainc_price[num - 1] };
			TotalOrders++;
			bill += 100;
			cout << "Do you want to order more from maincourse? Y/N: ";
			cin >> option_m;
			if (option_m == 'N')
				break;
		} while (option_m == 'Y');


		break;
	case 'C':
		system("cls");
		cout << "----------[MainCourse]----------" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << maincourse[i] << "    Rs." << mainc_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}

		char option_M;

		do {
			cout << "\nEnter index: ";
			cin >> num;
			orders[TotalOrders] = maincourse[num - 1];
			order_prices[TotalOrders] = { mainc_price[num - 1] };
			TotalOrders++;
			bill += 100;
			cout << "Do you want to order more from maincourse? Y/N: ";
			cin >> option_M;
			if (option_M == 'N')
				break;
		} while (option_M == 'Y');


		break;

	case 'd':
		system("cls");
		cout << "----------[Desserts]----------" << endl;
		for (int i = 0; i < 2; i++)
		{
			cout << desserts[i] << "    Rs." << dsrt_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}
		char option_d;
		do {
			cout << "\nEnter index: ";
			cin >> num;
			orders[TotalOrders] = desserts[num - 1];
			order_prices[TotalOrders] = dsrt_price[num - 1];
			TotalOrders++;
			bill += 100;
			cout << "Do you want to order more from desserts? Y/N: ";
			cin >> option_d;
			if (option_d == 'N')
				break;
		} while (option_d == 'Y');


		break;
	case 'D':
		system("cls");
		cout << "----------[Desserts]----------" << endl;
		for (int i = 0; i < 2; i++)
		{
			cout << desserts[i] << "    Rs." << dsrt_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}
		char option_D;
		do {
			cout << "\nEnter index: ";
			cin >> num;
			orders[TotalOrders] = desserts[num - 1];
			order_prices[TotalOrders] = dsrt_price[num - 1];
			TotalOrders++;
			bill += 100;
			cout << "Do you want to order more from desserts? Y/N: ";
			cin >> option_D;
			if (option_D == 'N')
				break;
		} while (option_D == 'Y');


		break;

	}
	system("cls");
	cout << "------Your order has been placed------" << endl;
	do {
		cout << "Press [1] to go to menu to order other items or [2] to checkout" << endl;
		cin >> num;
		if (num == 1)
			goto label;
		else if (num == 2) {
			billing();
		}
		else cout << "invalid input";
	} while (num != 1 && num != 2);



}



void billing() {

	order();
	system("cls");
	float total = bill + (15.0 / 100 * bill);
	if (num == 1) {
		cout << "Your items cost " << "Rs. " << bill << endl;
		cout << "The tax is 15%" << endl;
		cout << "Your total bill with tax is: " << endl;
		cout << "BILL = " << "Rs " << total << ".00";
		cout << endl;
		cout << "----------------THANKS FOR ORDERING------------------- ";


	}


}
void order()
{
	system("cls");
	cout << "You have ordered the following items: " << endl;
	for (int i = 0; i < TotalOrders; i++) {
		cout << orders[i] << "----Rs." << order_prices[i] << endl;
	}

	cout << "Press [1] to confirm your order and proceed\n";
	cin >> num;
}




