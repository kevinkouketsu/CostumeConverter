#ifndef BASECONVERTER_HPP
#define BASECONVERTER_HPP

#include <string>

class BaseConverter
{
public:
    BaseConverter() = default;
    
    virtual bool ReadInput(std::string inputFile) = 0;
    virtual bool WriteOutput(std::string outputFile) = 0;
};

#endif