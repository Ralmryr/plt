#include "State.h"

using namespace state;
using namespace std;


State::State() {
    //Instantiate all players
    for(int i = 0; i < 5; i++) {
        listPlayers.push_back(make_shared<Player>(i));
    }
    board = make_shared<Board>();
    globalParameters = make_shared<GlobalParameters>();
    uiDataProvider = make_shared<UiDataProvider>();

    // Creates the link between the data provider and the game elements
    uiDataProvider->hookComponents(listPlayers, board, globalParameters);
}

State::~State() {

}

const std::shared_ptr<UiDataProvider> &State::getUiDataProvider() const {
    return this->uiDataProvider;
}
