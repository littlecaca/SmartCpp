#include <string>
#include <iostream>

class Screen
{
public:
    typedef std::string::size_type pos;
    using Action =
        char (Screen::*)(pos, pos) const;
    using Action2 =
        char (Screen::*)() const;
        
    char get_cursor() const { return contents[cursor]; }
    char get() const;
    char get(pos ht, pos wd) const;
    static const std::string Screen::*data()
    {
        return &Screen::contents;
    }
    static const pos Screen::*cur()
    {
        return &Screen::cursor;
    }

private:
    std::string contents;
    pos cursor;
    pos height, width;
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
