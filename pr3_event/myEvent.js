/**
 * Create functions to sort,reverse and search for an element in an array.
 * Register and trigger these functions using events.
 */

let events = require('events');
let emitters = new events.EventEmitter();
emitters.addListener('sort', (arr) => {
    console.log("Array Before Sorted : " + arr);
    arr.sort((a,b) => {return a-b});
    console.log("Array after Sorted : " + arr);
});
emitters.addListener('reverse', (arr) => {
    console.log("Array Before Reversed : " + arr);
    arr.reverse()
    console.log("Array after Reversed : " + arr);
});
emitters.addListener('findElement', (arr, element) => {
    let index;
    for (index = -1; index < arr.length - 1; index++)
        if (arr[index+1] == element)
            break;
    console.log(index != -1?`Element Found at index ${index}`:"Element Didn't Found");    
});
let arr = [1, 2, 5, 5, 54, 64, 34, 645, 3, 4, 5, 6, 7, 7];
let element = 4;
emitters.emit('sort', arr);
emitters.emit('reverse', arr);
emitters.emit('findElement', arr, element);