#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>

using namespace std;

class account {
	int acno;
	char name[50];
	int deposit;
	char type;
public:
	void create_account();	//function to get data from user
	void show_account() const;	//function to show data on screen
	void modify();	//function to add new data
	void dep(int);	//function to accept amount and add to balance amount
	void draw(int);	//function to accept amount and subtract from balance amount
	void transactions(int); //function to do transactions
	void report() const;	//function to show data in tabular format
	int retacno() const;	//function to return account number
	int retdeposit() const;	//function to return balance amount
	char rettype() const;	//function to return type of account
};

void account::create_account() {
	cout << "\nEnter The account No. :";
	cin >> acno;
	cout << "\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nEnter Type of The account (C/S) : ";
	cin >> type;
	type = toupper(type);
	cout << "\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin >> deposit;
	cout << "\n\n\nAccount Created..";
}

void account::show_account() const {
	cout << "\nAccount No. : " << acno;
	cout << "\nAccount Holder Name : ";
	cout << name;
	cout << "\nType of Account : " << type;
	cout << "\nBalance amount : " << deposit;
}


void account::modify() {
	cout << "\nAccount No. : " << acno;
	cout << "\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nModify Type of Account : ";
	cin >> type;
	type = toupper(type);
	cout << "\nModify Balance amount : ";
	cin >> deposit;
}

void transactions() {
	int trans[7] = {0, 1, 2, 3, 4, 5, 6};
	int items[3] = { 1,2,3 };
	char o;
	do {
		cout << "\n Transactions Menu!\n";
		cout << "\n01. Deposit";
		cout << "\n02 Withdraw";
		cout << "\n03 Buy";
		cout << "\n04 Sell Using Existing Funds";
		cout << "\n05 Sell Using Credit";
		cout << "\n06 Null Transaction";

		cout << "Select Your Option:(1-6): ";
		cin >> o;

		system("cls");

		switch (o) {
			case '1':
				int amount;
				int acno;
				cout << "Enter Acount Number: ";
				cin >> acno;
				cout << "Enter amount to deposit: ";
				cin >> amount;
				cout << amount << " has been deposited to " << acno << endl;
				break;
			case '2':
				int am;
				int ac;

				cout << "Enter Acount Number: ";
				cin >> ac;
				cout << "Enter amount to withdraw: ";
				cin >> am;

				cout << am<< " has been withdrawn from " << ac<<" number\n";
				break;
			case '3':
				int aco;
				int buy;

				cout << "Enter Acount Number: ";
				cin >> aco;
				cout << "Enter Item Number to Buy: ";
				cin >> buy;
				if (buy==items[0]){
					cout << "You Purchased Item Number 1\n";
					cout << "200$s have been deducted from your acount\n";
				}
				else if (buy == items[1]) {
					cout << "You Purchased Item Number 2\n";
					cout << "100$s have been deducted from your acount\n";
				}
				else if (buy == items[2]) {
					cout << "You Purchased Item Number 3\n";
					cout << "700$s have been deducted from your acount\n";
				}
				break;
			case '4':
				int acon;
				int sell;

				cout << "Enter Acount Number: ";
				cin >> acon;
				cout << "Enter Item Number to Buy: ";
				cin >> sell;

				if (sell == items[0]) {
					cout << "You sold Item Number " << items[0] << "\n";
					cout << "200$s have been added to your acount\n";
				}
				else if (sell == items[1]) {
					cout << "You sold Item Number " << items[1] << "\n";
					cout << "100$s have been added to your acount\n";
				}
				else if (sell == items[2]) {
					cout << "You sold Item Number "  << items[2] << "\n";
					cout << "700$s have been added to your acount\n";
				}
				break;
			case '5':
				int acot;
				int sel, credit;

				cout << "Enter Acount Number: ";
				cin >> acot;
				cout << "Enter Credit Card Number: ";
				cin >> credit;
				cout << "Enter Item Number to Buy: ";
				cin >> sel;

				if (sell == items[0]) {
					cout << "You sold Item Number " << items[0] << "using"<<credit<<" card\n";
					cout << "200$s have been added to your acount\n";
				}
				else if (sell == items[1]) {
					cout << "You sold Item Number " << items[1] << "using" << credit << " card\n";
					cout << "100$s have been added to your acount\n";
				}
				else if (sell == items[2]) {
					cout << "You sold Item Number " << items[0] << "using" << credit << " card\n";
					cout << "700$s have been added to your acount\n";
				}
			case '6':
				int send,rec;

				cout << "Enter Your Acount number: ";
				cin >> send;
				cout << "Enter Reciver acount number: ";
				cin >> rec;

				cout << "Null Transaction send to" << rec << " acount number\n";
				break;
			case '0':
				cout << "\nExiting";
				break;
			default:cout << "\a";
			}
		cin.ignore();
		cin.get();
		} while (o != '0');
}

