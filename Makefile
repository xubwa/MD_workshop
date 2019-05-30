CXXFLAGS = -I$(PWD)
src = main.cc cubic.cc
obj = obj/main.o obj/cubic.o

obj/%.o: src/%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@
all : $(obj)
	$(CXX) $(CXXFLAGS) -o md_workshop $(obj)
clean :
	find . -name "*.o"|xargs rm clean 2>/dev/null;rm -f md_workshop >/dev/null 2>&1
