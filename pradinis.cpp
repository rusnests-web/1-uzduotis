#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using std::string;
using std::vector;
struct studentas
{
  string vardas, pavarde;
  vector<int> nd;
  int egz;
  int suma;
  float vidurkis, galutinis;
};

void printas(studentas &A);

int main()
{
    int k;
    std::vector<studentas> grupe;
    studentas A;
    std::cout << "Iveskite studentu skaiciu sarase: ";
    int n;
    std::cin >> n;
    for (int j = 0; j < n; j++)
    {
        std::cout << "Iveskite per tarpa studento varda ir pavarde: ";
        std::cin >> A.vardas >> A.pavarde;
        std::cout << "Iveskite semestro namu darbu pazymiu kieki: ";
        std::cin >> k;
        for (int i = 0; i < k; i++)
        {
            std::cout << "Iveskite " << i + 1 << " pazymi: ";
            int a;
            std::cin >> a;
            A.nd.push_back(a);
        }
        std::cout << "Iveskite semestro egzamino pazymi: ";
        std::cin >> A.egz;
        A.suma = 0;
        for (int p : A.nd) A.suma += p;
        A.vidurkis = A.suma / k;
        A.galutinis = 0.4 * A.vidurkis + 0.6 * A.egz;
        std::cout << A.vidurkis << " " << A.galutinis;
        grupe.push_back(A);
        A.pavarde.clear();
        A.vardas.clear();
        A.nd.clear();
    }
    std::cout << "Studentu duomenys: \n";
    std::cout << std::left << std::setw(13) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(20) << "Galutinis (Vid.)" << "\n";
    std::cout << std::string(48, '-') << "\n";
    for (studentas &B : grupe) printas(B);
}

void printas(studentas &A)
{
    std::cout << std::left << std::setw(13) << A.vardas << std::left << std::setw(15) << A.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << A.galutinis << "\n";
}