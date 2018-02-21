#include <iostream>
#include <memory>
#include <algorithm>
#include <utility>

using namespace std;

size_t strlen(char *s)
{
    size_t i = 0;
    for ( ; *s != '\0'; ++s, ++i)
        ;
    return i;
}

class String {
    friend ostream &operator<<(ostream &, const String &);
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);
    friend bool operator<(const String &, const String &);
public:
    String(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const char *s);
    String(const String &);
    String &operator=(const String &);
    ~String();
    void push_back(const char &);
    void reserve(size_t sz);
    void resize(size_t sz);
    void resize(size_t sz, const char &ch);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char *begin() const { return elements; }
    char *end() const  { return first_free; }
    String(String &&rhs) noexcept;
    String& operator=(String &&rhs) noexcept;
    char &operator[](size_t n)
        { return elements[n]; }
    const char &operator[](size_t n) const
        { return elements[n]; }
private:
    char *elements;
    char *first_free;
    char *cap;
    std::allocator<char> alloc;
    void free();
    void reallocate();
    void alloc_n_move(size_t newcap);
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    pair<char *, char *> alloc_n_copy
        (const char *, const char *);
};

ostream &operator<<(ostream &os, const String &str)
{
    for (auto elem = str.elements; elem != str.first_free; ++elem)
        os << *elem;
    return os;
}

bool operator==(const String &lhs, const String &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    for (size_t i = 0; i != lhs.size(); ++i)
        if (*(lhs.elements) != *(rhs.elements))
            return false;
    return true;
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    size_t i = 0;
    for (; (i != lhs.size()) && (i != rhs.size()); ++i) {
        if (*(lhs.elements + i) < *(rhs.elements + i))
            return true;
    }
    return lhs.size() < rhs.size();
}

String::String(const char *s)
{
    size_t sz = strlen(s);
    auto newdata = alloc.allocate(sz);
    for (size_t i = 0; i != sz; ++i)
        alloc.construct(newdata + i, *s++);
    elements = newdata;
    first_free = cap = newdata + sz;
}

void String::alloc_n_move(size_t newcap)
{
    auto elem = elements;
    auto newdata = alloc.allocate(newcap);
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(newdata + i, move(*elem++));
    free();
    elements = newdata;
    first_free = newdata + size();
    cap = newdata + newcap;
}

void String::reallocate()
{
    auto newcapacity = size() ? 2 * capacity() : 1;
    alloc_n_move(newcapacity);
}

void String::push_back(const char &ch)
{
    chk_n_alloc();
    alloc.construct(first_free++, ch);
}

pair<char *, char *>
String::alloc_n_copy(const char *b, const char *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void String::free()
{
    if (elements) {
        for_each(elements, first_free, [this](char &pc)
            {alloc.destroy(&pc);});
        alloc.deallocate(elements, cap - elements);
    }
}

String::String(const String &str)
{
    auto newdata = alloc_n_copy(str.begin(), str.end());
    elements = newdata.first;
    cap = first_free = newdata.second;
    cout << "String(const String &str)" << endl;
}

String::~String()
{
    free();
}

String &String::operator=(const String &str)
{
    auto newdata = alloc_n_copy(str.begin(), str.end());
    free();
    elements = newdata.first;
    cap = first_free = newdata.second;
    cout << "String &operator=(const String &str)" << endl;
    return *this;
}

String::String(String &&rhs) noexcept: elements(rhs.elements),
    first_free(rhs.first_free), cap(rhs.cap)
{
    cout << "String(String &&rhs)" << endl;
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

String& String::operator=(String &&rhs) noexcept
{
    cout << "String& operator=(String &&rhs)" << endl;
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}
