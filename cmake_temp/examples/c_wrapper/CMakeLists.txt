
add_executable(c_example ../../../examples/c_wrapper/c_example.c ../../../examples/c_wrapper/elfio_c_wrapper.cpp ../../../examples/c_wrapper/elfio_c_wrapper.h)
target_link_libraries(c_example PRIVATE elfio::elfio)
