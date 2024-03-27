#include "PGMReader.hpp"
#include <set>

PGMReader::PGMReader(const std::string& imagePath)
{
    imageFile.open(imagePath, std::ios::in);
    if (imageFile.is_open())
    {
        name = imagePath;
        loadImageData();
    }
    else
    {
        std::cerr << "Nie udalo sie otworzyc pliku " << imagePath << std::endl;
    }
}

void PGMReader::loadImageData()
{
    std::string line;
    std::getline(imageFile, line); // P2
    if (line != "P2")
    {
        std::cerr << "Nieprawidlowy format pliku." << std::endl;
        return;
    }

    while (imageFile.peek() == '#')
    {
        std::getline(imageFile, line);
    }

    imageFile >> width >> height >> maxColorValue;

    int pixelValue;
    while (imageFile >> pixelValue)
    {
        imageData.push_back(pixelValue);
    }

    for (int color : imageData)
    {
        colorFrequency[color]++;
    }

}

void PGMReader::printImageInfo()
{
    std::cout << "Nazwa pliku: " << name << std::endl;
    std::cout << "Rozmiar obrazu: " << width << "x" << height << std::endl;
    std::cout << "Maksymalna wartosc koloru: " << maxColorValue << std::endl;
    std::cout << "Ilosc unikalnych kolorow: " << calcualteNumberOfUniqueColors() << std::endl;
    auto mostFrequent = getMostFrequentColor();
    std::cout << "Najczesciej wystepujacy kolor: " << mostFrequent.first << ", wystepuje " << mostFrequent.second << " razy" << std::endl;
}

void PGMReader::printMostFrequentColor()
{
    auto mostFrequent = getMostFrequentColor();
    std::cout << "Kolor: " << mostFrequent.first << " Ilosc: " << mostFrequent.second << std::endl;
}

int PGMReader::calcualteNumberOfUniqueColors()
{
    auto uniqueColors = colorFrequency.size();
    return uniqueColors;
}

std::pair<int, int> PGMReader::getMostFrequentColor() const
{

    std::pair<int, int> mostFrequent(0, 0);
    for (const auto& pair : colorFrequency)
    {
        if (pair.second > mostFrequent.second)
        {
            mostFrequent = pair;
        }
    }

    return mostFrequent;
}