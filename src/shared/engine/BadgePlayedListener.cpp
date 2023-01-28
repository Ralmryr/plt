#include "BadgePlayedListener.h"

#include <iostream>
#include <utility>

using namespace std;
using namespace engine;


BadgePlayedListener::BadgePlayedListener(const state::State &state, const EventDetails &eventDetails,
                                         std::vector<std::shared_ptr<Reaction>> reactionList) : eventDetails(eventDetails),
                                                                                                reactions(std::move(reactionList)){

}

BadgePlayedListener::~BadgePlayedListener() = default;


std::vector<std::shared_ptr<Reaction>> BadgePlayedListener::onNotify(EventManager &eventManager, EventDetails &eventDetails) {
    return this->reactions;
}
