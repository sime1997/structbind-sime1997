#include "../src/kredit.h"
#include "gtest/gtest.h"

TEST(Kredit, Konstruktor){
    Osiguranje osig;
    osig.broj = 568;
    Kredit kredit1("pero", "", 50'000.00, 2.85, "EUR", std::make_shared<Osiguranje>(osig)); 

    EXPECT_EQ(kredit1.nositelj(),std::string("pero"));
    EXPECT_EQ(kredit1.jamac(),std::string(""));
    EXPECT_EQ(kredit1.iznos(), 50'000.00); 
    EXPECT_EQ(kredit1.kamata(), 2.85); 
    EXPECT_STREQ(kredit1.valuta(), "EUR");
    EXPECT_EQ(kredit1.osiguranje()->broj, 568);
}

TEST(Kredit, binding1){
    Osiguranje osig;
    osig.broj = 568;
    Kredit kredit1("pero", "", 50'000.00, 2.85, "EUR", std::make_shared<Osiguranje>(osig)); 

    auto [ nositelj, jamac, iznos, kamata, valuta, osiguranje] = kredit1;

    EXPECT_EQ(nositelj,std::string("pero"));
    EXPECT_EQ(jamac,std::string(""));
    EXPECT_EQ(iznos, 50'000.00); 
    EXPECT_EQ(kamata, 2.85); 
    EXPECT_STREQ(valuta, "EUR");
    EXPECT_EQ(osiguranje->broj, 568);

}

TEST(Kredit, binding2){
    Osiguranje osig;
    osig.broj = 1568;
    Kredit kredit2("boro", "zelko", 100'000.00, 2.95, "US", std::make_shared<Osiguranje>(osig)); 
    auto & [ nositelj, jamac, iznos, kamata, valuta, osiguranje] = kredit2;

    EXPECT_EQ(nositelj,std::string("boro"));
    EXPECT_EQ(jamac,std::string("zelko"));
    EXPECT_EQ(iznos, 100'000.00); 
    EXPECT_EQ(kamata, 2.95); 
    EXPECT_STREQ(valuta, "US");
    EXPECT_EQ(osiguranje->broj, 1568);
 
   
    kamata = 10.0;
    EXPECT_EQ(kredit2.kamata(), 10.0); 
    kredit2.kamata() = 1.0;
    EXPECT_EQ(kamata, 1.0); 

}

TEST(Kredit, binding3){
    Osiguranje osig;
    osig.broj = 1568;
    Kredit kredit2("boro", "zelko", 100'000.00, 2.95, "US", std::make_shared<Osiguranje>(osig)); 
    auto && [ nositelj, jamac, iznos, kamata, valuta, osiguranje] = kredit2;

    EXPECT_EQ(nositelj,std::string("boro"));
    EXPECT_EQ(jamac,std::string("zelko"));
    EXPECT_EQ(iznos, 100'000.00); 
    EXPECT_EQ(kamata, 2.95); 
    EXPECT_STREQ(valuta, "US");
    EXPECT_EQ(osiguranje->broj, 1568);
 
   
    kamata = 10.0;
    EXPECT_EQ(kredit2.kamata(), 10.0); 
    kredit2.kamata() = 1.0;
    EXPECT_EQ(kamata, 1.0); 
}

TEST(Kredit, binding4){
    Osiguranje osig;
    osig.broj = 1568;
    Kredit kredit2("boro", "zelko", 100'000.00, 2.95, "US", std::make_shared<Osiguranje>(osig)); 
    auto && [ nositelj, jamac, iznos, kamata, valuta, osiguranje] = std::move(kredit2);

    EXPECT_EQ(nositelj,std::string("boro"));
    EXPECT_EQ(jamac,std::string("zelko"));
    EXPECT_EQ(iznos, 100'000.00); 
    EXPECT_EQ(kamata, 2.95); 
    EXPECT_STREQ(valuta, "US");
    EXPECT_EQ(osiguranje->broj, 1568);
 
   
    kamata = 10.0;
    EXPECT_EQ(kredit2.kamata(), 10.0); 
    kredit2.kamata() = 1.0;
    EXPECT_EQ(kamata, 1.0); 

}


TEST(Kredit, binding5){
    Osiguranje osig;
    osig.broj = 1568;
    Kredit kredit2("boro", "zelko", 100'000.00, 2.95, "US", std::make_shared<Osiguranje>(osig)); 
    auto [ nositelj, jamac, iznos, kamata, valuta, osiguranje] = std::move(kredit2);

    EXPECT_EQ(nositelj,std::string("boro"));
    EXPECT_EQ(jamac,std::string("zelko"));
    EXPECT_EQ(iznos, 100'000.00); 
    EXPECT_EQ(kamata, 2.95); 
    EXPECT_STREQ(valuta, "US");
    EXPECT_EQ(osiguranje->broj, 1568);
 
   
    kamata = 10.0;
    EXPECT_NE(kredit2.kamata(), 10.0); 
    kredit2.kamata() = 1.0;
    EXPECT_NE(kamata, 1.0); 

}


TEST(Kredit, binding6){
    Osiguranje osig;
    osig.broj = 1568;
    Kredit kredit("boro", "zelko", 100'000.00, 2.95, "US", std::make_shared<Osiguranje>(osig)); 
    auto const & [ nositelj, jamac, iznos, kamata, valuta, osiguranje] = kredit;

    EXPECT_EQ(nositelj,std::string("boro"));
    EXPECT_EQ(jamac,std::string("zelko"));
    EXPECT_EQ(iznos, 100'000.00); 
    EXPECT_EQ(kamata, 2.95); 
    EXPECT_STREQ(valuta, "US");
    EXPECT_EQ(osiguranje->broj, 1568);
 
   
    kredit.kamata() = 1.0;
    EXPECT_NE(kamata, 1.0); 

}
