TARGET = programa
CXXFLAGS := -Wall -Wextra -Werror
LDFLAGS  := -lstdc++ -lm -std=c++03

all: $(TARGET)

$(TARGET): main.cpp
	g++ $(CXXFLAGS) -o $(TARGET) main.cpp $(LDFLAGS)

clean:
	rm -f $(TARGET)

run:
	./$(TARGET)

r: clean all run

i:
	cat input.txt | ./$(TARGET)