all:
	g++ --std=c++11 main.cpp
	./a.out > test.dot
	#./a.out
	dot -Tpng test.dot -o output.png
	deepin-image-viewer output.png
