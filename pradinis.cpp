#include "studentas.h"
#include "funkcijos.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

int main()
{
    int k;
    std::vector<studentas> grupe;
    std::list<studentas> grupe_list;
    int konteineris = 1;
    std::string failo_pavadinimas;
    studentas A;
    std::cout << "Ar norite sugeneruoti penkis atsitiktinius studentu sarasu failus? (t / n): ";
    std::string atsakymas1;
    std::cin >> atsakymas1;
    while (atsakymas1 != "t" && atsakymas1 != "n")
    {
        std::cout << "Klaida: neteisinga ivestis, iveskite t arba n: ";
        std::cin >> atsakymas1;
    }
    if (atsakymas1 == "t")
    {
        spartos_analize();
        return 0;
    }
    else if (atsakymas1 == "n")
    {
        std::cout << "Ar norite skaityti studentu duomenis is failo? (t / n): ";
        std::string atsakymas2;
        std::cin >> atsakymas2;
        while (atsakymas2 != "t" && atsakymas2 != "n")
        {
            std::cout << "Klaida: neteisinga ivestis, iveskite t arba n: ";
            std::cin >> atsakymas2;
        }
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
            std::cout << "Pasirinkite konteineri: \n";
            std::cout << "1. Vector (iveskite 1); \n";
            std::cout << "2. List (iveskite 2): ";
            while (!(std::cin >> konteineris) || (konteineris != 1 && konteineris != 2))
            {
                std::cout << "Klaida: neteisinga ivestis, iveskite 1 (Vector) arba 2 (List): ";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            std::cout << "Ar zinomas studentu skaicius sarase? (t / n): ";
            std::string atsakymas3;
            std::cin >> atsakymas3;
            while (atsakymas3 != "t" && atsakymas3 != "n")
            {
                std::cout << "Klaida: neteisinga ivestis, iveskite t arba n: ";
                std::cin >> atsakymas3;
            }
            if (atsakymas3 == "t")
            {
                std::cout << "Iveskite studentu skaiciu sarase: ";
                int n;
                while (!(std::cin >> n) || n <= 0) 
                {
                    std::cout << "Klaida: studentu skaicius turi buti skaicius, didesnis uz 0. Iveskite studentu skaiciu sarase: ";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                for (int j = 0; j < n; j++)
                {
                    std::cout << "Iveskite per tarpa studento varda ir pavarde: ";
                    std::cin >> A.vardas >> A.pavarde;
                    std::cout << "Iveskite semestro namu darbu pazymiu kieki: ";
                    while (!(std::cin >> k) || k <= 0) 
                    {
                        std::cout << "Klaida: pazymiu kiekis turi buti skaicius, didesnis uz 0. Iveskite pazymiu kieki: ";
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                    }
                    std::cout << "Ar norite sugeneruoti atsitiktinius namu darbu ir egzamino pazymius? (t / n): ";
                    std::string atsakymas4;
                    std::cin >> atsakymas4;
                    while (atsakymas4 != "t" && atsakymas4 != "n")
                    {
                        std::cout << "Klaida: neteisinga ivestis, iveskite t arba n: ";
                        std::cin >> atsakymas4;
                    }
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
                        if (konteineris == 1)
                            grupe.push_back(A);
                        else
                            grupe_list.push_back(A);
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
                        if (konteineris == 1)
                            grupe.push_back(A);
                        else
                            grupe_list.push_back(A);
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
                        std::cout << "Klaida: pazymiu kiekis turi buti skaicius, didesnis uz 0. Iveskite pazymiu kieki: ";
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                    }
                    std::cout << "Ar norite sugeneruoti atsitiktinius namu darbu ir egzamino pazymius? (t / n): ";
                    std::string atsakymas4;
                    std::cin >> atsakymas4;
                    while (atsakymas4 != "t" && atsakymas4 != "n")
                    {
                        std::cout << "Klaida: neteisinga ivestis, iveskite t arba n: ";
                        std::cin >> atsakymas4;
                    }
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
                        if (konteineris == 1)
                            grupe.push_back(A);
                        else
                            grupe_list.push_back(A);
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
                        if (konteineris == 1)
                            grupe.push_back(A);
                        else
                            grupe_list.push_back(A);
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
    while (!(std::cin >> pasirinkimas) || (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3))
    {
        std::cout << "Klaida: neteisinga ivestis, iveskite 1, 2 arba 3: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::cout << "Studentu duomenys (" << (konteineris == 2 ? "List" : "Vector") << "): \n";
    if (pasirinkimas == 1)
    {
        std::cout << std::left << std::setw(13) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Vid.)" << std::left << std::setw(20) << "Objekto adresas" << "\n";
        std::cout << std::string(68, '-') << "\n";
    }
    else if (pasirinkimas == 2)
    {
        std::cout << std::left << std::setw(13) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Med.)" << std::left << std::setw(20) << "Objekto adresas" << "\n";
        std::cout << std::string(68, '-') << "\n";
    }
    else if (pasirinkimas == 3)
    {
        std::cout << std::left << std::setw(13) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Vid.)" << std::left << std::setw(20) << "Galutinis (Med.)" << std::left << std::setw(20) << "Objekto adresas" << "\n";
        std::cout << std::string(88, '-') << "\n";
    }
    if (konteineris == 2)
    {
        for (studentas &B : grupe_list) printas(B, pasirinkimas);
    }
    else
    {
        for (studentas &B : grupe) printas(B, pasirinkimas);
    }
}