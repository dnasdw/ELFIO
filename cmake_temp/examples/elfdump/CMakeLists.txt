
add_executable(elfdump ../../../examples/elfdump/elfdump.cpp)
target_link_libraries(elfdump PRIVATE elfio::elfio)
