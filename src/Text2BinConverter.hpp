#ifndef TEXT2BINCONVERTER_HPP
#define TEXT2BINCONVERTER_HPP

#include "BaseConverter.hpp"
#include "SMountCostume.hpp"
#include <vector>

class Text2BinConverter : public BaseConverter
{
public:
    virtual bool ReadInput(std::string inputFile) override;
    virtual bool WriteOutput(std::string outputFile) override;

protected:
    std::vector<SMountCostume> m_MountCostume;
};




#endif