#include "Text2BinConverter.hpp"
#include <fstream>
#include <sstream>

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
        else if (type == kMesh1Tag)
            str >> costume.nMesh[0];
        else if (type == kMesh2Tag)
            str >> costume.nMesh[1];
        else if (type == kSkin1Tag)
            str >> costume.nSkin[0];
        else if (type == kSkin2Tag)
            str >> costume.nSkin[1];
        else if (type == kSancTag)
            str >> costume.nSanc;
        else if (type == kScaleTag)
            str >> costume.fMountScale;
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
