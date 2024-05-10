#include <iostream>
#include <string>

void engine()
{
    bool flag = true;
    while(flag)
    {
        std::cout << "1. Create a new spreadsheet\n";
        std::cout << "2. Open a spreadsheet\n";
        std::cout << "3. Exit\n";
        int choice;
        std::cin >> choice;
        switch(choice)
        {
            case 1:
                std::cout << "Enter the name of the spreadsheet: ";
                std::string name;
                std::cin >> name;
                std::cout << "Enter the number of rows: ";
                int rows;
                std::cin >> rows;
                std::cout << "Enter the number of columns: ";
                int columns;
                std::cin >> columns;
                break;
            case 2:
                std::cout << "Enter the name of the spreadsheet: ";
                std::string name;
                std::cin >> name;
                break;
            case 3:
                flag = false;
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    }
}