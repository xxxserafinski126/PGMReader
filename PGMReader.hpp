#ifndef _PGMREADER_HPP_
#define _PGMREADER_HPP_

#include "ImageReader.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>

class PGMReader : public ImageReader
{
public:
    PGMReader(const std::string& imagePath);
    ~PGMReader(); //destruktor upewniający się czy plik jest zamknięty
    void printImageInfo() override; //metoda wypisująca informacje o pliku pgm
    void printMostFrequentColor() override; //metoda wypisująca najczęściej występujący kolor
    int calcualteNumberOfUniqueColors() override; //w calculate jest literówka, ale zostawiłem tak jak było na githubie

private:
    std::fstream imageFile;
    std::vector<int> imageData;
    int width;
    int height;
    int maxColorValue;
    std::string name;

    void loadImageData();
    std::map<int, int> colorFrequency;
    std::pair<int, int> getMostFrequentColor() const;
};

#endif // _PGMREADER_HPP_
