#include <iostream>
#include <string>
using namespace std; 
class Account 6 
{
private:
int Id;
string Name;
double Balance;
public:
void SetData(); //To read the values for data members
void GetData(); //Print the values of data members
void Deposit(double amount); //To deposit the amount
void Withdraw(double amount); //To withdraw the amount
double GetBalance(); 
};
void Account::GetData() 
{
	cout << "---------Account Details---------" << endl;
	cout << "Id: " << Id << endl;
	cout << "Name: " << Name << endl;
	cout << "Balance: " << Balance << endl;
	cout << "---------------------------------" << endl;
 }
 void Account::SetData() 28 {
	cout << "Enter Id: ";
	cin >> Id;
	cout << "Enter Name: ";
	cin >> Name;
	cout << "Enter Balance: ";
	cin >> Balance; 35 }
void Account::Deposit(double amount) 37 {
	this->Balance += amount; 39 }
void Account::Withdraw(double amount) 41 {
	if (this->Balance - amount < 500)
	throw "Insufficient Funds";
	this->Balance -= amount; 45 }
 double Account::GetBalance() 47 {
	return Balance; 49 }
 int ShowMenu() 51 {
	int op;
	cout << "1. Create Object" << endl;
	cout << "2. Set Data" << endl;
	cout << "3. Get Data" << endl;
	cout << "4. Deposit" << endl;
	cout << "5. Withdraw" << endl;
	cout << "6. Destroy object" << endl;
	cout << "7. Exit" << endl;
	cout << "---------------------------" << endl;
	cout << "Enter your choice: ";
	cin >> op;
	return op; 64 }

 int main()
 
 {
	int op;
	double amount;
	Account *pAccount = NULL;	//assigning null value to the pointer object
	do {
	op = ShowMenu();
	switch(op)
	{
	case 1:
	if (pAccount == NULL)
	pAccount = new Account();
	else
	cout << "Object already created" << endl;
	break;
	case 2:
	pAccount->SetData();
	break;
	case 3:
	pAccount->GetData();
		break;
			case 4:
	cout << "Enter the amount to Deposit: ";
	cin >> amount;
	pAccount->Deposit(amount);
	break;
	case 5:
	cout << "Enter the amount to Withdraw: ";
	cin >> amount;
	pAccount->Withdraw(amount);
	break;
	case 6:
	if (pAccount != NULL)
	{
	delete pAccount;
	pAccount = NULL;
	}
	else
cout << "Object is not existing" << endl;
	break;
	}
	} while (op != 7);
	return 0;
 } 

