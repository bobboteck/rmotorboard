# RevisionCode #

## Next step ##
Configurare il Timer1 e relativo interrupt, per fare in modo che venga scatenato ogni millisecondo. Modificare il main per far lampeggiare il led tramite apposito contatore gestito dall'interrupt del Timer1.

## Stato attuale ([r9](https://code.google.com/p/rmotorboard/source/detail?r=9)) ##
Si tratta del progetto di partenza configurato per il dsPIC indicato, prevede la configurazione dell'oscillatore e la creazione della libreria dei Settings. Il programma principale fa lampeggiare un led sulla porta RA4 determinando i tempi tramite la funzione di Delay.