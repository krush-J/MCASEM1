console.log('before next tick');
process.nextTick(() => {
    console.log('in next tick body');
});
console.log('after next tick');