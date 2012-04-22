all: tm

tm: transition.cpp main.cpp
	g++ transition.cpp main.cpp -o tm
