src = $(wildcard *.cpp) \
	$(wildcard geometry/*.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = -std=c++17

ero: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) ero
