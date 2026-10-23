#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
#include <Windows.h>
using namespace std;

void daily_salesScreen() {
	cout << "============================ DAILY SALES REPORT ======================================\n"
		<< "--------------------------------------------------------------------------------------\n";
}

void return_screen() {//enos
	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << "           *****   *****  ******  **    **  **   **  *****       *****     ***    ********  *****\n";
	cout << "           **  **  **     **      **    **  ***  **  **  **      **  **   *   *   **        **\n";
	cout << "           *****   *****  *****   **    **  ** * **  **   *      *****   *******  **  ****  *****\n";
	cout << "           ** **   **     **      ********  **  ***  **  **      **      *     *  **    **  **\n";
	cout << "           **  **  *****  **       ******   **   **  *****       **      *     *  ********  *****\n\n";
	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}

void restockScreen() {
	cout << "          **************************************************************************************************\n";
	cout << "          **************************************************************************************************" << endl << endl;
	cout << "           *****   *****  ******  ******   ******   ******   *   *         *****     ***    ********  *****\n";
	cout << "           **  **  **     *         **     *    *   *        * *           **  **   *   *   **        **\n";
	cout << "           *****   *****  ******    **     *    *   *        **            *****   *******  **  ****  *****\n";
	cout << "           ** **   **          *    **     *    *   *        * *           **      *     *  **    **  **\n";
	cout << "           **  **  *****  ******    **     ******   ******   *   *         **      *     *  ********  *****\n\n";
	cout << "          **************************************************************************************************\n";
	cout << "          **************************************************************************************************" << endl << endl;
}

void header();

struct MenuItem {
	string name;
	int quantity;
	string supplier;
	double price;
	string phone;
	int quantity_sold;
};

MenuItem Hardware[] = {
	{"Cellophane Tape", 5, "Stocth", 2.50, "012-1212121" , 13},
	{"Masking Tape", 5, "Stocth", 2.00, "012-1212121" ,14},
	{"Duct Tape", 5, "Stocth", 2.80, "012-1212121" ,23},
	{"Double Sided Tape", 5, "Scotch", 2.30, "012-1212121" ,9},
	{"UHU Glue", 5, "Stocth", 5.00, "012-1212121" ,11}
};
MenuItem Home_Appliances[] = {
	{"Door Knob", 6, "Courts", 7.00, "013-6664455" ,12},
	{"Toilet Bowl Seat", 6, "Courts", 15.50, "013-6664455",5},
	{"Clock", 6, "Courts", 9.20, "013-6664455",9},
	{"Flower Pot", 6, "Courts", 5.70, "013-6664455",3},
	{"Water hose", 6, "Courts", 11.00, "013-6664455",4}
};
MenuItem Electrical[] = {
	{"AA Alkaline Batteries", 3, "Ninjaz", 7.00, "018-1234567",2},
	{"AAA Alkaline Batteries", 3, "Ninjaz", 9.00, "018-1234567",3},
	{"LED Light Bulb", 3, "Ninjaz", 6.50, "018-1234567",4},
	{"Extension Cord", 3, "Ninjaz", 15.00, "018-1234567",8},
	{"Type C Charging Cable", 3, "Ninjaz", 5.00, "018-1234567",12}
};
struct InvoiceItem {
	string name;
	string supplier;
	double price;
	int quantity;
};

InvoiceItem restockinvoice[100];
int restockinvoiceCount = 0;

int Hardware_size = sizeof(Hardware) / sizeof(Hardware[0]);
int Home_App_Size = sizeof(Home_Appliances) / sizeof(Home_Appliances[0]);
int Electrical_size = sizeof(Electrical) / sizeof(Electrical[0]);

vector<string> ItemInCart;
vector<double> Price_of_ItemInCart;
vector<int> Quantity_of_ItemInCart;

//functions
void welcome_menu();//ryan
void display_menu(MenuItem item[], int size, const string title);//ryan
void Selection_menu();//ryan
void Customer_menu();//ryan
void Buying_menu();//ryan
void Staff_menu();//ryan
void order_item(MenuItem item[], int size, int order);//ryan

void invoice(); //hueysryan
void Payment_method(double total, double service_tax, double members_discount, bool hasMembership); //hueysryan
void displayCategory(MenuItem items[], int size, string categoryName);//hueysryan
void restockItem(MenuItem items[], int index);//hueysryan
void restock();//hueysryan

