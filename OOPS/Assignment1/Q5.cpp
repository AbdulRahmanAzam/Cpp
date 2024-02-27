#include <iostream>
using namespace std;

class User;
class BOGOCoupon;

class Restaurant {
    private:
    string name;
    string location;
    string menuList[3];
    float prices[3];
    int validCouponCodesList[15];
    static int couponsRedeemedCount;
    
    public : 
    
        Restaurant(string name, string location) : name(name), location(location) {}
        
        static const int totalMenu=3;
        
        void setMenuAndprices(string menu1, string menu2, string menu3, float price1, float price2, float price3) {
           menuList[0] = menu1,
           menuList[1] = menu2,
           menuList[2] = menu3;
           prices[0] = price1,
           prices[1] = price2,
           prices[2] = price3;
        }
        
        void displayMenu() {            
            for(int i = 0; i < totalMenu; i++) {

                cout << "Menu " << i+1 << " : " << menuList[i] << endl;
            }
        }
        
        float generateBill() {
            return 1;
        }
        
        float applyDiscount() {
            return 1;
        }
};

class BOGOCoupon {
    private:
    string couponCode,  restaurantCode;
    float validFrom, validUntil;
   
   // here uses friend class learned from GFG
    friend class User ;

    public: 
    // default constructor
    BOGOCoupon(){};

    // parametrized contructor
    BOGOCoupon(string CouponCode, float ValidFrom, float ValidUntil, string RestaurantCode) : couponCode(CouponCode) , validFrom(ValidFrom), validUntil(ValidUntil), restaurantCode(RestaurantCode){}

        bool isValid(float time) {
            if(validFrom< time && time<validUntil){
                return 1;
            }else{
                return 0;
            }
        }
};

class User {
    private:
    string name;
    string redeem_coupon_list[15];
    BOGOCoupon couponsList[15];
    int age;
    int mobileNumber;
    
    public : 
    // default constructor
    User(){}
    // parametrizedd constructor
    User(string name,int age,int mobileNumber): name(name), age(age), mobileNumber(mobileNumber){}

        int counter =0;
        void accumulateCoupon() {
            string coupon_code;  
            string restaurant_code;
            float valid_from; 
            float valid_until;

            cout<<"Enter restaurent code :";
            cin>>restaurant_code;
            cout<<"Enter Coupon code :";
            cin>>coupon_code;
            cout<<"Enter valid From :";
            cin>>valid_from;
            cout<<"Enter valid Until :";
            cin>>valid_until;

            couponsList[counter].restaurantCode  = restaurant_code;
            couponsList[counter].couponCode  = coupon_code;
            couponsList[counter].validFrom  = valid_from;
            couponsList[counter].validUntil  = valid_until;

            if(hasValidCoupon(couponsList[counter], coupon_code) && redeemCoupon(coupon_code)){

                cout<<"COUPON IS VALID  "<<endl;
                counter++;
            }
            
        }
        
        bool hasValidCoupon(BOGOCoupon &BOGOCoupo, string coupan) { 
            if(coupan[0] == BOGOCoupo.restaurantCode[0] && coupan[1] == BOGOCoupo.restaurantCode[1] ){
                return 1;
            }else{
                cout<<"Code doesnt matches with the restaurant code "<<endl;
                return 0;
            }
        }
        
        bool redeemCoupon(string redeemCoupon) {
            for(int i=0;i<counter;i++)
                if(redeemCoupon == redeem_coupon_list[i]) 
                    return 0;
            
            redeem_coupon_list[counter] = redeemCoupon ;
            return 1;
        }
};

int main() {
    
    Restaurant R1("Food Haven", "City Center"), R2("Pixel Bites", "Cyber street");
    R1.setMenuAndprices("Sushi","Pad Thai","Mango Tango",120.0,540.5,3455.8);
    R2.setMenuAndprices("Binary Burger", "Pastasss", "Amini",340.0,560.0,760.5);


    cout<<"Menu of Food Heaven"<< endl;
    R1.displayMenu();
    cout<<"Menu of Pixel Bites"<< endl;
    R2.displayMenu();
    User u1,u2;

    u1 =  User("Abdul Rahman Azam", 10, 867);
    u2 =  User("Talha Rusman", 30, 283);
    u1.accumulateCoupon();
    u2.accumulateCoupon();
    return 0;
}
