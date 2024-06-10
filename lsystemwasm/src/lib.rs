use wasm_bindgen::prelude::*;
mod main;

#[wasm_bindgen]
extern{
    fn alert(s: &str);
}

#[wasm_bindgen]
pub fn greet(){
    alert("Hello World!");
}

#[wasm_bindgen]
pub fn create_lsystem(){
    let axiom = main::run_lsystem();
    alert(&axiom);
}