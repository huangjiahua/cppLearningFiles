#include <iostream>
#include <string>
#include <fstream>

void main_menu(void);
void choose_func(bool &);
void thanks(void);
void create_account(void);
bool check_exist(const std::string &);
bool check_num(const std::string &);
void deposit(void);
void withdraw(void);
void enquiry(void);
void list(void);
void print_line(void);
void print_list(const std::string &, const std::string &, const std::string &,
    const std::string &);
void delete_account(void);
void modify(void);

class Account {
private:
    std::string id;
    std::string holder_name;
    char type;
    unsigned long long amount;
public:
    Account(std::string i, std::string hn, char t, unsigned long long a):
        id(i), holder_name(hn), type(t), amount(a) { }
    Account(): Account("", "", 'S', 0) { }
    Account(std::ifstream &);

    void save() const;
    void write_list() const;
    std::string show_id() {return id;}
    std::string show_name() {return holder_name;}
    char show_type() {return type;}
    unsigned long long show_amount() {return amount;}
    void deposit(unsigned long long m) {amount += m;};
    void withdraw(unsigned long long m) {amount -= m;}

};

void Account::save() const{
    std::ofstream output("info/" + id);
    output << id << std::endl;
    output << holder_name << std::endl;
    output << type << std::endl;
    output << amount << std::endl;
    output.close();
}

void Account::write_list() const{
    std::ofstream output("info/list", std::ofstream::app);
    output << id << std::endl;
}

Account::Account(std::ifstream &is)
{
    is >> id >> holder_name >> type >> amount;
}
