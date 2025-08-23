
add_executable(c_example ../../../examples/c_interop/c_example.c ../../../examples/c_interop/elfio_c_interop.cpp ../../../examples/c_interop/elfio_c_interop.h)
target_link_libraries(c_example PRIVATE elfio::elfio)
