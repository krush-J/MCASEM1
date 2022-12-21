let isLeapYearTimeout;
let isLeapYear = () => {
    let year = parseInt(input.question('Enter Year : '));
    if(year % 4 == 0 || year % 100 == 0)
        console.log(`${year} is a leap year.`);
    else
        console.log(`${year} is not a leap year.`);
        clearTimeout(isLeapYearTimeout);
}
isLeapYearTimeout = setTimeout(isLeapYear, 10000);