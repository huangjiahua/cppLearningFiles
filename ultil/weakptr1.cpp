#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Person : public std::enable_shared_from_this<Person> {
public:
    string name;
    shared_ptr<Person> mother;
    shared_ptr<Person> father;
    vector<shared_ptr<Person>> kids;

    Person (const string &n,
            shared_ptr<Person> m = nullptr,
            shared_ptr<Person> f = nullptr)
      : name(n), mother(m), father(f) { }
    ~Person() {
        cout << "delete " << name << endl;
    }

    void setParentsAndTheirKids(shared_ptr<Person> m = nullptr,
                                shared_ptr<Person> f = nullptr) {
        mother = m;
        father = f;
        if (m != nullptr)
            m->kids.push_back(shared_from_this());
        if (f != nullptr)
            m->kids.push_back(shared_from_this());
    }
};

shared_ptr<Person> initFamily(const string& name)
{
    shared_ptr<Person> mom(new Person(name + "',s mom"));
    shared_ptr<Person> dad(new Person(name + "',s dad"));
    shared_ptr<Person> kid(new Person(name, mom, dad));
    mom->kids.push_back(kid);
    dad->kids.push_back(kid);
    return kid;
}


int main()
{
    shared_ptr<Person> p = initFamily("nico");

    cout << "nico's family exists" << endl;
    cout << "- nico is shared " << p.use_count() << " times" << endl;
    cout << "- name of 1st kid of nico's mom: "
         << p->mother->kids[0]->name << endl;

    string name = "bill";
    shared_ptr<Person> mom(new Person(name + "'s mom"));
    shared_ptr<Person> dad(new Person(name + "'s dad"));
    shared_ptr<Person> kid(new Person(name));
    kid->setParentsAndTheirKids(mom, dad);
}
