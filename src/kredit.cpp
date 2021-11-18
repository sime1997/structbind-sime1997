#include "kredit.h"
#include <string.h>
#include<iostream>
Kredit::Kredit(std::string nositelj,  std::string jamac,  double iznos, double kamata, const char * valuta, 
               std::shared_ptr<Osiguranje> osiguranje):
    _nositelj(nositelj), _jamac(jamac), _iznos(iznos), _kamata(kamata),_osiguranje(osiguranje)
    {
        
        strcpy(_valuta, valuta);
        std::cout<<_osiguranje->broj;   
    }



// TODO Implementacija konstruktora.
