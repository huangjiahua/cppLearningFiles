/*
** JH container series
** JHVec
** similar to std::vector
 */
#include <memory>
#include <utility>
#include <iostream>
#include <algorithm>

template <typename T>
class JHVec {
public:
    // value_type and size_type
    using value_type = T;
    using size_type = size_t;

    // constructor
    JHVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    JHVec(std::initializer_list<value_type> il);
    JHVec(size_type n, value_type value);
    //template <typename IT>
    //JHVec(const IT& b, const IT &e);

    // destructor
    ~JHVec();

    // copy controls
    JHVec(const JHVec<T>&);
    JHVec<T> &operator=(const JHVec<T>&);
    template <typename C> JHVec(const C&);
    template <typename C> JHVec<T> &operator=(const C&);
    JHVec(JHVec<T> &&) noexcept;
    JHVec<T> &operator=(JHVec<T> &&) noexcept;

    // iterator related
    using iterator = value_type *;
    value_type *begin() const { return elements; }
    value_type *end() const { return first_free; }
    const value_type *cbegin() const
    { return elements; }
    const value_type *cend() const
    { return first_free; }

    // size related
    size_type size() const
    { return first_free - elements; }
    size_type capacity() const
    { return cap - elements; }
    void reserve(size_type sz);
    void resize(size_type sz, const value_type &str);

    // add and erase elements
    void push_back(const value_type&);
    void push_back(value_type &&);
    void pop_back();
    void erase(value_type* iter);
    void insert(value_type* iter, const value_type&);
    template <typename... Args>
    void emplace_back(Args&&...);

    // unary operators
    value_type &operator[](const size_type& );


private:
    std::allocator<value_type> alloc;
    value_type *elements;
    value_type *first_free;
    value_type *cap;

    void free();
    void reallocate();
    void chk_n_alloc()
    {
        if(size() == capacity()) reallocate();
    }
    std::pair<value_type*, value_type*>
    alloc_n_copy(const value_type*, const value_type*);
    void alloc_n_move(size_type);
    void range_initialize(const value_type*, const value_type*);

};

/*
** private member functions
 */
template <typename T>
void JHVec<T>::alloc_n_move(size_type new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_type i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

template <typename T>
void JHVec<T>::free()
{
    if (elements) {
        std::for_each(elements, first_free, [this](value_type &ps)
            {alloc.destroy(&ps);});
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
std::pair<T*, T*>
JHVec<T>::alloc_n_copy(const value_type *b, const value_type *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
void JHVec<T>::reallocate()
{
    auto newcapacity = size() ? 2 *size() : 1;
    alloc_n_move(newcapacity);
}

template <typename T>
void JHVec<T>::range_initialize(const value_type* b, const value_type* e)
{
    auto newdata = alloc_n_copy(b, e);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

/*
** constructor
 */
template <typename T>
JHVec<T>::JHVec(std::initializer_list<value_type> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    cap = first_free = data.second;
}

template <typename T>
JHVec<T>::JHVec(size_type n, value_type value)
{
    auto data = alloc.allocate(n);
    auto dest = data;
    for (size_type i = 0; i != n; ++i)
        alloc.construct(dest++, value);
    elements = data;
    cap = first_free = dest;
}

/*
template <typename T>
template <typename IT>
JHVec<T>::JHVec(const IT &b, const IT &e)
{
    auto data = alloc_n_copy(b, e);
    free();
    elements = data.first;
    cap = first_free = data.second;
}
 */

/*
** destructor
 */
template <typename T>
JHVec<T>::~JHVec() { free(); }

/*
** copy control
 */
template <typename T>
JHVec<T>::JHVec(const JHVec<T>& org)
{
    auto data = alloc_n_copy(org.begin(), org.end());
    elements = data.first;
    cap = first_free = data.second;
}

template <typename T>
JHVec<T> &JHVec<T>::operator=(const JHVec<T>& org)
{
    if (this != org) {
        auto data = alloc_n_copy(org.begin(), org.end());
        free();
        elements = data.first;
        cap = first_free = data.second;
    }
    return *this;
}

template <typename T>
JHVec<T>::JHVec(JHVec<T>&& rhs) noexcept:
    elements(rhs.elements), first_free(rhs.first_free),
        cap(rhs.cap)
{
    rhs.elements = rhs.cap = rhs.first_free = nullptr;
}

template <typename T>
JHVec<T> &JHVec<T>::operator=(JHVec&& rhs) noexcept
{
    if (rhs != this) {
        free();
        elements = rhs.elements;
        cap = rhs.cap;
        first_free = rhs.first_free;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

template <typename T>
template <typename C>
JHVec<T>::JHVec(const C& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
}


template <typename T>
template <typename C>
JHVec<T> &JHVec<T>::operator=(const C& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

/*
** size_related member-functions
 */
template <typename T>
void JHVec<T>::reserve(size_type sz)
{
    if (sz <= capacity())
        return ;
    alloc_n_move(sz);
}

template <typename T>
void JHVec<T>::resize(size_type sz, const value_type &value)
{
    if (sz < size())
        while (first_free != elements + sz)
            alloc.destroy(--first_free);
    else if (sz > size()) {
        if (sz > capacity())
            reserve(sz * 2);
        for (size_type i = size(); i != sz; ++i)
            alloc.construct(first_free++, value);
    }
}

// add and erase elements
template <typename T>
void JHVec<T>::push_back(const value_type &newdata)
{
    chk_n_alloc();
    alloc.construct(first_free++, newdata);
}

template <typename T>
void JHVec<T>::push_back(value_type &&newdata)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(newdata));
}

template <typename T>
void JHVec<T>::pop_back()
{
    if (!size())
        throw std::out_of_range("the JHVec is already empty");
    else {
        alloc.destroy(first_free--);
    }
}

template <typename T>
void JHVec<T>::insert(value_type* iter, const value_type& value)
{
    auto newcap =
        (size() == capacity()) ? capacity() + 1 : capacity();
    auto newdata = alloc.allocate(newcap);
    auto dest = newdata;
    value_type* elem = begin();
    for (size_type i = 0; i != size() + 1; ++i) {
        if (elem == iter) {
            alloc.construct(dest++, value);
            continue;
        }
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcap;
}

template <typename T>
void JHVec<T>::erase(value_type* iter)
{
    auto newcap = capacity();
    auto newdata = alloc.allocate(newcap);
    auto dest = newdata;
    value_type* elem = begin();
    for (size_type i = 0; i != size() - 1; ++i) {
        if (elem == iter)
            ++elem;
        alloc.construct(dest++, std::move(*elem++));
    }
}

template <typename T>
template <typename... Args>
inline
void JHVec<T>::emplace_back(Args&&...args)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

/*
** unart operators
 */

template <typename T>
typename JHVec<T>::value_type &
JHVec<T>::operator[](const size_type& index)
{
    return elements[index];
}
