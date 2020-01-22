project(Engine LANGUAGES CXX)

file(GLOB_RECURSE ENGINE_SOURCE "*.hpp" "*.cpp")
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ENGINE_SOURCE})

add_library(Engine SHARED ${ENGINE_SOURCE})

target_include_directories(Engine
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(Engine PRIVATE ENGINE_LIBRARY)

set_target_properties(
  Engine PROPERTIES
  CXX_STANDARD 11
  CXX_STANDARD_REQUIRED ON
)
