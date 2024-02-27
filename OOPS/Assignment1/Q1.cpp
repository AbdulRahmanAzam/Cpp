// Abdul Rahman Azam
// 23k-0061
// took little bit help form geek for geek
#include <iostream>
#include <vector>
using namespace std;

class Pet {
private:
    string name;
    string healthStatus;
    int hungerLevel;
    int happinessLevel;
    string specialSkills;

public:
    // Default constructor
    Pet() {
        healthStatus = "Healthy";
        hungerLevel = 3;
        happinessLevel = 3;
    }

    // Parameterized constructor
    Pet(string name, string healthStatus, int hungerLevel, int happinessLevel,string specialSkills) {
        this->name = name;
        this->healthStatus = healthStatus;
        this->happinessLevel = happinessLevel;
        this->hungerLevel = hungerLevel;
        this->specialSkills = specialSkills;
    }

    void displayPetDetails() {
        cout << "Name: " << name << endl;
        cout << "Health Status: " << healthStatus << endl;
        cout << "Happiness Level: " << happinessLevel << endl;
        cout << "Hunger Level: " << hungerLevel << endl;
        cout << "Special Skills:" << specialSkills;
    }

    void updateHappiness() {
        if (hungerLevel <= 5) {
            happinessLevel--;
        } else if (hungerLevel >= 10) {
            cout << "Happiness level is at maximum." << endl;
        } else {
            happinessLevel++;
        }
    }

    void updateHealth(string healthStatus) {
        this->healthStatus = healthStatus;
    }

    void updateHunger(int hunger) {
        hungerLevel = hunger;
    }
};

class Adopter {
private:
    string adopterName;
    int adopterMobileNum;
    vector<Pet*> adoptedPetRecords;

public:
    Adopter(string adopterName, int adopterMobileNum) {
        this->adopterName = adopterName;
        this->adopterMobileNum = adopterMobileNum;
    }

    void adoptPet(Pet* obj) {
        cout << adopterName << " with mobile number " << adopterMobileNum << " is adopting a pet." << endl;
        adoptedPetRecords.push_back(obj);
    }

    void returnPet() {
        if (!adoptedPetRecords.empty()) {
            cout << adopterName << " is returning the adopted pet." << endl;
            adoptedPetRecords.pop_back();
        } else {
            cout << "No pet to return." << endl;
        }
    }

    void displayAdoptedPets() {
        if (adoptedPetRecords.empty()) {
            cout << adopterName << " has not adopted any pets yet." << endl;
        } else {
            cout << adopterName << "'s adopted pets:" << endl;
            for (Pet* pet : adoptedPetRecords) {
                pet->displayPetDetails();
                cout << endl;
            }
        }
    }
};

int main() {
    vector<Pet> pets;
    vector<Adopter> adopters;

    while (true) {
        cout << "\nVirtual Pet Adoption System\n"
             << "1. Add Pet\n"
             << "2. Display all Pets\n"
             << "3. Adopt a Pet\n"
             << "4. Return a Pet\n"
             << "5. Display all adopted Pets\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, healthStatus;
                int hungerLevel, happinessLevel;
                string specialSkills;

                cout << "Enter pet details:" << endl;
                cout << "Name: ";
                cin >> name;
                cout << "Health Status: ";
                cin >> healthStatus;
                cout << "Hunger Level: ";
                cin >> hungerLevel;
                cout << "Happiness Level: ";
                cin >> happinessLevel;

                int numSkills;
                cout << "Enter special skills:" << endl;
                    cin >> specialSkills;
        

                Pet newPet(name, healthStatus, hungerLevel, happinessLevel, specialSkills);
                pets.push_back(newPet);
                break;
            }
            case 2: {
                cout << "\nAll Pets:" << endl;
                for (Pet& pet : pets) {
                    pet.displayPetDetails();
                    cout << endl;
                }
                break;
            }
            case 3: {
                if (!pets.empty()) {
                    cout << "Enter adopter details:" << endl;
                    string name;
                    int mobileNum;
                    cout << "Name: ";
                    cin >> name;
                    cout << "Mobile Number: ";
                    cin >> mobileNum;
                    Adopter newAdopter(name, mobileNum);

                    cout << "Enter index of pet to adopt: ";
                    int index;
                    cin >> index;
                    if (index >= 0 && index < pets.size()) {
                        newAdopter.adoptPet(&pets[index]);
                        adopters.push_back(newAdopter);
                    } else {
                        cout << "Invalid index." << endl;
                    }
                } else {
                    cout << "No pets available for adoption." << endl;
                }
                break;
            }
            case 4: {
                if (!adopters.empty()) {
                    int index = adopters.size() - 1;
                    adopters[index].returnPet();
                } else {
                    cout << "No adopters." << endl;
                }
                break;
            }
            case 5: {
                for (Adopter& adopter : adopters) {
                    adopter.displayAdoptedPets();
                }
                break;
            }
            case 6: {
                cout << "Exiting program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
