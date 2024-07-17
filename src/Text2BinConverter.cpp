#include "Text2BinConverter.hpp"
#include <fstream>
#include <sstream>
#include <regex>

bool Text2BinConverter::ReadInput(std::string inputFile)
{
    std::fstream stream{ inputFile, std::fstream::in };
    if (!stream)
        return false;

    SMountCostume costume{};
    std::string line;
    while (std::getline(stream, line))
    {
        if (line[0] == '#')
        {
            if(costume.nIndex != 0)
                m_MountCostume.push_back(std::move(costume));

            continue;
        }

        std::stringstream str{ line };
        std::string type;
        str >> type;

        if (type == kIndexTag)
            str >> costume.nIndex;
        else if (type == kItemListIndexTag)
            str >> costume.nItemListIndex;
        else if (type == kSkinMeshTypeTag)
            str >> costume.nSkinMeshType;
        else if (type == kSancTag)
            str >> costume.nSanc;
        else if (type == kScaleTag)
            str >> costume.fMountScale;
        else
        {
            std::regex meshSkinPattern(R"((nMesh|nSkin)(\d+))");
            std::smatch match;

            if (std::regex_match(type, match, meshSkinPattern))
            {
                const std::string prefix = match[1];
                const int index = std::stoi(match[2]);

                if (index >= kTotalParts)
                    continue;

                if (prefix == "nMesh")
                {
                    str >> costume.nMesh[index];
                }
                else if (prefix == "nSkin")
                {
                    str >> costume.nSkin[index];
                }
            }

        }
    }

    if (costume.nIndex != 0)
        m_MountCostume.push_back(std::move(costume));
        
    return true;
}

bool Text2BinConverter::WriteOutput(std::string outputFile)
{
    std::fstream st{ outputFile, std::ios::out | std::ios::binary };
    if (!st.is_open())
        return false;

    auto nCount = m_MountCostume.size();
    st.write(reinterpret_cast<char*>(&nCount), sizeof(int));

    auto costumes = EncDecBinary(m_MountCostume);

    auto buffer = (char*)costumes.data();
    auto size = nCount * sizeof(SMountCostume);
    st.write(buffer, size);
    return true;
}
