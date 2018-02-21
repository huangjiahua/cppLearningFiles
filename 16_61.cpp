#include <iostream>
#include <memory>
#include <utility>
#include <string>

using namespace std;

template <typename T, typename... Args>
inline
shared_ptr<T> jh_make_shared(Args&&... args)
{
    shared_ptr<T> ret(new T(std::forward<Args>(args)... ));
    return ret;
}

int main()
{
    shared_ptr<string> ss = jh_make_shared<string>(14, 'c');
}
