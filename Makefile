CCOMP = g++

FLAGS = -lopencv_core -lopencv_highgui -lopencv_imgproc -L/usr/local/lib -L.

DBDIR = $(PWD)/orl_faces
DIR = $(PWD)

Faces: main.cpp
	$(CCOMP) main.cpp -o Faces $(FLAGS)
	
	
run: Faces
	./Faces $(DBDIR) $(DIR)


clean:
	rm -f Faces 

