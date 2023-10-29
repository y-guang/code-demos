# include<iostream>

enum weekdays {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

int main(int argc, char const *argv[])
{
    weekdays aday;

    aday = Thursday;
    std::cout << "aday = Thursday;" << std::endl;
    std::cout << aday << std::endl;
    std::cout << (aday == 3) << std::endl;
    std::cout << std::endl;

    aday = Monday;
    std::cout << "aday = Monday;" << std::endl;
    std::cout << aday << std::endl;
    std::cout << (aday == 0) << std::endl; // maping to int
    std::cout << std::endl;

    return 0;
}