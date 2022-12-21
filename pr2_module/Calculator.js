exports.add = (a, b) => console.log(`${a} + ${b} = ${a+b}`);
exports.sub = (a, b) => console.log(`${a} - ${b} = ${a-b}`);
exports.mult = (a, b) => console.log(`${a} * ${b} = ${a*b}`);
exports.div = (a, b) => {
    if (b == 0){
        console.log("divider can't be a zero");
        return;
    }
    console.log(`${a} / ${b} = ${a/b}`);
}
