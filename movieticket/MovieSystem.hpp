#ifndef MovieSystem_HPP
#define MovieSystem_HPP

#include "User.hpp"
#include "Zone.hpp"
#include "Movie.hpp"



class MovieSystem
{
    vector<User *> users;
    vector<Zone *> zones;
    vector<Movie *> movies;

public:
    MovieSystem() {}

    void addZones();
    void registerUser();
    void addMovies();

};

#endif
