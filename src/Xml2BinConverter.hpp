#ifndef XML2BINCONVERTER_HPP
#define XML2BINCONVERTER_HPP

#include "Text2BinConverter.hpp"

class Xml2BinConverter : public Text2BinConverter
{
public:
    virtual bool ReadInput(std::string inputFile) override;
};

#endif