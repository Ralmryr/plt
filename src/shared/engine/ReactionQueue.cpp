#include "ReactionQueue.h"

#include <iostream>

using namespace std;
using namespace engine;

ReactionQueue::ReactionQueue() {
    cout << "Hello from reactionQueue " << endl;
}

ReactionQueue::~ReactionQueue() {

}

void ReactionQueue::addReaction(std::shared_ptr<Reaction> newReaction) {
    reactionQueue.push_back(std::move(newReaction));
}

void ReactionQueue::clearAll() {
    reactionQueue.clear();
    listCheckpoints.clear();
}

void ReactionQueue::clearToLastCheckpoint() {
    int lastCheckpoint = listCheckpoints.back();
    for(int i = lastCheckpoint; i != int(reactionQueue.size()); i++) {
        reactionQueue.pop_back();
    }
}

void ReactionQueue::addCheckpoint() {
    int index = int(reactionQueue.size());
    listCheckpoints.push_back(index);
}

void ReactionQueue::consume() {
    for (int i = int(reactionQueue.size()); i != 0; i--) {
        reactionQueue[i]->execute();
    }
    this->clearAll();
}


