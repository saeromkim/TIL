const readline=require('readline');

const rl=readline.createInterface({
	input:process.stdin,
	output: process.stdout
});

rl.on("line",(input1)=>{
	rl.on("line",(input2)=>{
		var result=input1-input2;
		console.log(result);
		rl.close();
	});
});
