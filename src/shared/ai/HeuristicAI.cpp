//
// Created by arthur on 19/12/22.
//

#include "HeuristicAI.h"
#include "../../constants.hpp"
#include <algorithm>

//adjacency score value for deciding placement on board (see finBestPosition)


using namespace ai;
using namespace std;
using namespace engine;



ai::HeuristicAI::HeuristicAI(std::shared_ptr<state::State> state) {
    this->state=std::move(state);
    this->resourceWeightMap =
            {{state::GOLD_PROD,1},
             {state::IRON_PROD,2},
             {state::TITANIUM_PROD,2},
             {state::PLANT_PROD,2},
             {state::ENERGY_PROD,2},
             {state::HEAT_PROD,2},

             {state::GOLD,1},
             {state::IRON,2},
             {state::TITANIUM,2},
             {state::PLANT,2},
             {state::ENERGY,2},
             {state::HEAT,2},

             {state::NT,6},
             {state::PV,5}};
    this->tileWeightMap=
            {{state::FOREST,20},
             {state::CITY,20},
             {state::OCEAN,20},
             {state::MINE,20},
             {state::FORBIDDEN,20},
             {state::MOHOL,20},
             {state::NUKE,20},
             {state::PRESERVED,20},
             {state::ZOO,20},
             {state::COMMERCIAL,20},
             {state::CAPITAL,20},
             {state::INDUSTRY,20},
             {state::NOCTIS,20},
             {state::PHOBOS,20},
             {state::GANYMEDE,20},
             };
    this->otherWeightMap=
            {{"Card",3},
             {"oxygen",10},
             {"temperature",11},};
}

ai::HeuristicAI::~HeuristicAI()= default;

void ai::HeuristicAI::playTurn() {}

int ai::HeuristicAI::chooseBestCard() {
    /*
     * algo a suivre :
     *
     * calcule un score de rentabilité pour toutes les cartes en main
     * calcule la rentabilité des projets std
     * joue la carte/le projet std avec le meilleur score
     *
     * */

    return 0;
}

/*   formule de caclule du score :
     *
     * valeur = bonus de prod * (fonction decroissante des tours de jeu)
     * + bonus instantanée - couts de la carte
     *
     * bonus de prod et instant : chaque ressource a un poid different
     * fonction decroissante : a determiner, varie de ~4 ou 5 à 0.
     *
     * */

bool isProd(const ModifyResourceReaction& reaction){
    if(reaction.getResType()==state::GOLD_PROD
       ||reaction.getResType()==state::IRON_PROD
       ||reaction.getResType()==state::TITANIUM_PROD
       ||reaction.getResType()==state::PLANT_PROD
       ||reaction.getResType()==state::ENERGY_PROD
       ||reaction.getResType()==state::HEAT_PROD)
        return true;
    else
        return false;
}


//parameter of this function may vary for different heuristic AI
//starts >2, tends toward 0
//begin at Nb = 0
//reach 0 around Nb = 12
int decreasingFunction(int NbGeneration){


}

int ai::HeuristicAI::calculateCardScore(int iDcard) {
    int score=0;
    int prodGain=0, instantGain=0, cost=0;
    cardReader->parseCard(iDcard,state);
    std::vector<std::shared_ptr<Reaction>> listGain = cardReader->getInstantReactions();

    //calculate prod_gain :
    //compare all gain from the card to their weight
    //only the modifyRessourceReaction can be prod_gain
    for(const std::shared_ptr<Reaction>& reaction : listGain){
        if(reaction->getReactionType()==engine::ModifyResource){
            auto temp = dynamic_pointer_cast<ModifyResourceReaction>(reaction) ;
            if(isProd(*temp))
                prodGain+=temp->getAmount()* resourceWeightMap[temp->getResType()];
            else
                instantGain +=temp->getAmount()* resourceWeightMap[temp->getResType()];
        }
        else if(reaction->getReactionType()==engine::DrawCard){
            instantGain += otherWeightMap["Card"];
        }
        else if(reaction->getReactionType()==engine::IncreaseGP){
            auto temp = dynamic_pointer_cast<IncreaseGPReaction>(reaction) ;
            instantGain +=temp->getAmount()* otherWeightMap[temp->getParamName()];

        }
        else if(reaction->getReactionType()==engine::PlaceTile){
            auto temp = dynamic_pointer_cast<engine::PlaceTileReaction>(reaction) ;
            instantGain += tileWeightMap[temp->getTileType()];

            //instantGain+=CARD_INSTANT_GAIN;
        }
    }

    cost=cardReader->getCost();
    if(!cardReader->checkCondition(iDcard,state))
        cost+=1000;

    score = prodGain* decreasingFunction(1)+instantGain-cost;


    return score;
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

    if (tile == state::FOREST) {
        //look for your cities on the board
        //return the coord adjacent to the most of your cities

        for (int i = 0; i < listTile.size(); i++) {
            if (listTile[i].getType() == state::CITY /*&& listOwner[i]==state.get*/) {
                std::vector<state::Tile> neighbour = board->getNeighbors(listTile[i].getCoords());
                for (int j = 0; j < listTile.size(); j++) {
                    auto it = adjacency.find(neighbour[j].getCoords());
                    if (it == adjacency.end()) {
                        if(listOwner[i]==player->getId())
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


