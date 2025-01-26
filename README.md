# Minitalk

Minitalk è un progetto che esplora la comunicazione tra processi (IPC) in ambiente Unix/Linux. Lo scopo del progetto è implementare un semplice sistema di messaggistica tra un client e un server utilizzando **segnali Unix** (`SIGUSR1` e `SIGUSR2`).

## 📜 Descrizione

Il progetto si compone di due programmi principali:
1. **Server**: Un processo che riceve messaggi dal client e li visualizza.
2. **Client**: Un processo che invia un messaggio al server usando segnali Unix.

La comunicazione è unidirezionale: il client invia caratteri al server, uno alla volta, codificandoli in segnali binari (`SIGUSR1` e `SIGUSR2`).

### Funzionalità principali
- Il server deve essere in grado di:
  - Ricevere segnali dal client.
  - Ricostruire i messaggi inviati e stamparli sullo standard output.
- Il client deve essere in grado di:
  - Inviare un messaggio di testo al server specificando il PID di quest'ultimo.

---

## ⚙️ Compilazione

Per compilare i programmi **server** e **client**, usa il comando:

make all 


Il comando genererà i due eseguibili:

- server
- client
## 🚀 Esecuzione
1. Avvia il server
Prima di tutto, avvia il server per iniziare a ricevere messaggi. Il server stamperà il suo PID, che servirà per la comunicazione con il client.
```
./server
Output esempio:
Server avviato. PID: 12345
```
2. Invia un messaggio con il client
Usa il PID del server per inviare un messaggio. Ad esempio, per inviare il messaggio "Hello", usa il comando:
```
./client 12345 "Hello"
```
## 🛠️ Struttura del progetto
server.c: Implementa il server, che riceve segnali e ricostruisce il messaggio.
client.c: Implementa il client, che converte il messaggio in segnali e li invia al server.
utils.c: Contiene funzioni di supporto come la gestione degli errori.
Makefile: Contiene le regole per compilare il progetto.
## 📝 Funzionamento tecnico
Il client invia ogni carattere come una sequenza di segnali:
- **SIGUSR1:** Rappresenta il bit 0.
- **SIGUSR2:** Rappresenta il bit 1.
Il server interpreta i segnali e ricostruisce il messaggio, un carattere alla volta.
Esempio di trasmissione
Il client invia la rappresentazione binaria di un carattere (ad esempio, A = 01000001).
Il server riceve i segnali e converte i bit in un carattere leggibile.
## 🔧 Debug e Test
Visualizza i processi attivi
Per verificare il PID del server:
- ps -aux | grep server
Interrompere il server
Per il server in esecuzione con:
- kill <PID_SERVER>
