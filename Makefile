all: tm

tm: deffile.cpp defreader.cpp environment.cpp tape.cpp transition.cpp transitionfunction.cpp turingmachine.cpp main.cpp strreader.cpp strfile.cpp
	g++ deffile.cpp defreader.cpp environment.cpp tape.cpp transition.cpp transitionfunction.cpp turingmachine.cpp main.cpp strreader.cpp strfile.cpp -o tm

clean: 
	rm -f *.o *.swp tm
