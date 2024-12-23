#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <windows.h>

using namespace std;
void menu_order_bill();
void login();
void billing();
void order();
void admin();
string orders[20];
int order_prices[20];
int bill;
int TotalOrders = 0;
int num;

int main() {

	int continuee;
	do
	{

		login();

		system("cls");
		menu_order_bill();
		cout << "\nPress 1 to go to start.\nPress anyother button to quit.";
		cin >> continuee;
		if (continuee != 1)
			break;
	} while (continuee == 1);


}

void login() {
	int number;
	int newpassword;
	int password;
	int filepasswords;
	string fileusernames;
	string newusername;
	string username;
	bool admin_;
beginning:
	system("cls");
	cout << " ____________________________________________________________________________________\n";
	cout << "|                                                                                    |\n";
	cout << "|--------------------------Restaurant Management System------------------------------|\n";
	cout << "|                                                                                    |\n";
	cout << "|                           Press [1] to SignUp                                      |\n";
	cout << "|                           Press [2] to login                                       |\n";
	cout << "                            Press [3] for Admin: ";

	cin >> number;
	ofstream file1;
	ifstream file2;
	ifstream file3;
	bool found = false;
	switch (number) {
	case 1: {
		system("cls");
		cout << " ____________________________________________________________________________________\n";
		cout << "|                                                                                    |\n";
		cout << "|------------------------------------SIGN UP-----------------------------------------|\n";
		cout << "                        Enter username: ";
	label5:	cin >> newusername;
		file3.open("DataFile.txt");
		bool UsernameAvailable = true;
		while (file3 >> fileusernames >> filepasswords) {
			if (newusername == fileusernames) {
		cout << "\n            This username is already taken, choose another username\n";
		cout << "                        Enter username: ";

				UsernameAvailable = false;
				file3.close();
			}
		}
		if (UsernameAvailable == false) {
			goto label5;;
		}


		cout << "                        Make a password(number): ";
		cin >> newpassword;
		file1.open("DataFile.txt", ios::app);
		file1 << newusername << " " << newpassword << endl;
		file1.close();

	}
	case 2:
		system("cls");
		cout << " ____________________________________________________________________________________\n";
		cout << "|                                                                                    |\n";
		cout << "|--------------------------------------LOGIN-----------------------------------------|\n";
		
	label1:	cout << "                    Enter the username:";
		cin >> username;
		cout << "                        Enter password:";
		cin >> password;
		file2.open("DataFile.txt");

		while (file2 >> fileusernames >> filepasswords) {
			if (username == fileusernames && password == filepasswords) {
				file2.close();
		cout << "\n                      logged in successfully\n";
				Sleep(2000);
				found = true;
				break;

			}
		}

		if (found == false) {
		cout << "                        invalid username or password try again\n";
			file2.close();
			goto label1;
		}
		break;
	case 3:
		system("cls");
		string adminusername = "ranger";
		string adminpassword = "cplusplus";
		string entered_username;
		string entered_password;
		char backk;
		cout << " ____________________________________________________________________________________\n";
		cout << "|                                                                                    |\n";
		cout << "|--------------------------------------ADMIN-----------------------------------------|\n";
		do {
			cout << "                           username: ";
			cin >> entered_username;
			cout << "                           password: ";
			cin >> entered_password;


			if (entered_username == adminusername && entered_password == adminpassword)
			{
				admin();
				goto beginning;
			}
			else {
				cout << "\n                     Wrong username or password";

				cout << "\n                     Press Q to go back: ";
				cin >> backk;
			}

			if (backk == 'q' || backk == 'Q')
				goto beginning;

		} while (entered_username != adminusername || entered_password != adminpassword);






	}
}
void menu_order_bill()
{//menu items
	const int appt_size = 4;
	const int soup_size = 4;
	const int mainc_size = 4;
	const int dsrt_size = 4;

	string menu_items[4] = { "[Appetizers]","[Soups]", "[Maincourse]","[Desserts]" };
	string appetizer[appt_size] = { "[Garlic Bread]","[Chicken Wings]","[Nachos with cheese]","[Crackers]" };
	string soups[soup_size] = { "[Corn Soup]","[Hot n Sour]","[Yakhni]","[Special soup]" };
	string maincourse[mainc_size] = { "[Lache wala Paratha]","[Nihari]","[Daal]","[Chicken Karahi]" };
	string desserts[dsrt_size] = { "[Kheer]","[Sohan Halwa]","[Mithai]","[Gajar Halwa]" };
	//menu prices
	int apt_price[4] = { 100,200,300,150 };
	int soup_price[4] = { 100,200,300,400 };
	int mainc_price[4] = { 100,200,300,500 };
	int dsrt_price[4] = { 100,200,150,300 };

label:
	system("cls");
	cout << " ____________________________________________________________________________________\n";
	cout << "|                                                                                    |\n";
	cout << "|--------------------------------------MENU------------------------------------------|\n";
	cout << "|                           Press:                                                   |" << endl;
	cout << "|                               [A] for Appetizers                                   |" << endl;
	cout << "|                               [B] for Soups                                        |" << endl;
	cout << "|                               [C] for MainCourse]                                  |" << endl;
	cout << "|                               [D]for  Desserts                                     |" << endl;
	char option;
	cin >> option;

	switch (option)
	{

	case 'a':
		system("cls");
		cout << " ____________________________________________________________________________________\n";
		cout << "|                                                                                    |\n";
		cout << "|--------------------------------------MENU------------------------------------------|\n";
		cout << "|----------------------------------[Appetizers]--------------------------------------|\n" << endl;
		for (int i = 0; i < appt_size; i++)
		{

		cout << "                      "<<appetizer[i] << "    Rs." << apt_price[i] << "(Press [" << i + 1 << "] to order)";
			cout << endl;

		}
		char option_a;
		do {
			do {
		cout << "\n                                 Enter index: ";
				cin >> num;
			} while (num > appt_size || num < 1);

			orders[TotalOrders] = appetizer[num - 1];
			order_prices[TotalOrders] = apt_price[num - 1];
			TotalOrders++;
			bill += apt_price[num - 1];
			do {
		cout << "                   Do you want to order more from appetizers? Y/N: ";
				cin >> option_a;


				if (option_a != 'N' && option_a != 'Y')
		cout << "\n                            Only enter Y or N\n";
			} while (option_a != 'N' && option_a != 'Y');
			if (option_a == 'N')
				break;
		} while (option_a == 'Y');

		break;
	case 'A':
		system("cls");
		cout << " ____________________________________________________________________________________\n";
		cout << "|                                                                                    |\n";
		cout << "|--------------------------------------MENU------------------------------------------|\n";
		cout << "|----------------------------------[Appetizers]--------------------------------------|\n" << endl;
		for (int i = 0; i < appt_size; i++)
		{

		cout << "                      "<<appetizer[i] << "    Rs." << apt_price[i] << "(Press [" << i + 1 << "] to order)";
			cout << endl;

		}
		char option_A;
		do {
			do {
		cout << "\n                                Enter index: ";
				cin >> num;
			} while (num > appt_size || num < 1);
			orders[TotalOrders] = appetizer[num - 1];
			order_prices[TotalOrders] = apt_price[num - 1];
			TotalOrders++;
			bill += apt_price[num - 1];
			do {
		cout << "                  Do you want to order more from appetizers? Y/N: ";
				cin >> option_A;


				if (option_A != 'N' && option_A != 'Y')
		cout << "\n                            Only enter Y or N\n";
			} while (option_A != 'N' && option_A != 'Y');
			if (option_A == 'N')
				break;
		} while (option_A == 'Y');

		break;
	case 'b':
		system("cls");
		
		cout << " ____________________________________________________________________________________\n";
		cout << "|                                                                                    |\n";
		cout << "|--------------------------------------MENU------------------------------------------|\n";
		cout << "|-------------------------------------[SOUPS]----------------------------------------|\n" << endl;
		for (int i = 0; i < soup_size; i++)
		{
		cout << "                            " << soups[i] << "    Rs." << soup_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}
		char option_s;
		do {
			do {
		cout << "\n                                Enter index: ";
				cin >> num;
			} while (num > soup_size || num < 1);

			orders[TotalOrders] = soups[num - 1];
			order_prices[TotalOrders] = soup_price[num - 1];
			TotalOrders++;
			bill += soup_price[num - 1];
			do {
		cout << "                  Do you want to order more from maincourse? Y/N: ";
				cin >> option_s;


				if (option_s != 'N' && option_s != 'Y')
		cout << "\n                           Only enter Y or N\n";
			} while (option_s != 'N' && option_s != 'Y');
			if (option_s == 'N')
				break;
		} while (option_s == 'Y');



		break;
	case 'B':
		system("cls");
		cout << " ____________________________________________________________________________________\n";
		cout << "|                                                                                    |\n";
		cout << "|--------------------------------------MENU------------------------------------------|\n";
		cout << "|-------------------------------------[SOUPS]----------------------------------------|\n" << endl;
		for (int i = 0; i < soup_size; i++)
		{
		cout << "                          "<<soups[i] << "    Rs." << soup_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}
		char option_S;
		do {
			do
			{
				cout << "\n                         Enter index: ";
				cin >> num;
			} while (num > soup_size || num < 1);

			orders[TotalOrders] = soups[num - 1];
			order_prices[TotalOrders] = soup_price[num - 1];
			TotalOrders++;
			bill += soup_price[num - 1];
			do {
				cout << "         Do you want to order more from maincourse? Y/N: ";
				cin >> option_S;


				if (option_S != 'N' && option_S != 'Y')
			    cout << "\n                     Only enter Y or N\n";
			} while (option_S != 'N' && option_S != 'Y');
			if (option_S == 'N')
				break;
		} while (option_S == 'Y');



		break;

	case 'c':
		system("cls");
		cout << " ____________________________________________________________________________________\n";
		cout << "|                                                                                    |\n";
		cout << "|--------------------------------------MENU------------------------------------------|\n";
		cout << "|----------------------------------[MAINCOURSE]--------------------------------------|\n" << endl;
		for (int i = 0; i < mainc_size; i++)
		{
		cout << "                         " << maincourse[i] << "    Rs." << mainc_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}

		char option_m;

		do {
			do {
		cout << "\n                                Enter index: ";
				cin >> num;
			} while (num > mainc_size || num < 1);
			orders[TotalOrders] = maincourse[num - 1];
			order_prices[TotalOrders] = { mainc_price[num - 1] };
			TotalOrders++;
			bill += mainc_price[num - 1];
			do {
		cout << "                    Do you want to order more from maincourse? Y/N: ";
				cin >> option_m;


				if (option_m != 'N' && option_m != 'Y')
		cout << "\n                            Only enter Y or N\n";
			} while (option_m != 'N' && option_m != 'Y');
			if (option_m == 'N')
				break;
		} while (option_m == 'Y');


		break;
	case 'C':
		system("cls");
		cout << " ____________________________________________________________________________________\n";
		cout << "|                                                                                    |\n";
		cout << "|--------------------------------------MENU------------------------------------------|\n";
		cout << "|----------------------------------[MAINCOURSE]--------------------------------------|\n" << endl;
		for (int i = 0; i < mainc_size; i++)
		{
		cout << "                       " << maincourse[i] << "    Rs." << mainc_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}

		char option_M;

		do {
			do
			{
		cout << "\n                               Enter index: ";
				cin >> num;
			} while (num > mainc_size || num < 1);
			orders[TotalOrders] = maincourse[num - 1];
			order_prices[TotalOrders] = { mainc_price[num - 1] };
			TotalOrders++;
			bill += mainc_price[num - 1];
			do {
		cout << "                   Do you want to order more from maincourse? Y/N: ";
				cin >> option_M;


				if (option_M != 'N' && option_M != 'Y')
		cout << "\n                             Only enter Y or N\n";
			} while (option_M != 'N' && option_M != 'Y');
			if (option_M == 'N')
				break;
		} while (option_M == 'Y');


		break;

	case 'd':
		system("cls");
		cout << " ____________________________________________________________________________________\n";
		cout << "|                                                                                    |\n";
		cout << "|--------------------------------------MENU------------------------------------------|\n";
		cout << "|-----------------------------------[DESSERTS]---------------------------------------|\n" << endl;
		for (int i = 0; i < dsrt_size; i++)
		{
		cout << "                          " << desserts[i] << "    Rs." << dsrt_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}
		char option_d;
		do {
			do
			{
		cout << "\n                                Enter index: ";
				cin >> num;
			} while (num > dsrt_size || num < 1);
			orders[TotalOrders] = desserts[num - 1];
			order_prices[TotalOrders] = dsrt_price[num - 1];
			TotalOrders++;
			bill += dsrt_price[num - 1];
			do {
		cout << "                    Do you want to order more from desserts? Y/N: ";
				cin >> option_d;



				if (option_d != 'N' && option_d != 'Y')
		cout << "\n                            Only enter Y or N\n";
			} while (option_d != 'N' && option_d != 'Y');
			if (option_d == 'N')
				break;
		} while (option_d == 'Y');


		break;
	case 'D':
		system("cls");
		cout << " ____________________________________________________________________________________\n";
		cout << "|                                                                                    |\n";
		cout << "|--------------------------------------MENU------------------------------------------|\n";
		cout << "|-----------------------------------[DESSERTS]---------------------------------------|\n" << endl;
		for (int i = 0; i < dsrt_size; i++)
		{
		cout << "                          " << desserts[i] << "    Rs." << dsrt_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}
		char option_D;
		do {
			do {
		cout << "\n                                Enter index: ";
				cin >> num;
			} while (num > dsrt_size || num < 1);
			orders[TotalOrders] = desserts[num - 1];
			order_prices[TotalOrders] = dsrt_price[num - 1];
			TotalOrders++;
			bill += dsrt_price[num - 1];
			do {
		cout << "                    Do you want to order more from desserts? Y/N: ";
				cin >> option_D;


				if (option_D != 'N' && option_D != 'Y')
		cout << "\n                            Only enter Y or N\n";
			} while (option_D != 'N' && option_D != 'Y');
			if (option_D == 'N')
				break;
		} while (option_D == 'Y');




		break;

	default:
		if (option != 'a' && option != 'A' && option != 'b' && option != 'B' && option != 'c' && option != 'C' && option != 'd' && option != 'D') {
			cout << "\nInvalid Input.";
			goto label;
		}


	}
	system("cls");
	cout << "----------------------------Your order has been selected--------------------------" << endl;
	do {
	cout << "          Press [1] to go to menu to order other items or [2] to checkout" << endl;
		cin >> num;
		if (num == 1)
			goto label;
		else if (num == 2)
		{
			order();
			billing();
		}
		else 
	cout << "\n                               invalid input\n";
	} while (num != 1 && num != 2);



}
void order()
{
	system("cls");
	cout << " ____________________________________________________________________________________\n";
	cout << "|                                                                                    |\n";
	cout << "|--------------------------------------CART------------------------------------------|\n";
	cout << "                        You have ordered the following items: " << endl;
	for (int i = 0; i < TotalOrders; i++) {
	cout << "                        " << orders[i] << "----Rs." << order_prices[i] << endl;
	}
	ofstream save_items;
	save_items.open("itemsold.txt", ios::app);
	if (save_items.is_open())
	{
		for (int i = 0; i < TotalOrders; i++) {
			save_items << orders[i] << endl;
		}
		save_items.close();
	}
	else
	cout << "\n                           Failed to save items.\n";
	do
	{
	cout << "                    Press [1] to confirm your order and proceed\n";
		cin >> num;

		if (num == 1)
			break;
	} while (num != 1);


}


