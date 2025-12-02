CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = ../oscilador_completo
OBJS = main.o funciones.o grafica.o animacion.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp funciones.h grafica.h animacion.h
	$(CXX) $(CXXFLAGS) -c main.cpp

funciones.o: funciones.cpp funciones.h grafica.h animacion.h
	$(CXX) $(CXXFLAGS) -c funciones.cpp

grafica.o: grafica.cpp grafica.h
	$(CXX) $(CXXFLAGS) -c grafica.cpp

animacion.o: animacion.cpp animacion.h
	$(CXX) $(CXXFLAGS) -c animacion.cpp

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f ../resultados/listas/*.txt
	rm -f ../resultados/graficas/*.png
	rm -f ../resultados/gif/*.gif

run: $(TARGET)
	cd .. && ./oscilador_completo

.PHONY: all clean run