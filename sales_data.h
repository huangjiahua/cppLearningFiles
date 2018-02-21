#include <iostream>
#include <string>

using namespace std;

class Sales_data {
// non member Sales_data interface function
friend std::hash<Sales_data>;
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend ostream &operator<<(ostream &os, const Sales_data &item);
friend std::istream &read(std::istream&, Sales_data&);
friend istream &operator>>(istream &is, Sales_data &item);
friend Sales_data operator+(const Sales_data &, const Sales_data &);
friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs);

public:
    // constructor added
    Sales_data(const std::string &s, unsigned n, double p) :
               bookNo(s), units_sold(n), revenue(p*n)
    {
        std::cout << "Sales_data(string, unsigned, double)" << std::endl;
    }

    Sales_data(): Sales_data("", 0, 0)
    {
        std::cout << "Sales_data()" << std::endl;
    }
    Sales_data(const std::string &s): Sales_data(s, 0, 0)
    {
        std::cout << "Sales_data(string)" << std::endl;
    }
    Sales_data(std::istream &is): Sales_data()  {
        std::cout << "Sales_data(istream)" << std::endl;
        double price = 0.0;
        is >> bookNo >> units_sold >> price;
        revenue = price * units_sold;
    }
    Sales_data(const Sales_data&);
    Sales_data& operator=(const Sales_data&);
    Sales_data& operator=(const string &);
    Sales_data& operator+=(const Sales_data&);
    std::string isbn() const { return bookNo; }
    unsigned units() const { return units_sold; }
    Sales_data &combine(const Sales_data&);
    explicit operator string() {return bookNo;}
    explicit operator double() {return revenue;}
private:
    // member
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    //new member
    double avg_price() const;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

ostream &operator<<(ostream &os, const Sales_data &item);
istream &operator>>(istream &is, Sales_data &item);
Sales_data &operator+(Sales_data &lhs, Sales_data &rhs);

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn() &&
           lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs);
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data &Sales_data::operator=(const string &str)
{
    bookNo = str;
    units_sold = 0;
    revenue = 0;
    return *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &item)
{
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;
}

ostream &operator<<(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();

    return os;
}

istream &operator>>(istream &is, Sales_data &item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = item.units_sold * price;
    else
        item = Sales_data();
    return is;
}



double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::ostream &print(std::ostream &os, const Sales_data &sd)
{
    os << sd.isbn() << " " << sd.units_sold << " " << sd.revenue
       << " " << sd.avg_price();
    return os;
}

std::istream &read(std::istream &is, Sales_data &sd)
{
    double price = 0.0;
    is >> sd.bookNo >> sd.units_sold >> price;
    sd.revenue = sd.units_sold * price;
    return is;
}

Sales_data add(const Sales_data &r1, const Sales_data &r2)
{
    Sales_data rhs = r1;
    rhs.combine(r2);
    return rhs;
}

namespace std {
    template <>
    struct hash<Sales_data>
    {
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator()(const Sales_data& s) const;
    };
    size_t
    hash<Sales_data>::operator()(const Sales_data& s) const
    {
        return hash<string>()(s.bookNo) ^
        hash<unsigned>()(s.units_sold) ^
        hash<double>()(s.revenue);
    }
}
