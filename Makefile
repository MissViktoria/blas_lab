CC = gcc
CFLAGS = -Wall -fPIC -O2
LDFLAGS = -L. -lbadblas -lsqlite3 -lm
RPATH = -Wl,-rpath,/app

# Сборка библиотеки BLAS
blas: libbadblas.so

libbadblas.so: bad_cblas.o
	$(CC) -shared -o $@ $^

bad_cblas.o: bad_cblas.c bad_cblas.h
	$(CC) $(CFLAGS) -c bad_cblas.c

# Сборка интерфейсных тестов
tests: bad_tests

bad_tests: bad_tests.c libbadblas.so
	$(CC) -o $@ bad_tests.c -L. -lbadblas -lsqlite3 -lm $(RPATH)

# Сборка тестов производительности
perf: perf_tests

perf_tests: perf_tests.c libbadblas.so
	$(CC) -o $@ perf_tests.c -L. -lbadblas -lm $(RPATH)

clean:
	rm -f *.o *.so bad_tests perf_tests

.PHONY: blas tests perf clean