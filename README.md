# Operating-Systems

## Spis treści

### Laboratoria

- [Laboratoria](#laboratoria)
- [Zestaw 1](#zestaw-1)
- [Zestaw 2](#zestaw-2)

### Rozwiązania

- [Zestaw 1](https://github.com/tukarp/Operating-Systems/blob/main/Laboratoria/Zestaw%201.c)
- [Zestaw 2 - Zadanie 1](https://github.com/tukarp/Operating-Systems/blob/main/Laboratoria/Zestaw%202.1.c)
- [Zestaw 2 - Zadanie 2](https://github.com/tukarp/Operating-Systems/blob/main/Laboratoria/Zestaw%202.2.c)

### Notatki




# Laboratoria

## Zestaw 1

### Zadanie 1

Napisz program, który utworzy 3 procesy potomne. Poniższy schemat przedstawia strukturę potomków oraz ich zadania.

|                               |                Program                   |                            |
| :---------------------------: | :--------------------------------------: | :------------------------: |
|           Potomek I           |               Potomek II                 |         Potomek III        |
| Tworzy pliki P1.txt i P2.txt. | Kopiuje zawartość pliku P1.txt do P2.txt | Tworzy dwa procesy zombie. |
| Potomek 1 Potomka I - pobiera tekst od użytkownika za pomocą funkcji read i zapisuje do P1.txt. | Potomek 1 potomka II - przesuwa wskaźnik w pliku P2.txt o 10 bajtów w prawo i wyświetli treść. |  |
|  Potomek 2 Potomka I - tworzy kopię deskryptora pliku P1.txt i z jego użyciem odczytuje tekst z pliku P1.txt | Potomek 2 Potomka II - sprawdza czy P2.txt ma prawo do wykonywania, jeżeli nie to zostanie ono dodane. |  |

### Zadanie 2

Napisz program, który utworzy dwóch potomków. Jeden z nich wyświetli ścieżkę bieżącego katalogu, drugi wyświetli listę procesów. Zadanie należy wykonać z użyciem funkcji exec.

[Rozwiązanie](https://github.com/tukarp/Operating-Systems/blob/main/Laboratoria/Zestaw%201.c)

## Zestaw 2

### Zadanie 1

Napisz program, który utworzy poniższą strukturę:

|                       Program                          |                                                          |
| :----------------------------------------------------: | :------------------------------------------------------: |
|                      Potomek I                         |                       Potomek II                         |
| Potomek 1 Potomka I - w bieżącym katalogu tworzy plik1 | Potomek I Potomka II - skopiuje zawartość plik1 do plik2 |
| Potomek 2 Potomka I - pobierze tekst od użytkownika i zapisze go do plik1 | Potomek 2 Potomka II - Sprawdzi prawa jakie posiada plik2 i wyświetli odpowiedni komunikat w każdym przypadku |

Proces macierzysty powinien wyświetlać ile znaków zapisano do plik1. Nie używać poleceń z użyciem funkcji system().

[Rozwiązanie](https://github.com/tukarp/Operating-Systems/blob/main/Laboratoria/Zestaw%202.1.c)

### Zadanie 2

Napisz program który utworzy ```n``` potomków. Liczbę ```n``` podaje użytkownik. Każdy potomek przekazuję liczbę z zakresu od ```1-100``` - podana przez użytkownika. Proces macierzysty generuje losowo liczbę z zakresu ```1-100```, wyświetla ją i porównuje z wartościami przekazanymi przez jej potomków. Wyświetla odpowiednie komunikaty dla mniejszej liczby, równej i większej.

[Rozwiązanie](https://github.com/tukarp/Operating-Systems/blob/main/Laboratoria/Zestaw%202.2.c)
