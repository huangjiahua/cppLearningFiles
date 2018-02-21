#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <algorithm>

using namespace std;

class StrVec {
    friend bool operator<(const StrVec &, const StrVec &);
public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(initializer_list<string> il);
    StrVec(const StrVec &);
    StrVec&operator=(const StrVec&);
    StrVec &operator=(initializer_list<string> il);
    StrVec(StrVec &&s) noexcept;
    StrVec &operator=(StrVec &&rhs) noexcept;
    ~StrVec();
    void push_back(const std::string&);
    void push_back(std::string &&);
    void reserve(size_t sz);
    void resize(size_t sz, const string &str = string());
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
    string &operator[](size_t n)
        { return elements[n]; }
    const string &operator[](size_t n) const
        { return elements[n]; }
    template <class... Args> void emplace_back(Args&&...);

private:
    std::allocator<std::string> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity()) reallocate();
    }
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string *, const std::string *);
    void free();
    void reallocate();
    void alloc_n_move(size_t new_cap);
    void range_initialize(const string *first, const string *last);
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
    size_t i = 0;
    for ( ; (i != lhs.size()) && (i != rhs.size()); ++i)
        if (*(lhs.elements + i) < *(rhs.elements + i))
            return true;
    return lhs.size() < rhs.size();
}

template <class... Args>
inline
void StrVec::emplace_back(Args&&... args)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

void StrVec::range_initialize(const string *first, const string *last)
{
    auto newdata = alloc_n_copy(first, last);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(initializer_list<string> il): StrVec()
{
    range_initialize(il.begin(), il.end());
}

void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

StrVec::StrVec(StrVec &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec &StrVec::operator=(initializer_list<string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}


void StrVec::free()
{
    if (elements) {
        for_each(elements, first_free, [this](string &ps)
            {alloc.destroy(&ps);});
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::alloc_n_move(size_t new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    alloc_n_move(newcapacity);
}

void StrVec::reserve(size_t sz)
{
    if (sz <= capacity())
        return ;
    alloc_n_move(sz);
}

void StrVec::resize(size_t count, const string &str)
{
    if (count > size()) {
        if (count > capacity())
            reserve(count * 2);
        for (size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, str);
    }
    else if (count < size()) {
        while (first_free != elements + count)
            alloc.destroy(--first_free);
    }
}

void StrVec::push_back(string &&s)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}
