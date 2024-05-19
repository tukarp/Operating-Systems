# Systemy Operacyjne

## Zestaw 01

### Zadanie 1

Napisz program, który utworzy 3 procesy potomne. Poniższy schemat przedstawia strukturę potomków oraz ich zadania.

|                               |                Program                   |                            |
| :---------------------------: | :--------------------------------------: | :------------------------: |
|           Potomek I           |               Potomek II                 |         Potomek III        |
| Tworzy pliki file1.txt i file2.txt | Kopiuje zawartość pliku file1.txt do file2.txt | Tworzy dwa procesy zombie |
| Potomek 1 Potomka I - pobiera tekst od użytkownika za pomocą funkcji read i zapisuje do file1.txt | Potomek 1 potomka II - przesuwa wskaźnik w pliku file2.txt o 10 bajtów w prawo i wyświetli treść |  |
|  Potomek 2 Potomka I - tworzy kopię deskryptora pliku file1.txt i z jego użyciem odczytuje tekst z pliku file1.txt | Potomek 2 Potomka II - sprawdza czy file2.txt ma prawo do wykonywania, jeżeli nie to zostanie ono dodane |  |

### Zadanie 2

Napisz program, który utworzy dwóch potomków. Jeden z nich wyświetli ścieżkę bieżącego katalogu, drugi wyświetli listę procesów. Zadanie należy wykonać z użyciem funkcji exec.
