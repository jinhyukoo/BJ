const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input.push(line)
    if(input.length === 2) rl.close();
  })
  .on('close', function () {
    main();
    process.exit();
});



const main = () => {
    const x = input[0];
    const y = input[1];
    
    if(x>0 && y>0) console.log(1);
    if(x>0 && y<0) console.log(4);
    if(x<0 && y>0) console.log(2);
    if(x<0 && y<0) console.log(3);
}
