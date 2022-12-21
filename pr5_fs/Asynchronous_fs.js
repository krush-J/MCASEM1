const fs = require('fs');
const r = require('readline-sync');
let p = '.\\1\\';
let writeFile = () => {
    console.log('OPERATION : WRITING');
    let fileName = r.question('Enter file name(name.ext): ');
    let data = r.question('Enter data that has to be write on file : ');
    fs.writeFile(p + fileName, data, (error) => {
        if (error)
            console.log(error);
        console.log('data written on file : ' + fileName);
        console.log('-------------------------------------------------------------------------------');
    });
}
let readFile = () => {
    console.log('OPERATION : READING');
    let fileName = r.question('Enter file name(name.ext): ');
    fs.readFile(p + fileName, (error, data) => {
        if (error)
            console.log(error);
        console.log('File Contains : ' + data);
        console.log('-------------------------------------------------------------------------------');
    });
}
let appendFile = () => {
    console.log('OPERATION : APPEND');
    let fileName = r.question('Enter file name(name.ext): ');
    let data = r.question('Enter data that has to be appended on file : ');
    fs.appendFile(p + fileName, data, (error) => {
        if (error)
            console.log(error);
        console.log('data appended on file : ' + fileName);
        console.log('-------------------------------------------------------------------------------');
    });
}
let deleteFile = () => {
    console.log('OPERATION : DELETE');
    let fileName = r.question('Enter file name to delete: ');
    fs.unlink(p + fileName, (error) => {
        if (error)
            console.log(error);
        console.log('file deleted : ' + fileName);
        console.log('-------------------------------------------------------------------------------');
    });
}
let renameFile = () => {
    console.log('OPERATION : RENAME');
    let oldName = r.question('Enter old file name: ');
    let newName = r.question('Enter new file name to rename: ');
    fs.rename(p + oldName, p + newName, (error) => {
        if (error)
            console.log(error);
        console.log(`file renamed from ${oldName} to ${newName}`);
        console.log('-------------------------------------------------------------------------------');
    });
}
let fileUtil = () => {
    let flag = true;
    console.log('-------------------------------------------------------------------------------');
    console.log(`File Operations{1:read | 2:write | 3:Append | 4:rename | 5:Delete | other:exit}`);
    console.log('-------------------------------------------------------------------------------');
    let ch = parseInt(r.question('Enter Your Choice : '));
    console.log('-------------------------------------------------------------------------------');
    switch (ch) {
        case 1: readFile(); break;
        case 2: writeFile(); break;
        case 3: appendFile(); break;
        case 4: renameFile(); break;
        case 5: deleteFile(); break;

    }
}
fileUtil();