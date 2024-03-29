#include <iostream>
#include <memory>
#include "Bin2TextConverter.hpp"
#include "Bin2XmlConverter.hpp"
#include "Text2BinConverter.hpp"
#include "Xml2BinConverter.hpp"
#include "config.h"

int main(int argc, char** argv) 
{
    std::cout << PROJECT_NAME << " " << PROJECT_VER << " created by " << PROJECT_CREATOR << std::endl;
    if (argc != 4)
    {
        std::cout << "How to use: <operation> <inputfile> <outputfile>" << std::endl;
        std::cout << "\tOperation:" << std::endl;
        std::cout << "\t\tbin2text" << std::endl;
        std::cout << "\t\ttext2bin" << std::endl;
        std::cout << "\t\txml2bin" << std::endl;
        std::cout << "\t\tbin2xml" << std::endl;
        return 1;
    }

    std::string operation { argv[1] };
    std::unique_ptr<BaseConverter> converter;

    if (operation == "bin2text")
    {
        converter = std::make_unique<Bin2TextConverter>();
    }
    else if (operation == "text2bin")
    {
        converter = std::make_unique<Text2BinConverter>();
    }
    else if (operation == "bin2xml")
    {
        converter = std::make_unique<Bin2XmlConverter>();
    }
    else if (operation == "xml2bin")
    {
        converter = std::make_unique<Xml2BinConverter>();
    }
    else
    {
        std::cout << "Invalid operation" << std::endl;

        return 1;
    }
    
    if (!converter->ReadInput(argv[2]))
    {
        std::cout << "Fail to read input file " << std::endl;

        return 1;
    }

    if (!converter->WriteOutput(argv[3]))
    {
        std::cout << "Fail to write output file " << std::endl;

        return 1;
    }
    return 1;
}