void feedback();//enos
bool return_yes();//enos
void refund_menu();//enos

void Staff_login(); //kaiheng
double SalesReportMenu(MenuItem Item[], int size); //kaiheng

int GetValidInput(int x, int y); //valid input within range
int GetValidInt() {
	int value;
	while (true) {
		cin >> value;
		if (cin.fail()) {
			cout << "Please enter valid numbers: ";
			cin.clear();
			cin.ignore(1000);
		}
		else {
			return value;
		}
	}
} //check if its an int

int main() {
	welcome_menu();
	header();
	Selection_menu();

	return 0;
}

void welcome_menu() {

	cout << "          *******************************************************************************************\n"
		<< "                                                 Welcome to...\n"
		<< "          *******************************************************************************************\n\n";

	Sleep(500);

	cout << "                          **       **   *****   ******        ******    **  ***    ***" << endl
		<< "                          ***     ***   **  **  **            **   ***  **   ***  ***" << endl
		<< "                          ** *   * **   *****   ******        **   ***  **     ****" << endl
		<< "                          **  * *  **   ** **       **        **   ***  **      **" << endl
		<< "                          **   *   **   **  **  ******   *    ******    **      **" << endl << endl;

	cout << "          *******************************************************************************************\n\n\n";

	cout << endl;
}

void Selection_menu() {
	int input;
	bool valid = false;
	do {
		cout << "\nMAIN ACCESS MENU\n";
		cout << "Please select your role: " << endl;
		cout << "[1] Customer - Shop and make purchases" << endl;
		cout << "[2] Staff - Access employee functions" << endl;
		cout << "[3] Exit Program." << endl;
		cout << "Select: ";

		cin >> input;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << endl;

		switch (input) {
		case 1:
			valid = true;
			Customer_menu();
			break;
		case 2:
			valid = true;
			Staff_login();
			break;

		case 3:
			valid = true;
			cout << "Shutting down...\n";
			Sleep(1200);
			cout << "X_X";
			continue;

		default:
			cout << "Invalid Input." << endl;
			Selection_menu();
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
		}
	} while (!valid);
}

void display_menu(MenuItem item[], int size, const string title)
{
	cout << "\n------------ " << title << " ------------\n";
	for (int i = 0; i < size; i++) {
		cout << "[" << i + 1 << "] "
			<< left << setw(25) << item[i].name  // Fixed width for names
			<< right << setw(6) << fixed << setprecision(2) << item[i].price << "$\n";
	}
	cout << "[0] Back" << endl;
	cout << "--------------------------------------\n";
}

void order_item(MenuItem item[], int size, int order) {
	int input, quantity;
	string Item_name;
	double Item_price;

	Item_name = item[order - 1].name;
	Item_price = item[order - 1].price;
	while (true) {
		cout << "Quantity: ";
		cin >> quantity;
		if (quantity > 0 && quantity <= 100) {
			break;
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Number. (Do not exceed 100)" << endl;
		}
	}

	cout << quantity << " " << Item_name << " has been added into cart!" << endl << endl;
	ItemInCart.push_back(Item_name);
	Price_of_ItemInCart.push_back(Item_price);
	Quantity_of_ItemInCart.push_back(quantity);
	item[order - 1].quantity_sold += quantity;
}

void Customer_menu() {
	header();
	cout << "CUSTOMER SERVICES\n";
	int input;
	bool valid = false;
	do {
		cout << "[1] Buy Items\n[2] Refund \n[3] Customer feedback \n[0] Back";
		cout << "\nSelect: ";

		if (!(cin >> input)) {  // Check if input failed
			input = 4;
			cin.clear();  // Clear error state
			cin.ignore(1000, '\n');  // Discard bad input
		}
		cin.clear();  // Clear error state
		cin.ignore(1000, '\n');
		cout << endl;
		switch (input) {
		case 0: //back
			valid = true;
			Selection_menu();
			break;

		case 1:
			valid = true;
			Buying_menu();
			break;
		case 2:
			valid = true;
			refund_menu();//REFUND MODULE
			break;
		case 3:
			valid = true;
			feedback();//FEEDBACK MODULE
			break;

		case 4:
			cout << "Invalid Input. Please enter a number.\n";
			cin.clear();
			cin.ignore();
			break;
		default:
			valid = false;
			cout << "Invalid Input.";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			break;
		}
	} while (!valid);
}

