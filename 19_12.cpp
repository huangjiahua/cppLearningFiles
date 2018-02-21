#include <iostream>
#include <string>

class Screen {
public:
    using Action = Screen& (Screen::*)();
    Screen(): contents("good") { }
    typedef std::string::size_type pos;
    char get_cursor() const { return contents[cursor]; }
    char get() const;
    char get(pos ht, pos wd) const;
    static const std::string Screen::*data()
    { return &Screen::contents; }

    enum Directions { HOME, FORWARD, BACK, UP, DOWN};
    Screen& move(Directions);
    Screen& home();
    Screen& forward();
    Screen& back();
    Screen& up();
    Screen& down();
private:
    static Action Menu[];
    std::string contents;
    pos cursor;
    pos height, width;
};

Screen::Action Screen::Menu[] = {
    &Screen::home,
    &Screen::forward,
    &Screen::back,
    &Screen::up,
    &Screen::down,
};

Screen& Screen::move(Directions cm)
{
    return (this->*Menu[cm])();
}



int main()
{
    using std::string;
    Screen myScreen;
    const string Screen::*pdata = Screen::data();
    auto s = myScreen.*pdata;
    std::cout << s << std::endl;

}
