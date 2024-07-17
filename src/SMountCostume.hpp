#ifndef SMOUNTCOSTUME_HPP
#define SMOUNTCOSTUME_HPP

struct SMountCostume
{
    int nIndex;
    int nItemListIndex;
    int nSkinMeshType;
    int nMesh[kTotalParts];
    int nSkin[kTotalParts];
    int nSanc;
    float fMountScale;
};

#endif
