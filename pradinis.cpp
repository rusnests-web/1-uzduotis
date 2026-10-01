#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <random>
#include <chrono>
using std::string;
using std::vector;
struct studentas
{
  string vardas, pavarde;
  vector<int> nd;
  int egz;
  float suma;
  float vidurkis, mediana, galutinisVid, galutinisMed;
};

void printas(studentas &A, int pasirinkimas);
void failo_skaitymas(std::vector<studentas> &grupe, string &failo_pavadinimas);
void failu_generavimas(const string& failo_pavadinimas, size_t studentu_skaicius, size_t nd_kiekis);
void spartos_analize();
void studentu_rusiavimas(const std::vector<studentas> &grupe, std::vector<studentas> &vargsiukai, std::vector<studentas> &kietiakai);
void studentu_isvedimas(const std::string &failoPavadinimas, const std::vector<studentas> &grupe);
void isvedimo_rusiavimas(std::vector<studentas> &grupe, int pasirinkimas);
bool pagal_varda(const studentas &A, const studentas &B);
bool pagal_pavarde(const studentas &A, const studentas &B);
bool pagal_galutinisVid(const studentas &A, const studentas &B);
bool pagal_galutinisMed(const studentas &A, const studentas &B);

int main()
{
    int k;
    std::vector<studentas> grupe;
    std::string failo_pavadinimas;
    studentas A;
    std::cout << "Ar norite sugeneruoti penkis atsitiktinius studentu sarasu failus? (t / n): ";
    string atsakymas1;
    std::cin >> atsakymas1;
    if (atsakymas1 == "t")
    {
        spartos_analize();
        return 0;
    }
    else if (atsakymas1 == "n")
    {
        std::cout << "Ar norite skaityti studentu duomenis is failo? (t / n): ";
        string atsakymas2;
        std::cin >> atsakymas2;
        if (atsakymas2 == "t")
        {
            try
            {
                failo_skaitymas(grupe, failo_pavadinimas);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what();
                return 1;
            }
            std::sort(grupe.begin(), grupe.end(), [](const studentas &A, const studentas &B)
            {
                if (A.vardas != B.vardas) return A.vardas < B.vardas;
                return A.pavarde < B.pavarde;
            });
        }
        else if (atsakymas2 == "n")
        {
            std::cout << "Ar zinomas studentu skaicius sarase? (t / n): ";
            string atsakymas3;
            std::cin >> atsakymas3;
            if (atsakymas3 == "t")
            {
                std::cout << "Iveskite studentu skaiciu sarase: ";
                int n;
                std::cin >> n;
                for (int j = 0; j < n; j++)
                {
                    std::cout << "Iveskite per tarpa studento varda ir pavarde: ";
                    std::cin >> A.vardas >> A.pavarde;
                    std::cout << "Iveskite semestro namu darbu pazymiu kieki: ";
                    while (!(std::cin >> k) || k <= 0) 
                    {
                        std::cout << "Klaida: pazymiu kiekis turi buti didesnis uz 0. Iveskite pazymiu kieki: ";
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                    }
                    std::cout << "Ar norite sugeneruoti atsitiktinius namu darbu ir egzamino pazymius? (t / n): ";
                    string atsakymas4;
                    std::cin >> atsakymas4;
                    if (atsakymas4 == "n")
                    {
                        for (int i = 0; i < k; i++)
                        {
                            std::cout << "Iveskite " << i + 1 << " pazymi: ";
                            int a;
                            while (!(std::cin >> a)) 
                            {
                                std::cout << "Klaida: netaisyklingi duomenys, iveskite " << i + 1 << " pazymi (skaiciu): ";
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');
                            }
                            A.nd.push_back(a);
                        }
                        std::cout << "Iveskite egzamino pazymi: ";
                        while (!(std::cin >> A.egz)) 
                            {
                                std::cout << "Klaida: netaisyklingi duomenys, iveskite egzamino pazymi (skaiciu): ";
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');
                            }
                        A.suma = 0;
                        for (int p : A.nd) A.suma += p;
                            A.vidurkis = A.suma / k;
                        std::sort(A.nd.begin(), A.nd.end());
                        if (k % 2 == 0)
                            A.mediana = (A.nd[k / 2 - 1] + A.nd[k / 2]) / 2.0;
                        else
                            A.mediana = A.nd[k / 2];
                        A.galutinisVid = 0.4 * A.vidurkis + 0.6 * A.egz;
                        A.galutinisMed = 0.4 * A.mediana + 0.6 * A.egz;
                        grupe.push_back(A);
                        A.pavarde.clear();
                        A.vardas.clear();
                        A.nd.clear();
                    }
                    else if (atsakymas4 == "t")
                    {
                        for (int i = 0; i < k; i++)
                        {
                            int a = rand() % 10 + 1;
                            A.nd.push_back(a);
                            A.egz = a;
                        }
                        std::cout <<"Sugeneruoti namu darbu pazymiai: ";
                        for (int paz : A.nd) std::cout << paz << " ";
                        std::cout << "\n";
                        std::cout <<"Sugeneruotas egzamino pazymys: " << A.egz << "\n";
                        A.suma = 0;
                        for (int p : A.nd) A.suma += p;
                            A.vidurkis = A.suma / k;
                        std::sort(A.nd.begin(), A.nd.end());
                        if (k % 2 == 0)
                            A.mediana = (A.nd[k / 2 - 1] + A.nd[k / 2]) / 2.0;
                        else
                            A.mediana = A.nd[k / 2];
                        A.galutinisVid = 0.4 * A.vidurkis + 0.6 * A.egz;
                        A.galutinisMed = 0.4 * A.mediana + 0.6 * A.egz;
                        grupe.push_back(A);
                        A.pavarde.clear();
                        A.vardas.clear();
                        A.nd.clear();
                    }
                }
            }
            else if (atsakymas3 == "n")
            {
                while (true)
                {
                    std::cout << "Iveskite per tarpa studento varda ir pavarde (arba iveskite q, jei norite baigti): ";
                    std::cin >> A.vardas;
                    if (A.vardas == "q") break;
                    std::cin >> A.pavarde;
                    std::cout << "Iveskite semestro namu darbu pazymiu kieki: ";
                    while (!(std::cin >> k) || k <= 0) 
                    {
                        std::cout << "Klaida: pazymiu kiekis turi buti didesnis uz 0. Iveskite pazymiu kieki: ";
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                    }
                    std::cout << "Ar norite sugeneruoti atsitiktinius namu darbu ir egzamino pazymius? (t / n): ";
                    std::string atsakymas4;
                    std::cin >> atsakymas4;
                    if (atsakymas4 == "ne")
                    {
                        for (int i = 0; i < k; i++)
                        {
                            std::cout << "Iveskite " << i + 1 << " pazymi: ";
                            int a;
                            while (!(std::cin >> a)) 
                            {
                                std::cout << "Klaida: netaisyklingi duomenys, iveskite " << i + 1 << " pazymi (skaiciu): ";
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');
                            }
                            A.nd.push_back(a);
                        }
                        std::cout << "Iveskite egzamino pazymi: ";
                        while (!(std::cin >> A.egz)) 
                            {
                                std::cout << "Klaida: netaisyklingi duomenys, iveskite egzamino pazymi (skaiciu): ";
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');
                            }
                        A.suma = 0;
                        for (int p : A.nd) A.suma += p;
                            A.vidurkis = A.suma / k;
                        std::sort(A.nd.begin(), A.nd.end());
                        if (k % 2 == 0)
                            A.mediana = (A.nd[k / 2 - 1] + A.nd[k / 2]) / 2.0;
                        else
                            A.mediana = A.nd[k / 2];
                        A.galutinisVid = 0.4 * A.vidurkis + 0.6 * A.egz;
                        A.galutinisMed = 0.4 * A.mediana + 0.6 * A.egz;
                        grupe.push_back(A);
                        A.pavarde.clear();
                        A.vardas.clear();
                        A.nd.clear();
                    }
                    else if (atsakymas4 == "t")
                    {
                        for (int i = 0; i < k; i++)
                        {
                            int a = rand() % 10 + 1;
                            A.nd.push_back(a);
                            A.egz = a;
                        }
                        std::cout <<"Sugeneruoti namu darbu pazymiai: ";
                        for (int paz : A.nd) std::cout << paz << " ";
                        std::cout << "\n";
                        std::cout <<"Sugeneruotas egzamino pazymys: ";
                        std::cout << A.egz << "\n";
                        A.suma = 0;
                        for (int p : A.nd) A.suma += p;
                            A.vidurkis = A.suma / k;
                        std::sort(A.nd.begin(), A.nd.end());
                        if (k % 2 == 0)
                            A.mediana = (A.nd[k / 2 - 1] + A.nd[k / 2]) / 2.0;
                        else
                            A.mediana = A.nd[k / 2];
                        A.galutinisVid = 0.4 * A.vidurkis + 0.6 * A.egz;
                        A.galutinisMed = 0.4 * A.mediana + 0.6 * A.egz;
                        grupe.push_back(A);
                        A.pavarde.clear();
                        A.vardas.clear();
                        A.nd.clear();
                    }
                }
            }
        }
    }
    std::cout << "Pasirinkite galutinio balo skaiciavimo buda: \n";
    std::cout << "1. Pagal namu darbu pazymiu vidurki (iveskite 1); \n";
    std::cout << "2. Pagal namu darbu pazymiu mediana (iveskite 2); \n";
    std::cout << "3. Pagal abu (iveskite 3): ";
    int pasirinkimas;
    std::cin >> pasirinkimas;
    std::cout << "Studentu duomenys: \n";
    if (pasirinkimas == 1)
    {
        std::cout << std::left << std::setw(13) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Vid.)" << "\n";
        std::cout << std::string(48, '-') << "\n";
    }
    else if (pasirinkimas == 2)
    {
        std::cout << std::left << std::setw(13) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Med.)" << "\n";
        std::cout << std::string(48, '-') << "\n";
    }
    else if (pasirinkimas == 3)
    {
        std::cout << std::left << std::setw(13) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Vid.)" << std::left << std::setw(20) << "Galutinis (Med.)" << "\n";
        std::cout << std::string(68, '-') << "\n";
    }
    for (studentas &B : grupe) printas(B, pasirinkimas);
}

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

void studentu_isvedimas(const string &failoPavadinimas, const std::vector<studentas> &grupe)
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