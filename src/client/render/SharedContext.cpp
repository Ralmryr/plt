
#include "SharedContext.h"

#include <utility>

using namespace std;
using namespace render;

SharedContext::SharedContext(shared_ptr<SceneManager> sceneManager, shared_ptr<engine::EventManager> eventManager) :
                             sceneManager(std::move(sceneManager)), eventManager(std::move(eventManager)) {

}

std::shared_ptr<engine::EventManager> SharedContext::getEventManager() {
    return eventManager;
}

std::shared_ptr<SceneManager> SharedContext::getSceneManager() {
    return sceneManager;
}

SharedContext::~SharedContext() = default;


