#######################################################################################
# CONFIGURATION
#######################################################################################

# On peut definir des variables de Makefile avec VAR=... et les utiliser avec ${VAR}


GPP=g++ -Wall -std=c++20 -Iincludes -Iincludes/headers -Iincludes/templates
GSL_LIBS=-lgsl -lgslcblas -lm

EXE=./src/main.exe
SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)

# La liste des executables a compiler est mise dans une variable EXE.
# les executables sont en .exe pour pouvoir beneficier de la regle generique de conversion de .o en .exe
EXE=main.exe


#######################################################################################

all: ${EXE} 

#######################################################################################	

# Compilation

# Des classes
%.o:%.cpp %.h
	${GPP} -c -o $@ $<

# Des programmes principaux
%.o:%.cpp
	${GPP} -c -o $@ $<

#######################################################################################

#Links

${EXE}: ${OBJ}
	${GPP} -o $@ ${OBJ} ${GSL_LIBS}

#######################################################################################

clean:
	rm -rf *.o ${EXE} auto_*.dat
