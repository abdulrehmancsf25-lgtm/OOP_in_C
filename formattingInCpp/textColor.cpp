// #include <iostream>

// int main() {
//     std::cout << "Normal Text ";
    
//     // Change text color to Red
//     std::cout << "\033[31m" << "WED" << "\033[0m";
    
//     std::cout << " Normal Text Again" << std::endl;

//     return 0;
// }
#include <iostream>
#include <conio.h>

int main() {
    int key = _getch();
    
    // Check if an extended key (like arrow keys) was pressed
    if (key == 0 || key == 224) {
        key = _getch(); // Get the second code for the arrow key
        
        switch (key) {
            case 72: std::cout << "Up Arrow Pressed\n"; break;    // Up key
            case 80: std::cout << "Down Arrow Pressed\n"; break;  // Down key
            case 75: std::cout << "Left Arrow Pressed\n"; break;  // Left key
            case 77: std::cout << "Right Arrow Pressed\n"; break; // Right key
        }
    }

    return 0;
}