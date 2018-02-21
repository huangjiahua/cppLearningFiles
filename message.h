#include <iostream>
#include <string>
#include <set>
#include <utility>

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message &, Message &);
public:
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &str = ""):
        contents(str) { }
    // copy control to manage pointers to this Message
    Message(const Message&);
    Message& operator=(const Message&); // copy assignment
    Message(Message &&m);
    Message &operator=(Message &&m);
    ~Message(); // destructor
    // add/remove this Message from the specified Folder's set of messages
    void save(Folder&);
    void remove(Folder&);
    // insert/remove a Folder in this Message's folders
    void insertFolder(Folder*);
    void removeFolder(Folder*);
private:
    std::string contents; // actual message text
    std::set<Folder*> folders; // Folders that have this Message
    // utility functions used by copy constructor, assignment, and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const Message&);
    // remove this Message from every Folder in folders
    void remove_from_Folders();
    void move_Folders(Message *m);
};

class Folder {
public:
    void addMsg(Message*); //add a Message in the Folder
    void remMsg(Message*); //remove a Message int the Folder
private:
    std::set<Message*> msgs;
};

void Folder::addMsg(Message *msg)
{
    msgs.insert(msg);
}

void Folder::remMsg(Message *msg)
{
    msgs.erase(msg);
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m): contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

Message::~Message()
{
    remove_from_Folders();
}

Message &Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

void Message::insertFolder(Folder *f)
{
    folders.insert(f);
}

void Message::removeFolder(Folder *f)
{
    folders.erase(f);
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);
    for (auto f : folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

Message::Message(Message &&m): contents(std::move(m.contents))
{
    move_Folders(&m);
}

Message& Message::operator=(Message &&m)
{
    if (this != &m) {
        remove_from_Folders();
        contents = std::move(m.contents);
        move_Folders(&m);
    }
    return *this;
}
