# module
# clang++ -Wall -std=c++2a -fimplicit-modules -fimplicit-module-maps -c ${MODULE_SRC}  -Xclang -emit-module-interface -o ${MODULE} 
# app
# clang++ -Wall -std=c++2a -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=modules main.cpp ${MODULE_SRC} -o $(EXE)
EXE = cpp_modules
MODULE_SRC = modules/example.cpp
APP_SRC = main.cpp
MODULE = modules/example.pcm
MODULE_FLAGS = -stdlib=libc++ -fbuiltin-module-map -fmodules-ts -Xclang -emit-module-interface -c

all: module app traditional

module :
	clang++ -Wall -std=c++2a -fmodules ${MODULE_FLAGS} ${MODULE_SRC} -o ${MODULE}

app : ${MODULE} 
	clang++ -Wall -std=c++2a -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=modules ${APP_SRC} ${MODULE_SRC} -o ${EXE}

traditional:
	clang++ -Wall -std=c++2a traditionalway/main.cpp -o traditional

modern: module app

clean :
	-rm ./$(EXE) ./${MODULE}
