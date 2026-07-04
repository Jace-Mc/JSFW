RuntimeDir := JSFW-1.0/GLAL/runtime/src
IncludeDir := JSFW-1.0/GLAL
JFWSrc := JSFW-1.0/JSFW/src
JFWinclude := JSFW-1.0
BuildDir := JSFW-1.0/Build

LINUX-BUILD:
	mkdir -p $(BuildDir)/lib
	mkdir -p $(BuildDir)/include

	gcc -c $(JFWSrc)/jsfwcore.c -I$(JFWinclude) -I$(IncludeDir)
	gcc -c $(RuntimeDir)/linuxcore.c -I$(JFWinclude) -I$(IncludeDir)

	ar rcs $(BuildDir)/lib/libjfw1.a jsfwcore.o linuxcore.o

	cp -r $(JFWinclude)/JSFW $(BuildDir)/include/

clean:
	-rm *.o
