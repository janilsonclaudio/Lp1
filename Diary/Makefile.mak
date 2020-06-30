main.o: main.cpp
    g++ -I include -std=c++11 -c main.cpp
diary.o: diary.cpp
    g++ -I include -std=c++11 -c diary.cpp
time.o: time.cpp
    g++ -I include -std=c++11 -c time.cpp
diary: main.o diary.o time.o
    g++ -I include -std=c++11 -o main.o diary.o time.o