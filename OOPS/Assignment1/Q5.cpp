#include <iostream>
using namespace std;

class Restaurant {
    private:
    string restaurant_name;
    string location;
    string menu_list[10];
    float price_list[10];
    int valid_coupon_codes_list[10];
    static int coupons_redeemed_count;
    
    public:
    void display_menu(){
        
    }
    float generate_bill(){
        
    }
    float apply_discount(){
        
    }
};

class BOGOCoupon {
    private:
    string coupon_code;
    string valid_from;
    string valid_until;
    string restaurant_code;
    
    public:
    bool is_valid(){
        
    }
};

class User {
    private:
    string name;
    int age;
    int mobile_number;
    string coupon_list[10];
    // extra
    BOGOCoupon [10];
    
    public:
    void Accuumulate_coupon(){
        
    }
    bool Has_valid_coupon(){
        
    }
    bool redeem_coupon(){
        
    }
};

int main() {
    
    return 0;
}





