use wasm_bindgen::prelude::*;
// mod main;

#[wasm_bindgen]
extern{
    fn alert(s: &str);
}

#[wasm_bindgen]
pub fn greet(){
    alert("Hello World!");
}

// pub fn create_lsystem(){
//     main::run_lsystem();
// }