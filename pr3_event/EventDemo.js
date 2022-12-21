// Create an application to demonstrate various Node.js Events 
// in the event emitter class.
 
let events = require('events'); // importing events
let eventEmitter = new events.EventEmitter(); // creating event emitter object
 
// registering the listener to the custom events
eventEmitter.on('customEvent', (msg) => {
    console.log(msg);
});
eventEmitter.addListener('nestedEvents', (msg, nestedEventMsg) => {
    console.log(msg);
    eventEmitter.emit('customEvent', nestedEventMsg);
});
// passing multiple listener to event
let fun1 = () => console.log('Hello from function 1');
let fun2 = () => console.log('Hello from function 2');
eventEmitter.on('multiListener', fun1);
// add the listener at the start of listener array
eventEmitter.prependListener('multiListener', fun2);
// removing custom listener from events Listeners
// this will remove fun1 from emitter
eventEmitter.removeListener('multiListener', fun1);
console.log(eventEmitter.listeners('multiListener'));
//trigger to custom events
eventEmitter.emit('customEvent', 'Calling the custom event');
eventEmitter.emit('nestedEvents', 'Calling The nested event',
                     'calling custom event from another custom event');
eventEmitter.emit('multiListener');
// return total number of listener are registered to given event
let listenerToCustomEvent = eventEmitter.listenerCount('multiListener');
console.log(`total listener to multiListener event is ${listenerToCustomEvent}`);
// return array of events registered in emitter
console.log('events registered in emitter');
eventEmitter.eventNames().forEach((x) => {
    console.log('\t' + x);
});
// remove all listener from a events Listener
eventEmitter.removeAllListeners('multiListener');
console.log(eventEmitter.listeners('multiListener'));
 
// specify limit of listener on a particular event
eventEmitter.setMaxListeners(5);
// get limit of listener on particular emitter
console.log(eventEmitter.getMaxListeners());
