*This project has been created as part of the 42 curriculum by thdeglos and tcloix.*

# push_swap

## Description

**push_swap** is a sorting project: given a list of unique integers placed in a stack `A`, the program prints the shortest sequence of operations that sorts `A` in ascending order (smallest number on top), using a second, initially empty stack `B`.

The only allowed operations are:

| Operation | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the first two elements of A / B / both |
| `pa` / `pb` | move the top element of B to A / of A to B |
| `ra` / `rb` / `rr` | rotate A / B / both up (the first element becomes the last) |
| `rra` / `rrb` / `rrr` | reverse rotate A / B / both (the last element becomes the first) |

The goal is not only to sort, but to sort with as **few operations as possible**. The program therefore implements several algorithms with different complexities, and can choose between them automatically depending on how sorted the input already is.

### Features

- Four strategies, selectable with a flag:
  - `--simple`: selection sort, O(n²)
  - `--medium`: chunk-based sort, O(n√n)
  - `--complex`: radix sort, O(n log n)
  - `--adaptive` (default): picks one of the three according to the input's disorder
- A dedicated algorithm for very small stacks (see [Small](#small-selection-sort-down-to-three-elements)).
- A `--bench` flag that prints statistics on `stderr` (disorder, strategy used, number of operations, detail per operation).
- Input accepted as several arguments (`./push_swap 3 2 1`) or as a single quoted string (`./push_swap "3 2 1"`).
- Error handling: non-numeric input, integers outside the `int` range, duplicates and unknown flags all print `Error` on `stderr`.

## Instructions

### Compilation

Requirements: a C compiler (`cc`/`gcc`) and `make`. Libft is included in the repository and built by the Makefile.

```sh
make        # builds ./push_swap
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + all
```

The code is compiled with `-Wall -Wextra -Werror`.

### Usage

```sh
./push_swap [strategy] [--bench] <integers...>
```

```sh
./push_swap 2 1 3 6 5 8                 # adaptive strategy (default)
./push_swap --complex 5 4 3 2 1         # force the O(n log n) algorithm
./push_swap "3 2 1" --bench             # statistics on stderr
```

Example of `--bench` output (printed on `stderr`, the operations stay on `stdout`):

```
[bench] disorder: 48.22%
[bench] strategy: Adaptive / O(n*sqrt(n))
[bench] total_ops: 1246
[bench] sa: 0 sb: 0 ss: 0 pa: 100 pb: 100
[bench] ra: 950 rb: 49 rr: 0 rra: 0 rrb: 47 rrr: 0
```

### Testing

Count the operations used on 100 random numbers:

```sh
ARG=$(shuf -i 1-10000 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

Check the result with the checker provided by the 42 subject:

```sh
./push_swap $ARG | ./checker_linux $ARG
```

### Project structure

```
.
├── main.c           entry point: parsing, strategy choice, cleanup
├── push_swap.h
├── algo/            the sorting algorithms (simple, medium, complex, small)
├── basefunction/    the 11 stack operations (swap, push, rotate, reverse rotate)
├── utils/           argument parsing, error handling, disorder metric, indexing, benchmark
└── libft/
```

## Work distribution

The project was split between the two members of the team, and each file was written, tested and reviewed by its author.

| Member | Files |
|---|---|
| **thdeglos** | `utils/parse_flags.c`, `utils/error.c`, `utils/duplicates.c`, `utils/bench.c`, `utils/bench_ops.c`, `algo/algo3.c` (complex strategy: radix sort), `Makefile` |
| **tcloix** | `main.c`, `algo/algo1.c` (simple strategy: selection sort), `algo/algo2.c` (medium strategy: chunk-based sort), `algo/small_algo.c`, `basefunction/` (the 11 stack operations), `utils/parse_ints.c`, `utils/listfiller.c`, `utils/indexer.c`, `utils/disorderchecker.c` |
| **Both** | `push_swap.h` |

In short, thdeglos handled flag parsing, error management, duplicate detection, the `--bench` feature and the radix sort, as well as the build system. tcloix handled the program's entry point, the input parsing and the stack setup, the stack operations, the disorder metric and the other sorting strategies. The header file was designed together, since it defines the data structures and prototypes shared by every part of the code.

## Algorithms

### Common preparation

**Indexing.** Before sorting, every value is replaced by its **rank** in the sorted list: the smallest value becomes `0`, the next `1`, and so on up to `n-1`. For example `[-50, 1000, 7, 42]` becomes `[0, 3, 1, 2]`. This costs no operation (it is only a computation), and it makes the algorithms independent of the actual values: ranks are contiguous, which is what the chunk and radix algorithms rely on.

**Disorder metric.** The disorder of a stack is the fraction of pairs `(i, j)` with `i` before `j` that are in the wrong order (inversions):

```
disorder = inverted pairs / total pairs
```

It is `0` for a sorted list, `1` for a reversed list, and about `0.5` for a random list. It is computed once, in O(n²), before sorting, and costs no operation. If the disorder is `0`, nothing is printed.

### Simple: selection sort — O(n²)

1. Find the smallest element of `A`.
2. Bring it to the top by the shortest path (`ra` if it is in the first half, `rra` otherwise).
3. `pb` it to `B`.
4. Repeat until `A` is empty, then `pa` everything back.

Because the minima are pushed in increasing order, `B` ends up in decreasing order from top to bottom, and the final `pa` calls reverse it into an ascending `A`.

**Cost.** Each element may need up to n/2 rotations: about n²/8 operations on random input (≈ 32 000 for 500 numbers). **Why keep it:** on an almost sorted list the minimum is always near the top, so each element costs about 2 operations (one rotation at most, plus `pb` and `pa`). That is why it is the best choice for low disorder.

### Small: selection sort down to three elements

A variant of the simple algorithm dedicated to very small stacks, where a general-purpose strategy has too much overhead.

- **2 elements:** `sa` if they are in the wrong order, nothing otherwise.
- **3 elements or more:**
  1. While `A` holds more than 3 elements, find the smallest one (same search as the simple algorithm), bring it to the top by the shortest path (`ra` or `rra`) and `pb` it.
  2. Sort the 3 remaining elements of `A` directly with a hard-coded case analysis (see below).
  3. `pa` everything back from `B`. The minima were pushed in increasing order, so `B` is in decreasing order from top to bottom and the `pa` calls put them back in ascending order on top of the sorted three.

**The three-element case.** With `a`, `b`, `c` the values from top to bottom, only 5 orders are possible besides the sorted one, and each is fixed with at most 2 operations:

| Order `(a, b, c)` | Operations |
|---|---|
| `2 1 3` | `sa` |
| `3 2 1` | `sa`, `rra` |
| `3 1 2` | `ra` |
| `1 3 2` | `sa`, `ra` |
| `2 3 1` | `rra` |
| `1 2 3` | nothing |

**Cost.** Each of the n − 3 extracted elements costs at most n/2 rotations, plus `pb` and `pa`, plus at most 2 operations for the last three. For 5 numbers this gives at most 10 operations. **Why keep it:** for tiny inputs the O(n²) cost is negligible, and the explicit handling of 2 and 3 elements avoids wasted rotations that the generic algorithms would make.

### Medium: chunk sort — O(n√n)

The ranks are cut into consecutive **chunks** of size `c`.

- **Phase 1 (A → B).** On each pass over `A`, `limit` grows by `c`. Every element whose rank is below `limit` is pushed to `B` (`pb`), the others are skipped (`ra`). After the last pass, `B` contains the chunks stacked in order: small ranks at the bottom, large ranks on top.
- **Phase 2 (B → A).** Repeatedly find the largest rank in `B`, bring it to the top by the shortest path (`rb` or `rrb`), and `pa` it. Since we always extract the maximum, `A` fills from the largest to the smallest value and ends up sorted.

**Why chunks.** Without them, the maximum could be anywhere in `B` and each search would cost about n/4 rotations. With chunks, the maximum is always in the most recently pushed chunk, close to the top.

**Choosing the chunk size.** The cost depends on `c` through two opposite terms:

- phase 1 makes about n/c passes, each walking over roughly n/2 elements: ≈ n² / (2c);
- phase 2 needs about c/4 rotations per extracted element: ≈ n·c / 4.

A small `c` makes phase 1 expensive, a large `c` makes phase 2 expensive. For `c` proportional to √n, both terms are of order n√n. We measured the total cost on random lists (average of 15 runs) to pick the constant:

| Chunk size `c` | 100 numbers | 500 numbers |
|---|---|---|
| √n / 2 (first version) | ≈ 1 264 | ≈ 12 385 |
| √n | ≈ 856 | ≈ 8 311 |
| **√(3n)** (chosen) | **≈ 729** | **≈ 7 349** |
| √(4n) | ≈ 771 | ≈ 7 354 |

The optimum is flat between √(2n) and √(4n); we use **`c = √(3n)`** (the smallest `c` with `c² ≥ 3n`). The first version, with `√n / 2`, was still O(n√n) but with a larger constant: too many passes over `A`, which was too slow for 500 numbers.

### Complex: radix sort — O(n log n)

An LSD (least significant digit first) radix sort in base 2, applied to the ranks. There are `⌈log₂ n⌉` passes (9 for 500 numbers). One pass on bit `b`:

- for each of the n elements of `A`: if bit `b` is `0`, `pb`; if it is `1`, `ra`;
- then `pa` everything back from `B` to `A`.

After a pass, all the elements with bit `b` at `0` come before those with bit `b` at `1`, **keeping their relative order** (the pass is stable). Stability is what guarantees that later passes do not undo the work of the earlier ones. After the pass on the most significant bit, `A` is sorted.

**Cost.** A pass costs about 1.5n operations (n `pb`/`ra`, plus about n/2 `pa`), so ≈ 1.5·n·⌈log₂ n⌉ in total: ≈ 1 080 for 100 numbers and ≈ 6 800 for 500 numbers. This cost does not depend on the initial order, which is why this algorithm is used for highly disordered input.

### Adaptive strategy

The default mode measures the disorder `d` and picks the algorithm accordingly:

| Disorder | Algorithm | Reason |
|---|---|---|
| `d < 0.2` | simple, O(n²) | the list is almost sorted: the minimum is always near the top |
| `0.2 ≤ d < 0.5` | medium, O(n√n) | intermediate case |
| `d ≥ 0.5` | complex, O(n log n) | strongly disordered input (a random list is around 0.5) |

### Measured results (random inputs)

| Algorithm | 100 numbers | 500 numbers |
|---|---|---|
| Simple | ≈ 1 400 | ≈ 32 000 |
| Medium | ≈ 730 | ≈ 7 350 |
| Complex | ≈ 1 080 | ≈ 6 800 |

## Resources

### References

- [Selection sort — Wikipedia](https://en.wikipedia.org/wiki/Selection_sort) (simple and small algorithms)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort) (complex algorithm)
- [Inversion (discrete mathematics) — Wikipedia](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)) (basis of the disorder metric)
- Cormen, Leiserson, Rivest, Stein, *Introduction to Algorithms*, chapter 8.3 (radix sort)
- The 42 `push_swap` subject

### Use of AI

I used an AI assistant (Claude, by Anthropic) for the following tasks:

- **Code review:** it read the project and pointed out bugs, notably an undefined behaviour in the disorder computation (a `size_t` pointer cast over an `int`, detected with AddressSanitizer), a wrong strategy label in the benchmark output, a possible crash and a memory leak in the argument parsing, and a duplicated `Error` message.
- **Documentation:** it helped draft this README.

The AI was used as a reviewer and tutor; the suggestions were tested before being kept.
