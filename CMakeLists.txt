cmake_minimum_required(VERSION 3.23)
project(Kursach2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Kursach2 main.cpp Client.h Tarif.h Drive20Tarif.h PlusTarif.h Drive5Tarif.h User.h  Admin.h StudentTarif.h PensionerTarif.h MyException.h)
