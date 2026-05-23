FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    libsqlite3-dev \
    sqlite3 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Копируем все файлы
COPY bad_cblas.c bad_cblas.h Makefile bad_tests.c perf_tests.c run_tests.sh /app/

# Делаем скрипт запуска исполняемым
RUN chmod +x /app/run_tests.sh

# Собираем библиотеку BLAS
RUN make -f Makefile blas

# Собираем тесты
RUN make -f Makefile tests
RUN make -f Makefile perf

# Запускаем тесты при старте контейнера
CMD ["/app/run_tests.sh"]