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
	int num;
	int newpass;
	int option;
	char goback;
	int key;
	char option2;
	system("cls");
	do {
		cout << "==================Welcome To RESTAURANT MANAGEMENT SYSTEM==================\n";
	backlabel:
		cout << "||           press 1 to Generate a key or 2 to login with key            ||\n";

		cin >> num;
		
	} while (num != 1&&num != 2);
	ofstream file;
	ifstream file2;
	switch (num) {
	case 1:
		srand(time(0));
		key = rand() % 9999;
		system("cls");
	cout << "===========================Generate key Press[1]===========================\n";
		cin >> option;
		if(option==1){
			cout << "key: " << key << " (Make sure you remember the key as it will be required for login)";
			file.open("keys.txt", ios::app);
			file << key<< endl;
			file.close();
			cout << "\nProceed to signup? (Y/N): ";
			cin >> option2;
			if (option2 == 'n' || option2 == 'N')
				goto backlabel;
		}
		else {
			cout << "Press b to go back";
			cin >> goback;
			if (goback == 'b' || goback == 'B')
				goto backlabel;
		}
		

	case 2:
		system("cls");
		char approve = NULL;
		string filekey;

		string key_entered;
		cout << "============================L O G I N============================\n";
		do{
			if (file2.is_open())
				file2.close();
		/*label:*/	cout << "\nEnter key: ";
		cin >> key_entered;


		file2.open("keys.txt");

		if (file2.is_open())
		{
			while (file2 >> filekey)
			{
				if (key_entered == filekey)
				{
					cout << "\nSuccess!";
					Sleep(2000);
					while (approve != 'y')
					{
						cout << " Press y to proceed:\n";
						cin >> approve;
						if (approve == 'y')
							break;
					}break;


				}
				else
				{
					cout << "\nChecking";

				}
			}
			if (key_entered != filekey)
				cout << "\nWrong key\n";
		}
		else
			cout << "Couldn't open file";
		} while (key_entered != filekey);

		/*do {

			login >> filepassword;
			getline(login, filepassword);
			if (password == filepassword) {
				cout << "\nsuccessfull\n" << endl;
				cout << "Do you want to go further:\n";
				cin >> approve;

				login.close();
				break;

			}


			else {
				cout << "invalid\n";
				goto label;
			}


		} while (password != filepassword);
	}*/


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


		file2.close();
		
	}
}
void menu_order_bill()
{//menu items
	const int appt_size = 4;
	const int soup_size = 4;
	const int mainc_size = 4;
	const int dsrt_size = 4;

	string menu_items[4] = { "[Appetizers]","[Soups]", "[Maincourse]","[Desserts]" };
	string appetizer[appt_size] = { "[Garlic Bread]","[Chicken Wings]","[Nachos with cheese]","[Crackers]"};
	string soups[soup_size] = { "[Corn Soup]","[Hot n Sour]","[Yakhni]","[Special soup]"};
	string maincourse[mainc_size] = { "[Lache wala Paratha]","[Nihari]","[Daal]","[Chicken Karahi]"};
	string desserts[dsrt_size] = { "[Kheer]","[Sohan Halwa]","[Mithai]","[Gajar Halwa]"};
	//menu prices
	int apt_price[4] = { 100,200,300,150 };
	int soup_price[4] = { 100,200,300,400 };
	int mainc_price[4] = { 100,200,300,500 };
	int dsrt_price[4] = { 100,200,150,300 };

label:
	cout << "Press:" << endl;
	cout << "[A] for Appetizers" << endl;
	cout << "[B] for Soups" << endl;
	cout << "[C] for MainCourse]" << endl;
	cout << "[D]for  Desserts" << endl;
	char option;
	cin >> option;

	switch (option)
	{

	case 'a':
		system("cls");
		cout << "----------[Appetizers]----------" << endl;
		for (int i = 0; i < appt_size; i++)
		{

			cout << appetizer[i] << "    Rs." << apt_price[i] << "(Press [" << i + 1 << "] to order)";
			cout << endl;

		}
		char option_a;
		do {
			do {
				cout << "\nEnter index: ";
				cin >> num;
			} while (num > appt_size || num < 1);

			orders[TotalOrders] = appetizer[num - 1];
			order_prices[TotalOrders] = apt_price[num - 1];
			TotalOrders++;
			bill += apt_price[num - 1];
			do {
				cout << "Do you want to order more from appetizers? Y/N: ";
				cin >> option_a;


				if (option_a != 'N' && option_a != 'Y')
					cout << "\nOnly enter Y or N\n";
			} while (option_a != 'N' && option_a != 'Y');
			if (option_a == 'N')
				break;
		} while (option_a == 'Y');

		break;
	case 'A':
		system("cls");
		cout << "----------[Appetizers]----------" << endl;
		for (int i = 0; i < appt_size; i++)
		{

			cout << appetizer[i] << "    Rs." << apt_price[i] << "(Press [" << i + 1 << "] to order)";
			cout << endl;

		}
		char option_A;
		do {
			do {
				cout << "\nEnter index: ";
				cin >> num;
			} while (num > appt_size || num < 1);
			orders[TotalOrders] = appetizer[num - 1];
			order_prices[TotalOrders] = apt_price[num - 1];
			TotalOrders++;
			bill += apt_price[num - 1];
			do {
				cout << "Do you want to order more from appetizers? Y/N: ";
				cin >> option_A;


				if (option_A != 'N' && option_A != 'Y')
					cout << "\nOnly enter Y or N\n";
			} while (option_A != 'N' && option_A != 'Y');
				if (option_A == 'N')
					break;
			} while (option_A == 'Y');

			break;
	case 'b':
		system("cls");
		cout << "----------[Soups]----------" << endl;
		for (int i = 0; i < soup_size; i++)
		{
			cout << soups[i] << "    Rs." << soup_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}
		char option_s;
		do {
			do {
				cout << "\nEnter index: ";
				cin >> num;
			}while(num > soup_size || num < 1);

			orders[TotalOrders] = soups[num - 1];
			order_prices[TotalOrders] = soup_price[num - 1];
			TotalOrders++;
			bill += soup_price[num - 1];
			do {
				cout << "Do you want to order more from maincourse? Y/N: ";
				cin >> option_s;


				if (option_s != 'N' && option_s != 'Y')
					cout << "\nOnly enter Y or N\n";
			} while (option_s != 'N' && option_s != 'Y');
			if (option_s == 'N')
				break;
		} while (option_s == 'Y');



		break;
	case 'B':
		system("cls");
		cout << "----------[Soups]----------" << endl;
		for (int i = 0; i < soup_size; i++)
		{
			cout << soups[i] << "    Rs." << soup_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}
		char option_S;
		do {
			do
			{
				cout << "\nEnter index: ";
				cin >> num;
			} while (num > soup_size || num < 1);

			orders[TotalOrders] = soups[num - 1];
			order_prices[TotalOrders] = soup_price[num - 1];
			TotalOrders++;
			bill += soup_price[num - 1];
			do {
				cout << "Do you want to order more from maincourse? Y/N: ";
				cin >> option_S;


				if (option_S != 'N' && option_S != 'Y')
					cout << "\nOnly enter Y or N\n";
			} while (option_S != 'N' && option_S != 'Y');
			if (option_S == 'N')
				break;
		} while (option_S == 'Y');



		break;

	case 'c':
		system("cls");
		cout << "----------[MainCourse]----------" << endl;
		for (int i = 0; i < mainc_size; i++)
		{
			cout << maincourse[i] << "    Rs." << mainc_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}

		char option_m;

		do {
			do {
				cout << "\nEnter index: ";
				cin >> num;
			}while (num > mainc_size || num < 1);
			orders[TotalOrders] = maincourse[num - 1];
			order_prices[TotalOrders] = { mainc_price[num - 1] };
			TotalOrders++;
			bill += mainc_price[num - 1];
			do {
				cout << "Do you want to order more from maincourse? Y/N: ";
				cin >> option_m;


				if (option_m != 'N' && option_m != 'Y')
					cout << "\nOnly enter Y or N\n";
			} while (option_m != 'N' && option_m != 'Y');
			if (option_m == 'N')
				break;
		} while (option_m == 'Y');


		break;
	case 'C':
		system("cls");
		cout << "----------[MainCourse]----------" << endl;
		for (int i = 0; i < mainc_size; i++)
		{
			cout << maincourse[i] << "    Rs." << mainc_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}

		char option_M;

		do {
			do
			{
				cout << "\nEnter index: ";
				cin >> num;
			}while (num > mainc_size || num < 1);
			orders[TotalOrders] = maincourse[num - 1];
			order_prices[TotalOrders] = { mainc_price[num - 1] };
			TotalOrders++;
			bill += mainc_price[num - 1];
			do {
				cout << "Do you want to order more from maincourse? Y/N: ";
				cin >> option_M;


				if (option_M != 'N' && option_M != 'Y')
					cout << "\nOnly enter Y or N\n";
			} while (option_M != 'N' && option_M != 'Y');
			if (option_M == 'N')
				break;
		} while (option_M == 'Y');


		break;

	case 'd':
		system("cls");
		cout << "----------[Desserts]----------" << endl;
		for (int i = 0; i < dsrt_size; i++)
		{
			cout << desserts[i] << "    Rs." << dsrt_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}
		char option_d;
		do {
			do
			{
				cout << "\nEnter index: ";
				cin >> num;
			}while (num > dsrt_size || num < 1);
			orders[TotalOrders] = desserts[num - 1];
			order_prices[TotalOrders] = dsrt_price[num - 1];
			TotalOrders++;
			bill += dsrt_price[num - 1];
			do {
				cout << "Do you want to order more from desserts? Y/N: ";
				cin >> option_d;



				if (option_d != 'N' && option_d != 'Y')
					cout << "\nOnly enter Y or N\n";
			} while (option_d != 'N' && option_d != 'Y');
			if (option_d == 'N')
				break;
		} while (option_d == 'Y');


		break;
	case 'D':
		system("cls");
		cout << "----------[Desserts]----------" << endl;
		for (int i = 0; i < dsrt_size; i++)
		{
			cout << desserts[i] << "    Rs." << dsrt_price[i] << " (Press [" << i + 1 << "] to order)";
			cout << endl;
		}
		char option_D;
		do {
			do {
				cout << "\nEnter index: ";
				cin >> num;
			}while (num > dsrt_size || num < 1);
			orders[TotalOrders] = desserts[num - 1];
			order_prices[TotalOrders] = dsrt_price[num - 1];
			TotalOrders++;
			bill += dsrt_price[num - 1];
			do {
				cout << "Do you want to order more from desserts? Y/N: ";
				cin >> option_D;


				if (option_D != 'N' && option_D != 'Y')
					cout << "\nOnly enter Y or N\n";
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
		cout << "------Your order has been selected------" << endl;
		do {
			cout << "Press [1] to go to menu to order other items or [2] to checkout" << endl;
			cin >> num;
			if (num == 1)
				goto label;
			else if (num == 2)
			{
				order();
				billing();
			}
			else cout << "\ninvalid input\n";
		} while (num != 1 && num != 2);


	
}
void order()
{
	system("cls");
	cout << "You have ordered the following items: " << endl;
	for (int i = 0; i < TotalOrders; i++) {
		cout << orders[i] << "----Rs." << order_prices[i] << endl;
	}
	do
	{
		cout << "Press [1] to confirm your order and proceed\n";
		cin >> num;

		if (num == 1)
			break;
	} while (num != 1);

	
}


void billing() {

	
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






