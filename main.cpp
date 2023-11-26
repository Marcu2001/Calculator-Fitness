#include <iostream>

class Micronutrient
{
    int vitamine = 0;
    int minerale = 0;
public:
    //int get_vitamine(){return vitamine;}
    //int get_minerale(){return minerale;}
    Micronutrient(int vitamine_, int minerale_){vitamine = vitamine_; minerale = minerale_;}
    friend std::ostream& operator<<(std::ostream &out,const Micronutrient& other)
    {
        out << "vitamine:" << other.vitamine << " " << ",minerale:" << other.minerale << "\n";
        return out;
    }
};

class Macronutrient
{
    int proteina = 0;
    int carbohidrat = 0;
    int grasime = 0;
public:
    //int get_proteina() { return proteina;}
    //int get_carbohidrat() { return carbohidrat;}
    //int get_grasime() { return grasime;}
    Macronutrient(int proteine_, int carbohidrati_, int grasimi_){ proteina = proteine_; carbohidrat = carbohidrati_; grasime = grasimi_;}
    friend std::ostream& operator<<(std::ostream &out,const Macronutrient& other)
    {
        out << "proteine:" << other.proteina << " " << ",carbohidrati:" << other.carbohidrat << " " << ",grasimi:" << other.grasime << "\n";
        return out;
    }
};

class Aliment
{
    std::string denumire;
    Macronutrient Macronutrienti;
    Micronutrient Micronutrienti;
public:
    Aliment(const std::string &denumire, Macronutrient macronutrient, Micronutrient micronutrient) : denumire(denumire), Macronutrienti(macronutrient),
                                                                                                     Micronutrienti(micronutrient) {}
    //std::string get_denumire(){return denumire;}
    Aliment(const Aliment& other) : denumire(other.denumire), Macronutrienti(other.Macronutrienti), Micronutrienti(other.Micronutrienti){}
    Aliment& operator=(const Aliment& other)
    {
        denumire = other.denumire;
        Macronutrienti = other.Macronutrienti;
        Micronutrienti = other.Micronutrienti;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream &out,const Aliment& other)
    {
        out << "Aliment:" << other.denumire << " " << other.Macronutrienti << " " << other.Micronutrienti << "\n";
        return out;
    }


    ~Aliment(){}
};


int main()
{

    Macronutrient macronutrient1(22, 2, 1);
    Micronutrient micronutrient1(4, 5);
    Aliment aliment1("piept de pui", macronutrient1, micronutrient1);
    std::cout << aliment1;
    //std::cout << "Alimentul " << aliment1.get_denumire();

    //std::cout << " contine la 100 de grame de produs: " << macronutrient1.get_proteina() << "g de proteine, ";
    //std::cout << macronutrient1.get_carbohidrat() << "g de carbohidrati, ";
    //std::cout << macronutrient1.get_grasime() << "g de grasimi, ";
    //std::cout << micronutrient1.get_vitamine() << " vitamine si ";
    //std::cout << micronutrient1.get_minerale() << " minerale";
    Macronutrient macronutrient2(1, 2, 3);
    Micronutrient micronutrient2(1, 2);
    Aliment aliment2("ceva", macronutrient2, micronutrient2);
    std::cout << aliment2;
    aliment2 = aliment1;
    std::cout << aliment2;
    //Macronutrient macronutrient2(macronutrient1);
    //Micronutrient micronutrient2(micronutrient1);
    //std::cout << aliment1;
    //std::cout << macronutrient1;
    //std::cout << micronutrient1;
    //std::cout << aliment2;
    //std::cout << macronutrient2;
    //std::cout << micronutrient2;



    return 0;
}