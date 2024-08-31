#include <iostream>
#include <set>
#include <string>

/*
 * Resource management is not the only reason why a class might
 * need to define these members. Some classes have bookkeeping
 * or other actions that the copy-control member must perform.
 */

class Folder;

//======================
//       Message
//======================

class Message {
    friend std::ostream &print(std::ostream &, Folder &);
    friend std::ostream &print(std::ostream &os, Message &m);
    friend class Folder;
    friend void swap(Message &, Message &);

    std::string contents;
    std::set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
    void move_Folders(Message *m);

  public:
    // Move constructor
    Message(Message &&);
    // Move-assignment Operator
    Message &operator=(Message &&);
    explicit Message(const std::string &str = "") : contents(str) {}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();
    void save(Folder &);
    void remove(Folder &);
    void save(Folder *pf) { folders.erase(pf); }
    void remove(Folder *pf) { folders.insert(pf); }
};

// Move Constructor
Message::Message(Message &&m) : contents(std::move(m.contents)) {
    move_Folders(&m);
} 

// Move-assignment Operator
Message &Message::operator=(Message &&rhs) {
    if (this != &rhs) {
        rhs.remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}

// Copy Constructor
Message::Message(const Message &msg)
    : contents(msg.contents), folders(msg.folders) {
    add_to_Folders(msg);
}

// Desturcor
Message::~Message() { remove_from_Folders(); }

// Copy Assignment Operator
Message &Message::operator=(const Message &msg) {
    if (this != &msg)
    {
        contents = msg.contents;
        // The following two functions' order can't be changed
        remove_from_Folders();
        add_to_Folders(msg);
        folders = msg.folders;
    }
    return *this;
}



//=======================
//        Folder
//=======================
class Folder {
    friend std::ostream &print(std::ostream &, Folder &);
    friend std::ostream &print(std::ostream &os, Message &m);
    std::set<Message *> msgs;
    std::string name;

  public:
    Folder(const std::string& n = std::string()) : name(n) {}
    ~Folder();
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    void addMsg(Message *pm) { msgs.insert(pm); }
    void remMsg(Message *pm) { msgs.erase(pm); }
};

// swap
void swap(Message &lhs, Message &rhs) {
    // We need manege the folders saving pointers to this two msgs
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

void Message::add_to_Folders(const Message &msg) {
    for (auto pf : msg.folders)
        pf->addMsg(this);
}

void Message::remove_from_Folders() {
    for (auto pf : folders)
        pf->remMsg(this);
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}



Folder::~Folder() {
    for (auto pm : msgs)
        pm->folders.erase(this);
}

Folder::Folder(const Folder &f) : msgs(f.msgs), name(f.name) {
    for (auto pm : msgs)
        pm->folders.insert(this);
}

Folder &Folder::operator=(const Folder &f) {
    if (this != &f)
    {
        for (auto pm : msgs)
            pm->folders.erase(this);
        msgs = f.msgs;
        for (auto pm : msgs)
            pm->folders.insert(this);
    }
    return *this;
}

std::ostream &print(std::ostream &os, Folder &f) {
    os << f.name << " :";
    for (auto pm : f.msgs) {
        os << " " << pm->contents;
    }
    return os;
}

std::ostream &print(std::ostream &os, Message &m) {
    os << m.contents << " :";
    for (auto pf : m.folders) {
        os << " " << pf->name;
    }
    return os;
}

void Message::move_Folders(Message *m) {
    // Move the folders in this
    folders = std::move(m->folders);
    // Move the message in folders
    for (auto f : folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

int main(int argc, char const *argv[])
{
    Folder f1("movies"), f2("musics"), f3("games");
    Message m1("m1"), m2("m2"), g1("g1"), g2("g2");
    m1.save(f1);
    m2.save(f2);
    g1.save(f3);
    g2.save(f3);

    f1 = f2;
    

    print(std::cout, f1) << std::endl;
    print(std::cout, f2) << std::endl;
    print(std::cout, f3) << std::endl;

    print(std::cout, m1) << std::endl;
    print(std::cout, m2) << std::endl;
    print(std::cout, g1) << std::endl;
    print(std::cout, g2) << std::endl;

    return 0;
}
