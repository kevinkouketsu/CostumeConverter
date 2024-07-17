#include "Xml2BinConverter.hpp"
#include "pugixml/pugixml.hpp"
#include <iostream>

bool Xml2BinConverter::ReadInput(std::string inputFile)
{
    using namespace pugi;
    xml_document doc;
    xml_parse_result result = doc.load_file(inputFile.c_str());
    if (!result)
    {        
        std::cout << "Parse error: " << result.description() << ", character pos= " << result.offset;
        return false;
    }
    
    auto mountsNode = doc.child("mounts");
    for (const auto& mountNode : mountsNode.children("mount"))
    {
        SMountCostume mount{};
        mount.nIndex = mountNode.attribute(kIndexTag).as_int();
        mount.nItemListIndex = mountNode.attribute(kItemListIndexTag).as_int();
        mount.nSkinMeshType = mountNode.attribute(kSkinMeshTypeTag).as_int();

        for (size_t i = 0; i < kTotalParts; ++i)
        {
            mount.nMesh[i] = mountNode.attribute((std::string(kMeshTag) + std::to_string(i)).c_str()).as_int();
            mount.nSkin[i] = mountNode.attribute((std::string(kSkinTag) + std::to_string(i)).c_str()).as_int();
        }

        mount.nSanc = mountNode.attribute(kSancTag).as_int();
        mount.fMountScale = mountNode.attribute(kScaleTag).as_float();

        m_MountCostume.emplace_back(std::move(mount));
    }

    return true;
}