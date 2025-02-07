# Define o nome do projeto e a versão
cmake_minimum_required(VERSION 3.10)
project(MeuProjeto VERSION 1.0)

# Define o padrão de C++ que queremos usar
set(CMAKE_CXX_STANDARD 11)

# Define o diretório de arquivos de cabeçalho
include_directories(include)

# Adiciona os arquivos fonte ao projeto
add_executable(MeuPrograma src/main.cpp src/contaBancaria.cpp)
