# Target: test.exe

test.exe: test.obj add_i.obj
	bcc32 test.obj add_i.obj

test.obj: add_i.c
	bcc32 -c test.c

add_i.obj: test.c
	bcc32 -c add_i.c
