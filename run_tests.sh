#!/bin/bash

echo "=== Running BLAS tests ==="
export LD_LIBRARY_PATH=/app:$LD_LIBRARY_PATH

# Запускаем интерфейсные тесты
./bad_tests

echo ""
echo "=== Running Performance tests ==="
./perf_tests

# echo ""
# echo "=== Test results in database ==="
# sqlite3 /data/results.db "SELECT * FROM blas_tests;"

echo "=== Done ==="