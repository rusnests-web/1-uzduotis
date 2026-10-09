# 1-uzduotis

## Failu kurimas

Programa atsitiktinai generuoja penkis tekstinius studentu sarasu failus is atitinkamai 1000, 10000, 100000, 1000000 ir 10000000 irasu. Kiekviena ju sudaro vardo, pavardes stulpeliai ir atsitiktinai parinktas kiekis namu darbu pazymiu stulpeliu (nuo 7 iki 20 imtinai). Namu darbu ir egzamino pazymiai generuojami atsitiktinai nuo 1 iki 10 imtinai.

### Failu kurimo laikas:

|Failas|Laikas (s)|
|------|----------|
|1000 irasu (10 ND)|0.016536|
|10000 irasu (7 ND)|0.125006|
|100000 irasu (10 ND)|0.827061|
|1000000 irasu (19 ND)|12.645660|
|10000000 irasu (17 ND)|114.053876|
---

## Programos spartos analize

Zemiau pateikiami programos spartos analizes rezultatu ***vidurkiai*** Vector ir List atvejais, apskaiciuoti atlikus tris testus:

### Programos sparta (Vector):

|Failas|Nuskaitymas, s|Studentu dalijimas, s|Rusiavimas didejimo tvarka su sort, s|Vargsiuku isvedimas, s|Kietiaku isvedimas, s|Is viso, s|
|------|--------------|---------------------|-------------------------------------|----------------------|---------------------|----------|
|1000 irasu (10 ND)|0.038347|0.001592|0.002195|0.004756|0.00633|0.05322|
|10000 irasu (7 ND)|0.238906|0.016107|0.017993|0.041369|0.100758|0.363897|
|100000 irasu (10 ND)|1.477374|0.060930|0.085725|0.118127|0.194705|1.936861|
|1000000 irasu (19 ND)|11.523682|0.611187|0.913147|1.286063|1.748179|16.082258|
|10000000 irasu (17 ND)|74.681584|6.426020|8.248470|11.587636|17.188267|118.131977|
---
Visais atvejais sparciausiai vykdoma studentu dalijimo funkcija, o leciausiai - nuskaitymas.

### Programos sparta (List):

