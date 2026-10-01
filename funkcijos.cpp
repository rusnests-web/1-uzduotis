#include "studentas.h"
#include "funkcijos.h"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using std::string;
using std::vector;

void printas(studentas &A, int pasirinkimas)
{
    if (pasirinkimas == 1)
    {
        std::cout << std::left << std::setw(13) << A.vardas << std::left << std::setw(15) << A.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << A.galutinisVid << "\n";
    }
    else if (pasirinkimas == 2)
    {
        std::cout << std::left << std::setw(13) << A.vardas << std::left << std::setw(15) << A.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << A.galutinisMed << "\n";
    }
    else if (pasirinkimas == 3)
    {
        std::cout << std::left << std::setw(13) << A.vardas << std::left << std::setw(15) << A.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << A.galutinisVid << std::left << std::setw(20) << A.galutinisMed << "\n";
    }
}

void failo_skaitymas(std::vector<studentas> &grupe, string &failo_pavadinimas)
{
    std::ifstream failas;
    while (!failas.is_open())
    {
        if (failo_pavadinimas.empty())
        {
            std::cout << "Iveskite failo pavadinima: ";
            if (!(std::cin >> failo_pavadinimas))
            {
                throw std::runtime_error("Klaida: nepavyko nuskaityti failo pavadinimo");
            }
        }
        failas.clear();
        failas.open(failo_pavadinimas);
        if (!failas.is_open())
        {
            std::cout << "Klaida: failas '" << failo_pavadinimas << "' nerastas arba jo nepavyko atidaryti\n";
            failo_pavadinimas.clear();
        }
    }
    std::string eilute;
    if (std::getline(failas, eilute))
    {
        int nd_kiekis = 0;
        int eil_ilgis = eilute.length();
        studentas A;
        std::string zodis = "";
        for (int i = 0; i <= eil_ilgis; i++)
        {
            if (i < eil_ilgis && eilute[i] != ' ' && eilute[i] != '\t' && eilute[i] != '\r' && eilute[i] != '\n')
            {
                zodis += eilute[i];
            }
            else if (!zodis.empty())
            {
                int zod_ilgis = zodis.length();
                if (zod_ilgis > 2 && (zodis[0] == 'N' && zodis[1] == 'D'))
                {
                    nd_kiekis++;
                }
                zodis = "";
            }
        }
        while (failas >> A.vardas >> A.pavarde)
        {
            A.nd.clear();
            A.suma = 0;
            for (int i = 0; i < nd_kiekis; i++)
            {
                int paz;
                if (!(failas >> paz)) 
                {
                    throw std::runtime_error("Klaida: netaisyklingi namu darbu pazymiu duomenys faile");
                }
                A.nd.push_back(paz);
                A.suma += paz;
            }
            if (!(failas >> A.egz))
            {
                throw std::runtime_error("Klaida: netaisyklingi egzamino pazymio duomenys faile");
            }
            int k = A.nd.size();
            if (k > 0)
            {
                A.vidurkis = A.suma / k;
                std::sort(A.nd.begin(), A.nd.end());
                if (k % 2 == 0)
                    A.mediana = (A.nd[k / 2 - 1] + A.nd[k / 2]) / 2.0;
                else
                    A.mediana = A.nd[k / 2];
            }
                A.galutinisVid = 0.4 * A.vidurkis + 0.6 * A.egz;
                A.galutinisMed = 0.4 * A.mediana + 0.6 * A.egz;
                grupe.push_back(A);
        }
    }   
    failas.close();
}

void failu_generavimas(const string& failo_pavadinimas, size_t studentu_skaicius, size_t nd_kiekis)
{
    std::ofstream failas(failo_pavadinimas);
    if (!failas.is_open()) {
        std::cerr << "Klaida kuriant faila: " << failo_pavadinimas << "\n";
        return;
    }
    std::random_device seed;
    std::mt19937 rng(seed());
    std::uniform_int_distribution<int> pazDist(1, 10);
    failas << "Vardas Pavarde ";
    for (int j = 1; j <= nd_kiekis; ++j) {
        failas << "ND" << j << " ";
    }
    failas << "Egz.\n";
    for (size_t i = 1; i <= studentu_skaicius; ++i) {
        failas << "Vardas" << i << " " << "Pavarde" << i << " ";
        for (int j = 0; j < nd_kiekis; ++j) {
            failas << pazDist(rng) << " ";
        }
        failas << pazDist(rng) << "\n";
    }
    failas.close();
}

