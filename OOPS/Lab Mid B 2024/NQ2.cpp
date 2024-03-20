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
    Movie* movies;
    int NumMovies;
    
    Playlist(const string& name) : name(name) {}
    
    void addMovie(Movie* movie){
        Movie newmovie = new Movie*[4];
        movies[NumMovies] = *movie;
        NumMovies++;
    }
    void removeMovie(Movie* movie){
        movies[NumMovies];
        NumMovies--;
    }
    void displayInfo() const{
        cout << "movies" << endl;
        for(int i=0; i< NumMovies ; i++){
            cout << "movie name = " << movies[i].title << endl;
        }
    }
};

class User{
    public:
    string name;
    Playlist* playlist;
    int numPlaylists = 0;
    
    User(const string& name) : name(name){}
    
    void createPlaylist(const string& playlistName){
        playlist[numPlaylists].name = playlistName;
        numPlaylists++;
    }
    void addMovietoPlaylist(Playlist* playlist, Movie* movie){
        playlist[numPlaylists].addMovie(movie);
        numPlaylists++;
    }
    void removeMovieFromPlaylist(Playlist* playlist, Movie* movie){
        playlist[numPlaylists].removeMovie(movie);
        numPlaylists--;        
    }
    void displayUserPlaylists(){
        cout << "Playlists " << endl;
        for(int i=0; i<numPlaylists; i++){
            cout << "user playlist = " << playlist[i].name;
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

    Playlist play1("Action Movies"),
    play2("Comedy Movies");

    a1.createPlaylist("Action Movies");

    // play1.addMovie(&a);
    // play1.addMovie(&b);

    a1.addMovietoPlaylist(&play1, &a);
    a1.addMovietoPlaylist(&play1, &b);

    a1.displayUserPlaylists();
}








