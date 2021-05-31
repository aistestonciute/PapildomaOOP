# Asociatyvių ir std::string konteinerių naudojimas
## Papildoma OOP užduotis

### Aprašymas

Programa skirta duotame tekste rasti žodžius, pasikartojančius daugiau nei 1 kartą. Šių žodžių pasikartojimų skaičius yra saugomas kartu su žodžiu. Taip pat programa suranda ir išveda *URL* (parašytus tiek pilnu, tiek sutrumpintu pavidalu).

### Veikimas

Paleiskite programą ir ji iš teksto, kuris saugomas **data.txt** faile išves skirtingus žodžius, kurie pasikartoja dažniau nei 1 kartą (kartu su pasikartojimų skaičiumi) ir tekste rastus *URL*. Šiuos duomenis programa automatiškai išveda į failą **results.txt**. Veikimo principas:
1. Programa iš `data.txt` failo duomenis surašo į `buffer'į`.
2. Tikrinama, ar `string` nėra *URL* (ieškoma, ar prasideda `http://`, `https://`, `www.`). 
3. Visos žodžio raidės padaromos mažosios.
4. Nuimami skyrybos ženklai.
5. Žodis įrašomas į konteinerį.
6. Tikrinama, kokiose vietose žodis kartojamas ir konteineryje taip pat saugoma informacija apie pasikartojimų skaičių ir eilutes, kur tas žodis kartojasi.
7. Į failą `results.txt`išvedami rezultatai.

### Paleidimas

Parisiųsti norimą versiją iš [Releases](https://github.com/aistestonciute/PapildomaOOP/releases) aplanko. Išarchyvuokite parisiųstą failą. Paleiskitę programą per norimą `IDE` arba per komandinę eilutę:

`
g++ -o main main.cpp
`
`
./main
`

### Versijos

[v1.0]() Pradinė versija, atitinkanti užduotyje aprašytą funkcionalumą.
