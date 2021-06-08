EXE = linked_list

all:
	${module}
	${main}
module:
	clang++ -Wall -std=c++2a -fimplicit-modules -fimplicit-module-maps -c modules/MyList.cpp  -Xclang -emit-module-interface -o modules/MyList.pcm

main:
	clang++ -Wall -std=c++2a -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=modules main.cpp modules/MyList.cpp -o $(EXE)

clean:
	-rm $(EXE)
