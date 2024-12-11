#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;
void menu();
void signup();
int order_menu();
void billing(int x);

//restaurant management system

int main() {
	int total;
	signup();
	menu();
	total = order_menu();
	billing(total);
}

void signup() {

	srand(time(0));

	
	int enteredpassword=rand()%1000;
	int password=2005;
	string usrname = "ranger123";
	string logname = "unknown";
	
	
	

		do {
			cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Enter credentials to Login//////////////////////////" << endl;
			cout << "Enter username:";
			cin >> logname;
			if (logname == usrname)
			{
				cout << "Enter password: ";
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
		} while ((enteredpassword != password)||(logname!=usrname));
		
	
}

void menu()

{//menu items
	
	
	string menu_items[4] = { "appetizer","soups", " maincourse","desserts" };
	string appetizer[3] = { "Garlic Bread","Chicken Wings","Nachos with cheese" };
	string soups[3] = { "corn soup","hot n sour","yakhni" };
	string maincourse[3] = { "lache wala paratha","nihari","daal" };
	string desserts[2] = { "kheer","sohan halwa" };
	//menu prices
	int apt_price[3] = { 100,200,300 };
	int soup_price[3] = { 100,200,300 };
	int mainc_price[3] = { 100,200,300 };
	int dsrt_price[2] = { 100,200 };

	cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Appetizers//////////////////////////\n";
	for (int i = 0; i < 3; i++)
	{
		cout <<endl<< i+1 << ". " << appetizer[i] << "------->Rs." << apt_price[i] << endl;
}
	cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Soups//////////////////////////\n";
	for (int i = 0; i < 3; i++)
	{
		cout << endl << i+1 << ". " << soups[i] << "------->Rs." << soup_price[i] << endl;
	}
	cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\main course//////////////////////////\n";
	for (int i = 0; i < 3; i++)
	{
		cout << endl << i+1 << ". " << maincourse[i] << "------->Rs." << mainc_price[i] << endl;
	}

	cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Desserts//////////////////////////\n";
	for (int i = 0; i < 2; i++)
	{
		cout << endl << i+1 << ". " << desserts[i] << "------->Rs." << dsrt_price[i] << endl;
	}
	


}
int order_menu()
{
	string cart[20];
	int cart_prices[20];
	int index;
	
	//options used in switch statement
	char ap_opt;
	char sp_opt;
	char mc_opt;
	char ds_opt;
	//counter used in switch
	int count = 0;
	//menu items
	string menu_items[4] = { "appetizer","soups", " maincourse","desserts" };
	string appetizer[3] = { "Garlic Bread","Chicken Wings","Nachos with cheese" };
	string soups[3] = { "corn soup","hot n sour","yakhni" };
	string maincourse[3] = { "lache wala paratha","nihari","daal" };
	string desserts[2] = { "kheer","sohan halwa" };
	//menu prices
	int apt_price[3] = { 100,200,300 };
	int soup_price[3] = { 100,200,300 };
	int mainc_price[3] = { 100,200,300 };
	int dsrt_price[2] = { 100,200 };
	//menu options
label:
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
	char optionn;
	cout << "Do you want to order anything else? Y/N\n";
	cin >> optionn;
	
	if (optionn == 'Y') {
		menu();
		goto label;
	}
	
	else
	{
		cout << "Your selected items:\n";
		for (int i = 0; i < count; i++)
		{
			cout << i + 1 << ". " << cart[i] << "    Rs." <<cart_prices[i] << endl;
		}
	}
	char confirm;
	cout << "\nDo you want to confirm order? Y/N\n";
	cin >> confirm;
	int total = 0;
	double gst;
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
	cout << endl << "Total + %15: " << total_w_tax;
}

