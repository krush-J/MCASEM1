let input = require("readline-sync");
let printTableInterval;
let printTable = () =>{
    let n = parseInt(input.question('Enter a number : '));
    let table = '';
    for(let i = 1; i <= 10; i++)
        table = table + (i * n) + ' ';
    console.log(table);
    clearInterval(printTableInterval);
} 
printTableInterval = setInterval(printTable, 10000);