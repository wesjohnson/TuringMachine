all: tm

tm: environment.cpp finalstates.cpp inputalphabet.cpp inputstrings.cpp tape.cpp transition.cpp transitionfunction.cpp turingmachine.cpp utilities.cpp main.cpp states.cpp tapealphabet.cpp
	g++ environment.cpp finalstates.cpp inputalphabet.cpp inputstrings.cpp tape.cpp transition.cpp transitionfunction.cpp turingmachine.cpp utilities.cpp main.cpp states.cpp tapealphabet.cpp -o tm

clean: 
	rm -f *.o *.swp tm
