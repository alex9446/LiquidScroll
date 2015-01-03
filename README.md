##Indice
[**Installazione manuale**](#installazione-manuale)  
[**Aggiornamento**](#aggiornamento)  
[**Installazione automatica**](#installazione-automatica)  
[**Esempi**](#esempi)  

##Installazione manuale
1. Aprire il terminale

2. Spostarsi nella cartella `libraries` di arduino
  
	> Se arduino &eacute; stato installato tramite pacchetto la cartella di arduino predefinita &eacute; 
	`/usr/share/arduino/`
	
	```sh
	cd /usr/share/arduino/libraries/
	```
	
3. Scaricare la libreria
  ```sh
  git clone https://github.com/alex9446/LiquidScroll.git
  ```

4. Riavviare arduino

##Aggiornamento
1. Aprire il terminale e spostarsi nella cartella `libraries`

2. Aggiornare la libreria
  ```sh
  git pull
  ```

3. Riavviare arduino

##Installazione automatica
> Con questo metodo di installazione non si potr&aacute; aggiornare tramite git

1. [Scaricare l&apos;archivio ZIP](https://github.com/alex9446/LiquidScroll/archive/master.zip) della libreria

2. Importare libreria selezionando `Sketch > Importa libreria > Add Library`

##Esempi
> Aprire esempi selezionando `File > Esempi > LiquidScroll`

[OppositeScroll](https://github.com/alex9446/LiquidScroll/blob/master/examples/OppositeScroll/OppositeScroll.ino)
&ndash; Muove due parole in senso opposto