void account::dep(int x){
	deposit += x;
}

void account::draw(int x){
	deposit -= x;
}

void account::report() const {
	cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}


int account::retacno() const {
	return acno;
}

int account::retdeposit() const {
	return deposit;
}

char account::rettype() const {
	return type;
}


void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function


int main() {
	char ch;
	int num;
	intro();
	do {
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. NEW ACCOUNT";
		cout << "\n\n\t02. DEPOSIT AMOUNT";
		cout << "\n\n\t03. WITHDRAW AMOUNT";
		cout << "\n\n\t04. BALANCE ENQUIRY";
		cout << "\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout << "\n\n\t06. PERFORM TRANSACTIONS";
		cout << "\n\n\t07. CLOSE AN ACCOUNT";
		cout << "\n\n\t08. MODIFY AN ACCOUNT";
		cout << "\n\n\t00. EXIT";
		cout << "\n\n\tSelect Your Option (0-8) ";
		cin >> ch;

		system("cls");

		switch (ch) {
		case '1':
			write_account();
			break;
		case '2':
			cout << "\n\n\tEnter The account No. : "; cin >> num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout << "\n\n\tEnter The account No. : "; cin >> num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			cout << "\n\n\tEnter The account No. : "; cin >> num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			transactions();
			break;
		case '7':
			cout << "\n\n\tEnter The account No. : "; cin >> num;
			delete_account(num);
			break;
		case '8':
			cout << "\n\n\tEnter The account No. : "; cin >> num;
			modify_account(num);
			break;
		case '0':
			cout << "\n\n\tThanks for using bank managemnt system";
			break;
		default:cout << "\a";
		}

		cin.ignore();
		cin.get();
	} while (ch != '8');
	return 0;
}

void write_account() {
	account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
	outFile.close();
}

void display_sp(int n) {
	account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile){
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\nBALANCE DETAILS\n";

	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account))) {
		if (ac.retacno() == n) {
			ac.show_account();
			flag = true;
		}
	}
	inFile.close();

	if (flag == false)
		cout << "\n\nAccount number does not exist";
}


void modify_account(int n) {
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File) {
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false) {
		File.read(reinterpret_cast<char*> (&ac), sizeof(account));
		if (ac.retacno() == n) {
			ac.show_account();
			cout << "\n\nEnter The New Details of account" << endl;
			ac.modify();
			int pos = (-1) * static_cast<int>(sizeof(account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&ac), sizeof(account));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}


void delete_account(int n) {
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile) {
		cout << "File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account))) {
		if (ac.retacno() != n) {
			outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat", "account.dat");
	cout << "\n\n\tRecord Deleted ..";
}

void display_all() {
	account ac;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile){
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "====================================================\n";
	cout << "A/c no.      NAME           Type  Balance\n";
	cout << "====================================================\n";
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account))){
		ac.report();
	}
	inFile.close();
}

void deposit_withdraw(int n, int option) {
	int amt;
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File) {
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false) {
		File.read(reinterpret_cast<char*> (&ac), sizeof(account));
		if (ac.retacno() == n) {
			ac.show_account();
			if (option == 1) {
				cout << "\n\n\tTO DEPOSITE AMOUNT ";
				cout << "\n\nEnter The amount to be deposited";
				cin >> amt;
				ac.dep(amt);
			}
			if (option == 2) {
				cout << "\n\n\tTO WITHDRAW AMOUNT ";
				cout << "\n\nEnter The amount to be withdraw";
				cin >> amt;
				int bal = ac.retdeposit() - amt;
				if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C'))
					cout << "Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos = (-1) * static_cast<int>(sizeof(ac));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&ac), sizeof(account));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}

void intro(){
	cout << "\n\n\n\t  BANK ACCOUNT";
	cout << "\n\n\t    MANAGEMENT";
	cout << "\n\n\t    SYSTEM";
	cin.get();
}
