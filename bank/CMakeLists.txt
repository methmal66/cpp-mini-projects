cmake_minimum_required(VERSION 3.0)
project(bank VERSION 1.0)
add_executable(bank src/main.cpp src/services.cpp src/helps.cpp src/CLI11.hpp)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)