void billing() {


	system("cls");
	float total = bill + (15.0 / 100 * bill);
	if (num == 1) {
		cout << " ____________________________________________________________________________________\n";
		cout << "|                                                                                    |\n";
		cout << "|--------------------------------------BILL------------------------------------------|\n";
		for (int i = 0; i < TotalOrders; i++) {
			cout << "                       " << orders[i] << "-------Rs." << order_prices[i] << endl;
		}
			cout << "                       cost: " << "Rs. " << bill << endl;
			cout << "                       The tax is 15%" << endl;
			cout << "                       Your total bill with tax is: " << endl;
			cout << "                       BILL = " << "Rs " << total << ".00";
			cout << endl;
			cout << "--------------------------------THANKS FOR ORDERING-----------------------------------";


		}
		ofstream billfile;
		billfile.open("sales.txt", ios::app);

		if (billfile.is_open())
		{
			billfile << total << endl;
			billfile.close();
		}
		else
		{
			cout << "\nBill save: not recorded";
		}


	}


void admin()
{
	char go;
	ifstream billfilee;
	billfilee.open("sales.txt");
	int sales;
	int total_sales = 0;
	while (billfilee >> sales)
	{
		total_sales += sales;
	}
	cout << "\nTotal sales: " << total_sales;
	do
	{
		cout << "\nPress Y to return";
		cin >> go;
	} while (go != 'Y');
	billfilee.close();

}