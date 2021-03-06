CC=gcc
CXX=g++
CFLAGS=-I./inc -I/usr/include/libxml2 -O2 -pipe -march=native
CXXFLAGS=
LDFLAGS=
LIB=-lGL -lglut -lGLEW -lxml2

run: bin/main
	./bin/main --verbose
clean:
	rm obj/*
bin/main: obj/bill.o obj/colour.o obj/cylinder.o obj/handler.o obj/hd.o obj/hp.o obj/hs.o obj/lcd.o obj/line.o obj/main.o obj/matrix.o obj/mesh.o obj/poly.o obj/projet.o obj/shader.o obj/sock.o obj/sphere.o obj/sprite.o obj/string.o obj/texture.o obj/vector.o 
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIB)


obj/bill.o: src/bill.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/colour.o: src/colour.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/cylinder.o: src/cylinder.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/handler.o: src/handler.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/hd.o: src/hd.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/hp.o: src/hp.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/hs.o: src/hs.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/lcd.o: src/lcd.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/line.o: src/line.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/matrix.o: src/matrix.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/mesh.o: src/mesh.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/poly.o: src/poly.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/projet.o: src/projet.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/shader.o: src/shader.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/sock.o: src/sock.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/sphere.o: src/sphere.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/sprite.o: src/sprite.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/string.o: src/string.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/texture.o: src/texture.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/vector.o: src/vector.c
	$(CC) $(CFLAGS) -c -o $@ $<


