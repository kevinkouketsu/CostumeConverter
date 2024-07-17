#include "Bin2TextConverter.hpp"
#include <fstream>

bool Bin2TextConverter::ReadInput(std::string inputFile)
{
    std::ifstream stream{ inputFile };
    if (!stream)
        return false;

    int nCount{};
    stream.read((char*)&nCount, sizeof(int));
    m_MountCostume.resize(nCount);

    auto size = nCount * sizeof(SMountCostume);

    auto buffer = (char*)m_MountCostume.data();
    stream.read(buffer, size);

    m_MountCostume = EncDecBinary(m_MountCostume);

    return true;
}

bool Bin2TextConverter::WriteOutput(std::string outputFile)
{
    std::fstream stream{ outputFile, std::fstream::out | std::fstream::trunc };
    if (!stream)
        return false;

    int iTotal{};
    for (const auto& mount : m_MountCostume)
    {
        stream << "#" << std::endl;
        stream << kIndexTag << " " << mount.nIndex << std::endl;
        stream << kItemListIndexTag << " " << mount.nItemListIndex << std::endl;
        stream << kSkinMeshTypeTag << " " << mount.nSkinMeshType << std::endl;

        for (size_t i = 0; i < kTotalParts; ++i)
        {
            stream << kMeshTag << i << " " << mount.nMesh[i] << std::endl;
            stream << kSkinTag << i << " " << mount.nSkin[i] << std::endl;
        }

        stream << kSancTag << " " << mount.nSanc << std::endl;
        stream << kScaleTag << " " << mount.fMountScale << std::endl << std::endl;
    }

    return true;
}