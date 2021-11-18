#pragma once
#include<memory>
struct Osiguranje{
     long broj;
};


class Kredit{
    std::string _nositelj;
    std::string _jamac;
    double      _iznos;
    double      _kamata;
    char        _valuta[4];
    std::shared_ptr<Osiguranje> _osiguranje;
    using Polje = const char[4];
public:
    Kredit(std::string nositelj,  std::string jamac,  double iznos, double kamata, const char *, std::shared_ptr<Osiguranje> osiguranje=nullptr);
    std::string nositelj()
        {
            return _nositelj;
        }
    std::string jamac()
        {
            return _jamac;
        }
    double iznos()
        {
            return _iznos;
        }
    double  kamata()
        {
            return _kamata;
        }
    char* valuta()
        {
            return _valuta;
        }
     std::shared_ptr<Osiguranje> osiguranje()
        {
            return _osiguranje;
        }
   // TODO Vaše sučelje dolazi ovdje.
};

// TODO Vaša implementacija dolazi ovdje
