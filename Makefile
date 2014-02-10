CCOMP = g++

FLAGS = -lopencv_core -lopencv_highgui -lopencv_imgproc -L/usr/local/lib -L.

DIR = $(PWD)/orl_faces

Faces: main.cpp
	$(CCOMP) main.cpp -o Faces $(FLAGS)
	
	
run: Faces
	./Faces $(DIR)


clean:
	rm -f Faces 

