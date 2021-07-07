EXE = linked_list
MODULE = modules/Mylist.pcm
MODULE_SRC = modules/MyList.cpp

all: module app

module:
	clang++ -Wall -std=c++2a -fimplicit-modules -fimplicit-module-maps -c ${MODULE_SRC}  -Xclang -emit-module-interface -o ${MODULE}

app:
	clang++ -Wall -std=c++2a -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=modules main.cpp ${MODULE_SRC} -o $(EXE)

clean:
	-rm $(EXE) ${MODULE}
