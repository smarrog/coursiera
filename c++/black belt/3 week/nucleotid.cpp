#include <cstddef>

struct Nucleotide {
    char Symbol;
    size_t Position;
    int ChromosomeNum;
    int GeneNum;
    bool IsMarked;
    char ServiceInfo;
};

struct CompactNucleotide {
    uint32_t Position;
    uint32_t Symbol:2;
    uint32_t ChromosomeNum:6; // 1 - 46
    uint32_t IsMarked:1; // bool
    uint32_t GeneNum:15;  // 0 - 25.000
    uint32_t ServiceInfo:8; // any char
};

bool operator == (const Nucleotide& lhs, const Nucleotide& rhs) {
    return (lhs.Symbol == rhs.Symbol)
           && (lhs.Position == rhs.Position)
           && (lhs.ChromosomeNum == rhs.ChromosomeNum)
           && (lhs.GeneNum == rhs.GeneNum)
           && (lhs.IsMarked == rhs.IsMarked)
           && (lhs.ServiceInfo == rhs.ServiceInfo);
}


CompactNucleotide Compress(const Nucleotide& n) {
    CompactNucleotide result{};

    result.Position = n.Position;

    switch (n.Symbol) {
        case 'A': { result.Symbol = 0; break; }
        case 'T': { result.Symbol = 1; break; }
        case 'G': { result.Symbol = 2; break; }
        case 'C': { result.Symbol = 3; break; }
    }

    result.ChromosomeNum = n.ChromosomeNum;
    result.IsMarked = n.IsMarked ? 1 : 0;
    result.GeneNum = n.GeneNum;
    result.ServiceInfo = n.ServiceInfo;

    return result;
}


Nucleotide Decompress(const CompactNucleotide& cn) {
    Nucleotide result{};

    result.Position = cn.Position;

    switch (cn.Symbol) {
        case 0: { result.Symbol = 'A'; break; }
        case 1: { result.Symbol = 'T'; break; }
        case 2: { result.Symbol = 'G'; break; }
        case 3: { result.Symbol = 'C'; break; }
    }

    result.ChromosomeNum = cn.ChromosomeNum;
    result.IsMarked = cn.IsMarked > 0;
    result.GeneNum = cn.GeneNum;
    result.ServiceInfo = cn.ServiceInfo;

    return result;
}