# compilador
CXX = g++
# flags do compilador. Esse Wall e para ativar warnings, -std=c++11 diz que precisa ser c++ 11. c++ 11 inventou o nullptr.
CXXFLAGS = -Wall -std=c++11
# source file
SRC = excoin.cpp
OBJ = $(SRC:.cpp=.o)
# executavel
EXEC = excoin.exe

# pesquisei isso aqui pq dava problema no windows pq nao tem rm
ifeq ($(OS),Windows_NT)
    RM = del /f
    RUN = .\\$(EXEC)
else
    RM = rm -f
    RUN = ./$(EXEC)
endif

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# make clean
clean:
	$(RM) $(OBJ) $(EXEC)

# make run
run: $(EXEC)
	$(RUN)
