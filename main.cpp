#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

class Micronutrient
{
    int vitamine = 0;
    int minerale = 0;
public:
    int get_vitamine() const {return vitamine;}
    int get_minerale() const {return minerale;}
    Micronutrient(int vitamine_, int minerale_){vitamine = vitamine_; minerale = minerale_;}
    friend std::ostream& operator<<(std::ostream &out,const Micronutrient& other)
    {
        out << "Vitamine: " << other.vitamine << "\n" << "Minerale: " << other.minerale;
        return out;
    }
    friend std::istream& operator>>(std::istream &in, Micronutrient& other)
    {
        in >> other.vitamine >> other.minerale;
        return in;
    }
};

class Macronutrient
{
    int proteina = 0;
    int carbohidrat = 0;
    int grasime = 0;
public:
    int get_proteina() const { return proteina;}
    int get_carbohidrat() const { return carbohidrat;}
    int get_grasime() const { return grasime;}
    Macronutrient(int proteine_, int carbohidrati_, int grasimi_){ proteina = proteine_; carbohidrat = carbohidrati_; grasime = grasimi_;}
    friend std::ostream& operator<<(std::ostream &out,const Macronutrient& other)
    {
        out << "Proteine: " << other.proteina <<"g"<< "\n" << "Carbohidrati: " << other.carbohidrat << "g" << "\n" << "Grasimi: " << other.grasime << "g" << "\n";
        return out;
    }
    friend std::istream& operator>>(std::istream &in, Macronutrient& other)
    {
        in >> other.proteina >> other.carbohidrat >> other.grasime;
        return in;
    }
};

class Aliment
{
    std::string denumire;
    Macronutrient Macronutrienti;
    Micronutrient Micronutrienti;
    int Kcal = Macronutrienti.get_proteina() * 4 + Macronutrienti.get_carbohidrat() * 4 + Macronutrienti.get_grasime() * 9;
public:
    Aliment(const std::string &denumire, Macronutrient macronutrient, Micronutrient micronutrient) : denumire(denumire), Macronutrienti(macronutrient),
                                                                                                     Micronutrienti(micronutrient) {}
    std::string get_denumire() const {return denumire;}
    Macronutrient get_macronutrient() const {return Macronutrienti;}
    Micronutrient get_micronutrient() const {return Micronutrienti;}
    int get_Kcal() const {return Kcal;}
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
        out << "Aliment:" << other.denumire <<"\n" << other.Macronutrienti << other.Micronutrienti << "\n" << "Kcalorii: " << other.Kcal;
        return out;
    }
    friend std::istream& operator>>(std::istream &in, Aliment& other)
    {
        in >> other.denumire >> other.Macronutrienti >> other.Micronutrienti;
        return in;
    }
    ~Aliment(){}
};

class Meniu
{
    Aliment aliment;
    int gramaj;
public:
    Meniu(Aliment aliment, int gramaj) : aliment(aliment), gramaj(gramaj) {}
    int get_gramaj(){return gramaj;}
    Aliment get_aliment(){return aliment;}
    friend std::ostream& operator<<(std::ostream &out, const Meniu& other)
    {
        out << "Aliment: " << other.aliment.get_denumire() << "\n";
        out << "Gramaj: " << other.gramaj << "g" << "\n";
        out << "Kcal: " << other.aliment.get_Kcal() << "\n";
        out << "Proteine: " << other.aliment.get_macronutrient().get_proteina() * ( other.gramaj / 100) << "g" << "\n";
        out << "Carbohidrati: " << other.aliment.get_macronutrient().get_carbohidrat() * ( other.gramaj / 100) << "g" << "\n";
        out << "Grasimi: " << other.aliment.get_macronutrient().get_grasime() * ( other.gramaj / 100) << "g" << "\n";
        out << "Vitamine: " << other.aliment.get_micronutrient().get_vitamine() << "\n";
        out << "Minerale: " << other.aliment.get_micronutrient().get_minerale() << "\n";

        return out;
    }



};


