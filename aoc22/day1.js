const fs = require("fs");

const lines = fs
  .readFileSync("day1.txt", { encoding: "utf-8" })
  .split('\n\n');


  let max1 = 0;
  let max2 = 0;
  let max3 = 0;
  //lines.forEach((capture, i) => console.log(`Capture #${i}:\n${capture}`));
let newarr = [];
for (let i = 0; i < lines.length; i++) {
    const arr = lines[i].toString().split("\n").map((x) => parseInt(x));

    console.log(arr);
  
    let temp = 0;
    for (let j = 0; j < arr.length; j++) {
        temp += arr[j]
    }

    newarr.push(temp);
    if (temp > max1) {
        max1 = temp;
    } else if (temp > max2) {
        max2 = temp;
    } else if (temp > max3) {
        max3 = temp;
    }

}
newarr.sort(function(a, b){return b-a});
console.log(newarr)
console.log(max1)
console.log(max2)
console.log(max3)

console.log(max1+max2+max3);
