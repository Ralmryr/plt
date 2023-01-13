#include "BaseScene.h"

void render::BaseScene::setTransparent(bool transparent) {
    this->transparent = transparent;
}

bool render::BaseScene::getTransparent() const {
    return transparent;
}

render::BaseScene::BaseScene() {
    transparent = false;
}

render::BaseScene::~BaseScene() = default;
