use std::collections::HashMap;
struct LSystem {
    vars: Vec<char>,
    constants: Vec<char>,
    axiom: String,
    rules: HashMap<char, String>,
}

fn create_generation(ls: &LSystem, n: usize) -> String {

    let mut gen: String = String::from(&ls.axiom); // Starting string

    let mut i: usize = 0;
    while i < n {
        let mut pos: usize = 0;
        loop {
            // Do stuff
            let c: char = gen.chars().nth(pos).unwrap();
            if ls.rules.contains_key(&c) {
                gen.replace_range(pos..pos+1, &ls.rules[&c]);
                pos += ls.rules[&c].chars().count();
            } else {
                pos += 1;
            }
            if pos >= gen.chars().count() {
                break;
            }
        }
        i += 1;
    }
    println!("Final Axiom: {}", gen);
    gen
}

pub fn run_lsystem() -> String {
    let v = vec!['0', '1'];

    let c = vec!['[',']'];

    let a = "0".to_string();

    let mut m = HashMap::new();
    m.insert('0', String::from("1[0]0"));
    m.insert('1', String::from("11"));

    let ls = LSystem {
        vars: v,
        constants: c,
        axiom: a,
        rules: m,
    };

    let gen = create_generation(&ls, 2);
    gen
}

fn main() {
    let gen = run_lsystem();
    println!("Final Axiom: {gen}");
}
