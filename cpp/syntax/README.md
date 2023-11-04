# Basic Syntax of CPP

ref: [《C++快速入门》](https://www.bilibili.com/video/BV1Ps411w73m/)

## content

| concept     | file                                     | section                     |
| ----------- | ---------------------------------------- | --------------------------- |
| io          | [io.cpp](./src/io.cpp)                   |                             |
| fio         | [fio.cpp](./src/fio.cpp)                 | [file io](#file-io)         |
| overload    | [overload.cpp](./src/overload.cpp)       |                             |
| union       | [union.cpp](./src/union.cpp)             | [union](#union)             |
| enum        | [enum.cpp](./src/enum.cpp)               | [enum](#enum)               |
| class       | [class.cpp](./src/class.cpp)             |                             |
| inheritance | [inheritance.cpp](./src/inheritance.cpp) | [inheritance](#inheritance) |
| static      | [static.cpp](./src/static.cpp)           | [static](#static)           |

## file io

`fstream` lib.

- `ifstream` for in stream.
- `ofstream` for out.

## union

union is "overloading" type. use the same space to store different type of data.

## enum

mapping element to index [0, n-1].

## inheritance

Different from Java, child cannot touch private member of parent. Use `protected` instead.

## static

Different from Java, static is just the extend C's static to class.

However, compared with C, the access control rely more on namespace than static.

Note the static member variable need to be initialized outside the class.
