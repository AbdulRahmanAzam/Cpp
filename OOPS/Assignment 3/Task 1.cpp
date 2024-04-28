#include <iostream>
using namespace std;

class Medicine{
    private:
    string name;
    string formula;
    float retailPrice;
    string manufactureDate;
    string expirationDate;

    public:
    Medicine(string name, string formula, float retailPrice, string manufactureDate, string expirationDate) :
    name(name), formula(formula), retailPrice(retailPrice), manufactureDate(manufactureDate), expirationDate(expirationDate) {}
    Medicine(){

    }

    void setname(string name){
        this->name = name;
    }
    void setformula(string formula){
        this->formula = formula;
    }
    void setretailPrice(float retailPrice){
        this->retailPrice = retailPrice;
    }
    void setManufactureDate(string manufactureDate){
        this->manufactureDate = manufactureDate;
    }
    void setexpirationDate(string expirationDate){
        this->expirationDate = expirationDate;
    }

    string getname(){
        return this->name;
    }
    string getformula(){
        return this->formula;
    }
    float getretailPrice(){
        return this->retailPrice;
    }
    string getManufactureDate(){
        return this->manufactureDate;
    }
    string getexpirationDate(){
        return this->expirationDate;
    }

    bool operator==(const Medicine& other) {
        return this->expirationDate.substr(0,4) == other.expirationDate.substr(0,4);
    }

    virtual void displayDetails(){
        cout << "Name " << this->name << endl
        << "Formula " << this->formula << endl
        << "Retail Price " << this->retailPrice << endl
        << "Manufacture Date " << this->manufactureDate << endl
        << "Expiration Date " << this->expirationDate << endl ;
    }
};

class Tablet : public Medicine{
    private:
    float sucroseLevel;

    public:
    Tablet(float sucroseLevel ,string name, string formula, float retailPrice, string manufactureDate, string expirationDate) : 
    Medicine(name, formula, retailPrice, manufactureDate, expirationDate), sucroseLevel(sucroseLevel) {}

    void displayDetails() override {
        cout << "sucrose Level " << sucroseLevel << endl;
    }
};

class Capsule : public Medicine {
    private:
    short unsigned absorptionPercentage;

    public:
    Capsule(short unsigned absorptionPercentage, string name, string formula, float retailPrice, string manufactureDate, string expirationDate) :
    Medicine(name, formula, retailPrice, manufactureDate, expirationDate), absorptionPercentage(absorptionPercentage) {}

    void displayDetails() override {
        cout << "Absorption Percentage " << this->absorptionPercentage << endl;
    }
};

class Syrup : public Medicine {
    private:

    public:
    Syrup(string name, string formula, float retailPrice, string manufactureDate, string expirationDate) :
    Medicine(name, formula, retailPrice, manufactureDate, expirationDate) {}

    void displayDetails() override {
   
    }
};

class Pharmacist {
    private:

    public:
    void Search_Medicine(const string& formula, Medicine* medicines, int size){
        for(int i =0; i < size; ++i){
            if(medicines[i].getformula() == formula){
                medicines[i].displayDetails();
            }
        }
    }
};

class Counter{
    private:
    float totalRevenue;

    public:
    Counter() : totalRevenue(0.0) {}
    void Search_Medicine(const string& name, Medicine* medicine, int size){
        for(int i=0; i < size; ++i){
            if(medicine[i].getname() == name){
                medicine[i].displayDetails();
            }
        }
    }
    void Update_Revenue(float revenue){
        totalRevenue += revenue;
    }
};

int main(){
    Medicine med1("Panadol", "form1", 20.5, "2024 04 15", "2024 07 20");
    Tablet tab1(0.65, "tablet 1", "form1", 65, "2024 04 15", "2026 07 20");
    Capsule cap1(75 , "Panadol", "form2", 90, "2024 04 15", "2027 07 20");
    Syrup syr1("syrup 1", "form2", 200, "2024 04 15", "2024 07 20");

    Medicine* medicines[] = {&med1, &tab1, &cap1, &syr1};
    int size = 4;

    Pharmacist pharmacist;
    Counter counter;

    pharmacist.Search_Medicine("form1", *medicines, size);
    counter.Search_Medicine("Panadol", *medicines, size);
    counter.Update_Revenue(5050);
}
