// a class Person
class Person {
public:
    Person() = default;
    Person(std::string n, std::string a) :
        name(n), address(a) { }
    explicit Person(std::istream &is = std::cin): Person()
    {
        is >> name >> adress;
    }
    std::istream &getInfo(std::istream &is) {
        is >> name >> address;
        return is;
    }
    void print(std::ostream &os) {
        os << name << " " << address;
    }
    std::string p_name() const {return name;}
    std::string p_address() const {return address;}
private:
    std::string name;
    std::string address;
};
