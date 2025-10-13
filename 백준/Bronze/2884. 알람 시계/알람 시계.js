let fs = require('fs');
let BOJ = true;

let input = fs.readFileSync(BOJ ? "/dev/stdin" : "input.txt").toString().split('\n');
let line = input[0].split(' ');

let h = parseInt(line[0]);
let m = parseInt(line[1]);

m -= 45;

if(m < 0){
	m += 60;
	h -= 1;
	if(h < 0) h += 24;
}

console.log(`${h} ${m}`);