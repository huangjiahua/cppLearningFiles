#include <iostream>
#include <string>

void *operator new(size_t size) {
    if (void *mem = malloc(size)) {
        std::cout << "hey, new version of new" << std::endl;
        return mem;
    }
    else
        throw std::bad_alloc();
}

void operator delete(void *mem) noexcept { free(mem); }

int main()
{
    int *p = new int;
    *p = 45;
}
