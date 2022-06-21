# cpp-benchmark-example

Experimental benchmark C++ use.

## Usage

Generate the build files and select configuration for release builds:

```console
❯ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
# ...
```

Build in release configuration (and in parallel):

```console
❯ cmake --build build --config Release --parallel 4
[ 17%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/benchmark_register.cc.o
[ 17%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/benchmark_api_internal.cc.o
[ 17%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/benchmark.cc.o
[ 17%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/benchmark_name.cc.o
[ 21%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/benchmark_runner.cc.o
[ 26%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/colorprint.cc.o
[ 30%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/commandlineflags.cc.o
[ 34%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/complexity.cc.o
[ 39%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/console_reporter.cc.o
[ 43%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/counter.cc.o
[ 47%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/csv_reporter.cc.o
[ 52%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/json_reporter.cc.o
[ 56%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/reporter.cc.o
[ 65%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/sleep.cc.o
[ 65%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/statistics.cc.o
[ 69%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/string_util.cc.o
[ 73%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/sysinfo.cc.o
[ 78%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark.dir/timers.cc.o
[ 82%] Linking CXX static library libbenchmark.a
[ 82%] Built target benchmark
[ 91%] Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o
[ 91%] Building CXX object CMakeFiles/benchmark_example.dir/main.cpp.o
[ 95%] Linking CXX static library libbenchmark_main.a
[ 95%] Built target benchmark_main
[100%] Linking CXX executable benchmark_example
[100%] Built target benchmark_example
```

Execute the benchmark:

```console
❯ build/benchmark_example
Unable to determine clock rate from sysctl: hw.cpufrequency: No such file or directory
2022-06-21T22:29:06+02:00
Running build/benchmark_example
Run on (8 X 24.0925 MHz CPU s)
CPU Caches:
  L1 Data 64 KiB (x8)
  L1 Instruction 128 KiB (x8)
  L2 Unified 4096 KiB (x8)
Load Average: 1.41, 1.67, 1.76
-------------------------------------------------------------
Benchmark                   Time             CPU   Iterations
-------------------------------------------------------------
tribonacci            3919389 ns      3918949 ns          177
tribonacci_iter           108 ns          108 ns      6578762
tribonacci_dynamic       1676 ns         1676 ns       492022
```

## Status

Experimental

**Note**: The default branch is `default`.
