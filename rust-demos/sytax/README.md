# rust sytax

ref: [Rust语言圣经(Rust Course)](https://course.rs/basic/ownership/ownership.html)

## content

| chapter | concept | file                             | section           |
| ------- | ------- | -------------------------------- | ----------------- |
| 2.2     | types   | [types.rs](./src/bin/types.rs)   | [types](#types)   |
| 2.4.1   | string  | [string.rs](./src/bin/string.rs) | [string](#string) |

## types

- `char` type is 32-bit.
- integer types provide methods to handle overflow, e.g. `wrapping_add()`.

## string

major types:

- `str`: immutable, UTF-8 byte sequence.
- `String` mutable, heap-allocated.

