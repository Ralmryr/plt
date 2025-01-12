
set(lib_shared_target shared_static)

# Generate header files from dia UML files
generate_dia_header("${CMAKE_CURRENT_SOURCE_DIR}/../state.dia")
generate_dia_header("${CMAKE_CURRENT_SOURCE_DIR}/../engine.dia")
generate_dia_header("${CMAKE_CURRENT_SOURCE_DIR}/../ai.dia")

# Find all source files to compile into a library
file(GLOB_RECURSE shared_sources *.cpp)

# Build the "shared" library and add required includes
add_library(${lib_shared_target} STATIC ${shared_sources} ${jsoncpp_sources})
add_dependencies(${lib_shared_target} generate-headers)
target_include_directories(${lib_shared_target} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR} 
        ${jsoncpp_include_dir}
  )

set(shared_target shared)
add_executable(${shared_target} main.cpp main.cpp state/Board.cpp state/Card.cpp state/CardBoard.cpp state/CardsHand.cpp state/GlobalParameters.cpp state/Player.cpp state/ResourceBoard.cpp state/Tile.cpp state/RenderAPI.cpp ../constants.hpp state/State.cpp engine/BadgePlayedListener.cpp engine/DrawCardReaction.cpp engine/Listener.cpp engine/EventManager.cpp engine/IncreaseGPReaction.cpp engine/ModifyResourceReaction.cpp engine/PlaceTileReaction.cpp engine/Reaction.cpp engine/ReactionQueue.cpp engine/TilePlacedListener.cpp state/EventSender.cpp engine/EventDetails.cpp engine/CardReader.cpp ai/AI.cpp ai/BasicAI.cpp ai/HeuristicAI.cpp ai/AdvancedAI.cpp ai)
target_link_libraries(${shared_target} ${lib_shared_target})
if(BUILD_CODE_COVERAGE)
    add_dependencies(code-coverage ${shared_target})
endif()

# vim: set sw=2 sts=2 et: