#include <iostream>
using namespace std;

class Post;
class RegularUser;
class BusinessUser;

class User{
    public:
    string username;
    string email;
    string password;

    User(string username, string email, string password) : username(username), email(email) {
        this->password = passwordEncryption(username, password);
    }

    void userVerification(string username, string password){
        password = passwordEncryption(username, password);

        if(this->password == password){
            cout << "user is successfully logged in to the accont" << endl;
        }

    }

    // XOR Encryption Algorithm
    string passwordEncryption(string username, string password){
        string key = username;

        for(int i=0; i<password.length(); i++){ // XOREncryptDecrypt
            password[i] = password[i] ^ key[i % key.length()];
        }
        return password;
    }
};
class Post{
    public:
    int postId;
    string content;
    int likes;
    string comments[100];
    int no_of_comments;
    int views;
    
    Post(int postId, string content) : content(content), postId(postId), likes(0), no_of_comments(0), views(0) {}

    void addingComments(string comment){
        comments[no_of_comments] = comment;
        no_of_comments++;
    }

    void likingposts(){
        likes++;
    }
    void viewing(){
        views++;
    }

    void displaypostdetails(){
        cout << "The post id is = " << postId << endl
        << "content = " << content << endl
        << "likes = " << likes << endl
        << "no of Comments = " << no_of_comments << endl
        << "views = " << views << endl;

        cout << "Comments are: " << endl;
        for(int i=0; i< no_of_comments ; i++){
            cout << comments[i] << endl;
        }
        cout << endl;
     }
};

class RegularUser : public User{
    public:
    int feedSize;
    static const int MAX_FEED_SIZE = 10;
    Post* feed[MAX_FEED_SIZE];

    RegularUser(string username, string email, string password) : User(username, email, password), feedSize(0) {}

    void addToFeed(Post *fe){
        if(feedSize <= 5){
            feed[feedSize] = fe;
            feedSize++;
        }else{
            cout << "Regular User can post a maximum of 5 posts" << endl;
            return;
        }
    }

    void viewFeed(){
        for(int i =0; i< feedSize; i++){
            feed[i]->displaypostdetails();
        }
    }
};

class BusinessUser : public User{
    public:
    int feedSize;
    int promotionLimit = 10;
    static int countpromote;
    static const int MAX_FEED_SIZE = 10;
    Post* feed[MAX_FEED_SIZE];

    BusinessUser(string username, string email, string password) : User(username, email, password) {}

    void promotePost(Post &post){
        if(checkPromotionLimit(post)){
            cout << "Your post is promoted" << endl;
            post.likes = (post.likes)*2;
            post.views = (post.views)*3;
        }
    }
    
    bool checkPromotionLimit(Post &post){
        if(countpromote >= promotionLimit){
            cout << "Can't promote more, the maximum post promotion limit reached" << endl;
            return 0;
        }
        countpromote++;
        return 1;
    }

    void addToFeed(Post* fe){
        if(feedSize <= 10){
            feed[feedSize] = fe;
            feedSize++;
        }else{
            cout << "BUssiness user can post a maximum of 10 posts" << endl;
            return;
        }
    }

    void viewFeed(){
        for(int i =0; i< feedSize; i++){
            feed[i]->displaypostdetails();
        }
    }
};
int BusinessUser::countpromote = 0;

int main(){
    RegularUser r1("AbdulRahmanAzam", "azamabdulrahman930", "saudia"),
    r2("AbdulBasitAzam", "azamabdulbasit", "qatar");

    Post p1(123, "image of cat");


    r1.addToFeed(&p1);
    r1.viewFeed();

    p1.addingComments("impressive cat");
    p1.addingComments("amazing!");

    p1.likingposts();
    r1.viewFeed();

    Post p2(321, "rolls royce"); 
    BusinessUser b1("buser1","bussiness@", "anything");
    b1.addToFeed(&p2);
    b1.promotePost(p2);
    p2.likingposts();
    p2.addingComments("king of luxury");

    b1.viewFeed();
}
