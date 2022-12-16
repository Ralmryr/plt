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
    uiDataProvider = make_shared<RenderAPI>();

    // Creates the link between the data provider and the game elements
    uiDataProvider->hookComponents(listPlayers, board, globalParameters);
}

State::~State() {

}

const std::shared_ptr<RenderAPI> &State::getUiDataProvider() const {
    return this->uiDataProvider;
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

const std::shared_ptr<Player> State::getSpecificPlayer (int idPlayer) const {
    return this->listPlayers[idPlayer];
}

const std::shared_ptr<Deck>& State::getDeck() const{
    return this->deck;
}

const std::shared_ptr<Player>& State::getCurrentPlayer() const {
    return listPlayers[currentPlayer];
}
