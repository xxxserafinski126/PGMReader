#include <iostream>
#include "PGMReader.hpp"

int main()
{
    PGMReader pgmReader("a.pgm");

    std::cout << "Informacje o obrazie PGM:" << std::endl;
    pgmReader.printImageInfo();

    std::cout << "Najczesciej wystepujacy kolor:" << std::endl;
    pgmReader.printMostFrequentColor();

    PGMReader pgmReader2("feep.pgm");


    std::cout << std::endl;

    std::cout << "Informacje o obrazie PGM:" << std::endl;
    pgmReader2.printImageInfo();

    std::cout << "Najczesciej wystepujacy kolor:" << std::endl;
    pgmReader2.printMostFrequentColor();


    return 0;
}