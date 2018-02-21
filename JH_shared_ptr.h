template <typename T>
class JH_shared_ptr {
public:
    JH_shared_ptr() = default;
    JH_shared_ptr(T *p): ptr(p)
    { count = 1; }
    JH_shared_ptr(T *p, void (*d)(T*)): ptr(p), del(d)
    { count = 1; }
    JH_shared_ptr(const JH_shared_ptr &jh):
        ptr(jh.ptr), del(jh.del)
    {
        ++count;
    }
    ~JH_shared_ptr()
    {
        if (count) {
            ptr = nullptr;
            del = nullptr;
        }
        else  {
            del ? del(ptr) : delete ptr;
            ptr = nullptr;
        }
    }
private:
    T *ptr;
    void (*del)(T*);
    static unsigned count;
};
