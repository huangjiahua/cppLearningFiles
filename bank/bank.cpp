#include <iostream>
#include <cctype>
#include <vector>
#include <cstdlib>
#include "bank.h"

using namespace std;

int main()
{
    bool active = 1;
    while (active) {
        main_menu();
        choose_func(active);
    }
    thanks();
}

void main_menu(void)
{
    cout << "MAIN MENU" << endl;
    cout << "01. NEW ACCOUNT" << endl;
    cout << "02. DEPOSIT AMOUNT" << endl;
    cout << "03. WITHDRAW AMOUNT" << endl;
    cout << "04. BALANCE ENQUIRY" << endl;
    cout << "05. ALL ACCOUNT HOLDER LIST" << endl;
    cout << "06. CLOSE AN ACCOUNT" << endl;
    cout << "07. MODIFY AN ACCOUNT" << endl;
    cout << "08. EXIT" << endl;
}

void choose_func(bool &act)
{
    char opt = 0;
    cout << "SELECT YOUR OPTION <1~8>: ";
    if (cin >> opt) {
        system("clear");
        switch (opt - '0') {
            case 8: {
                act = 0;
                system("clear");
                break;
            }
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                enquiry();
                break;
            case 5:
                list();
                break;
            case 6:
                delete_account();
                break;
            case 7:
                modify();
                break;
            default:
                break;
        }
    }
    else {
        cin.clear();
        cerr << "WRONG USAGE" << endl;
        return ;
    }
}

void thanks()
{
    cout << "THANKS FOR USING" << endl;
}

void create_account()
{
    string number, name, amount;
    char type;
    cout << "==== NEW ACCOUNT ====\n" << endl;
    cout << "Enter the account number: " << flush;
    cin >> number;
    while (!check_exist(number)) {
        cout << "\nThis number have been occupied! Please pick another one"
            << endl;
        cout << "Enter the account number: " << flush;
        cin >> number;
    }

    cout << "Enter the name of the holder(use_ instead of space): " << flush;
    cin >> name;

    cout << "Enter the type of the account <S or T>: " << flush;
    cin >> type;
    while (type != 'S' && type != 'T') {
        cout << "\nThe type must be either S or T!" << endl;
        cout << "Enter the type of the account <S or T>: " << flush;
        cin >> type;
    }

    cout << "Enter initial amount\n\t>=500 for Saving >=1000 for current: "
        << flush;
    cin >> amount;
    while (!check_num(amount)) {
        cout << "Please enter digits" << endl;
        cout << "Enter initial amount\n\t>=500 for Saving >=1000 for current: "
            << flush;
        cin >> amount;
    }

    Account new_account(number, name, type, stoull(amount));
    new_account.save();
    new_account.write_list();
    system("clear");
    cout << "Your account created successfully..." << endl;
}

void deposit()
{
    string no;
    string money;
    cout << "==== ACCOUNT TRANSACTION FORM ====\n" << endl;
    cout << "Enter the account No. : " << flush;
    cin >> no;
    while (check_exist(no)) {
        cout << "No matching id!" << endl;
        cout << "Enter the account No. : " << flush;
        cin >> no;
    }
    ifstream input("info/" + no);
    Account user(input);

    cout << "\n---- ACCOUNT STATUS ----" << endl;
    cout << "ACCOUNT No.: " << user.show_id() << endl;
    cout << "ACCOUNT HOLDER NAME: " << user.show_name() << endl;
    cout << "TYPE of ACCOUNT: " << user.show_type() << endl;
    cout << "BAlANCE AMOUNT: " << user.show_amount() << endl;
    cout << endl;

    cout << "Enter the amount to DEPOSIT: " << flush;
    cin >> money;
    while (!check_num(money)) {
        cout << "Please enter digit!" << endl;
        cout << "Enter the amount to DEPOSIT: " << flush;
        cin >> money;
    }
    user.deposit(stoull(money));
    user.save();
    system("clear");
    cout << "\t\tRecord Updated..." << endl;
}

void withdraw()
{
    string no;
    string money;
    cout << "==== ACCOUNT TRANSACTION FORM ====\n" << endl;
    cout << "Enter the account No. : " << flush;
    cin >> no;
    while (check_exist(no)) {
        cout << "No matching id!" << endl;
        cout << "Enter the account No. : " << flush;
        cin >> no;
    }
    ifstream input("info/" + no);
    Account user(input);

    cout << "\n---- ACCOUNT STATUS ----" << endl;
    cout << "ACCOUNT No.: " << user.show_id() << endl;
    cout << "ACCOUNT HOLDER NAME: " << user.show_name() << endl;
    cout << "TYPE of ACCOUNT: " << user.show_type() << endl;
    cout << "BAlANCE AMOUNT: " << user.show_amount() << endl;
    cout << endl;

    cout << "Enter the amount to WITHDRAW: " << flush;
    cin >> money;
    while (!check_num(money)) {
        cout << "Please enter digit!" << endl;
        cout << "Enter the amount to DEPOSIT: " << flush;
        cin >> money;
    }
    if (stoull(money) > user.show_amount()) {
        cout << "The account does not have that much money" << endl;
        cout << "Automatically withdraw all!" << endl;
        user.withdraw(user.show_amount());
    }
    else
        user.withdraw(stoull(money));
    user.save();
    cout << "\t\tRecord Updated..." << endl;
    char x;
    cin >> x;
    system("clear");
}

