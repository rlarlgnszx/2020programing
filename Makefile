CC=gcc
CFLAGS=-g -Wall
TARGET=sim.c
#OBJS=

sim2.c :
    gcc -o project_exe sim.2
clean  :
    rm *.o project_exe
