#include "State.h"
#include <iostream>

using namespace state;
using namespace std;


State::State(int Players) {
    //Instantiate all players
    nbPlayers=Players;
    for (int i = 0; i < nbPlayers; i++) {
        listPlayers.push_back(make_shared<Player>(i));
    }
    currentPlayer = 0;
    board = make_shared<Board>();
    globalParameters = make_shared<GlobalParameters>();
    deck = make_shared<Deck>(120);

    nbGeneration=1;
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
    currentPlayer = (currentPlayer+1)%nbPlayers;
    actionCount = 0;
}

void State::forceEndTurn() {
    getCurrentPlayer()->setForcedEndTurn(true);
    nextPlayer();
}

int State::getNbPlayers() const {
    return nbPlayers;
}


