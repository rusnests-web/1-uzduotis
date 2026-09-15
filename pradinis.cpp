#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <stdexcept>
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
void failo_skaitymas(std::vector<studentas> &grupe, std::string &failo_pavadinimas);

int main()
{
    int k;
    std::vector<studentas> grupe;
    std::string failo_pavadinimas;
    studentas A;
    std::cout << "Ar norite skaityti studentu duomenis is failo? (taip / ne): ";
    string atsakymas1;
    std::cin >> atsakymas1;
    if (atsakymas1 == "taip")
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
    else if (atsakymas1 == "ne")
    {
        std::cout << "Ar zinomas studentu skaicius sarase? (taip / ne): ";
        string atsakymas2;
        std::cin >> atsakymas2;
        if (atsakymas2 == "taip")
        {
            std::cout << "Iveskite studentu skaiciu sarase: ";
            int n;
            std::cin >> n;
            for (int j = 0; j < n; j++)
            {
                std::cout << "Iveskite per tarpa studento varda ir pavarde: ";
                std::cin >> A.vardas >> A.pavarde;
                std::cout << "Iveskite semestro namu darbu pazymiu kieki: ";
                std::cin >> k;
                std::cout << "Ar norite sugeneruoti atsitiktinius namu darbu ir egzamino pazymius? (taip / ne): ";
                std::string atsakymas3;
                std::cin >> atsakymas3;
                if (atsakymas3 == "ne")
                {
                    for (int i = 0; i < k; i++)
                    {
                        std::cout << "Iveskite " << i + 1 << " pazymi: ";
                        int a;
                        std::cin >> a;
                        A.nd.push_back(a);
                    }
                    std::cout << "Iveskite egzamino pazymi: ";
                    std::cin >> A.egz;
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
                else if (atsakymas3 == "taip")
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
        else if (atsakymas2 == "ne")
        {
            while (true)
            {
                std::cout << "Iveskite per tarpa studento varda ir pavarde (arba iveskite q, jei norite baigti): ";
                std::cin >> A.vardas;
                if (A.vardas == "q") break;
                std::cin >> A.pavarde;
                std::cout << "Iveskite semestro namu darbu pazymiu kieki: ";
                std::cin >> k;
                std::cout << "Ar norite sugeneruoti atsitiktinius namu darbu ir egzamino pazymius? (taip / ne): ";
                std::string atsakymas3;
                std::cin >> atsakymas3;
                if (atsakymas3 == "ne")
                {
                    for (int i = 0; i < k; i++)
                    {
                        std::cout << "Iveskite " << i + 1 << " pazymi: ";
                        int a;
                        std::cin >> a;
                        A.nd.push_back(a);
                    }
                    std::cout << "Iveskite egzamino pazymi: ";
                    std::cin >> A.egz;
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
                else if (atsakymas3 == "taip")
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

void failo_skaitymas(std::vector<studentas> &grupe, std::string &failo_pavadinimas)
{
    std::cout << "Iveskite failo pavadinima: ";
    std::cin >> failo_pavadinimas;
    std::ifstream failas(failo_pavadinimas);
    if (!failas.is_open())
    {
        throw std::runtime_error("Klaida: failas " + failo_pavadinimas + " nerastas arba jo nepavyko atidaryti \n");
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
                failas >> paz;
                A.nd.push_back(paz);
                A.suma += paz;
            }
            failas >> A.egz;
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