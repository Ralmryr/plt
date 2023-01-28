#include "EventDetails.h"

using namespace std;

engine::EventDetails::EventDetails(engine::EventType eventType) {
    this->eventType = eventType;
}

engine::EventDetails::~EventDetails() {

}

engine::EventDetails &engine::EventDetails::addInfo(const std::string& key, int value) {
    detailsMap.insert({key, value});
    return *this;
}

int engine::EventDetails::getValue(const std::string& key) {
    return detailsMap[key];
}

std::map<std::string, int> engine::EventDetails::getAllValues() {
    return detailsMap;
}

engine::EventType engine::EventDetails::getEventType() const {
    return this->eventType;
}

int &engine::EventDetails::operator[](const string &key) {
    return this->detailsMap[key];
}
