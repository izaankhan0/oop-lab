#include <iostream>
#include <stdexcept>
using namespace std;

class BankAccount {
	private:
		double accountBalance;
	public:
		BankAccount(){
			accountBalance = 0;
		}
		BankAccount(double initialAmount = 0.0) {
			if (initialAmount < 0.0) {
				throw invalid_argument("Error: Initial balance cannot be negative.");
			}
			accountBalance = initialAmount;
		}
		void depositAmount(double depositValue) {
			if (depositValue < 0.0) {
				throw invalid_argument("Error: Deposit amount cannot be negative.");
			}
			accountBalance = accountBalance + depositValue;
		}
		void withdrawAmount(double withdrawValue) {
			if (withdrawValue < 0.0) {
				throw invalid_argument("Error: Withdrawal amount cannot be negative.");
			}
			if (withdrawValue > accountBalance) {
				throw invalid_argument("Error: Withdrawal amount exceeds the account balance.");
			}
			accountBalance = accountBalance - withdrawValue;
		}
		double checkBalance() const {
			return accountBalance;
		}
};

int main() {
    try {
        BankAccount userAccount(1000.0);
        cout << "Initial Balance: $" << userAccount.checkBalance() << endl;

        userAccount.depositAmount(500.0);
        cout << "After depositing $500, Balance: $" << userAccount.checkBalance() << endl;

        userAccount.withdrawAmount(200.0);
        cout << "After withdrawing $200, Balance: $" << userAccount.checkBalance() << endl;

        userAccount.withdrawAmount(2000.0);
    } catch (const invalid_argument& errorMessage) {
        cerr << errorMessage.what() << endl;
    }
    return 0;
}
