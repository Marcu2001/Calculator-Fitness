#include <iostream>
#include <vector>
#include <fstream>


class Micronutrient
{
    int vitamine = 0;
    int minerale = 0;
public:
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
    float proteina = 0;
    float carbohidrat = 0;
    float grasime = 0;
public:
    float get_proteina() const { return proteina;}
    float get_carbohidrat() const { return carbohidrat;}
    float get_grasime() const { return grasime;}
    Macronutrient(float proteine_, float carbohidrati_, float grasimi_){ proteina = proteine_; carbohidrat = carbohidrati_; grasime = grasimi_;}
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
    float Kcal;
public:
    Aliment(const std::string &denumire, Macronutrient macronutrient, Micronutrient micronutrient) : denumire(denumire), Macronutrienti(macronutrient), Micronutrienti(micronutrient) {
        Kcal =  Macronutrienti.get_proteina() * 4 + Macronutrienti.get_carbohidrat() * 4 + Macronutrienti.get_grasime() * 9;
    }
    Macronutrient get_macronutrient() const {return Macronutrienti;}
    Aliment(const Aliment& other) : denumire(other.denumire), Macronutrienti(other.Macronutrienti), Micronutrienti(other.Micronutrienti), Kcal(other.Kcal){}
    Aliment& operator=(const Aliment& other)
    {
        denumire = other.denumire;
        Macronutrienti = other.Macronutrienti;
        Micronutrienti = other.Micronutrienti;
        Kcal = other.Kcal;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream &out,const Aliment& other)
    {
        out << "Aliment:" << other.denumire <<"\n" << other.Macronutrienti << other.Micronutrienti << "\n" << "Kcalorii: " << other.Kcal << "\n";
        return out;
    }
    friend std::istream& operator>>(std::istream &in, Aliment& other)
    {
        in >> other.denumire >> other.Macronutrienti >> other.Micronutrienti >> other.Kcal;
        return in;
    }
    ~Aliment(){}
};

class Jurnal {
    std::vector<Aliment> aliment;
    std::vector<float> gramaj;
    float total_proteine = 0, total_carbohidrati = 0, total_grasimi = 0, total_kcal = 0;
    std::string data;
public:
    Jurnal() = default;
    void set_aliment(Aliment x) {aliment.push_back(x);}
    void set_gramaj(float x) {gramaj.push_back(x);}
    friend std::ostream &operator<<(std::ostream &out, const Jurnal &other) {
        out << "Total proteine: " << other.total_proteine << "\n";
        out << "Total carbohidrati: " << other.total_carbohidrati << "\n";
        out << "Total grasimi: " << other.total_grasimi << "\n";
        out << "Total Kcal: " << other.total_kcal << "\n";

        return out;
    }
    void Calculare_Macros(int nr_alimente)
    {
        for(int i = 0; i < nr_alimente; i++)
        {
            total_proteine = total_proteine + aliment[i].get_macronutrient().get_proteina() * (gramaj[i] * 0.01);
            total_carbohidrati = total_carbohidrati + aliment[i].get_macronutrient().get_carbohidrat() * (gramaj[i] * 0.01);
            total_grasimi = total_grasimi + aliment[i].get_macronutrient().get_grasime() * (gramaj[i] * 0.01);
        }
        total_kcal = total_proteine * 4 + total_carbohidrati * 4 + total_grasimi * 9;
    }
};

int main() {
    std::ifstream fin("tastatura.txt");
    int nr_alimente;
    Jurnal Jurnal1;
    std::vector<Aliment> DATABASE;
    fin >> nr_alimente;

    for(int i = 0; i < nr_alimente; i++)
    {
        std::string denumire;
        float proteine, carbohidrati, grasimi;
        int vitamine, minerale;
        fin >> denumire >> proteine >> carbohidrati >> grasimi >> vitamine >> minerale;
        DATABASE.push_back({denumire, {proteine, carbohidrati, grasimi}, {vitamine, minerale}});
    }

    for(int i = 0; i < nr_alimente; i++)
       std::cout << DATABASE[i] << "\n";

    int nr_alimente_astazi;
    std::cin >> nr_alimente_astazi;
    for(int i = 0 ; i < nr_alimente_astazi; i++)
    {
        int alege_aliment;
        float gramaj;
        std::cin >> alege_aliment >> gramaj;
        Jurnal1.set_aliment(DATABASE[alege_aliment]);
        Jurnal1.set_gramaj(gramaj);
    }
    Jurnal1.Calculare_Macros(nr_alimente_astazi);
    std::cout << Jurnal1;

    return 0;
}