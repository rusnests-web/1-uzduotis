#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

struct studentas
{
    std::string vardas, pavarde;
    std::vector<int> nd;
    int egz;
    float suma;
    float vidurkis, mediana, galutinisVid, galutinisMed;
};

#endif