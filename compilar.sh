#!/bin/bash
find . -maxdepth 1 -name '*.cpp' -execdir g++ -o trem '{}' -lGL -lGLU -lglut \;
./trem
