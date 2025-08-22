
add_executable(writer ../../../examples/writer/writer.cpp)
target_link_libraries(writer PRIVATE elfio::elfio)
