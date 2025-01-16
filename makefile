all :
	g++ -I src/include -Lsrc/lib -o main main.cpp -lSDL2 -lSDL2_image

run :
	.\main