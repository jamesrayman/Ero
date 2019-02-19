src = $(wildcard *.cpp) \
	$(wildcard geometry/*.cpp)
obj = $(src:.c=.o)

LDFLAGS = -std=c++17

euclid: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) euclid
