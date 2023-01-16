#include "PayScene.h"

using namespace std;
using namespace render;

render::PayScene::PayScene() {
    popupPay = make_unique<PopupPay>();
    transparent = true;
}

void render::PayScene::update(const std::unordered_map<std::string, std::string> &data) {
    popupPay->update(data);
}

void render::PayScene::draw(sf::RenderWindow &window) {
    popupPay->draw(window);
}

std::vector<std::shared_ptr<Button>> PayScene::getListButtons() {
    return popupPay->getListButtons();
}

PayScene::~PayScene() = default;


