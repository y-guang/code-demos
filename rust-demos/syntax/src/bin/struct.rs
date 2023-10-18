fn main() {
    simplify_init(String::from("sy"), String::from("sy@mail.com"));
    simplify_update_field();
    field_ownership_transfer();
}


#[allow(dead_code)]
struct User {
    active: bool,
    username: String,
    email: String,
}

// tuple struct
#[allow(dead_code)]
struct Color(i32, i32, i32);

// Unit-like Struct
struct AlwaysEqual;
// no attribute but we can impl method for them.
impl PartialEq for AlwaysEqual {
    fn eq(&self, _other: &Self) -> bool {
        true
    }
}


fn init_user()-> User {
    let user = User {
        active: true,
        username: String::from("spike"),
        email: String::from("spikeyang.anu@gmail.com")
    };
    user
}

#[allow(unused_variables)]
fn simplify_init(username: String, email: String) {
    let user = User {
        active: true,
        username, // auto use the same name var
        email,
    };
}

#[allow(unused_assignments)]
fn simplify_update_field() {
    println!("simplify update field");

    let mut user = init_user();
    println!("addr of user: {:p}", &user);
    user = User{
        active: false,
        ..user
    };
    println!("addr of user: {:p}", &user);

    // also allow to create second user in this manner.
    let _user2 = User {
        active: false,
        ..user
    };

    println!()
}

#[allow(unused_variables)]
fn field_ownership_transfer() {
    let user = init_user();
    let mail = user.email;
    
    // println!("user.email: {}", user.email);
    // after ownership transfer, we cannot access the field again.
}