void enquiry()
{
    string no;
    cout << "==== BALANCE DETAIL ====\n" << endl;
    cout << "Enter the account No. : " << flush;
    cin >> no;
    while (check_exist(no)) {
        cout << "No matching id!" << endl;
        cout << "Enter the account No. : " << flush;
        cin >> no;
    }
    ifstream input("info/" + no);
    Account user(input);
    cout << "\n---- ACCOUNT STATUS ----" << endl;
    cout << "ACCOUNT No.: " << user.show_id() << endl;
    cout << "ACCOUNT HOLDER NAME: " << user.show_name() << endl;
    cout << "TYPE of ACCOUNT: " << user.show_type() << endl;
    cout << "BAlANCE AMOUNT: " << user.show_amount() << endl;
    cout << endl;

    int x;
    cin >> x;
}

void list()
{
    cout << "                    ";
    cout << "ACCOUNT HOLDER LIST" << endl;
    vector<string> id_list;
    string id;
    ifstream input("info/list");
    while (input >> id) {
        id_list.push_back(id);
    }
    input.close();
    print_line();
    print_list("A/c no.", "NAME", "Type", "Balance");
    print_line();
    for (const auto &i : id_list) {
        ifstream entry("info/" + i);
        Account curr(entry);
        print_list(curr.show_id(), curr.show_name(), string{curr.show_type()},
            to_string(curr.show_amount()));
    }
    int x;
    cin >> x;
    system("clear");
}

void print_line()
{
    for (int i = 0; i < 65; ++i)
        cout << "=";
    cout << endl;
}

void print_list(const string &str1, const string &str2, const string &str3,
    const string &str4)
{
    cout.clear();
    cout.setf(std::ios::left);
    cout.width(20);
    cout << str1;
    cout.setf(std::ios::left);
    cout.width(20);
    cout << str2;
    cout.setf(std::ios::left);
    cout.width(20);
    cout << str3;
    cout.setf(std::ios::left);
    cout.width(6);
    cout << str4;
    cout << endl;
}

void delete_account()
{
    string no;
    vector<string> id_list;
    string id;
    cout << "==== DELETE RECORD ====\n" << endl;
    cout << "Enter the account No. : " << flush;
    cin >> no;
    while (check_exist(no)) {
        cout << "The No. does not exist!" << endl;
        cout << "Enter the account No. : " << flush;
        cin >> no;
    }
    ifstream f("info/list");
    while (f >> id) {
        id_list.push_back(id);
    }
    f.close();
    auto i = id_list.begin();
    for (; i != id_list.end(); ++i) {
        if (*i == no)
            break;
    }
    id_list.erase(i);
    ofstream out("info/list");
    for (const auto & item : id_list) {
        out << item << endl;
    }
    string temp = string("rm ") + "info/" + no;
    system(temp.c_str());
    cout << "\n\nRECORD DELETED..." << flush;
    int x;
    cin >> x;
    system("clear");
}

void modify()
{
    cout << "==== MODIFY RECORD ====\n" << endl;
    string no;
    cout << "Enter the account No. : " << flush;
    cin >> no;
    while (check_exist(no)) {
        cout << "No matching id!" << endl;
        cout << "Enter the account No. : " << flush;
        cin >> no;
    }
    ifstream input("info/" + no);
    Account user(input);
    string name, amount;
    char type;

    cout << "\n---- ACCOUNT STATUS ----" << endl;
    cout << "ACCOUNT No.: " << user.show_id() << endl;
    cout << "ACCOUNT HOLDER NAME: " << user.show_name() << endl;
    cout << "TYPE of ACCOUNT: " << user.show_type() << endl;
    cout << "BAlANCE AMOUNT: " << user.show_amount() << endl;
    cout << endl;

    cout << "\n\n---- ENTER THE NEW DETAIL ----" << endl;
    cout << "Modify account holder name: " << flush;
    cin >> name;
    cout << "Modify account type: " << flush;
    cin >> type;
    while (type != 'T' && type != 'S') {
        cout << "The type can either be T or S!" << endl;
        cout << "Modify account type: " << flush;
        cin >> type;
    }
    cout << "Modify Balance Account: " << flush;
    cin >> amount;
    while (!check_num(amount)) {
        cout << "Please enter digits!" << endl;
        cout << "Modify Balance Account: " << flush;
        cin >> amount;
    }

    Account new_user(user.show_id(), name, type, stoull(amount));
    new_user.save();
    cout << "\n\n\t\tRECORD UPDATED..." << flush;
    int x;
    cin >> x;
    system("clear");
}

bool check_exist(const string &str)
{
    ifstream read_list("info/list");
    string prev;
    while (read_list >> prev) {
        if (str == prev)
            return 0;
    }
    return 1;
}

bool check_num(const string &num)
{
    for (const auto &i : num) {
        if (!isdigit(i))
            return 0;
    }
    return 1;
}
