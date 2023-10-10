all: compile link

compile:
	g++ -c main.cpp Tilemap.h -I"C:\Users\Chris\Desktop\coding\SFML-2.6.0\include" -DSFML_STATIC  

link:
	g++ main.o -o main -L"C:\Users\Chris\Desktop\coding\SFML-2.6.0\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

clean:
	rm -f main *.o
	