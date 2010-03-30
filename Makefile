OBJS = obj/main.o obj/render.o obj/world.o
INC = -I/home/reed/arcane/opengl/glutclass/glclasses
CC = g++
CFLAGS = -O3
TARGET = lens

lens: $(OBJS)
	g++ -o $(TARGET) $(OBJS) -lglut

obj/%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) -MM -MT 'obj/'$*.o $(CFLAGS) $(INC) $*.cpp > obj/$*.d


# pull in dependency info for *existing* .o files
-include $(shell mkdir obj 2>/dev/null) $(OBJS:.o=.d)


.PHONY: clean
clean:
	rm obj/* $(TARGET)
