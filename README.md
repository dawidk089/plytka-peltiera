# plytka-peltiera
**ogolne oprogramowanie kontrolera atmega8A kierunkowane na doswiadczenie z laboratoriow (badanie sprawnosci plytki peltiera)**

scenariusz programu przewiduje:
 - badanie mocy plytki peltiera przy roznicy temperatury ok 80st C w zaleznosci od zadanego obciazenia (oporu)
 - pomiar napiecia, natezenia wytwarzanego prze plytke oraz temperatury na grzejniku w czasie przy spadku temperatury na grzejniku ok 10st C (zaczynajac np przy 90st C)
 - pomiar napiecia, netezenia podawanego na plytke oraz temperatury w czasie dla spadku/wzrostu temperatury do 0/40st C

potrzebne moduly:
 - ADC
   - pomiar napiecia
   - posredni pomiar pradu przez spadek napiecia na boczniku 1A/10A 100mV
   - pomiar temperatur na czujce temepatury 
 - TIMER
   - pomiar czasu

wazne by mozna bylo skalibrowac czujniki

program na kontrolerze ma dostarczyc interfejs do prostego programowania kontrolera bez potrzeby zagladania w dokumentacje i przesuniec bitowych na wielu rejestrach - wyabstrachowanie wyzszego poziomu

odebranie i obrobka danych po stronie LabView


