#include <algorithm>
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

#include <tribonacci.hpp>


std::vector<unsigned> createTestNumbers() {
    std::vector<unsigned> v;
    for (int i=0; i<25; ++i) v.emplace_back(i);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
    return v;
}

void tribonacci(benchmark::State& state) {
    auto numbers = createTestNumbers();
    for (auto _ : state) {
      for (auto v: numbers) benchmark::DoNotOptimize(tribonacci(v));
    }
}
BENCHMARK(tribonacci);

void tribonacci_iter(benchmark::State& state) {
    auto numbers = createTestNumbers();
    for (auto _ : state) {
      for (auto v: numbers) benchmark::DoNotOptimize(tribonacci_iter(v));
    }
}
BENCHMARK(tribonacci_iter);

void tribonacci_dynamic(benchmark::State& state) {
    auto numbers = createTestNumbers();
    for (auto _ : state) {
        for (auto v: numbers) benchmark::DoNotOptimize(tribonacci_dynamic(v));
    }
}
BENCHMARK(tribonacci_dynamic);

BENCHMARK_MAIN();
