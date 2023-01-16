#include "BadgeScene.h"

using namespace std;
using namespace render;

void render::BadgeScene::update(const std::unordered_map<std::string, std::string> &data) {
    popupBadge->update(data);
}

void render::BadgeScene::draw(sf::RenderWindow &window) {
    popupBadge->draw(window);
}

render::BadgeScene::BadgeScene() {
    popupBadge = make_unique<PopupBadge>();
}

std::vector<std::shared_ptr<Button>> BadgeScene::getListButtons() {
    return popupBadge->getListButtons();
}

BadgeScene::~BadgeScene() = default;


