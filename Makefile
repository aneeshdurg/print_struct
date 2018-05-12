all: print_struct

source_files: print_struct.c
print_struct.c:
	./py_processor.py print_struct.pyp.h print_struct.pyp.c

print_struct: source_files
	gcc print_struct.c -o print_struct

clean:
	rm -rf print_struct.c print_struct.h print_struct
