#include <iostream>
#include <string>
#include <set>

using namespace std;

/*
**  Base Class Quote
 */
class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price):
        bookNo(book), price(sales_price) { }
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const
        { return n * price; }
    Quote(const Quote& rhs): bookNo(rhs.bookNo), price(rhs.price)
    {
#ifdef DEBUG
        cout << "Quote(const Quote&)" << endl;
#endif
    }
    Quote(Quote&& rhs): bookNo(rhs.bookNo), price(rhs.price)
    {
#ifdef DEBUG
        cout << "Quote(Quote &&)" << endl;
#endif
    }
    Quote& operator=(const Quote&) = default;
    Quote& operator=(Quote&&) = default;
    virtual ~Quote() = default;
    virtual void debug() const
    {
        cout << "data members: \n" << "\tbookNo: " << bookNo
             << "\tprice: " << price << endl;
    }
    virtual Quote* clone() const & {return new Quote(*this); }
    virtual Quote* clone() &&
        { return new Quote(std::move(*this));}
private:
    string bookNo;
protected:
    double price = 0.0;
};

/*
**  derived class Disc_quote
 */
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price,
        std::size_t qty, double disc):
            Quote(book, price), quantity(qty), discount(disc) { }
    Disc_quote(const Disc_quote &rhs): Quote(rhs), quantity(rhs.quantity),
        discount(rhs.discount)
    {
#ifdef DEBUG
        cout << "Disc_quote(const Disc_quote&)" << endl;
#endif
    }
    double net_price(std::size_t) const = 0;
    std::pair<size_t, double> discount_policy() const
        { return {quantity, discount}; }
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

/*
**  derived class Bulk_quote
 */
class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double price,
        std::size_t qty, double disc) :
            Disc_quote(book, price, qty, disc) { }
    Bulk_quote(const Bulk_quote &rhs): Disc_quote(rhs)
    {
#ifdef DEBUG
        cout << "Disc_quote(const Bulk_quote&)" << endl;
#endif
    }
    double net_price(std::size_t) const override;
    Bulk_quote* clone() const & override { return new Bulk_quote(*this); }
    Bulk_quote* clone() && override
        { return new Bulk_quote(std::move(*this)); }
};

/*
** derived class Limit_quote
 */
class Limit_quote : public Disc_quote {
public:
    Limit_quote() = default;
    Limit_quote(const std::string& book, double price,
        std::size_t qty, double disc) :
            Disc_quote(book, price, qty, disc) { }
    double net_price(std::size_t) const override;
};

/*
** realted container class basket
 */
class Basket {
public:
    void add_item(const std::shared_ptr<Quote> &sale)
        { items.insert(sale); }
    void add_item(const Quote& sale)
        { items.insert(std::shared_ptr<Quote>(sale.clone())); }
    void add_item(Quote&& sale)
        { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }
    double total_receipt(std::ostream&) const;
private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
        const std::shared_ptr<Quote> &rhs)
    { return lhs->isbn() < rhs->isbn(); }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*>
        items{compare};
};


/*
**  non-member functions
*/
double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "Isbn: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << endl;

    return ret;
}

/*
** member function of class Bulk_quote
 */
 double Bulk_quote::net_price(size_t cnt) const
 {
     if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
 }

 /*
 ** member functions of class Limit_quote
  */
double Limit_quote::net_price(size_t cnt) const
{
    if (cnt <= quantity)
        return cnt * (1 - discount) * price;
    else
        return quantity * (1 - discount) * price + (cnt - quantity) * price;
}

/*
**  member functions for class basket
 */
double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;

    for (auto iter = items.cbegin();
         iter != items.cend();
         iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << endl;
    return sum;
}
