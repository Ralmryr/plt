//
// Created by ismail on 04/10/22.
//

#include "ProjectCard.h"

state::ProjectCard::ProjectCard(std::string name, int cost, std::string type, std::vector<Badge> badges)
    : ProjectStd(name, cost), type(type), badge(badges) {

}

state::ProjectCard::~ProjectCard() {

}
