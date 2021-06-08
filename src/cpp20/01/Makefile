EXE = main

all:
	${module}
	${main}
module:
	clang++ -Wall -std=c++2a -fimplicit-modules -fimplicit-module-maps -c helloworld.cpp  -Xclang -emit-module-interface -o modules/helloworld.pcm

main:
	clang++ -Wall -std=c++2a -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=modules main.cpp helloworld.cpp -o $(EXE)

clean:
	-rm $(EXE)
