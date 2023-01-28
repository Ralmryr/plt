//
// Created by arthur on 19/12/22.
//

#include "HeuristicAI.h"
#include <algorithm>

//adjacency score value for deciding placement on board (see finBestPosition)
#define FOREST_ADJACENCY_VALUE_C 10
#define OCEAN_ADJACENCY_VALUE 2
#define CITY_ADJACENCY_VALUE_F 10
#define CARD_BONUS_PLACEMENT 4
#define IRON_BONUS_PLACEMENT 2
#define TITANIUM_BONUS_PLACEMENT 3
#define PLANT_BONUS_PLACEMENT 1

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
    Coord.first = 100; //initially set the coord to an impossible value to detect later
    //if the coordinate have already been set or not

    std::map<std::pair<int, int>, int> adjacency;
    //provide a placement score to interesting coordonate depending on the type of tile the ai
    //is trying to place.
    //select the coordonate with the highest score at the end
    //except for the reserved tile which go to their corresponding spot



    //calculate the best adjacency for oceans first
    //as it will be taken into account for every type of tile

    for (const auto &adjTile: listTile) {
        if (adjTile.getType() == state::OCEAN) {
            std::vector<state::Tile> neighbour = board->getNeighbors(adjTile.getCoords());
            for (int j = 0; j < (int) listTile.size(); j++) {
                auto it = adjacency.find(neighbour[j].getCoords());
                if (it == adjacency.end()) {
                    adjacency.insert({neighbour[j].getCoords(), 1});
                } else
                    it->second += OCEAN_ADJACENCY_VALUE;
            }
        }
    }

    if (tile == state::FOREST) { ///A FINIR !!!!!!!!!!!!!!!!!!!!!
        //il faut encore detecter uniquement les cite qui appartiennent au joueur
        //look for your cities on the board
        //return the coord adjacent to the most of your cities

        for (int i = 0; i < listTile.size(); i++) {
            if (listTile[i].getType() == state::CITY /*&& listOwner[i]==state.get*/) {
                std::vector<state::Tile> neighbour = board->getNeighbors(listTile[i].getCoords());
                for (int j = 0; j < listTile.size(); j++) {
                    auto it = adjacency.find(neighbour[j].getCoords());
                    if (it == adjacency.end()) {
                        if(listOwner[i]==state->getCurrentPlayer()->getId())
                            adjacency.insert({neighbour[j].getCoords(), CITY_ADJACENCY_VALUE_F});
                        else
                            adjacency.insert({neighbour[j].getCoords(), -CITY_ADJACENCY_VALUE_F});
                    } else {
                        if (listOwner[i] == state->getCurrentPlayer()->getId())
                            it->second += CITY_ADJACENCY_VALUE_F;
                        else
                            it->second -= CITY_ADJACENCY_VALUE_F;
                    }
                }
            }
        }
    }

    else if (tile == state::CITY) {
        //look for any forest on the board
        for (const auto &adjTile: listTile) {
            if (adjTile.getType() == state::FOREST) {
                std::vector<state::Tile> neighbour = board->getNeighbors(adjTile.getCoords());
                for (int j = 0; j < (int) listTile.size(); j++) {
                    auto it = adjacency.find(neighbour[j].getCoords());
                    if (it == adjacency.end()) {
                        adjacency.insert({neighbour[j].getCoords(), FOREST_ADJACENCY_VALUE_C});
                    } else
                        it->second += FOREST_ADJACENCY_VALUE_C;
                }
            }
        }
    }

    else if (tile == state::CAPITAL) {
        //look for any forest and ocean on the board
        for (const auto &adjTile: listTile) {
            if (adjTile.getType() == state::FOREST || adjTile.getType() == state::OCEAN) {
                std::vector<state::Tile> neighbour = board->getNeighbors(adjTile.getCoords());
                for (int j = 0; j < listTile.size(); j++) {
                    auto it = adjacency.find(neighbour[j].getCoords());
                    if (it == adjacency.end()) {
                        adjacency.insert({neighbour[j].getCoords(), FOREST_ADJACENCY_VALUE_C});
                    } else
                        it->second += FOREST_ADJACENCY_VALUE_C;
                }
            }
        }
    }

    else if (tile == state::NOCTIS || tile == state::GANYMEDE || tile == state::PHOBOS) {
        //place on reserved tile
        for (const auto &key: board->getListReserved()) {
            if (key.second == tile)
                Coord = key.first;
        }
    }

    else if (tile == state::OCEAN) {
        //only keep the adjacency scores for tiles that are reserved for ocean
        std::map<std::pair<int, int>, int> oceanAdjacency;
        for (const auto &key: board->getListReserved()) {
            if (key.second == tile){
                auto it = adjacency.find(key.first);
                if(it == adjacency.end()){
                    oceanAdjacency.insert({key.first,0});
                }
                else{
                    oceanAdjacency.insert({key.first,adjacency[key.first]});
                }
            }
        }
        auto best = std::max_element(oceanAdjacency.begin(), oceanAdjacency.end(),
                                     [](const auto &x, const auto &y) { return x.second < y.second; });
        Coord = best->first;
    }

    else {
        //find best authorized placement bonus
    }

    //check at least one valid adjacency has been found, or that coord haven t been set already
    if (Coord.first == 100) {
        if (!adjacency.empty()) {
            //find the highest adjacency among the score calculated previously
            auto best = std::max_element(adjacency.begin(), adjacency.end(),
                                         [](const auto &x, const auto &y) { return x.second < y.second; });
            Coord = best->first;
        }else{
            bool isValid = false;
            while (!isValid) {
                Coord.first = rand() % 9 - 4;
                Coord.second = rand() % 9 - 4;
                if (state->getBoard()->isPossibleToPlaceTile(Coord,tile))
                    isValid = true;
            }
        }
    }
    return Coord;
}