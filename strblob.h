#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
    friend class ConstStrBlobPtr;
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);
    friend bool operator<(const StrBlob &, const StrBlob &);
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(const StrBlob &org):
        data(make_shared<vector<string>>(*org.data)) { }
    StrBlob operator=(const StrBlob &org)
    {
        data = make_shared<vector<string>>(*org.data);
        return *this;
    }
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) {data->push_back(t);}
    void push_back(std::string &&t) {data->push_back(t);}
    void pop_back();
    std::string& front();
    std::string& back();
    const std::string &front() const;
    const std::string &back() const;
    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr cbegin();
    ConstStrBlobPtr cend();
    string &operator[](size_t n)
        { return (*data)[n]; }
    const string &operator[](size_t n) const
        { return (*data)[n]; }
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
    friend StrBlobPtr
    operator-(const StrBlobPtr &, size_t);
    friend int
    operator-(const StrBlobPtr &, const StrBlobPtr &);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    std::string& deref() const;
    StrBlobPtr& incr();
    size_t curr_size() const { return curr; }
    StrBlobPtr &operator[](size_t n)
    {
        curr = n;
        return *this;
    }

    StrBlobPtr &operator++()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

    StrBlobPtr &operator--()
    {
        --curr;
        check(-1, "decrement past begin of StrBlobPtr");
        return *this;
    }
    StrBlobPtr operator++(int)
    {
        StrBlobPtr ret = *this;
        ++*this;
        return ret;
    }
    StrBlobPtr operator--(int)
    {
        StrBlobPtr ret = *this;
        --*this;
        return ret;
    }
    StrBlobPtr operator+=(size_t n)
    {
        curr += n;
        return *this;
    }
    StrBlobPtr operator-=(size_t n)
    {
        curr -= n;
        return *this;
    }
    string& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    string* operator->() const{
        return & this->operator*();
    }
private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr(): curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    string& deref() const;
    ConstStrBlobPtr& incr();
    size_t curr_size() const {return curr;}
    const string &operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    const string* operator->() const
    {
        return & this->operator*();
    }
private:
    std::shared_ptr<vector<string>>
        check(size_t sz, const string &msg) const
    {
        auto ret = wptr.lock();
        if (!ret)
            throw runtime_error("not bind");
        if (sz >= ret->size())
            throw out_of_range(msg);
        return ret;
    }
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> li):
    data(make_shared<vector<string>>(li)) { }

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data < *rhs.data;
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.curr < rhs.curr;
}

StrBlobPtr operator+(const StrBlobPtr &lhs, size_t n)
{
    StrBlobPtr ret = lhs;
    ret += n;
    return ret;
}

StrBlobPtr operator-(const StrBlobPtr &lhs, size_t n)
{
    StrBlobPtr ret = lhs;
    ret -= n;
    return ret;
}

int operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.curr - rhs.curr;
}


void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);

    return ret;
}

string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

string& ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "defrence pase end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
    check(curr, "increment pase end of ConstStrBlobPtr");
    ++curr;
    return *this;
}
