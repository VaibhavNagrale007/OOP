fn main() {
    println!("Hello");
    // comment
    let x:u32 = 10;        // we can set types
    let mut y = 12;        // mut for chaging value of y
    println!("x = {1} y = {0}", y, x);
    y = y+10;
    println!("y = {0}", y);
    
    // resource with box
    let z : Box<u32> = Box::new(10);
    println!("z = {0}", z);
    let zz = z;
    // println!("z = {0}", z);  -> error as resource gone to zz
    println!("zz = {0}", zz);
    
    // resource given to function
    foo(zz);
    // println!("zz = {0}", zz);  -> error as foo took resource
    // try to return resource and print
    
    // scope of resource
    let zzz : Box<u32> = Box::new(30);
    {
        let y = zzz;
        println!("y of zzz : {0}",y);
    } // y died here
    // println!("zzz = {0}",zzz);   -> error as y took resource and died
    
    // borrow semantics
    let x : Box<u32> = Box::new(15);
    let y = &x;
    println!("borrow semantics x : {0} y : {1}", x, y);
    
    // borrow for different types
    let mut x : Box<u32> = Box::new(5);
    let u = &x;              // warning of not used u and x not changed but mutable
    let mut y = &x;          // warning variable y does not be mutable
    let z = & mut x;         // warning unused variable z
    let mut zz = & mut x;    // warning unused and mut not needed
    // first x has mutable resource which can be changed by Box only
    // then u is refrence to x and can be printed and not mutable
    // y will be mutable and currently have value of refrence of x
    // we can give z any mutable value and z need not be mutable
    // any one can give him pen and can use it any way
    
    // Structures in rust
    let f : Foo = Foo{name:"hi".to_string(), x:42};
    
    // Structure, trait and impl
    let Data = Foo{ name : "Roy".to_string(), x : 5};
    println!("{} and id {}", Data.tostring(), Data.id());
    
    // Copy and Clone traits
    // trait Clone
    // impl Clone for Foo {
    //    fn clone(&self){}  
    // };
    // similar to copy
    
    // freeing stuff trait
    // A be a structure
    // trait Drop{
    //   fn drop(& mut self);   
    // }
    // impl Drop for A{
    //    fn drop (self: & mut A){freeing stuff}
    // }
}

fn foo(u : Box<u32>){
    println!("Inside foo u : {0}", u);
}

struct Foo{
    name : String,
    x : u32
}

// traits in rust : traits are properties of types
trait ToString{
    fn tostring(&self) -> String;
    fn id(&self) -> u32;
}

impl ToString for Foo{
    fn tostring(&self) -> String{
        return format!("Foo has name : {}", self.name);
    }
    fn id(&self) -> u32{
        return self.x;
    }
}




