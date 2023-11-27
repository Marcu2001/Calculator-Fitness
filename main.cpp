#include <iostream>
#include <vector>
#include <fstream>

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
    Meniu(Aliment const &aliment, int gramaj) : aliment(aliment), gramaj(gramaj) {}
    int get_gramaj () const{return gramaj;}
    Aliment get_aliment(){return aliment;}
    friend std::ostream& operator<<(std::ostream &out, const Meniu& other)
    {
        out << "Aliment: " << other.aliment.get_denumire() << "\n";
        out << "Gramaj: " << other.gramaj << "g" << "\n";
        out << "Kcal: " << other.aliment.get_Kcal() << "\n";
        out << "Proteine: " << other.aliment.get_macronutrient().get_proteina() * ( other.gramaj * 0.01) << "g" << "\n";
        out << "Carbohidrati: " << other.aliment.get_macronutrient().get_carbohidrat() * ( other.gramaj * 0.01) << "g" << "\n";
        out << "Grasimi: " << other.aliment.get_macronutrient().get_grasime() * ( other.gramaj * 0.01) << "g" << "\n";
        out << "Vitamine: " << other.aliment.get_micronutrient().get_vitamine() << "\n";
        out << "Minerale: " << other.aliment.get_micronutrient().get_minerale() << "\n";

        return out;
    }

};


int main() {
    std::vector<Meniu> Meniu;
    std::vector<Aliment> DATABASE;
    std::ifstream fin("Tastatura.txt");
    //std::cout << "Cate alimente vreau sa introduc in meniu?" << "\n";
    int x;
    fin >> x;
    for (int i = 0; i < x; i++) {
        std::string denumire;
        fin >> denumire;
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
    int total_kcal = 0;
        for (int i = 0; i < x; i++)
        {
            std::cout << Meniu[i] << "\n";
            total_proteine += Meniu[i].get_aliment().get_macronutrient().get_proteina() * (Meniu[i].get_gramaj() * 0.01);
            total_grasimi += Meniu[i].get_aliment().get_macronutrient().get_grasime() * (Meniu[i].get_gramaj() * 0.01);
            total_carbohidrati += Meniu[i].get_aliment().get_macronutrient().get_carbohidrat() * (Meniu[i].get_gramaj() * 0.01);
            total_kcal += Meniu[i].get_aliment().get_Kcal() * (Meniu[i].get_gramaj() *0.01);
        }
        std::cout << "Total Proteine: " << total_proteine << "g" << "\n";
        std::cout << "Total Carbohidrati: " << total_carbohidrati << "g" << "\n";
        std::cout << "Total Grasimi: " << total_grasimi << "g" << "\n";
        std::cout << "Total Kcal: " << total_kcal << "kcal" << "\n";

        return 0;
    }