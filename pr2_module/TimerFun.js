/**
 * Print "Hello" every 500 milliseconds using Timer Module.
 * The message should be printed exactly 10 times. Use SetInterval ,
 * ClearInterval and SetTimeout methods.
 */
x = 0;
let interval = setInterval( () =>{
    console.log(`${++x} Hello`);
}, 500);

setTimeout(() => {    
    clearInterval(interval);
    console.log('5 seconds has ended');
}, 5500);
