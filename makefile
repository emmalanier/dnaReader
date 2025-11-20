#######################################################################################
# CONFIGURATION
#######################################################################################

# On peut definir des variables de Makefile avec VAR=... et les utiliser avec ${VAR}

GPP=g++ -Wall -std=c++20 -Iincludes -Iincludes/headers -Iincludes/templates
GSL_LIBS=-lgsl -lgslcblas -lm

EXE=main.exe
SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)

# SQL Section :
LDFLAGS = -lgsl -lgslcblas -lm -lsqlite3 -Iincludes -Iincludes/databases
DB = elements.db molecules.db aminoAcids.db
SQL = ./includes/databases/*.sql


#######################################################################################

all: ${DB} ${EXE}

#######################################################################################	

# Compilation

# Des classes
%.o:%.cpp %.h
	${GPP} -c -o $@ $<

# Des programmes principaux
%.o:%.cpp
	${GPP} -c -o $@ $<

# De la table de données
#${DB}: ${SQL}
#	sqlite3 $@ < $(filter %.sql,$(^))
elements.db: includes/databases/elements.sql
	sqlite3 $@ < $<

molecules.db: includes/databases/molecules.sql
	sqlite3 $@ < $<

aminoAcids.db: includes/databases/aminoAcids.sql
	sqlite3 $@ < $<

#######################################################################################

#Links

${EXE}: ${OBJ}
	${GPP} -o $@ ${OBJ} ${GSL_LIBS} ${LDFLAGS}

#######################################################################################

clean:
	rm -rf *.o ${EXE} auto_*.dat ${DB}
