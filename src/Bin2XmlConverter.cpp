#include "Bin2XmlConverter.hpp"
#include "pugixml/pugixml.hpp"

bool Bin2XmlConverter::WriteOutput(std::string outputFile)
{
    using namespace pugi;

    xml_document doc; 
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    declarationNode.append_attribute("encoding")   = "ISO-8859-1";
    declarationNode.append_attribute("standalone") = "yes";

    auto mountsNode = doc.append_child("mounts");

    for(const auto& mount : m_MountCostume)
    {
        auto mountNode = mountsNode.append_child("mount");
        mountNode.append_attribute(kIndexTag) = mount.nIndex;
        mountNode.append_attribute(kItemListIndexTag) = mount.nItemListIndex;
        mountNode.append_attribute(kSkinMeshTypeTag) = mount.nSkinMeshType;
        mountNode.append_attribute(kMesh1Tag) = mount.nMesh[0];
        mountNode.append_attribute(kMesh2Tag) = mount.nMesh[1];
        mountNode.append_attribute(kSkin1Tag) = mount.nSkin[0];
        mountNode.append_attribute(kSkin2Tag) = mount.nSkin[1];
        mountNode.append_attribute(kSancTag) = mount.nSanc;
        mountNode.append_attribute(kScaleTag) = mount.fMountScale;
    }
    
    return doc.save_file(outputFile.c_str());
}