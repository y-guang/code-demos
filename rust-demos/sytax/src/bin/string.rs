fn main() {
    string_vs_str();
    str_to_string();
    string_to_str();
    traverse_string();
}

fn string_vs_str() {
    println!("string vs slice");

    let str = "rust真🐂🍺";
    let string = String::from(str);

    println!("content: {}", str);
    println!("&str.len: {}, String.len: {}", str.len(), string.len());
    // same byte length hints the same encoding
    // it is utf-8

    // str is immutable UTF-8 byte seq.
    // String is mutable, heap-allocated.
    println!();
}

#[allow(unused_variables)]
fn str_to_string() {
    let str = "hello world";

    let string = str.to_string();
    let string = String::from(str);
}

#[allow(unused_variables)]
fn string_to_str() {
    let string = "hello world".to_string();

    let str = &string[..];
    let str = string.as_str();
    // note: although following type is &String, 
    // when deref, it will become &str if needed.
    let str = &string;
}

fn traverse_string() {
    // 索引非字符边界会引发panic, best practice 是
    for c in "rust真🐂🍺".chars() {
        print!("{}, ", c);
    }
    println!();
    println!();
}