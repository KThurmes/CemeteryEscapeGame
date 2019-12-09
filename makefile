#target: dependencies
#	rule to build
#must use tab for rules

CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#OBJS = *.o
OBJS = main.o Sister.o NPC.o Character.o enterToContinue.o Snack.o getRandomInt.o Empty.o Game.o Ghost.o Fence.o Gravestone.o GameBoard.o Menu.o Gate.o Player.o Space.o getNumberBetween.o Inventory.o Item.o Sheet.o Key.o
SRCS = *.cpp
HEADERS = *.hpp
#LDFLAGS = -lboost_date_time (any libraries you want to link)

proj5: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o proj5

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o proj5

valgrind:
	valgrind -v --leak-check=full proj5
	#--leak-check=full
	#--v --track-origin=yes