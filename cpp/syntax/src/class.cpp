#include <iostream>

class Repeater {
    public:
    std::string user;
    // function prototype
    void turn_on();
    void echo(std::string message);
    // constructor
    Repeater(std::string user);
    ~Repeater();

    private:
    bool is_on;
};

// function implementation
void Repeater::turn_on() {
    is_on = true;
}

void Repeater::echo(std::string message) {
    if (is_on) {
        std::cout << user << ": " << message << std::endl;
    }
}

// constructor implementation,
// we can also define it in the class
Repeater::Repeater(std::string user) {
    this->user = user;
    is_on = false;
}

// destructor implementation
Repeater::~Repeater() {
    std::cout << "Repeater is destroyed" << std::endl;
}

int main(int argc, char const *argv[])
{
    Repeater repeater("user");
    std::cout << "user: " << repeater.user << std::endl; // access public member
    // std::cout << "is_on:" << repeater.is_on << std::endl; // cannot access private member
    std::cout << "is_on: " << "cannot access private member" << std::endl;

    // change private by calling public function
    std::cout << "turn_on()" << std::endl;
    repeater.turn_on();

    repeater.echo("hello world");

    // no need to call destructor manually
    return 0;
}
