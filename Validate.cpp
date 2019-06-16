//Andy Vicario
//cs162-400
//11/25/18

#include "Validate.hpp"


int validate(int min, int max)
{
    int numChoice;
    std::cin >> numChoice;
    
    //while number does not fail or is not between the range retry
    while(std::cin.fail() || (std::cin.peek()!='\r' && std::cin.peek()!='\n')
          || (numChoice<min || numChoice>max))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Invalid entry, try again: ";
        std::cin >> numChoice;
    }
    
    return numChoice;
}
