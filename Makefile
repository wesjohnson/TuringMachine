all: tm

tm: deffile.cpp defreader.cpp environment.cpp finalstates.cpp inputalphabet.cpp tape.cpp transition.cpp transitionfunction.cpp turingmachine.cpp utilities.cpp main.cpp states.cpp tapealphabet.cpp strreader.cpp strfile.cpp
	g++ deffile.cpp defreader.cpp environment.cpp finalstates.cpp inputalphabet.cpp tape.cpp transition.cpp transitionfunction.cpp turingmachine.cpp utilities.cpp main.cpp states.cpp tapealphabet.cpp strreader.cpp strfile.cpp -o tm

clean: 
	rm -f *.o *.swp tm
