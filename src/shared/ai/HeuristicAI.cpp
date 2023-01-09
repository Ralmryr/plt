//
// Created by arthur on 19/12/22.
//

#include "HeuristicAI.h"
#include <algorithm>

using namespace ai;
using namespace std;

ai::HeuristicAI::HeuristicAI(std::shared_ptr<state::State> state) {
    this->state=std::move(state);
}

ai::HeuristicAI::~HeuristicAI()= default;

void ai::HeuristicAI::playTurn() {}

int ai::HeuristicAI::chooseBestCard() {
    return 0;
}

std::pair<int, int> ai::HeuristicAI::findBestPosition(state::TileType tile) {
    std::shared_ptr<state::Board> board = state->getBoard();
    std::vector<state::Tile> listTile = board->getListTiles();
    std::vector<int> listOwner = board->getListOwners();
    std::pair<int, int> Coord;
    std::map<std::pair<int,int>,int> adjacency;

    if(tile ==state::FOREST){ ///A FINIR !!!!!!!!!!!!!!!!!!!!!
    //il faut encore detecter uniquement les cite qui appartiennent au joueur
        //look for your cities on the board
        //return the coord adjacent to the most of your cities

        for (int i =0; i < listTile.size(); i++){
            if(listTile[i].getType()==state::CITY /*&& listOwner[i]==state.get*/){
                std::vector<state::Tile> neighbour = board->getNeighbors(listTile[i].getCoords());
                for (int j=0; j <listTile.size();j++){
                    auto it = adjacency.find(neighbour[j].getCoords());
                    if(it==adjacency.end()){
                        adjacency.insert({neighbour[j].getCoords(),1});
                    } else
                        it->second+=1;
                }
            }
        }
        auto best = std::max_element(adjacency.begin(),adjacency.end(),
                                     [](const auto &x, const auto &y)
                                     {return x.second<y.second;});
        Coord=best->first;
    }  //70% done

    else if(tile ==state::CITY  ){
        //look for any forest on the board
        //return the coord adjacent to the most forest

        for (const auto& tile:listTile){
            if(tile.getType()==state::FOREST){
                std::vector<state::Tile> neighbour = board->getNeighbors(tile.getCoords());
                for (int j=0; j <listTile.size();j++){
                    auto it = adjacency.find(neighbour[j].getCoords());
                    if(it==adjacency.end()){
                        adjacency.insert({neighbour[j].getCoords(),1});
                    }
                    else
                        it->second+=1;
                }
            }
        }
        //case where there are no forest on the board
        if(adjacency.empty()){

        }

        //find the highest adjacency
        auto best = std::max_element(adjacency.begin(),adjacency.end(),
                                     [](const auto &x, const auto &y)
                                     {return x.second<y.second;});
        Coord=best->first;
    } //80%

    else if(tile ==state::CAPITAL){
        //look for any forest and ocean on the board
        //return the coord adjacent to the most forest and ocean (ocean priority)
        for (const auto& tile:listTile){
            if(tile.getType()==state::FOREST || tile.getType()==state::OCEAN){
                std::vector<state::Tile> neighbour = board->getNeighbors(tile.getCoords());
                for (int j=0; j <listTile.size();j++){
                    auto it = adjacency.find(neighbour[j].getCoords());
                    if(it==adjacency.end()){
                        adjacency.insert({neighbour[j].getCoords(),1});
                    }
                    else
                        it->second+=1;
                }
            }
        }
        //find the highest adjacency
        auto best = std::max_element(adjacency.begin(),adjacency.end(),
                                     [](const auto &x, const auto &y)
                                     {return x.second<y.second;});
        Coord=best->first;
    }  //80%

    else if(tile ==state::NOCTIS || tile ==state::GANYMEDE || tile ==state::PHOBOS){
        //place on reserved tile
        for(const auto& key : board->getListReserved()){
            if(key.second==tile)
                Coord=key.first;
        }
    } //100%

    else if(tile ==state::OCEAN  ){

    }  //0%

    else {
        //find best authorized placement bonus
    }
    return Coord;
}