void spartos_analize()
{
    std::vector<size_t> dydziai = {1000, 10000, 100000, 1000000, 10000000};
    std::random_device seed;
    std::mt19937 rng(seed());
    std::uniform_int_distribution<int> ndDist(7, 20);
    for (size_t dydis : dydziai) {
        std::string failo_pavadinimas = "studentai_" + std::to_string(dydis) + ".txt";
        std::ifstream dabartinis_failas(failo_pavadinimas);
        bool failas_egzistuoja = dabartinis_failas.is_open();
        dabartinis_failas.close();
        if (failas_egzistuoja)
        {
            std::cout << "Failas " << failo_pavadinimas << " jau egzistuoja; naudojamas esamas failas.\n";
        }
        else
        {
            int nd_kiekis = ndDist(rng);
            auto pradzia = std::chrono::high_resolution_clock::now();
            failu_generavimas(failo_pavadinimas, dydis, nd_kiekis);
            auto pabaiga = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> t_generavimo = pabaiga - pradzia;
            std::cout << dydis << " irasu failo (" << nd_kiekis << " ND) sukurimo laikas: " << std::fixed << std::setprecision(6) << t_generavimo.count() << "\n";
        }
    }
    int pasirinkimas = 1;
    std::cout << "Pasirinkite isvedimo failu duomenu rikiavimo parametra: \n";
    std::cout << "1. Pagal varda (iveskite 1); \n";
    std::cout << "2. Pagal pavarde (iveskite 2); \n";
    std::cout << "3. Pagal galutini (Vid.) (iveskite 3); \n";
    std::cout << "4. pagal galutini (Med.) (iveskite 4): ";
    std::cin >> pasirinkimas;
    if (pasirinkimas < 1 || pasirinkimas > 4)
    {
        pasirinkimas = 1;
    }
    for (size_t dydis : dydziai) {
        std::string failo_pavadinimas = "studentai_" + std::to_string(dydis) + ".txt";
        std::vector<studentas> grupe;
        std::vector<studentas> vargsiukai;
        std::vector<studentas> kietiakai;
        std::string varg = "vargsiukai_" + std::to_string(dydis) + ".txt";
        std::string kiet = "kietiakai_" + std::to_string(dydis) + ".txt";
        auto t1 = std::chrono::high_resolution_clock::now();
        failo_skaitymas(grupe, failo_pavadinimas);
        auto t2 = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<double> t_skaitymo = t2 - t1;
        std::cout << dydis << " irasu failo skaitymo laikas: " << std::fixed << std::setprecision(6) << t_skaitymo.count() << "\n";
        auto t3 = std::chrono::high_resolution_clock::now();
        studentu_rusiavimas(grupe, vargsiukai, kietiakai);
        auto t4 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> t_dalijimo = t4 - t3;
        std::cout << dydis << " irasu failo dalijimo i dvi grupes laikas: " << std::fixed << std::setprecision(6) << t_dalijimo.count() << "\n";
        auto t5 = std::chrono::high_resolution_clock::now();
        isvedimo_rusiavimas(vargsiukai, pasirinkimas);
        isvedimo_rusiavimas(kietiakai, pasirinkimas);
        auto t6 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> t_rusiavimo = t6 - t5;
        std::cout << dydis << " irasu failo rusiavimo didejimo tvarka su sort funkcija laikas: " << std::fixed << std::setprecision(6) << t_rusiavimo.count() << "\n";
        auto t7 = std::chrono::high_resolution_clock::now();
        studentu_isvedimas(varg, vargsiukai);
        auto t8 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> t_vargsiuku = t8 - t7;
        std::cout << dydis << " irasu vargsiuku isvedimo laikas: " << std::fixed << std::setprecision(6) << t_vargsiuku.count() << "\n";
        auto t9 = std::chrono::high_resolution_clock::now();
        studentu_isvedimas(kiet, kietiakai);
        auto t10 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> t_kietiaku = t10 - t9;
        std::cout << dydis << " irasu kietiaku isvedimo laikas: " << std::fixed << std::setprecision(6) << t_kietiaku.count() << "\n";
        std::chrono::duration<double> is_viso = t_skaitymo + t_dalijimo + t_rusiavimo + t_vargsiuku + t_kietiaku;
        std::cout << dydis << " irasu testo laikas: " << std::fixed << std::setprecision(6) << is_viso.count() << "\n";
    }
}

void studentu_rusiavimas(const std::vector<studentas> &grupe, std::vector<studentas> &vargsiukai, std::vector<studentas> &kietiakai)
{
    for (const studentas&B : grupe)
    {
        if (B.galutinisVid < 5.0 && B.galutinisMed < 5.0)
        {
            vargsiukai.push_back(B);
        }
        else if (B.galutinisVid >= 5.0 && B.galutinisMed >= 5.0)
        {
            kietiakai.push_back(B);
        }
    }
}

void studentu_isvedimas(const std::string &failoPavadinimas, const std::vector<studentas> &grupe)
{
    std::ofstream outputas(failoPavadinimas);
    if (!outputas.is_open())
    {
        std::cerr << "Klaida: nepavyko atidaryti failo " << failoPavadinimas << " rasymui\n";
        return;
    }
    outputas << std::left << std::setw(13) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Vid.)" << std::left << std::setw(20) << "Galutinis (Med.)" << "\n";
    outputas << std::string(68, '-') << "\n";
    for (const studentas&A : grupe)
    {
        outputas << std::left << std::setw(13) << A.vardas << std::left << std::setw(15) << A.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << A.galutinisVid << std::left << std::setw(20) << A.galutinisMed << "\n";
    }
    outputas.close();
}

void isvedimo_rusiavimas(std::vector<studentas> &grupe, int pasirinkimas) {
    if (pasirinkimas == 1) {
        std::sort(grupe.begin(), grupe.end(), pagal_varda);
    } 
    else if (pasirinkimas == 2) {
        std::sort(grupe.begin(), grupe.end(), pagal_pavarde);
    } 
    else if (pasirinkimas == 3) {
        std::sort(grupe.begin(), grupe.end(), pagal_galutinisVid);
    } 
    else if (pasirinkimas == 4) {
        std::sort(grupe.begin(), grupe.end(), pagal_galutinisMed);
    }
}

bool pagal_varda(const studentas &A, const studentas &B) {
    if (A.vardas != B.vardas) return A.vardas < B.vardas;
    return A.pavarde < B.pavarde;
}
bool pagal_pavarde(const studentas &A, const studentas &B) {
    if (A.pavarde != B.pavarde) return A.pavarde < B.pavarde;
    return A.vardas < B.vardas;
}
bool pagal_galutinisVid(const studentas &A, const studentas &B)
{
    return A.galutinisVid < B.galutinisVid;
}
bool pagal_galutinisMed(const studentas &A, const studentas &B)
{
    return A.galutinisMed < B.galutinisMed;
}