// Abdul Rahman Azam
// 23k-0061

#include <iostream>
#include <vector>
using namespace std;

class Pet {
    private:
    string healthStatus;
    int hungerLevel;
    int happinessLevel;
    string specialSkill[5];

    public:
    Pet(){
        healthStatus = "Healthy";
        hungerLevel = 3;
        happinessLevel = 3;
        specialSkill[0] = "none";
    }

    void displayPetDetails(){
        cout << "health Status = " << this->healthStatus 
        << "\nHappiness Level = " << this->happinessLevel
        << "\nHunger Level = " << this->hungerLevel
        << "\nspecial Skills " << endl;

        for(int i=0; i< specialSkill->length(); i++){
            cout << "\t" << specialSkill[i] << endl;
        }
    }

    void updateHappiness(){
        if(hungerLevel <= 5){
            this->happinessLevel--;
        }else if(hungerLevel == 10){
            cout << "Happiness level is 100% max" << endl;
        }else
            this->happinessLevel++;
    }

    void updateHealth(string healthStatus){
        this->healthStatus = healthStatus;
    }
    
    void updateHunger(int hunger){
        this->hungerLevel = hunger;
    }
};

class Adopter{
    private:
    string adopterName;
    int adopterMobileNum;
    vector<Pet*> adoptedPetRecords;

    public:
    //constructor
    Adopter(string adopterName, int adopterMobileNum){
        this->adopterName = adopterName;
        this->adopterMobileNum = adopterMobileNum;
    }

    void adoptPet(Pet& obj){
        adoptedPetRecords.push_back(&obj);
    }

    void returnPet(){
        adoptedPetRecords.pop_back();
    }

    void displayAdoptedPets(){
        for(Pet* petinfo : adoptedPetRecords){
            petinfo->displayPetDetails();
            cout << endl;
        }
    }
};

int main(){
    Pet cat, dog, monkey;
    Adopter a1("Abdul Rahman Azam", 03163677527);

    
    a1.adoptPet(cat);
    a1.adoptPet(dog);
    

    cat.updateHunger(6);
    cat.updateHealth("Healthy");
    cat.updateHappiness();
    
    dog.updateHunger(2);
    dog.updateHealth("Sick");
    dog.updateHappiness();

    a1.displayAdoptedPets();
}
