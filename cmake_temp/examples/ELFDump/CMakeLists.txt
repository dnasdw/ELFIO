
add_executable(ELFDump ../../../examples/ELFDump/ELFDump.cpp)
target_link_libraries(ELFDump PRIVATE elfio::elfio)
