# Systemy Operacyjne

## Zestaw 2

### Zadanie 1

Napisz program, który utworzy poniższą strukturę:

|                       Program                          |                                                          |
| :----------------------------------------------------: | :------------------------------------------------------: |
|                      Potomek I                         |                       Potomek II                         |
| Potomek 1 Potomka I - w bieżącym katalogu tworzy plik1 | Potomek I Potomka II - skopiuje zawartość plik1 do plik2 |
| Potomek 2 Potomka I - pobierze tekst od użytkownika i zapisze go do plik1 | Potomek 2 Potomka II - Sprawdzi prawa jakie posiada plik2 i wyświetli odpowiedni komunikat w każdym przypadku |

Proces macierzysty powinien wyświetlać ile znaków zapisano do plik1. Nie używać poleceń z użyciem funkcji system().

### Zadanie 2

Napisz program który utworzy ```n``` potomków. Liczbę ```n``` podaje użytkownik. Każdy potomek przekazuję liczbę z zakresu od ```1-100``` - podana przez użytkownika. Proces macierzysty generuje losowo liczbę z zakresu ```1-100```, wyświetla ją i porównuje z wartościami przekazanymi przez jej potomków. Wyświetla odpowiednie komunikaty dla mniejszej liczby, równej i większej.
