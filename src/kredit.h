#pragma once

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
    Kredit(std::string nositelj,  std::string jamac, 
           double iznos, double kamata, const char *, std::shared_ptr<Osiguranje> osiguranje=nullptr);
   // TODO Vaše sučelje dolazi ovdje.
};

// TODO Vaša implementacija dolazi ovdje
