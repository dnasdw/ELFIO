
add_executable(anonymizer ../../../examples/anonymizer/anonymizer.cpp)
target_link_libraries(anonymizer PRIVATE elfio::elfio)
