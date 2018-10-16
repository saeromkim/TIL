var fs=require('fs');
var readline = require('readline');
var stream = require('stream');

var instream=fs.createReadStream('./text.txt');
var outstream = new stream;
var rl = readline.createInterface(instream, outstream);

rl.on('line',function(line){
	var tokens=line.split(" ");
	console.log(tokens[0]);
});



rl.on('close',function() {
	
});