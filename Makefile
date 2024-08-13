# CC = g++
# CFLAGS =  -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_image.framework/Headers -I/Library/Frameworks/SDL2_ttf.framework/Headers -I/Library/Frameworks/SDL2_mixer.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer

# all: main

# main: main.cpp game.cpp bird.cpp game.h pipe.h bird.h
# 	$(CC) $(CFLAGS) main.cpp game.cpp bird.cpp -o main

# clean:
# 	rm -f main

CC = g++
CFLAGS =  -I/Library/Frameworks/SDL2.framework/Headers \
          -I/Library/Frameworks/SDL2_image.framework/Headers \
          -I/Library/Frameworks/SDL2_ttf.framework/Headers \
          -I/Library/Frameworks/SDL2_mixer.framework/Headers \
          -F/Library/Frameworks \
          -framework SDL2 \
          -framework SDL2_image \
          -framework SDL2_ttf \
          -framework SDL2_mixer \
          -Wl,-rpath,/Library/Frameworks

all: main

main: main.cpp game.cpp bird.cpp game.h pipe.h bird.h
	$(CC) $(CFLAGS) main.cpp game.cpp bird.cpp -o main

clean:
	rm -f main
