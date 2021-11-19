#pragma once
#include<iostream>
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

    std::string nositelj() const {return _nositelj;}
    std::string & nositelj(){return _nositelj;}

    std::string jamac() const{return _jamac; }
    std::string & jamac(){return _jamac;}

    double iznos() const{return _iznos;}
    double & iznos(){return _iznos;}
    
    double  kamata() const{return _kamata;}
    double & kamata(){return _kamata;}

    const char*  valuta() const{return _valuta;}
    char*  valuta() {return _valuta;}

    std::shared_ptr<Osiguranje>  osiguranje() const
        {return _osiguranje;}

// TODO Vaše sučelje dolazi ovdje.
template <std::size_t N> 
friend decltype(auto) get(Kredit const &);

template <std::size_t N> 
friend decltype(auto) get(Kredit &);

template <std::size_t N> 
friend decltype(auto) get(Kredit &&);
};

// TODO Vaša implementacija dolazi ovdje


template <>
struct std::tuple_size<Kredit>{
    static constexpr int value =  6;
};





template <>
struct std::tuple_element<0, Kredit>{
     using type = std::string;
};

template <>
struct std::tuple_element<1, Kredit>{
     using type = std::string;
};

template <>
struct std::tuple_element<2, Kredit>{
     using type = double;
};

template <>
struct std::tuple_element<3, Kredit>{
     using type = double;
};

template <>
struct std::tuple_element<4, Kredit>{
     using type = char*;
};

template <>
struct std::tuple_element<5,Kredit>{
    using type=std::shared_ptr<Osiguranje>;
};



template<std::size_t N>
inline decltype(auto) get(Kredit & objekt){
     if      constexpr(N == 0) return objekt.nositelj();
     else if constexpr(N == 1) return objekt.jamac();
     else if constexpr(N == 2) return objekt.iznos();
     else if constexpr(N == 3) return objekt.kamata();
     else if constexpr(N == 4) return objekt.valuta();
     else if constexpr(N == 5) return objekt.osiguranje();
}

template<std::size_t N>
inline decltype(auto) get(Kredit const & objekt){
     if      constexpr(N == 0) return objekt.nositelj();
     else if constexpr(N == 1) return objekt.jamac();
     else if constexpr(N == 2) return objekt.iznos();
     else if constexpr(N == 3) return objekt.kamata();
     else if constexpr(N == 4) return objekt.valuta();
     else if constexpr(N == 5) return objekt.osiguranje();

}


template<std::size_t N>
inline decltype(auto) get(Kredit && objekt){
     if      constexpr(N == 0) return objekt.nositelj();
     else if constexpr(N == 1) return objekt.jamac();
     else if constexpr(N == 2) return objekt.iznos();
     else if constexpr(N == 3) return objekt.kamata();
     else if constexpr(N == 4) return objekt.valuta();
     else if constexpr(N == 5) return objekt.osiguranje();

}