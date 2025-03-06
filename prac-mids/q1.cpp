#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
	int accountID;
	string ownerName;
	string accType;
	double currentBalance;

public:
	// Default Constructor
	BankAccount()
	{
		accountID = 0;
		ownerName = "";
		currentBalance = 0.0;
		accType = "";
	}

	// Parameterized Constructor
	BankAccount(int id, string name, double balance, string type)
		: accountID(id), ownerName(name), currentBalance(balance), accType(type)
	{
	}

	// Copy Constructor
	BankAccount(const BankAccount &other)
	{
		accountID = other.accountID;
		ownerName = other.ownerName;
		currentBalance = other.currentBalance;
		accType = other.accType;
	}

	void depositFunds(double funds)
	{
		if (funds > 0)
		{
			currentBalance += funds;
			cout << "$" << funds << " added to your account." << endl;
		}
		else
		{
			cout << "Deposit amount must be positive." << endl;
		}
	}

	void withdrawFunds(double funds)
	{
		if (funds <= 0)
		{
			cout << "Withdrawal amount must be positive." << endl;
		}
		else if (funds <= currentBalance)
		{
			currentBalance -= funds;
			cout << "$" << funds << " deducted from your account." << endl;
		}
		else
		{
			cout << "Not enough funds in the account." << endl;
		}
	}

	void displayBalance()
	{
		cout << "Balance: $" << currentBalance << endl;
	}

	void showStatement()
	{
		cout << "Account ID: " << accountID << endl;
		cout << "Owner: " << ownerName << endl;
		cout << "Type: " << accType << endl;
		cout << "Balance: $" << currentBalance << endl;
	}
};

int main()
{
	BankAccount primary(987654, "Ali", 3000.0, "Checking");
	cout << "=-=-= Primary Account =-=-=" << endl;
	primary.displayBalance();
	primary.depositFunds(100);
	primary.displayBalance();
	primary.withdrawFunds(50);
	primary.showStatement();

	cout << "\n=-=-= Cloned Account =-=-=" << endl;
	BankAccount cloneAccount(primary);
	cloneAccount.displayBalance();
	cloneAccount.depositFunds(100);
	primary.displayBalance();
	cloneAccount.withdrawFunds(50);
	cloneAccount.showStatement();

	return 0;
}