double SalesReportMenu(MenuItem Item[], int size) {
	double grandTotal = 0; // start total at 0
	cout << left << setw(25) << "Item"
		<< setw(18) << "Supplier"
		<< setw(18) << "Unit Price"
		<< setw(13) << "Quantity"
		<< setw(18) << "Total Price" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size; ++i) {
		double total = Item[i].price * Item[i].quantity_sold;
		cout << left << setw(25) << Item[i].name
			<< setw(18) << Item[i].supplier
			<< "RM " << setw(15) << fixed << setprecision(2) << Item[i].price
			<< setw(15) << Item[i].quantity_sold
			<< "RM " << fixed << setprecision(2) << total << endl;
		grandTotal += total;

	}

	cout << "--------------------------------------------------------------------------------------" << endl;
	cout << right << setw(80) << "Total: RM " << fixed << setprecision(2) << grandTotal << endl << endl;
	return grandTotal;
}

void showSalesReport() {
	double Total_sales = SalesReportMenu(Hardware, Hardware_size) + SalesReportMenu(Electrical, Electrical_size) + SalesReportMenu(Home_Appliances, Home_App_Size);
	cout << "--------------------------------------------------------------------------------------" << endl;
	cout << right << setw(80) << "Grand Total: RM " << fixed << setprecision(2) << Total_sales << endl;// print the table

	Staff_menu();
	return;
}

void Staff_menu() {
	header();
	cout << "STAFF SERVICES\n";
	int input;
	bool valid = false;
	do {
		cout << "[1] Check Stock/Restock\n[2] Sales Report\n[0] Back";
		cout << "\nSelect: ";

		cin >> input;
		cin.clear();
		cin.ignore(1000, '\n');

		cout << endl;
		switch (input) {
		case 0: //back
			valid = true;
			Selection_menu();
			break;

		case 1:
			valid = true;
			restock();
			break;
		case 2:
			valid = true;
			daily_salesScreen();   // print the title
			showSalesReport();     // print the table
			break;

		default:
			valid = false;
			cout << "Invalid Input.";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			break;
		}
	} while (!valid);
}

void Buying_menu() {
	header();
	int input, order, quantity;
	string Item_name;
	double Item_price;
	bool valid = false;
	do {
		cout << "--------CATEGORIES-------" << endl;
		cout << "[1] Hardware \n[2] Home Appliances\n[3] Electrical";
		cout << "\n------------------------\n";
		cout << "[4] View Cart/Payment\n[0] Back" << endl;
		cout << "------------------------";
		cout << "\nSelect: ";

		cin >> input;
		cin.clear();
		cin.ignore(1000, '\n');

		switch (input) {
		case 1:

			display_menu(Hardware, Hardware_size, "HARDWARE MENU");
			order = GetValidInput(0, Hardware_size);
			if (order == 0) {
				break;
			}
			order_item(Hardware, Hardware_size, order);
			break;

		case 2:

			display_menu(Home_Appliances, Home_App_Size, "HOME APPLIANCES");
			order = GetValidInput(0, Home_App_Size);
			if (order == 0) {
				break;
			}
			order_item(Home_Appliances, Home_App_Size, order);
			break;

		case 3:

			display_menu(Electrical, Electrical_size, "ELECTRICAL");
			order = GetValidInput(0, Electrical_size);
			if (order == 0) {
				break;
			}
			order_item(Electrical, Electrical_size, order);
			break;

		case 4:
			valid = true;
			invoice();
			break;
		case 0:
			valid = true;
			Customer_menu();
			break;
		default:
			valid = false;
			cout << "\nInvalid Input." << endl << endl;
		    Buying_menu();
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
		}
	} while (!valid);
}

