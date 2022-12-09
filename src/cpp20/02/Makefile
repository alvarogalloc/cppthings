EXE = linked_list
MODULE = modules/Mylist.pcm
MODULE_SRC = modules/MyList.cpp

all: module app

module:
	clang++ -Wall -std=c++20 -fimplicit-modules -fimplicit-module-maps -fmodules-cache-path=modules-cache -c ${MODULE_SRC}  -Xclang -emit-module-interface -o ${MODULE}

app: module
	clang++ -Wall -std=c++20 -fimplicit-modules -fimplicit-module-maps  -fmodules-cache-path=modules-cache -fprebuilt-module-path=modules main.cpp ${MODULE_SRC} -o $(EXE)

clean:
	-rm $(EXE) ${MODULE}
