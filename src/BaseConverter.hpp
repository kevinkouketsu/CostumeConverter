#ifndef BASECONVERTER_HPP
#define BASECONVERTER_HPP

#include <string>

constexpr auto kIndexTag = "nIndex";
constexpr auto kItemListIndexTag = "nItemListIndex";
constexpr auto kSkinMeshTypeTag = "nSkinMeshType";
constexpr auto kTotalParts = 8;
constexpr auto kMeshTag = "nMesh";
constexpr auto kSkinTag = "nSkin";
constexpr auto kSancTag = "nSanc";
constexpr auto kScaleTag = "nScale";

class BaseConverter
{
public:
    BaseConverter() = default;
    
    virtual bool ReadInput(std::string inputFile) = 0;
    virtual bool WriteOutput(std::string outputFile) = 0;

    template<typename T>
    T EncDecBinary(const T& list)
    {
        auto copy = list;
        auto buffer = reinterpret_cast<char*>(copy.data());
        auto size = list.size() * sizeof(typename T::value_type);
        for (size_t i = 0; i < size; ++i)
            buffer[i] ^= 0x9c;

        return std::move(copy);
    }
};

#endif