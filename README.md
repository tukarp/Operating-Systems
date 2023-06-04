# Systemy Operacyjne

## Spis treści

### Laboratoria

- [Laboratoria](https://github.com/tukarp/Operating-Systems/blob/main/Laboratoria)
- [Zestaw 01](https://github.com/tukarp/Operating-Systems/blob/main/Laboratoria/Zestaw%2001)
- [Zestaw 02](https://github.com/tukarp/Operating-Systems/blob/main/Laboratoria/Zestaw%2002)
- [Zestaw 03](https://github.com/tukarp/Operating-Systems/blob/main/Laboratoria/Zestaw%2003)

### Notatki

- [Notatki](#notatki-1)
- [Programowanie](#programowanie)
  - [Komendy w języku ```C```](#komendy-w-języku-c)
  - [Prawa dostępu jako argumenty funkcji](#prawa-dostępu-jako-argumenty-funkcji)
- [Procesy](#procesy)
  - [Komendy w języku ```C```](#komendy-w-języku-c-1)
  - [Komenda ```ps```](#komenda-ps)
  - [Komenda ```top```](#komenda-top)
- [Wątki](#wątki)
  - [Komendy w języku ```C```](#komendy-w-języku-c-2)
- [Pamięć współdzielona](#pamięć-współdzielona)
  - [Komendy w języku ```C```](#komendy-w-języku-c-3)

### Strategie obsługi procesów

- [Strategie Obsługi Procesów](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w.pdf)
- [Strategia FCFS](https://github.com/tukarp/Operating-Systems/tree/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20FCFS)
  - [Strategia FCFS - Czas 1](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20FCFS/Strategia%20FCFS%20-%20Czas%2001.png)
  - [Strategia FCFS - Czas 2](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20FCFS/Strategia%20FCFS%20-%20Czas%2002.png)
  - [Strategia FCFS - Czas 3](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20FCFS/Strategia%20FCFS%20-%20Czas%2003.png)
- [Strategia RR](https://github.com/tukarp/Operating-Systems/tree/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20RR)
  - [Strategia RR, Kwant Czasu 1](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20RR/Kwant%201/Strategia%20RR%20Kwant%20czasu%201.png)
  - [Strategia RR, Kwant Czasu = 2 - Czas 1](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20RR/Kwant%202/Strategia%20RR%2C%20Kwant%20Czasu%20%3D%202%20-%20Czas%2001.png)
  - [Strategia RR, Kwant Czasu = 2 - Czas 2](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20RR/Kwant%202/Strategia%20RR%2C%20Kwant%20Czasu%20%3D%202%20-%20Czas%2002.png)
  - [Strategia RR, Kwant Czasu = 2 - Czas 3](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20RR/Kwant%202/Strategia%20RR%2C%20Kwant%20Czasu%20%3D%202%20-%20Czas%2003.png)
  - [Strategia RR, Kwant Czasu = 4 - Czas 1](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20RR/Kwant%204/Strategia%20RR%2C%20Kwant%20Czasu%20%3D%204%20-%20Czas%2001.png)
  - [Strategia RR, Kwant Czasu = 4 - Czas 2](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20RR/Kwant%204/Strategia%20RR%2C%20Kwant%20Czasu%20%3D%204%20-%20Czas%2002.png)
  - [Strategia RR, Kwant Czasu = 4 - Czas 3](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20RR/Kwant%204/Strategia%20RR%2C%20Kwant%20Czasu%20%3D%204%20-%20Czas%2003.png)
  - [Strategia RR](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20RR/Strategia%20RR.png)
- [Strategia SJF](https://github.com/tukarp/Operating-Systems/tree/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20SJF)
  - [Strategia SJF - Czas 1](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20SJF/Strategia%20SJF%20-%20Czas%2001.png)
  - [Strategia SJF - Czas 2](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20SJF/Strategia%20SJF%20-%20Czas%2002.png)
  - [Strategia SJF - Czas 3](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20SJF/Strategia%20SJF%20-%20Czas%2003.png)
- [Strategia SRTF](https://github.com/tukarp/Operating-Systems/tree/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20SRTF)
  - [Strategia SRTF - Czas 1](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20SRTF/Strategia%20SRTF%20-%20Czas%2001.png)
  - [Strategia SRTF - Czas 2](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20SRTF/Strategia%20SRTF%20-%20Czas%2002.png)
  - [Strategia SRTF - Czas 3](https://github.com/tukarp/Operating-Systems/blob/main/Strategie%20Obs%C5%82ugi%20Proces%C3%B3w/Strategia%20SRTF/Strategia%20SRTF%20-%20Czas%2003.png)

### Czasy

- ```Czas 1```

| Proces | Czas Przybycia | Czas Wykonania |
| :----: | :------------: | :------------: |
| P1     |        0       |        5       |
| P2     |        1       |        2       |
| P3     |        1       |        5       |
| P4     |        6       |        2       |
| P5     |        8       |        1       |

- ```Czas 2```

| Proces | Czas Przybycia | Czas Wykonania |
| :----: | :------------: | :------------: |
| P1     |        0       |        3       |
| P2     |        1       |        5       |
| P3     |        2       |        2       |
| P4     |        7       |        4       |
| P5     |        8       |        1       |

- ```Czas 3```

| Proces | Czas Przybycia | Czas Wykonania |
| :----: | :------------: | :------------: |
| P1     |        0       |       10       |
| P2     |        0       |       5        |
| P3     |        0       |       4        |
| P4     |        6       |       8        |
| P5     |        6       |       3        |

# Notatki

## Programowanie 

### Komendy w języku ```C```

- ```open``` - komenda służąca do otwarcia pliku,
- ```close``` - komenda służąca do zamknięcia pliku,
- ```creat``` - komenda służąca do utworzenia pliku i otwarcia go,
- ```dup``` - komenda służąca do utworzenia kopii deskryptora i nadania jej pierwszego wolnego numeru z tablicy otwartych plików,
- ```dup2``` - komenda służąca do utworzenie kopii deskryptora, umożliwiając określenie jej
identyfikatora przez użytkownika,
- ```unlink``` - komenda służąca do usunięcia dowiązania do pliku
- ```read``` - komenda służąca do odczytu fragmentu pliku,
- ```write``` - komenda służąca do zapisu fragmentu pliku,
- ```lseek``` - komenda służąca do przesunięcia wskaźnika bieżącej pozycji,

### Prawa dostępu jako argumenty funkcji

- ```O_RDONLY``` - argument otwarcia w trybie tylko do odczytu,
- ```O_WRONLY``` - argument otwarcia w trybie tylko do zapisu,
- ```O_RDWR``` - argument ootwarcia w trybie do odczytu i do zapisu,
- ```O_CREAT``` - argument utworzenia pliku, jeśli nie istnieje,
- ```O_TRUNC``` - argument obcięcia pliku, jeśli istnieje jest otwierany w trybie ```O_WRONLY``` lub ```O_RDWR```,
- ```O_EXCL``` - argument powodujący zgłoszenie błędu jeśli plik istnieje i otwarcie go z flagą ```O_CREAT```,
- ```O_APPEND``` - argument pisania na końcu pliku.

## Procesy

### Komendy w języku ```C```

- ```int fork(void)``` - komenda służąca do utworzenia procesu potomnego,
- ```int getpid(void)``` - komenda służąca do zwrócenie własnego identyfikatora procesu,
- ```void exit(int status)``` - komenda służąca do przekazania w odpowiednie miejsce tablicy
procesów wartości status,
- ```int wait(int * status)``` - komenda służąca do czekania ze względu na status,
- ```int waitpid(int pid, int * status, int options)``` - komenda służąca do czekania ze względu na status wątku.

### Komenda ```ps```

- ```ps``` - komenda pokazująca listę uruchomionych procesów,
  - ```-A``` - komenda wyświetlająca wszystkie procesy, także procesy innych użytkowników.
  - ```-a``` - komenda wyświetlająca wszystkie procesy uruchomione w aktualnym oknie terminala,
  - ```-a``` - komenda wyświetlająca listę informacji o procesach,
  - ```-m``` - komenda wyświetlająca informację o pamięci
  - ```-u``` - komenda wyświetlająca informację o procesach wybranego procesu.
- ```STAT``` - status procesu,
  - ```R``` - proces jest aktualnie wykonywane,
  - ```S``` - proces jest aktualnie uśpiony,
  - ```T``` - proces jest aktualnie zatrzymany,
  - ```Z``` - proces jest niewłaściwie zamknięty (zombie),
- ```USER``` - właściciel procesu,
- ```PID``` - identyfikator procesu,
- ```%CPU``` - procentowe zużycie procesora,
- ```%MEM``` - procentowe zużycie pamięci,
- ```VSZ``` - przydzielona pamięć wirtualna[kB],
- ```RSS``` - przydzielona pamięć fizyczna[kB],
- ```TTY``` - identyfikator terminala procesu,
- ```START``` - czas uruchomienia procesu,
- ```TIME``` - użycie procesora wyrażone w czasie,
- ```COMMAND``` - nazwa komendy/procesu oraz jego parametry,
- ```NI``` - wartość priorytetu nice.

### Komenda ```top```

- ```top``` - komenda pokazująca aktualny stan sytemu,
- ```PID``` - indentyfikator procesu,
- ```PPID``` - identyfikator procesu rodzica,
- ```USER``` - identyfikator właściciela procesu,
- ```UID``` - identyfikator procesu,
- ```PR``` - priorytet zadania,
- ```NI``` - wartość parametru nice,
- ```VIRT``` - wykorzystywany rozmiar pamięci wirtualnej,
- ```RES``` - wykorzystywany rozmiar pamięci fizycznej,
- ```SHR``` - wykorzystywany rozmiar pamięci współdzielonej,
- ```S``` - stan procesu,
- ```%CPU``` - procent czasu procesora,
- ```%MEM``` - procent wykorzystywanej przez proces pamięci fizycznej,
- ```TIME+``` - całkowity czas procesora poświęcony zadaniu,
- ```COMMAND``` - polecenie uruchamiające dane zadanie bądź proces.

## Wątki

### Komendy w języku ```C```

- ```pthread_create(pthread_t * thread, pthread_attr_t * attr, void * (* start_routine) (void *), void * arg)``` - komenda służąca do utworzenia wątku,
- ```pthread_t * thread``` - komenda służąca do identyfikacji wątku w systemie,
- ```pthread_attr_t * attr``` - komenda służąca do określenia atrubutów wątku,
- ```void*(* start_routine) (void *)``` - nazwa funkcji do wykonania dla tworzonego wątku,
- ```pthread_exit(void * retval)``` - komenda służąca do zakończenia wątku,
- ```pthread_join(pthread_t th, void ** thread_return)``` - komenda służąca do oczekiwania na zakończenie wątku,
- ```pthread_cancel``` - komenda służąca do zakończenia wykonywania innego wątku,
- ```pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER``` - komenda służąca do zapewnienia wzajemnego wykluczania,
- ```pthread_cond_t cond = PTHREAD_COND_INITIALIZER``` - komenda służąca do synchronizacja za pomocą zmiennych warunkowych polegająca na usypianiu i budzeniu wątku w sekcji krytycznej.

## Pamięć współdzielona

### Komendy w języku ```C```

- ```int shmget(key_t key, size_t size, int shmflags)``` - komenda służąca do utworzenia nowego segmentu pamięci dzielonej, lub uzyskania identyfikatora, a ty samym dostęp do segmentu już istniejącego,
- ```int shmctl(int shmid, int cmd, struct shmid_ds * buf)``` - komenda służąca do modyfikowania oraz odczytu rozmaitych właściwości segmentu pamięci dzielonej, a także do jego kasowania,
- ```char * shmat(int shmid, char * shmaddr, int shmflg)``` - komenda służąca do przyłączenia segmentu pamięci dzielonej do przestrzeni
adresowej procesu,
- ```char * shmdt(char * shmaddr)``` - komenda służąca do odłączania segmentu
pamięci wspólnej od procesu.
