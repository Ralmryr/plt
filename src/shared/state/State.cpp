#include "State.h"
#include <iostream>

using namespace state;
using namespace std;


State::State(int Players) {
    //Instantiate all players
    nbPlayers = Players;
    for (int i = 0; i < nbPlayers; i++) {
        listPlayers.push_back(make_shared<Player>(i));
    }
    currentPlayer = 0;
    board = make_shared<Board>();
    globalParameters = make_shared<GlobalParameters>();
    deck = make_shared<Deck>(120);

    nbGeneration = 1;
}

State::~State() {

}

void State::hookEventSender(std::shared_ptr<EventSender> eventSender) {
    board->setEventSender(eventSender);
}

const std::vector<std::shared_ptr<Player>> &State::getListPlayers() const {
    return this->listPlayers;
}

const std::shared_ptr<GlobalParameters> &State::getGlobalParameters() const {
    return this->globalParameters;
}

const std::shared_ptr<Board> &State::getBoard() const {
    return this->board;
}

std::shared_ptr<Player> State::getSpecificPlayer (int idPlayer) const {
    return this->listPlayers[idPlayer];
}

const std::shared_ptr<Deck>& State::getDeck() const{
    return this->deck;
}

const std::shared_ptr<Player>& State::getCurrentPlayer() const {
    return listPlayers[currentPlayer];
}

void State::increaseActionCount() {
    actionCount++;
    if (actionCount == 2) {
        nextPlayer();
    }
}

void State::nextPlayer() {
    bool allPlayersEnded = false;
    int tempNextPlayer = (currentPlayer+1)%nbPlayers;

    // If the player already ended its turn by force, it is the turn of the next player
    while(listPlayers[tempNextPlayer]->getForcedEndTurn()) {
        tempNextPlayer = (tempNextPlayer+1)%nbPlayers;
        // If the next player to play is the one after the current player, it means that everyone has played its final round
        if(tempNextPlayer == (currentPlayer+1)%nbPlayers) {
            allPlayersEnded = true;
            break;
        }
    }

    if(allPlayersEnded) {
        endGeneration();
    }
    else {
        currentPlayer = tempNextPlayer;
    }

    actionCount = 0;
}

void State::forceEndTurn() {
    getCurrentPlayer()->setForcedEndTurn(true);
    nextPlayer();
}

int State::getNbPlayers() const {
    return nbPlayers;
}

void State::endGeneration() {
    for(const auto& player : listPlayers) {
        player->setForcedEndTurn(false);
        player->getResourceBoard().produceResources();
    }
    currentPlayer = 0;
    nbGeneration += 1;
}

int State::getNbGeneration() const {
    return nbGeneration;
}


