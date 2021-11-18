#include "kredit.h"

#include<iostream>

int main(void){
    Osiguranje osig;
    osig.broj = 568;
    Kredit kredit1("pero", "", 50000.00, 2.85, "EUR", std::make_shared<Osiguranje>(osig)); 
    auto &[nositelj,jamac,iznos,kamata] = kredit1;
    nositelj="os";
    std::cout<<kredit1.nositelj()<<iznos<<kamata;
}
