# rust syntax

ref: [Rust语言圣经(Rust Course)](https://course.rs/basic/ownership/ownership.html)

## content

| chapter | concept   | file                                   | section                 |
| ------- | --------- | -------------------------------------- | ----------------------- |
| 2.2     | types     | [types.rs](./src/bin/types.rs)         | [types](#types)         |
| 2.4.1   | string    | [string.rs](./src/bin/string.rs)       | [string](#string)       |
| 2.3     | ownership | [ownership.rs](./src/bin/ownership.rs) | [ownership](#ownership) |
| 2.4.3   | struct    | [struct.rs](./src/bin/struct.rs)       | [struct](#struct)       |

## types

- `char` type is 32-bit.
- integer types provide methods to handle overflow, e.g. `wrapping_add()`.

## string

major types:

- `str`: immutable, UTF-8 byte sequence.
- `String` mutable, heap-allocated.

## ownership
- one value is own and only own by one variable at a given time point.
  - if deep copied, both variable is available.
  - if shallow copied, transfer of ownership, the original variable is not available.
  - if a type impl `Copy`, then it is on-stack and alway be deep copied, so no transfer of ownership.
  - common rules
    - all basic types and its combination impl `Copy`. 
    - And immutable variable `&T` is also `Copy`. 
    - mutable `&mut T` is NOT `Copy`.
- when variable out scope, the value is dropped.

ref as borrow
- mutable and immutable borrow CANNOT co-exist.
- mutable ref can be only one.

## struct

- the ownership of a field in struct can be transferred
- either all fields are mutable or immutable.