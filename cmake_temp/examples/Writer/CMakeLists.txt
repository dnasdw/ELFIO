
add_executable(Writer ../../../examples/Writer/Write.cpp)
target_link_libraries(Writer PRIVATE elfio::elfio)
