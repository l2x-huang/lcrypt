#include "benchmark/benchmark.h"
#include "lcrypt.h"

static const auto k1 = lcrypt::randomkey();
static const auto k2 = lcrypt::randomkey();

static void test_randomkey(benchmark::State& state) {
    for (auto _ : state) {
        lcrypt::randomkey();
    }
}
BENCHMARK(test_randomkey);

static void test_hmac64(benchmark::State& state) {
    for (auto _ : state) {
        lcrypt::hmac64(k1, k2);
    }
}
BENCHMARK(test_hmac64);

static void test_hashkey(benchmark::State& state) {
    for (auto _ : state) {
        lcrypt::hashkey(k1);
    }
}
BENCHMARK(test_hashkey);

static void test_dhexchange(benchmark::State& state) {
    for (auto _ : state) {
        lcrypt::dhexchange(k1);
    }
}
BENCHMARK(test_dhexchange);

static void test_dhsecret(benchmark::State& state) {
    for (auto _ : state) {
        lcrypt::dhsecret(k1, k2);
    }
}
BENCHMARK(test_dhsecret);

static void test_des_encode(benchmark::State& state) {
    for (auto _ : state) {
        lcrypt::des_encode(k1, "abcdefg");
    }
}
BENCHMARK(test_des_encode);

static void test_des_decode(benchmark::State& state) {
    auto r = lcrypt::des_encode(k1, "abcdefg");
    for (auto _ : state) {
        lcrypt::des_decode(k1, r);
    }
}
BENCHMARK(test_des_decode);

static void test_tohex(benchmark::State& state) {
    for (auto _ : state) {
        lcrypt::tohex(k1);
    }
}
BENCHMARK(test_tohex);

static void test_fromhex(benchmark::State& state) {
    auto t = lcrypt::tohex(k1);
    for (auto _ : state) {
        lcrypt::fromhex(t);
    }
}
BENCHMARK(test_fromhex);

static void test_base64_encode(benchmark::State& state) {
    for (auto _ : state) {
        lcrypt::base64_encode(k1);
    }
}
BENCHMARK(test_base64_encode);

static void test_base64_decode(benchmark::State& state) {
    auto t = lcrypt::base64_encode(k1);
    for (auto _ : state) {
        lcrypt::base64_decode(t);
    }
}
BENCHMARK(test_base64_encode);


BENCHMARK_MAIN();
