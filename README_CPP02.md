# CPP02

Ad-hoc polymorphism and the Orthodox Canonical Form with a fixed-point number class.

Part of my C++ modules at [Codam](https://www.codam.nl) (42 Network), written in C++98.

**Concepts:** operator overloading, Orthodox Canonical Form, fixed-point arithmetic.

## Exercises

| Folder | Exercise | What it does |
| --- | --- | --- |
| `ex00` | My First Class in Orthodox Canonical Form | `Fixed` class with default/copy constructors, copy assignment and destructor. |
| `ex01` | Towards a more useful fixed-point number class | Constructors from `int` and `float`, `toInt()`, `toFloat()` and `operator<<`. |
| `ex02` | Now we're talking | Comparison, arithmetic and increment/decrement operators, plus static `min`/`max`. |

## Build and run

Each exercise is self-contained. From the repository root:

```sh
cd ex00
make
./<executable>
```

`make fclean` removes the build output. Code is compiled with `-Wall -Wextra -Werror -std=c++98`.

## All modules

[CPP00](https://github.com/onmore1/CPP00) · [CPP01](https://github.com/onmore1/CPP01) · **CPP02** · [CPP03](https://github.com/onmore1/CPP03) · [CPP04](https://github.com/onmore1/CPP04) · [CPP05](https://github.com/onmore1/CPP05)
