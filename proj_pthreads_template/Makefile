# define a variable to contain all of our object files (if this list changes, we only need to change the variable)

objects = source/gol.o source/cells.o source/display.o
# define a variable for our include directory
include = includes
# specify a search path for all prerequisites; looks for .o, .c or .h files in ./ or source/ or includes/

VPATH = source:includes
# provide a parameter for our implicit compilation rule (for gcc)
CFLAGS = -I$(include)
# our project will be called proj_pthreads_template, and it LINKS object files gol_config.o, cells.o and display.o

proj_pthreads_template : $(objects)
	gcc -o proj_pthreads_template $(objects) -lpthread -lncurses
# compile golconfig.c to produce gol.o, if needed
gol.o : gol.c gol_config.h cells.h display.h

# compile , cells.c if needed
cells.o : source/cells.c cells.h gol_config.h

# compile display.c, if needed
display.o : display.c display.h gol_config.h
# a clean option that will remove proj_ and any object files, with EXTRA features now!

.PHONY : clean # declaring clean as "phony" prevents it from being ignored if a file named "clean" happens to exist in the directory!

clean :
	-rm proj_pthreads_template $(objects)
# ^
# |_______ with the "-" in front of rm, the rm command will continue to execute in spite of any errors generated (such as "file does not exist") 



