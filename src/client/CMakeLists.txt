
set(lib_client_target client_static)

# Generate header files from dia UML files
generate_dia_header("${CMAKE_CURRENT_SOURCE_DIR}/../client.dia")
generate_dia_header("${CMAKE_CURRENT_SOURCE_DIR}/../render.dia")

# Find all source files to include in library
file(GLOB_RECURSE client_sources *.cpp)
list(REMOVE_ITEM client_sources "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

# Build the "client" library, add required include and link against dependencies
add_library(${lib_client_target} STATIC ${client_sources} render/GlobalParametersDisplay.cpp render/MenuDisplay.cpp render/SceneManager.cpp render/PlayerScoreDisplay.cpp render/BoardDisplay.cpp render/PopupBadge.cpp render/TexturePool.cpp render/Textured.cpp render/EventHandler.cpp render/BadgeScene.cpp render/PayScene.cpp render/CardScene.cpp render/MainScene.cpp render/SharedContext.cpp render/PlaceTileScene.cpp render/PopupPay.cpp)
add_dependencies(${lib_client_target} generate-headers)
target_include_directories(${lib_client_target} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${SFML_INCLUDE_DIR}
  ${jsoncpp_include_dir}
  )
target_link_libraries(${lib_client_target} PUBLIC
  ${SFML_LIBRARIES}
  $<TARGET_NAME:shared_static>
  )

# Compile "client" executable
set(client_target client)
add_executable(${client_target} main.cpp client/test.cpp render/Text.cpp render/Button.cpp render/StdProjectDisplay.cpp render/PopupCard.cpp render/BaseScene.cpp)
target_link_libraries(${client_target} ${lib_client_target})
if(BUILD_CODE_COVERAGE)
  add_dependencies(code-coverage ${client_target})
endif()

# vim: set sw=2 sts=2 et: