#include <iostream>
#include <stdexcept>
#include <limits>

void MyFunc(int c)
{
    if (c > std::numeric_limits< char> ::max())
        throw std::invalid_argument("MyFunc argument too large.");
    //...
}

int main()
{
    try {
        MyFunc(256); //cause an exception to throw
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }
    //...
    return EXIT_SUCCESS;
}