#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Movie{
    public:
    string title;
    string director;
    int duration;
    
    Movie(const string& title, const string& director, int duration) : title(title), director(director), duration(duration) {}
    
    string getTitle() const {
        return this->title;
    }
    string getDirector() const {
        return this->director;
    }
    int getDuration() const{
        return this->duration;
    }
};

class Playlist{
    public:
    string name;
    Movie** movies;
    int NumMovies = 0;
    
    Playlist(const string& name) : name(name), movies(nullptr) {
        // movies = new Movie*[200];
    }
    
    void addMovie(Movie* movie){
        Movie** temp = new Movie*[NumMovies + 1];
        
        for(int i=0; i< NumMovies ; i++){
            temp[i] = movies[i];
        }
        temp[NumMovies] = movie;
        delete[] movies;
        movies = temp;
        NumMovies++;
    }
    void removeMovie(Movie* movie){
        
        for(int i=0; i<NumMovies - 1; i++){
            movies[i] = movies[i+1];
        }
        NumMovies--;
    }
    void displayInfo() const{
        cout << "movies" << endl;
        for(int i=0; i< NumMovies ; i++){
            cout << "movie name = " << movies[i]->title << endl;
        }
    }
    // ~Playlist(){
    //     for(int i=0; i<NumMovies; i++){
    //         delete movies[i];
    //     }
    //     delete[] movies;
    // }
};

class User{
    public:
    string name;
    Playlist** playlists;
    int numPlaylists = 0;
    
    User(const string& name) : name(name), playlists(nullptr){
        // playlists = new Playlist*[200];
    }
    
    ~User(){
        for(int i=0; i< numPlaylists ; i++){
            delete playlists[i];
        }
        delete[] playlists;
    }
    
    void createPlaylist(const string& playlistName){
        Playlist** temp = new Playlist*[numPlaylists + 1];
        
        for(int i=0; i< numPlaylists; i++){
            temp[i] = playlists[i];
        }
        temp[numPlaylists] = new Playlist(playlistName);
        
        delete[] playlists;
        playlists = temp;
        numPlaylists++;
        
    }
    void addMovietoPlaylist(Playlist* playlist, Movie* movie){
        for(int i=0; i<numPlaylists ; i++){
            if(playlist->name == playlists[i]->name){
                playlists[i]->addMovie(movie);
                break;
            }
        }
    }
    // void addMovietoPlaylist(const string& playlistName, Movie* movie){
    //     // playlist[numPlaylists].addMovie(movie);
    //     // playlist[numPlaylists]->addMovie(movie);
    //     for(int i=0; i<numPlaylists ; i++){
    //         if(playlistName == playlists[i]->name){
    //             playlists[i]->addMovie(movie);
    //             break;
    //         }
    //     }
    // }
    void removeMovieFromPlaylist(Playlist* playlist, Movie* movie){
        playlist[numPlaylists].removeMovie(movie);
        for(int i=0; i<numPlaylists-1; i++){
            playlists[i] = playlists[i+1];
        }
        numPlaylists--;
    }
    void displayUserPlaylists(){
        cout << "Playlists " << endl;
        for(int i=0; i<numPlaylists; i++){
            playlists[i]->displayInfo();
        }
    }
};

int main(){
    User a1("Mujeeb Rehman");
    // a1.createPlaylist("Action Movies");
    // a1.createPlaylist("Comedy Movies");
    
    Movie a("The Dark Knight", "Christopher Nolan", 60),
    b("Inception","Christopher Nolan", 60),
    c("The Hangover", "Todd Philliphs", 30),
    d("Superbad", "Greg Mottola", 50);
    // Movie* a = new Movie("The Dark Knight", "Christopher Nolan", 60);
    // Movie* b = new Movie("Inception", "Christopher Nolan", 60);

    Playlist play1("Action Movies"),
    play2("Comedy Movies");

    a1.createPlaylist("Action Movies");

    // play1.addMovie(&a);
    // play1.addMovie(&b);
    
    // a1.addMovietoPlaylist("Action Movies", &a);
    // a1.addMovietoPlaylist("Action Movies", &b);

    a1.addMovietoPlaylist(&play1, &a);
    a1.addMovietoPlaylist(&play1, &b);
    
    a1.displayUserPlaylists();
}








