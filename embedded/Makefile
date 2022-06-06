
PYLIB=/usr/lib/python3.8/config-3.8-x86_64-linux-gnu/libpython3.8.a
PYINC=-I-I/usr/include -I/usr/include -I/usr/include/python3.8 -I/usr/include/python3.8 
LIBS=-L/usr/lib -lexpat                       -L/usr/lib -lz                       -lexpat -lcrypt -lpthread -ldl  -lutil -lm -lm
OPTS=-DNDEBUG -g -fwrapv -O2 -Wall
PROGRAMS=pystring 
all: $(PROGRAMS)

pystring: pystring.o
	gcc pystring.o $(LIBS) $(PYLIB) -o pystring
pystring.o: pystring.c
	gcc pystring.c -c $(PYINC) $(OPTS)
clean:
	rm -f $(PROGRAMS) *.o *.pyc core
