#include <vector>
#include <iostream>
#include <memory>
#include <string>

template <typename> class BlobPtr;
template <typename> class Blob;

template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>
        (const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> il);
    size_type size() const { return data->empty(); }
    template <typename It> Blob(It b, It e);
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    T& back();
    T& operator[](size_type i);
    const T& back() const;
    const T& operator[](size_type i) const;
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
    data(std::make_shared<std::vector<T>>(il)) { }

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e):
    data(std::make_shared<std::vector<T>>(b, e)) { }

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
const T& Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

/*
** BlobPtr
 */
template <typename T> class BlobPtr {
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0):
        wptr(a.data), curr(sz) { }
    T& operator*() const
    {
        auto p = check(curr, "dereference pase end");
        return (*p)[curr];
    }
    BlobPtr& operator++();
    BlobPtr operator++(int);
    BlobPtr& operator--();
private:
    std::shared_ptr<std::vector<T>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}
