/**
 * Write a program to Print the given pattern
    1 2 3 4 5
    1 2 3 4
    1 2 3
    1 2 
    1
 */
pattern = () =>{
    let s;
    for(let i = 5; i >= 1; i--){
        s = '';
        for(let j = 1; j <= i; j++){
            s = `${s} ${j}`;
        }
        console.log(s);
    }
}
pattern();