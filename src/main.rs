fn reset_board(arr: &mut [[i32; 9]; 9]){
    for i in 0..9 {
        for j in 0..9 {
            arr[i][j] = 0;
        }
    }
    let mut j = 5;

    for i in 0..5 {
        for k in 0..9 {
            if k >= j {
                arr[i][k] = -1;
            }
            j += 1;
        }
    }

    for i in 5..9 {
        for k in 0..9 {
            if k >= j {
                arr[i][k] = -1;
            }
            j -= 1;
        }
    }
}
fn populate_board(arr: &mut [[i32; 9]; 9]) {
    for i in 0..9 {
        arr[i][0] = 1;
    }

    let mut k = 3;
    for i in 0..5 {
        for j in 0..9 {
            if j >= k {
                arr[i][j] = 2;
            }
            k += 1;
        }
    }

    for i in 5..9 {
        for j in 0..9 {
            if j >= k {
                arr[i][j] = 2;
            }
            k -= 1;
        }
    }
}

fn new_board() -> [[i32; 9]; 9] {
    let mut arr = [[0; 9]; 9];
    reset_board(&mut arr);
    populate_board(&mut arr);
    return arr;
}

fn print_board(arr: &[[i32; 9]; 9]) {
    for i in 0..9 {
        for j in 0..9 {
            if arr[i][j] == 0 {
                print!("[ ]");
            } else if arr[i][j] == 1 {
                print!("[1]");
            } else if arr[i][j] == 2 {
                print!("[2]");
            } else {
                print!("-");
            }
        }
        println!();
    }
}

/*
[1][0][0][0][2]-1-1-1-1
[1][0][0][0][0][2]-1-1-1
[1][0][0][0][0][0][2]-1-1
[1][0][0][0][0][0][0][2]-1
[1][0][0][0][0][0][0][0][2]
[1][0][0][0][0][0][0][2]-1
[1][0][0][0][0][0][2]-1-1
[1][0][0][0][0][2]-1-1-1
[1][0][0][0][2]-1-1-1-1
*/

fn main() {
    let mut arr = new_board();
    print_board(&arr);
    
}
