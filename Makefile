all: tm

tm: transition.cpp main.cpp
	g++ environment.cpp tape.cpp transition.cpp transitionfunction.cpp turingmachine.cpp main.cpp -o tm

clean: 
	rm -f *.o *.swp tm
