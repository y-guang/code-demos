fn main(){
    on_stack();
    on_heap();
    mutable_vs_immutable_ref();
}

fn on_stack() {
    println!("on stack");

    // for on stack basic value, direct copy it.
    let x = 5;
    let y = x;
    println!("x = {}, y = {}", x, y);
    println!("address of x = {:p}, address of y = {:p}", &x, &y);

    println!();
}

fn on_heap() {
    println!("on heap");

    // for on heap value, copy the pointer.
    let s1 = String::from("hello");
    let s2 = s1;

    // println!("s1 = {}", s1); // not allow
    println!("only s2 can be print = {}", s2);

    let s3 = s2.clone();
    println!("s2 and s3 can be accessed with clone = {}, {}", s2, s3);

    println!();
}

#[allow(unused_mut)]
#[allow(unused_variables)]
fn mutable_vs_immutable_ref() {
    println!("mutable vs immutable ref");

    let s_u = &String::from("hello");
    let s_u_2 = s_u;
    println!("s_u = {}, s_u_2 = {}", s_u, s_u_2);

    let mut s_m = String::from("hello");
    let mut s_m_r = &mut s_m;
    let mut s_m_r_2 = s_m_r;

    // println!("s_m_r = {}, s_m_r_2 = {}", s_m_r, s_m_r_2);
    // not allow, the &mut T is not Copy.

    println!();
}
