# 1-uzduotis

## Failu kurimas

Programa atsitiktinai generuoja penkis tekstinius studentu sarasu failus is atitinkamai 1000, 10000, 100000, 1000000 ir 10000000 irasu. Kiekviena ju sudaro vardo, pavardes stulpeliai ir atsitiktinai parinktas kiekis namu darbu pazymiu stulpeliu (nuo 7 iki 20 imtinai). Namu darbu ir egzamino pazymiai generuojami atsitiktinai nuo 1 iki 10 imtinai.

### Failu kurimo laikas:

|Failas|Laikas (s)|
|------|----------|
|1000 irasu (10 ND)|0.026312|
|10000 irasu (12 ND)|0.181505|
|100000 irasu (16 ND)|1.136747|
|1000000 irasu (17 ND)|11.232730|
|10000000 irasu (9 ND)|68.510706|
---

### Programos spartos analize:

|Failas|Nuskaitymas, s|Studentu dalijimas, s|Rusiavimas didejimo tvarka su sort, s|Vargsiuku isvedimas, s|Kietiaku isvedimas, s|Is viso, s|
|------|--------------|---------------------|-------------------------------------|----------------------|---------------------|----------|
|1000 irasu (10 ND)|0.016196|0.001511|0.001901|0.007422|0.006374|0.033404|
|10000 irasu (12 ND)|0.189315|0.014462|0.017993|0.041369|0.100758|0.363897|
|100000 irasu (16 ND)|1.477374|0.060930|0.085725|0.118127|0.194705|1.936861|
|1000000 irasu (17 ND)|11.523682|0.611187|0.913147|1.286063|1.748179|16.082258|
|10000000 irasu (9 ND)|74.681584|6.426020|8.248470|11.587636|17.188267|118.131977|
---
Visais atvejais sparciausiai vykdoma studentu dalijimo funkcija, o leciausiai - nuskaitymas.