int GetValidInput(int x, int y) {
	int input = -1;

	while (true) {
		cout << "Enter your choice. (" << x << "-" << y << ") : ";
		if (!(cin >> input)) {
			cout << "Invalid Input, please try again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		if (input < x || input > y) {
			cout << "Number is not within range! Try again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		cin.clear();
		cin.ignore(1000, '\n');
		return input;
	}
}

void invoice() {
	double total = 0;
	char input;
	bool valid = false;
	double service_tax = 0.06, members_discount = 0.1;
	if (ItemInCart.empty()) {
		cout << "\nNo items in Cart!" << endl;
		cout << "Returning to menu..." << endl;
		Sleep(1000);
		Buying_menu();
		return;
	}
	else {
		cout << endl << "----------------(YOUR CART)------------------" << endl;
		for (int i = 0; i < ItemInCart.size(); i++) {
			cout << endl << ItemInCart[i] << setw(25 - ItemInCart[i].length()) << " x" << Quantity_of_ItemInCart[i] << " "
				<< setw(15) << fixed << setprecision(2) << Price_of_ItemInCart[i] * Quantity_of_ItemInCart[i] << "$";
			total += Price_of_ItemInCart[i] * Quantity_of_ItemInCart[i];
		}

		cout << endl << "--------------------------------------------" << endl;
		cout << left << setw(39) << "\nTotal: " << fixed << setprecision(2) << total << "$" << endl;
		cout << left << setw(39) << "SST (6%): " << total * service_tax << "$" << endl;
		cout << left << setw(38) << "Total: " << total + (total * service_tax) << "$" << endl;
		cout << endl << "--------------------------------------------" << endl;
	}

	do {
		cout << "Would you like to proceed with payment ? (Y/N): ";
		cin >> input;
		cout << endl;
		if (input == 'y' || input == 'Y') {
			valid = true;
			cout << endl;
			Payment_method(total, service_tax, members_discount, true);
		}

		else if (input == 'n' || input == 'N') {
			valid = true;
			cout << "Returning to menu...\n";
			Sleep(1000);
			Buying_menu();
			return;
		}
		else {
			cout << "Invalid Input! Try again: \n";
			valid = false;
			cin.clear();
			cin.ignore(1000, '\n');
		}

	} while (!valid);
	Selection_menu();
	return;
}

bool return_yes() {
	string item;
	string return_reason;

	cout << "\n\n                                        Our Products:" << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "\tHardware\t\t" << "Home Appliances\t\t" << "Electrical" << endl;
	cout << "\t---------\t\t" << "--------------\t\t" << "-----------" << endl;
	cout << "\tCellophane Tape\t\t" << "Door Knob\t\t" << "AA Alkaline Batteries" << endl;
	cout << "\tMasking Tape\t\t" << "Toilet Bowl Seat\t" << "AAA Alkaline Batteries" << endl;
	cout << "\tDuct Tape\t\t" << "Clock\t\t\t" << "LED Light Bulb" << endl;
	cout << "\tDouble Sided Tape\t" << "Flower Pot\t\t" << "Extension Cord" << endl;
	cout << "\tUHU Glue\t\t" << "Water hose\t\t" << "Type C Charging Cable" << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;

	cin.ignore(1000, '\n');
	cout << "What is the item you would like to refund?: ";
	getline(cin, item);

	cout << "What is the reason of your refund?: ";
	getline(cin, return_reason);

	cout << "\n\n          *******************************************************************************************";
	cout << "\n                                              REFUND POLICY";
	cout << "\n          *******************************************************************************************\n";
	cout << "1. Refunds allowed within 7 days of purchase." << endl
		<< "2. Item must be unused and in original condition." << endl
		<< "3. No refunds for used or damaged items." << endl << endl;

	char return_confirm;
	while (true) {
		cout << "Are you sure you want to refund " << item << " ? (Y/N): ";
		cin >> return_confirm;

		if (return_confirm == 'Y' || return_confirm == 'y') {
			cout << "REFUND PENDING..." << endl;
			cout << "-------------------" << endl;
			Sleep(3000);
			cout << "Refund item  :" << setw(15) << item << endl;
			cout << "Refund reason:" << setw(15) << return_reason << endl << endl;
			cout << "Please be patient while waiting for the result of your refund. Thank you!\n\n\n\n";
			Sleep(3000);
			return true;
		}
		else if (return_confirm == 'N' || return_confirm == 'n') {
			char back_menu;
			while (true) {
				cout << "Back to the Return page? (Y/N): ";
				cin >> back_menu;

				if (back_menu == 'Y' || back_menu == 'y') {
					cout << endl << endl;
					return true;

				}
				else if (back_menu == 'N' || back_menu == 'n') {
					cout << "\nBack to selection\n\n";
					return_yes(); // re-run
					return false;
				}
				else {
					cout << "Invalid input, try again.\n";
				}
			}
		}
		else {
			cout << "Invalid input, try again.\n";
		}
	}
	return false; // fallback
}

void refund_menu() {
	bool keep_running = true;

	while (keep_running) {
		return_screen();

		char return_choice;
		cout << "Is there anything you would like to refund? (Y/N): ";
		cin >> return_choice;

		if (return_choice == 'Y' || return_choice == 'y') {
			keep_running = return_yes();
		}
		else if (return_choice == 'N' || return_choice == 'n') {
			cout << "\nYou chose not to refund, back to the menu\n\n";
			Customer_menu();
			keep_running = false;
		}
		else {
			cout << "\nInvalid input, try again\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}

void Staff_login() {
	string password;
	const int STAFF_ID = 1001;
	int staff_ID;
	bool ValidInput = false;
	int tries = 0;
	while (!ValidInput) {
		cout << endl << "Staff login" << endl;
		cout << "Enter staff ID (1001): ";
		cin >> staff_ID;
		cout << "Enter Password: ";
		cin >> password;
		if (staff_ID == STAFF_ID && password == "1234") {
			ValidInput = true;
			cout << endl;
			Staff_menu();
		}
		else {
			cout << endl << "Wrong details. Please try again. " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			tries++;
		}
		if (tries == 3) {

			cout << "Too many attempts in short time, try again later" << endl << endl; //extra function (3 tries limit)
			tries = 0;
			ValidInput = true;

			Selection_menu();
		}
	}
}

void header() {
	std::cout << "===========================================\n";
	std::cout << "           WELCOME TO MRS DIY!\n";
	std::cout << "   Everything You Need,Everything We Have\n";
	std::cout << "===========================================\n\n";
}

void displayCategory(MenuItem items[], int size, string categoryName) {

	cout << "Category: " << categoryName << endl;
	cout << "\n============================================== Current Stock =======================================================\n";
	cout << left << setw(10) << "ID"
		<< setw(30) << "Name"
		<< setw(15) << "Stock"
		<< setw(25) << "Supplier"
		<< setw(20) << "Price"
		<< "Phone" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------\n";

	for (int i = 0; i < size; ++i) {
		cout << left << setw(10) << (i + 1)
			<< setw(30) << items[i].name
			<< setw(15) << items[i].quantity
			<< setw(25) << items[i].supplier
			<< "RM " << setw(15) << fixed << setprecision(2) << items[i].price
			<< items[i].phone << endl;
	}
}

void restockItem(MenuItem items[], int index) { //huey sryan
	char again = 'n';
	int quantity;

	while (true) {
		cout << "Enter quantity to restock: ";
		cin >> quantity;
		cin.clear();
		cin.ignore(1000, '\n');

		if (quantity >= 1 && quantity <= 100000)
			break;
		else
			cout << "Invalid Input, try again." << endl << endl;
	}
	cout << endl;
	double total = quantity * items[index].price;
	cout << "You added: " << quantity << " x " << items[index].name
		<< " = RM " << fixed << setprecision(2) << total << endl;
	items[index].quantity += quantity;
	restockinvoice[restockinvoiceCount] = {
		items[index].name,
		items[index].supplier,
		items[index].price,
		quantity
	};

	restockinvoiceCount++;
	cout << "\nItem restocked successfully.\n";
	cout << "Subtotal: RM " << fixed << setprecision(2) << total << endl;
	cout << endl;
	cout << "RESTOCK INVOICE" << endl;
	cout << "---------------" << endl;
	cout << "Item Name      : " << items[index].name << endl;
	cout << "Supplier Name  : " << items[index].supplier << endl;
	cout << "Phone Number   : " << items[index].phone << endl;
	cout << "Unit Price     : RM " << fixed << setprecision(2) << items[index].price << endl;
	cout << "Quantity       : " << quantity << endl;
	cout << "---------------------------------------" << endl;
	cout << "Total price    : RM " << fixed << setprecision(2) << total << endl;
	cout << "---------------------------------------" << endl;
}

void restock() {
	char again = 'Y';
	int category;
	int id;
	string categoryName;
	restockScreen();

	do {
		cout << "Which category you want to restock ? " << endl;
		cout << "[1] Hardware" << endl;
		cout << "[2] Home Appliances" << endl;
		cout << "[3] Electrical" << endl;
		cout << "[0] Exit " << endl;
		cout << "Please enter your choice: " << endl;
		cin >> category;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << endl;

		MenuItem* selectedItems;
		int size = 5;
		if (category == 1) {
			selectedItems = Hardware;
			categoryName = "Hardware";
		}
		else if (category == 2) {
			selectedItems = Home_Appliances;
			categoryName = "Home Appliances";
		}
		else if (category == 3) {
			selectedItems = Electrical;
			categoryName = "Electrical";
		}
		else if (category == 0) {
			Staff_menu();
			return;
		}
		else {
			cout << "Invalid category. Please try again" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		displayCategory(selectedItems, size, categoryName);
		cout << "Enter item ID to restock" << endl;
		cout << "Enter [0] to return back" << endl;
		cin >> id;
		cin.clear();
		cin.ignore(1000, '\n');
		if (id >= 1 && id <= 5) {
			restockItem(selectedItems, id - 1);
			displayCategory(selectedItems, size, categoryName);
		}
		else if (id == 0) {
			restock();
		}
		else {
			cout << "Invalid item ID.";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		cout << endl;
		do {
			cout << "Do you want to restock another item? (Y/N): ";
			cin >> again;
			cout << endl;

			if (!(again == 'Y' || again == 'y' || again == 'N' || again == 'n')) {
				cout << "Invalid input! Please enter Y or N." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				again = 'Y';  // default to continue until valid input
			}

		} while (!(again == 'Y' || again == 'y' || again == 'N' || again == 'n'));

	} while (again == 'Y' || again == 'y');

	double grandTotal = 0;
	cout << "\nGenerating invoice....\n";
	Sleep(1000);

	cout << "================================ COMBINED INVOICE ===================================" << endl;
	cout << left << setw(25) << "Item"
		<< setw(18) << "Supplier"
		<< setw(18) << "Unit Price"
		<< setw(13) << "Quantity"
		<< setw(18) << "Total Price" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < restockinvoiceCount; ++i) {
		double total = restockinvoice[i].price * restockinvoice[i].quantity;
		cout << left << setw(25) << restockinvoice[i].name
			<< setw(18) << restockinvoice[i].supplier
			<< "RM " << setw(15) << fixed << setprecision(2) << restockinvoice[i].price
			<< setw(15) << restockinvoice[i].quantity
			<< "RM " << fixed << setprecision(2) << total << endl;
		grandTotal += total;
	}

	cout << "--------------------------------------------------------------------------------------" << endl;
	cout << right << setw(79) << "Grand Total: RM " << fixed << setprecision(2) << grandTotal << endl;
	Staff_menu ();
	return;
}

void Payment_method(double total, double service_tax, double members_discount, bool hasMembership) {
	int input;
	string method, card, pin;
	cout << "\n---------PAYMENT---------\n";
	cout << "Select a payment method:" << endl;
	cout << "[1] Cash" << endl;
	cout << "[2] Touch n Go" << endl;
	cout << "[3] Card" << endl;
	cout << "Select: ";
	input = GetValidInput(1, 3);
	switch (input) {

	case 1:
		method = "Cash";
		cout << "Cash" << endl;
		cout << "Please proceed to the counter and pay with cash." << endl << endl;
		break;
	case 2:
		method = "TNG";
		cout << "TNG" << endl;
		cout << "Please scan this QR code using your Touch n Go eWallet app." << endl;
		cout << "            ################" << endl;
		cout << "            # ##   ###   ###" << endl;
		cout << "            ###  ##  #### ##" << endl;
		cout << "            ##     QR  #   #" << endl;
		cout << "              ### ###   ####" << endl;
		cout << "            ## ##    ####   " << endl;
		cout << "            ################" << endl << endl;
		Sleep(3000);
		break;

	case 3:
		method = "Card";
		cout << "Card" << endl;
		cout << "Please enter your card last 4 digit." << endl;
		cout << "Enter card digit: ";
		int cardDigit = GetValidInt();
		cout << "Please enter your pin number." << endl;
		cout << "Enter pin number: ";
		int pinNumber = GetValidInt();
		cout << "Processing..." << endl;
		Sleep(1000);
		cout << "PIN accepted." << endl << endl;
		break;
	}

	cout << endl;
	cout << "Payment successful using " << method << "!" << endl;
	cout << "Generating your receipt..." << endl << endl;
	Sleep(1000);

	double tax = total * service_tax;
	double discount = hasMembership ? (total * members_discount) : 0;
	double finalTotal = total + tax - discount;

	cout << "<<<<<<<<<<<<<<< INVOICE >>>>>>>>>>>>>>>" << endl;
	cout << "                MRS DIY                " << endl;
	cout << "---------------------------------------" << endl;
	cout << "              011-2345678              " << endl << endl;
	cout << "       Invoice No: 1   1/9/2025        " << endl << endl;

	for (int i = 0; i < ItemInCart.size(); i++) {
		cout << ItemInCart[i] << " x" << Quantity_of_ItemInCart[i]
			<< right << setw(20)
			<< "  RM " << fixed << setprecision(2)
			<< Price_of_ItemInCart[i] * Quantity_of_ItemInCart[i] << endl;
	}

	cout << "----------------------------------------" << endl;
	cout << left << setw(30) << "Subtotal:" << "RM " << right << setw(5) << fixed << setprecision(2) << total << endl;
	cout << left << setw(30) << "SST (6%):" << "RM " << right << setw(5) << tax << endl;
	cout << left << setw(30) << "Total Payable:" << "RM " << right << setw(5) << finalTotal << endl;

	cout << "Paid method: " << method << endl << endl;
	cout << "============= THANK YOU =============" << endl;
	cout << "========== HAVE A NICE DAY ==========" << endl;
	cout << "======= PLEASE COME AGAIN :) ========" << endl << endl;

	// Clear cart 
	ItemInCart.clear();
	Price_of_ItemInCart.clear();
	Quantity_of_ItemInCart.clear();

	return;
}

void feedback() {
	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << "                     *****   *****  *****  *******   *****       *      ******  **   **\n";
	cout << "                     **      **     **     **    **  **  **     * *     **      **  **\n";
	cout << "                     *****   *****  *****  **    **  *****     *****    **      ****\n";
	cout << "                     **      **     **     **    **  **  **   **   **   **      **  **\n";
	cout << "                     **      *****  *****  ******    *****   **     **  ******  **   **\n\n";
	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

	char anonymous, fboption;
	string feedback, fbname;
	double rating;

	cout << "We value your opinion!" << endl
		<< "---------------------------" << endl
		<< "Your feedback helps us improve our products and services so we can serve you better." << endl
		<< "Please take a moment to share your thoughts! it only takes a few minutes." << endl << endl;

	while (true) {
		cout << "Would you like to give any feedback?(Y/N): ";
		cin >> fboption;
		if (fboption == 'y' || fboption == 'Y') {
			break;
		}
		else if (fboption == 'n' || fboption == 'N') {
			cout << "Redirecting you back to menu..." << endl << endl;
			Sleep(1000);//help enos - help me redirect back to menu
			Customer_menu();
			return;

		}
		else {
			cout << "Invalid Input, Please try again..." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}

	while (true) { 
		cout << "How would you rate your experience?\n";
		rating = GetValidInput(1, 5);
		if (rating >= 1 && rating <= 5) {
			break;
		}
		else {
			cout << "Invalid rating, please rate between 1-5." << endl << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}

	cin.ignore(10000, '\n');
	cout << "\nDo you have any comments or suggestions for us to improve?  \n" << "= ";
	getline(cin, feedback);

	while (true) {
		cout << "\nWould you like to stay anomynous for the feedback? (Y/N) > ";
		cin >> anonymous;
		if (anonymous == 'Y' || anonymous == 'y' || anonymous == 'N' || anonymous == 'n') {
			break;
		}
		else {
			cout << "Invalid Input, try again." << endl << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}

	switch (anonymous) {
	case 'Y':
	case 'y':
		cout << "\n\nAlright, we always respect your privacy!" << endl;
		fbname = "Anonymous User";
		break;
	case 'n':
	case 'N':
		cout << endl << "Please Enter Your Information Given:" << endl << "Your First Name: ";
		cin >> fbname;
		break;
	}

	cout << endl << "--------------------" << endl << "- FEEDBACK SUMMARY -"
		<< "\n--------------------" << endl;
	cout << left << setw(10) << "Name:" << fbname << endl;
	cout << left << setw(10) << "Rating:" << rating << endl;
	cout << left << setw(10) << "Feedback:" << feedback << endl << endl;
	cout << "========================================================================================================" << endl
		<< "Thank you for your feedback. Our team will carefully review it and work towards continuous improvement." << endl
		<< "========================================================================================================" << endl << endl;
	cout << "Redirecting you back to the menu..." << endl << endl;
	Sleep(2000);
	Customer_menu();
	return;
}

