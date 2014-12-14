
GRAPH = gnuplot

CC = gcc
CFLAGS = -Wall -O3 
LFLAGS = -O3
LIBS = -lgsl -lm 

se: se.o mc_se.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

res1: se
	./se > res1
	
se.png: se.gpl res1
	$(GRAPH) se.gpl

clean:
	rm -f *.o *~ mc-se

veryclean: clean
	rm -f res se.png 
