#include <iostream>
#include <vector>

class Micronutrient
{
    int vitamine = 1;
    int minerale = 1;
public:
    int get_vitamine(){return vitamine;}
    int get_minerale(){return minerale;}
    Micronutrient(int vitamine_, int minerale_){vitamine = vitamine_; minerale = minerale_;}
};

class Macronutrient
{
    int proteina = 1;
    int carbohidrat = 1;
    int grasime = 1;
public:
    int get_proteina() { return proteina;}
    int get_carbohidrat() { return carbohidrat;}
    int get_grasime() { return grasime;}
    Macronutrient(int proteine_, int carbohidrati_, int grasimi_){ proteina = proteine_; carbohidrat = carbohidrati_; grasime = grasimi_;}
};

class Aliment
{
    std::string denumire;
    std::vector<Macronutrient> Macronutrienti;
    std::vector<Micronutrient> Micronutrienti;
public:
    Aliment(std::string denumire_){denumire = denumire_;}
    std::string get_denumire(){return denumire;}
    Aliment(const Aliment& other)
    {
        denumire = other.denumire;
    }
    Aliment& operator=(const Aliment& other)
    {
        denumire = other.denumire;
        return *this;
    }
    ~Aliment(){}
};

int main()
{
    Aliment aliment1("piept de pui");
    Macronutrient macronutrient1(22, 2, 1);
    Micronutrient micronutrient1(4, 5);
    std::cout << "Alimentul " << aliment1.get_denumire();
    std::cout << " contine la 100 de grame de produs: " << macronutrient1.get_proteina() << "g de proteine, ";
    std::cout << macronutrient1.get_carbohidrat() << "g de carbohidrati, ";
    std::cout << macronutrient1.get_grasime() << "g de grasimi, ";
    std::cout << micronutrient1.get_vitamine() << " vitamine si ";
    std::cout << micronutrient1.get_minerale() << " minerale";

    return 0;
}