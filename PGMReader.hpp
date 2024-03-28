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
    ~PGMReader();
    void printImageInfo() override;
    void printMostFrequentColor() override;
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
