#include <iostream>
#include <memory>
#include "Bin2TextConverter.hpp"

int main(int argc, char** argv) 
{
    if (argc != 4)
    {
        std::cout << "How to use: <operation> <inputfile> <outputfile>" << std::endl;
        std::cout << "\tOperation: bin2text or text2bin" << std::endl;
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
        std::cout << "Not implemented yet";

        return 1;
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

    return 1;
}
