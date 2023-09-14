fn main() {
    // int
    print_boundary_int_values();
    overflow_handle();

    // char
    char_type();

    bool_type();
}

fn print_boundary_int_values() {
    println!("boundary int values");

    let i8_max: i8 = !(1 << 7);
    let i8_min: i8 = 1 << 7;
    let i16_max: i16 = !(1 << 15);
    let i16_min: i16 = 1 << 15;
    let i32_max: i32 = !(1 << 31);
    let i32_min: i32 = 1 << 31;
    let i64_max: i64 = !(1 << 63);
    let i64_min: i64 = 1 << 63;
    let i128_max: i128 = !(1 << 127);
    let i128_min: i128 = 1 << 127;

    print!("i8_max: {}, i8_min: {}\n", i8_max, i8_min);
    print!("i16_max: {}, i16_min: {}\n", i16_max, i16_min);
    print!("i32_max: {}, i32_min: {}\n", i32_max, i32_min);
    print!("i64_max: {}, i64_min: {}\n", i64_max, i64_min);
    print!("i128_max: {}, i128_min: {}\n", i128_max, i128_min);
    print!("\n");
}

fn overflow_handle() {
    println!("overflow handle");

    let a: u8 = 255;

    // panic in debug mode
    // let b = a + 20;
    // println!("255 + 20 = {}", b);

    // wrapping_add: allow overflow
    let b = a.wrapping_add(20);
    println!("wrapping_add\t255 + 20 = {}", b); // 19

    // checked_add: check overflow with Option
    let b = a.checked_add(20);
    println!("checked_add\t255 + 20 = {:?}", b); // None

    // overflowing_add: return value with overflow flag
    let b = a.overflowing_add(20);
    println!("overflowing_add\t255 + 20 = {:?}", b); // (19, true)

    // saturating_add: keep max value
    let b = a.saturating_add(20);
    println!("saturating_add\t255 + 20 = {}", b); // 255

    println!();
}

fn char_type() {
    println!("char type");
    println!(
        "char type is {} bytes size, i.e. similar to UTF-32",
        std::mem::size_of::<char>()
    );

    let c1 = 'a';
    let c2 = '中';
    let c3 = '🍺';

    println!(
        "c1: {}, \t U+{}, \t {}, \t len_utf8 {}, \t len_utf16 {}",
        c1,
        c1 as u32,
        c1 as u8,
        c1.len_utf8(),
        c1.len_utf16()
    );
    println!(
        "c2: {}, \t U+{}, \t {}, \t len_utf8 {}, \t len_utf16 {}",
        c2,
        c2 as u32,
        c2 as u8,
        c2.len_utf8(),
        c2.len_utf16()
    );
    println!(
        "c3: {}, \t U+{}, \t {}, \t len_utf8 {}, \t len_utf16 {}",
        c3,
        c3 as u32,
        c3 as u8,
        c3.len_utf8(),
        c3.len_utf16()
    );

    println!();
}

fn bool_type() {
    println!("bool type");

    let t = true;

    println!("t: {}", t);
    println!("size of bool: {}", std::mem::size_of::<bool>());

    println!();
}