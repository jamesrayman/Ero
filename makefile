src = $(wildcard *.cpp) \
	$(wildcard geometry/*.cpp) \
	$(wildcard *.tpp) \
	$(wildcard geometry/*.tpp)
obj = $(src:.c=.o)

LDFLAGS = -std=c++17

euclid: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) euclid
