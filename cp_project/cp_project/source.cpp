#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;
void menu();
void login();
int order_menu();
void billing(int x);

//restaurant management system

int main() {

	int total;
	char option;
	do {
		cout << "\nWelcome to Restaurant Management System\n\nPress L to login:";
		cin >> option;
		if (option == 'L')
		{
			login();
			menu();
			total = order_menu();
			billing(total);
		}
		else
			cout << "Press L only.";
	} while (option != 'L');
}
//login function
void login() {
	//random value to fill enteredpassword variable
	srand(time(0));


	int enteredpassword = rand() % 1000;
	//default password and username
	int password = 2005;
	string usrname = "ranger123";
	string logname = "unknown";




	do {
		cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Enter credentials to Login//////////////////////////" << endl;
		cout << "Enter username:";
		cin >> logname;
		if (logname == usrname)
		{
			cout << "Enter password(Number): ";
			cin >> enteredpassword;
			if (enteredpassword == password)
			{
				cout << "Login successful";
			}
			else
			{
				cout << "try again\n";
			}
		}
		else {
			cout << "\nWrong username\n";
		}
	} while ((enteredpassword != password) || (logname != usrname));


}
//menu function
void menu()

{//food items

	string menu_items[4] = { "appetizer","soups", " maincourse","desserts" };
	string appetizer[3] = { "Garlic Bread","Chicken Wings","Nachos with cheese" };
	string soups[3] = { "corn soup","hot n sour","yakhni" };
	string maincourse[3] = { "lache wala paratha","nihari","daal" };
	string desserts[2] = { "kheer","sohan halwa" };
//food prices
	int apt_price[3] = { 100,200,300 };
	int soup_price[3] = { 100,200,300 };
	int mainc_price[3] = { 100,200,300 };
	int dsrt_price[2] = { 100,200 };
//menu generation
	cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Appetizers//////////////////////////\n";
	for (int i = 0; i < 3; i++)
	{
		cout << endl << i + 1 << ". " << appetizer[i] << "------->Rs." << apt_price[i] << endl;
	}
	cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Soups//////////////////////////\n";
	for (int i = 0; i < 3; i++)
	{
		cout << endl << i + 1 << ". " << soups[i] << "------->Rs." << soup_price[i] << endl;
	}
	cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\main course//////////////////////////\n";
	for (int i = 0; i < 3; i++)
	{
		cout << endl << i + 1 << ". " << maincourse[i] << "------->Rs." << mainc_price[i] << endl;
	}

	cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Desserts//////////////////////////\n";
	for (int i = 0; i < 2; i++)
	{
		cout << endl << i + 1 << ". " << desserts[i] << "------->Rs." << dsrt_price[i] << endl;
	}



}
//order function
int order_menu()
{
	//cart to store selected dishes
	string cart[20];
	//cart to store selected dishes' prices
	int cart_prices[20];
	int index;

	//options used in switch statement
	char ap_opt;
	char sp_opt;
	char mc_opt;
	char ds_opt;
	//counter used in switch
	int count = 0;
	//food items
	string menu_items[4] = { "appetizer","soups", " maincourse","desserts" };
	string appetizer[3] = { "Garlic Bread","Chicken Wings","Nachos with cheese" };
	string soups[3] = { "corn soup","hot n sour","yakhni" };
	string maincourse[3] = { "lache wala paratha","nihari","daal" };
	string desserts[2] = { "kheer","sohan halwa" };
	//food prices
	int apt_price[3] = { 100,200,300 };
	int soup_price[3] = { 100,200,300 };
	int mainc_price[3] = { 100,200,300 };
	int dsrt_price[2] = { 100,200 };
	//menu options
label:
	//options
	cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\HOW TO USE//////////////////////////\n";
	cout << "Press A to order from Appetizers\n";
	cout << "Press S to order from Soups\n";
	cout << "Press M to order from Maincourse\n";
	cout << "Press D to order from Desserts\n";
	char option;
	cout << "Enter option:";
	cin >> option;

	switch (option)
	{
	case 'A':
		cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Appetizers//////////////////////////\n";
		for (int i = 0; i < 3; i++)
		{
			cout << endl << i + 1 << ". " << appetizer[i] << "------->Rs." << apt_price[i] << endl;
		}
		do {
			cout << "Enter index No. of dish: ";
			cin >> index;

			cout << "Dish: " << appetizer[index - 1] << endl;
			//dish gives index number of food which starts from one i.e
			//1. xyz
			//2. jkl
			//3. pqr
			//suppose user enters 1, so index - 1 will give first element in the appetizer array
			cart[count] = appetizer[index - 1];
			cart_prices[count] = apt_price[index - 1];
			count++;
			cout << "\ncart:\n";
			for (int i = 0; i < count; i++)
			{
				cout << cart[i] << endl;
			}
			cout << "Do you want to order more from appetizers? Y/N\n";
			cin >> ap_opt;


		} while (ap_opt != 'N');
		break;
	case 'S':
		cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Soups//////////////////////////\n";
		for (int i = 0; i < 3; i++)
		{
			cout << endl << i + 1 << ". " << soups[i] << "------->Rs." << soup_price[i] << endl;
		}
		do {
			cout << "Enter index No. of dish: ";
			cin >> index;

			cout << "Dish: " << soups[index - 1] << endl;

			cart[count] = soups[index - 1];
			cart_prices[count] = soup_price[index - 1];
			count++;
			cout << "\ncart:\n";
			for (int i = 0; i < count; i++)
			{
				cout << cart[i] << endl;
			}
			cout << "Do you want to order more from soups? Y/N\n";
			cin >> sp_opt;


		} while (sp_opt != 'N');
		break;

	case 'M':
		cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\main course//////////////////////////\n";
		for (int i = 0; i < 3; i++)
		{
			cout << endl << i + 1 << ". " << maincourse[i] << "------->Rs." << mainc_price[i] << endl;
		}
		do {
			cout << "Enter index No. of dish: ";
			cin >> index;

			cout << "Dish: " << maincourse[index - 1] << endl;

			cart[count] = maincourse[index - 1];
			cart_prices[count] = mainc_price[index - 1];
			count++;
			cout << "\ncart:\n";
			for (int i = 0; i < count; i++)
			{
				cout << cart[i] << endl;
			}
			cout << "Do you want to order more from maincourse? Y/N\n";
			cin >> mc_opt;


		} while (mc_opt != 'N');
		break;

	case 'D':
		cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Desserts//////////////////////////\n";
		for (int i = 0; i < 2; i++)
		{
			cout << endl << i + 1 << ". " << desserts[i] << "------->Rs." << dsrt_price[i] << endl;
		}
		do {
			cout << "Enter index No. of dish: ";
			cin >> index;

			cout << "Dish: " << desserts[index - 1] << endl;

			cart[count] = desserts[index - 1];
			cart_prices[count] = dsrt_price[index - 1];
			count++;
			cout << "\ncart:\n";
			for (int i = 0; i < count; i++)
			{
				cout << cart[i] << endl;
			}
			cout << "Do you want to order more from desserts? Y/N\n";
			cin >> ds_opt;


		} while (ds_opt != 'N');
		break;
	}
	//order anything else, if selected Y, label takes us back.
	char optionn;
	cout << "Do you want to order anything else? Y/N\n";
	cin >> optionn;

	if (optionn == 'Y') {
		menu();
		goto label;
	}

	else
	{//displays items you have selected
		cout << "Your selected items:\n";
		for (int i = 0; i < count; i++)
		{
			cout << i + 1 << ". " << cart[i] << "    Rs." << cart_prices[i] << endl;
		}
	}
	//confirms order
	char confirm;
	cout << "\nDo you want to confirm order? Y/N\n";
	cin >> confirm;
	//total variable which is used for billing
	int total = 0;

	if (confirm == 'Y')
	{
		for (int i = 0; i < count;i++)
		{
			total += cart_prices[i];
			cout << cart[i] << "  Rs." << cart_prices[i] << endl;
		}
		return total;

	}
	else if (confirm == 'N')
	{
		cout << "\n\nThank you for visiting";
	}
	else
		cout << "\n\nINVALID OPTION";

}

void billing(int x)
{
	int total = x;
	cout << "\n\n BILL";
	cout << "\nTotal: " << total;
	double gst = total * 0.15;
	double total_w_tax = total + gst;
	cout << endl << "Total + 15%: " << total_w_tax;
}

