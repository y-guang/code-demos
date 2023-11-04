#include <iostream>
#include <string>

class Father {
    friend class Friend;

   private:
    std::string name;

   protected:
    std::string nickname;

   public:
    Father(std::string name, std::string nickname);
    void get_info();
    ~Father();
};

Father::Father(std::string name, std::string nickname) {
    this->name = name;
    this->nickname = nickname;
}

Father::~Father() {}

void Father::get_info() {
    std::cout << "I am Father " << std::endl;
    std::cout << "\tMy name is " << this->name << std::endl;
    std::cout << "\tMy nickname is " << this->nickname << std::endl;
}

class Child : public Father {
   private:
    int age;  // child only member

   public:
    Child(std::string name, std::string nickname, int age);
    void get_info();
    ~Child();
};

Child::Child(std::string name, std::string nickname, int age)
    : Father(name, nickname) {
    this->age = age;
}

Child::~Child() {}

void Child::get_info() {
    std::cout << "I am Child " << std::endl;
    // std::cout << "\tMy name is " << this->name << std::endl; // cannot access
    // parent private member
    std::cout << "\tMy nickname is " << this->nickname << std::endl;
    std::cout << "\tMy age is " << this->age << std::endl;
}

class Friend {
   private:
    /* data */
   public:
    Friend();
    ~Friend();
    void tell_name(Father father);
};

Friend::Friend() {}

Friend::~Friend() {}

void Friend::tell_name(Father father) {
    std::cout << "My friend's name is " << father.name << std::endl;
}

int main(int argc, char const *argv[]) {
    Father father = Father("John", "Johny");
    father.get_info();

    Child child = Child("Bob", "Bobby", 10);
    child.get_info();

    Friend a_friend = Friend();
    a_friend.tell_name(father);
    a_friend.tell_name(child);
    return 0;
}
