#include "State.h"

using namespace state;
using namespace std;


State::State() {
    //Instantiate all players
    for(int i = 0; i < 5; i++) {
        listPlayers.push_back(make_shared<Player>(i));
    }
    currentPlayer = 0;
    board = make_shared<Board>();
    globalParameters = make_shared<GlobalParameters>();
    deck = make_shared<Deck>(20);
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
        actionCount = 0;
        currentPlayer = (currentPlayer+1)%5;
    }
}

void State::endTurn() {
    currentPlayer = (currentPlayer+1)%5;
    actionCount = 0;
}
