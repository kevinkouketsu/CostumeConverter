#ifndef BIN2XMLCONVERTER_HPP
#define BIN2XMLCONVERTER_HPP

#include "Bin2TextConverter.hpp"

class Bin2XmlConverter : public Bin2TextConverter 
{
public:
    virtual bool WriteOutput(std::string outputFile) override;
};

#endif