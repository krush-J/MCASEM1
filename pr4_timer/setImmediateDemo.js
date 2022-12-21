let str = input.question('Enter String : ');
let isPalindromeString = () => {
    let n = str.length;
    let k = n - 1;
    let flag = true;
    for(let i = 0; i < n / 2; i++){
        if(str.charAt(i) != str.charAt(k--)){
            flag = false;
            break;
        }
    }
    console.log(`${str} is ${flag?'':'not'} a palindrome string`);
}
str = str.toUpperCase();
isPalindromeStringImmediate = setImmediate(isPalindromeString);
