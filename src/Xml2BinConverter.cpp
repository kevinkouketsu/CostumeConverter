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
    for (auto mountNode : mountsNode.children("mount"))
    {
        SMountCostume mount{};
        mount.nIndex = mountNode.attribute(kIndexTag).as_int();
        mount.nItemListIndex = mountNode.attribute(kItemListIndexTag).as_int();
        mount.nSkinMeshType = mountNode.attribute(kSkinMeshTypeTag).as_int();
        mount.nMesh[0] = mountNode.attribute(kMesh1Tag).as_int();
        mount.nMesh[1] = mountNode.attribute(kMesh2Tag).as_int();
        mount.nSkin[0] = mountNode.attribute(kSkin1Tag).as_int();
        mount.nSkin[1] = mountNode.attribute(kSkin2Tag).as_int();
        mount.nSanc = mountNode.attribute(kSancTag).as_int();
        mount.fMountScale = mountNode.attribute(kScaleTag).as_float();

        m_MountCostume.emplace_back(std::move(mount));
    }

    return true;
}