CC = 		gcc
SRC_PATH =	src/
BIN_PATH = 	bin/
main = 		$(SRC_PATH)MaitreZombie.c
weapons = 	$(SRC_PATH)knife.c \
		$(SRC_PATH)handgun.c \
		$(SRC_PATH)shotgun.c

src = 		$(main) $(weapons)

all : $(src:.c=)
	-mkdir $(BIN_PATH)
	mv $(src:.c=) $(BIN_PATH)

clean :
	rm $(BIN_PATH)*

