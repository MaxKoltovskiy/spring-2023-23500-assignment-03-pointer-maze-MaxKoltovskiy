#include "Labyrinth.h"
#include <iostream>
bool isPathToFreedom(MazeCell* start, const std::string& moves, int found) {
    if(start == nullptr) {
        return false; 
    }

    if(start -> whatsHere != Item::NOTHING) {
        found++;
    }

    //std::cout<< found << moves<<"\n";
    if(moves == "" && found == 3) {
        return true;
    } else if(moves == "") {
        return false;
    }
    
    
    //std::cout<< moves[0]<< "\n";
    switch(moves[0]) {
        case 'N':
            return isPathToFreedom(start -> north, moves.substr(1), found);
            break;
        case 'E':
            return isPathToFreedom(start -> east, moves.substr(1), found);
            break;
        case 'S':
            return isPathToFreedom(start -> south, moves.substr(1), found);
            break;
        case 'W':
            return isPathToFreedom(start -> west, moves.substr(1), found);
            break;
    }

    return false;
}
