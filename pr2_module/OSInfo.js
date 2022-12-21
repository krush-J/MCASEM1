/**
 * Write a program to print information about the computer's operating system using OS  
    module(use any 5 methods).
 */
os = require('os');
os_info = () => {
    console.log(`Host Name      : ${os.hostname()}`);
    console.log(`CPU type       : ${os.arch()}`);
    console.log(`Total Memory   : ${os.totalmem()}`);
    console.log(`Free Memory    : ${os.freemem()}`);
    console.log(`Home Directory : ${os.homedir()}`);
}
os_info();