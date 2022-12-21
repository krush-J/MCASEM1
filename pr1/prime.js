// Print first 100 prime numbers
let isPrime = (num) => {
    for(let n = 2; n * 2 <= num; n++)
        if(num % n == 0)
            return false;
    return true;
}
let primeSeries = () => {
    let nums = [];
    for(let n = 2; n <= 100; n++)
        if(isPrime(n))
            nums.push(n);
    console.log(nums);
}
primeSeries();