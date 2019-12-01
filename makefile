#target: dependencies
#	rule to build
#must use tab for rules

CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
OBJS = main.o Character.o Empty.o Game.o GameBoard.o Menu.o Player.o Space.o getNumberBetween.o 
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