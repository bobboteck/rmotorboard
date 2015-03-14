# Linee guida scrittura software #
**Classi, Funzioni, Strutture**

Tutte le iniziali vanno indicate in maiuscolo, fanno eccezione i metodi relativi a periferiche del micro, il cui identificativo della periferica viene inserito all'inizio del nome e tutto in maiscolo. Non si usano caratteri di "underscore", ad eccezione di funzioni per la gestione degli eventi come possono essere gli interrupt.
Esempi possono essere:
```
LcdWriteChar(); // Funzione

UART1WriteChar(); // Funzione relativa ad una periferica

__ISR__UART(); // Gestione dell'evento interrupt
```
**Variabili, Parametri, Proprietà**

Sono indicati sempre con il primo carattere minuscolo, le restanti iniziali sono in maiuscolo. L'unica eccezione sono le variabili private delle librerie che iniziano con un carattere di "underscore".
Esempi possono essere:
```
int numeroCicliInterrupt;

unsigned char _timer;
```
**Costanti**

Le costanti vanno indicate tutte in maiuscolo, è ammesso l'uso del carattere "underscore".
Esempio può essere:
```
#define DIM_ARRAY 20
```
**Architettura**

Per quanto possibile si dovrà separare la parte di codice che accede direttamente alle periferiche, creando uno strato software che si occuperà della gestione a basso livello e uno più generale che utilizzerà questi metodi. Questo permetterà in futuro un porting più semplice, di alcune librerie, su altre piattaforme.