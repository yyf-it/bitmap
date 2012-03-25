objects=bitmap.o main.o
bitmap : $(objects)
	g++ -o bitmap $(objects)

main.o : bitmap.h
bitmap.o : bitmap.h

.PHONY : clean

clean:
	-rm bitmap $(objects)
