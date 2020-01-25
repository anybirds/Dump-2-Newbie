project(Scene LANGUAGES CXX)

file(GLOB_RECURSE SCENE_SOURCE "*.hpp" "*.cpp")
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SCENE_SOURCE})

add_library(Scene SHARED ${SCENE_SOURCE})

target_link_libraries(Scene PUBLIC Custom)

target_include_directories(Scene
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(Scene PRIVATE SCENE_LIBRARY)

set_target_properties(
  Scene PROPERTIES
  CXX_STANDARD 11
  CXX_STANDARD_REQUIRED ON
)
