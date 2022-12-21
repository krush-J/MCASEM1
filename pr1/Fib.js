/**
 * Print first fibonacci series where n will be user input
 * @param {last number of fibonnacie series} n 
 * @returns fibbonaccie series
 */

let series = (n) => {
    let ser = [0, 1];
    if (n == 1)
        return ser.slice(0,1);
    else if (n == 2)
        return ser;
    while (n-- > 2){      
        let len = ser.length;
        ser.push(ser.at(len - 1) + ser.at(len - 2));
    }
    return ser;
}
console.log(series(process.argv[2]));


