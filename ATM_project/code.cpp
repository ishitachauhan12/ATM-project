#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

/* Mini Project:- ATM Facility
1.Check Balance
2.Cash Withdrawal
3.User Details
4.Update Mobile no.
*/

class atm
{
private:
    long int account_no;
    string name;
    int PIN;
    string mobile_no;
    double balance;

public:
    // Setting an account

    void setData(long int accno, string pname, int pPIN, string pmobile_no, double pbalance)
    {
        account_no = accno;
        name = pname;
        PIN = pPIN;
        mobile_no = pmobile_no;
        balance = pbalance;
    }

    // get functions

    long int getAccNo()
    {
        return account_no;
    }

    string getName()
    {
        return name;
    }

    int getPIN()
    {
        return PIN;
    }

    string getMobileNo()
    {
        return mobile_no;
    }

    double getBalance()
    {
        return balance;
    }

    // Update Mobile No

    void UpdateMobileNo(string prev_mobile_no, string new_mobile_no)
    {
        if (prev_mobile_no == mobile_no)
        {
            mobile_no = new_mobile_no;
            cout << "Mobile Number Updated Successfully!";
            _getch();
        }
        else
        {
            cout << "Incorrect, Old Mobile Number";
        }
    }

    // Withdraw Cash

    void withdrawCash(int amount)
    {
        if (balance >= amount && amount > 0)
        {
            balance -= amount;
            cout << "Please collect your cash" << endl;
            cout << "Available Balance: " << balance << endl;
            _getch();
        }
        else
        {
            cout << "Incorrect data or Insufficient balance";
            _getch();
        }
    }
};

int main()
{
    // authentication details
    long int enterAccountNo;
    int choice = 0, enterPIN;

    system("cls"); // cleans the screen as we move to seperate window

    // created object named user1
    atm user1;

    // set details
    user1.setData(123456789, "Ishi", 1234, "9876543210", 10000.90);

    do
    {
        system("cls");
        cout << endl
             << "***WELCOME TO FREEFUND ATM***" << endl;
        cout << endl
             << "Enter your account no: ";
        cin >> enterAccountNo;
        cout << endl
             << "Enter PIN: ";
        cin >> enterPIN;

        if (enterAccountNo == user1.getAccNo() && enterPIN == user1.getPIN())
        {

            do
            {
                int amount = 0;
                string newMobileNo, prevMobileno;
                system("cls");

                cout << endl
                     << "***WELCOME TO FREEFUND ATM***" << endl;
                cout << endl
                     << "Hi, " << user1.getName() << endl;
                cout << endl
                     << "Select Options:";
                cout << endl
                     << "1. Check Balance";
                cout << endl
                     << "2. Cash Withdrawal";
                cout << endl
                     << "3. User details";
                cout << endl
                     << "4. Update Mobile No.";
                cout << endl
                     << "5. Exit" << endl;
                cin >> choice;
                switch (choice)
                {
                case 1:
                    cout << endl
                         << "Your bank balance is: " << user1.getBalance();
                    _getch();
                    break;

                case 2:
                    cout << endl
                         << "Enter amount: ";
                    cin >> amount;
                    cout << endl;
                    user1.withdrawCash(amount);
                    break;

                case 3:
                    cout << endl
                         << "Account No.: " << user1.getAccNo() << endl;
                    cout << "Name: " << user1.getName() << endl;
                    cout << "PIN: " << user1.getPIN() << endl;
                    cout << "Mobile NO.: " << user1.getMobileNo() << endl;
                    _getch();
                    break;

                case 4:
                    cout << endl
                         << "Enter Old Mobile No.: ";
                    cin >> prevMobileno;
                    cout << endl
                         << "Enter New Mobile No.: ";
                    cin >> newMobileNo;

                    user1.UpdateMobileNo(prevMobileno, newMobileNo);

                    break;

                case 5:
                    exit(0);

                default:
                    cout << "Enter valid data..";
                }

            } while (1);
        }

        else
        {
            cout << "Invalid Account no or PIN..";
            _getch();
        }

    } while (1);

    return 0;
}