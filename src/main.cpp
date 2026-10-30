#include "Photo.h"

#include <iostream>
#include <utility>

int main()
{
    int pixels[] = {
        120, 200, 150,
        80, 100, 255
    };

    // CONSTRUCTOR

    Photo f1("cat.jpg", 3, 2, pixels);

    f1.print();


    //COPY CONSTRUCTOR 

    Photo f2 = f1;

    std::cout << "\nwe modify the copy:\n";

    f2.modifyPixel(0, 50);

    std::cout << "\noriginal photo:\n";
    f1.print();

    std::cout << "\ncopied photo:\n";
    f2.print();


    //MOVE CONSTRUCTOR

    Photo f3 = std::move(f1);

    std::cout << "\nphoto after move:\n";
    f3.print();

    std::cout << "\nsource photo:\n";
    f1.print();


    //COPY ASSIGNMENT

    Photo f4("dog.jpg", 3, 2, pixels);

    f4 = f2;

    f4.print();


    //MOVE ASSIGNMENT

    f4 = std::move(f3);

    f4.print();

    return 0;
}