# kvik

> Fast, lightweight, definitely Not Redis.

**kvik** is a lightweight, in-memory caching server built in modern C++. Inspired by Redis, it supports a minimal set of core commands—GET, SET, DEL, and EXPIRE, making it ideal for learning or lightweight use cases. The server handles TCP connections asynchronously and uses a simple, custom protocol similar to RESP for client communication. Initially, all data is stored in memory without persistence, focusing on speed, concurrency, and foundational features of a key–value cache.

---

## Features

- **In-memory key–value storage** with string-based keys and values
- **Asynchronous TCP server** for client connections
- **RESP-like command protocol** (inspired by Redis protocol)
- **Multithreaded** connection handling with locking
- **TTL / EXPIRE** support for keys
- **Eviction policies** (e.g., LRU)
- **Persistence options**: snapshotting (RDB) or append-only logs (AOF)
- **Performance benchmarks** (latency, throughput)
- **Logging & observability**
- Optional: **Node.js wrapper** and client libraries
- **Dockerized** for easy deployment

---

## Project Roadmap

1. **Foundations**: C++ toolchain, build system (CMake), unit tests
2. **Core KV Store**: minimal single-threaded in-memory store
3. **Networking**: async TCP server, client protocol
4. **Command Parsing**: RESP-like parser and dispatcher
5. **Concurrency**: worker threads, locks, connection handling
6. **Memory Management**: TTL, LRU cache, key eviction
7. **Persistence**: RDB-style snapshots or AOF append log
8. **Advanced Features**: transactions, pub/sub (optional)
9. **Benchmarking**: microbenchmarks, load testing
10. **Integration Layer**: Node.js wrapper / clients (optional)
11. **Deployment**: Dockerfile, config management
12. **Observability**: logging, monitoring, test coverage
13. **Hardening**: edge cases, error handling, security
14. **Docs & Polish**: documentation, examples, resume writeup

---

## Build & Run

### Requirements
- C++17 or newer
- CMake
- [Optional] Docker

### Build

```bash
mkdir build && cd build
cmake ..
make
