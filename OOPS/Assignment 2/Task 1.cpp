#include <iostream>
using namespace std;

class SecurityTool{
    public:
    string securityLevel;
    float cost;
    int no_of_devices;
    
    SecurityTool(string securityLevel, float cost, int no_of_devices) : no_of_devices(no_of_devices) {
        if(securityLevel == "High" || securityLevel == "Medium" || securityLevel == "Low"){
            this->securityLevel = securityLevel;
        }else{
            this->securityLevel = "High";
        }

        if(cost >= 0){
            this->cost = cost;
        }else {
            this->cost = 0;
        }
    };

    void performScan(){
        cout << "Generic Security scan " << endl;
    }
};

class FirewallTool : public SecurityTool{
    public:
    int ports[100];
    string protocols[100];
    int count = 0;

    FirewallTool(string securityLevel, float cost, int no_of_devices) : SecurityTool(securityLevel, cost, no_of_devices) {
        if(no_of_devices > 10){
            cout << "A firewall can simultaneously run on only 10 devices" << endl;
            this->no_of_devices = 10;
        }
    }

    void generateList(){
        for(int i=0; i<24; i++){
            ports[i] = 6 + i;
        }
        cout << "Port List is generated" << endl;
        cout << "Port numbers are allowed in the range of " << 6 << " to " << 6 + 23;

        cout << "Protocol list only allows traffic from HTTPS, FTP, UDP, ICMP, SSH, SNMP" << endl;
    } 

    void performScan(){
        if(securityLevel == "High"){
            cout << "The traffic from port list and protocol list is allowed" << endl;

        }else if( securityLevel == "Medium"){
            cout << "The traffic from port list and protocol list is allowed with the next two ports" << endl;
            for(int i=25; i<25 + 2; i++) ports[i] = 6 + i;

        }else if(securityLevel == "Low"){
            cout << "The traffic from port list and protocol list is allowed with the next five ports" << endl;
            for(int i=25; i<25 + 5; i++) ports[i] = 6 + i;

            cout << "TCP and DNS protocol" << endl;
        }
    }
};

int main() {
    FirewallTool tool1("Low", 2500, 25),
    tool2("Medium", 10000,12),
    tool3("High", 25000, 8);

    tool1.performScan();
    tool2.performScan();
    tool3.performScan();


    return 0;
}