int main() {
    Micronutrient micronutrient1(4, 5);
    Macronutrient macronutrient1(20, 2, 1);
    Aliment aliment1("Piept de pui", macronutrient1, micronutrient1);
//    std::cout << meniu1;
//    std::cout << "\n";
    Micronutrient micronutrient2(10, 3);
    Macronutrient macronutrient2(4, 20, 1);
    Aliment aliment2("Portocala", macronutrient2, micronutrient2);
    //Meniu meniu2(aliment2, 300);
    //std::cout << meniu2;

    std::vector<Meniu> Meniu;
    std::vector<Aliment> DATABASE;

    std::ifstream fin("Tastatura.txt");

    //std::cout << "Cate alimente vreau sa introduc in meniu?" << "\n";
    int x;
    fin >> x;
    for (int i = 0; i < x; i++) {
        std::string denumire{"Aliment_"};
        int proteine;
        fin >> proteine;
        int carbohidrati;
        fin >> carbohidrati;
        int grasimi;
        fin >> grasimi;
        int vitamine;
        fin >> vitamine;
        int minerale;
        fin >> minerale;
        DATABASE.push_back({denumire, {proteine, carbohidrati, grasimi}, {vitamine, minerale}});
    }

    for (int i = 0; i < x; i++) {
        //std::cout << DATABASE[i] << "\n" "\n";
        int gramaj;
        fin >> gramaj;
        Meniu.push_back({DATABASE[i], gramaj});
    }
    int total_proteine = 0;
    int total_carbohidrati = 0;
    int total_grasimi = 0;
        for (int i = 0; i < x; i++)
        {
            //std::cout << Meniu[i] << "\n";
            total_proteine += Meniu[i].get_aliment().get_macronutrient().get_proteina() * (Meniu[i].get_gramaj() / 100);
            total_grasimi += Meniu[i].get_aliment().get_macronutrient().get_grasime() * (Meniu[i].get_gramaj() / 100);
            total_carbohidrati += Meniu[i].get_aliment().get_macronutrient().get_carbohidrat() * (Meniu[i].get_gramaj() / 100);
        }
        std::cout << total_proteine << "\n";
        std::cout << total_carbohidrati << "\n";
        std::cout << total_grasimi << "\n";





//    for(int i = 0; i < 2; i++)
//    {
//        Meniu.push_back({aliment1, 200});
//        Meniu.push_back({aliment2, 400});
//    }
//
//    for(int i = 0; i < 2; i++)
//        std::cout << Meniu[i] << "\n" << "\n";



//    Macronutrient macronutrient1(22, 2, 1);
//    Micronutrient micronutrient1(4, 5);
//    Aliment aliment1("piept de pui", macronutrient1, micronutrient1);
//    std::cout << aliment1;
//    //std::cout << "Alimentul " << aliment1.get_denumire();
//
//    //std::cout << " contine la 100 de grame de produs: " << macronutrient1.get_proteina() << "g de proteine, ";
//    //std::cout << macronutrient1.get_carbohidrat() << "g de carbohidrati, ";
//    //std::cout << macronutrient1.get_grasime() << "g de grasimi, ";
//    //std::cout << micronutrient1.get_vitamine() << " vitamine si ";
//    //std::cout << micronutrient1.get_minerale() << " minerale";
//    Macronutrient macronutrient2(1, 2, 3);
//    Micronutrient micronutrient2(1, 2);
//    Aliment aliment2("ceva", macronutrient2, micronutrient2);
//    std::cout << aliment2;
//    aliment2 = aliment1;
//    std::cout << aliment2;
//    //Macronutrient macronutrient2(macronutrient1);
//    //Micronutrient micronutrient2(micronutrient1);
//    //std::cout << aliment1;
//    //std::cout << macronutrient1;
//    //std::cout << micronutrient1;
//    //std::cout << aliment2;
//    //std::cout << macronutrient2;
//    //std::cout << micronutrient2;
//    Micronutrient *micro;
//    for(int i = 0; i < 2; i++)
//        std::cin >> micro[i];
//    for(int i = 0; i < 2; i++)
//        std::cout << micro[i];


        return 0;
    }