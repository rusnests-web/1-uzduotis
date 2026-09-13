#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
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

int main()
{
    int k;
    std::vector<studentas> grupe;
    studentas A;
    std::cout << "Ar zinomas studentu skaicius sarase? (taip / ne): ";
    string atsakymas;
    std::cin >> atsakymas;
    if (atsakymas == "taip")
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
            std::string atsakymas2;
            std::cin >> atsakymas2;
            if (atsakymas2 == "ne")
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
            else if (atsakymas2 == "taip")
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
    else if (atsakymas == "ne")
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
            std::string atsakymas2;
            std::cin >> atsakymas2;
            if (atsakymas2 == "ne")
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
            else if (atsakymas2 == "taip")
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