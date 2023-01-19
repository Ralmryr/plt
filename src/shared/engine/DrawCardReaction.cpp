#include "DrawCardReaction.h"

using namespace engine;
using namespace std;
using namespace state;


DrawCardReaction::DrawCardReaction (const state::State& state, int idPlayer){
    this->player= state.getSpecificPlayer(idPlayer);
    this->deck= state.getDeck();
    this->reactionType=engine::DrawCard;
}

DrawCardReaction::~DrawCardReaction () = default;


void DrawCardReaction::execute (){
    CardReader cardReader;
    int idCard = deck->drawCard();
    cardReader.parseCardInfo(idCard);
    auto newCard = make_shared<Card>(idCard, cardReader.getCost(), cardReader.getListBadges());
    player->getCardsHand().addCard(newCard);
}

string DrawCardReaction::query (){
    if (deck->getSize()!=0)
        return "";
    else return "No more cards";
}
void DrawCardReaction::procNotification (){

}
