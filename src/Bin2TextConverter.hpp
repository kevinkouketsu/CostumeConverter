#ifndef BIN2TEXTCONVERTER_HPP
#define BIN2TEXTCONVERTER_HPP

#include <vector>
#include "BaseConverter.hpp"
#include "SMountCostume.hpp"

class Bin2TextConverter : public BaseConverter
{
public:
    virtual bool ReadInput(std::string inputFile) override;
    virtual bool WriteOutput(std::string outputFile) override;

protected:
    std::vector<SMountCostume> m_MountCostume;
};

#endif