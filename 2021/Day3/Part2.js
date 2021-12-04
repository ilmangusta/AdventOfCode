const fs = require('fs')
fs.readFile('imput.txt', (err, data) => 
{
  if (err) throw err;
  var d=data.toString().split("\n");
  var m=parseInt(mostCommon(d,0),2);
  var l=parseInt(leastCommon(d,0),2);
  console.log(m*l)
  return m*l;
})

function mostCommon(a,k){
  if (a.length==1){
    return a[0];
  }
  var cont0=0; cont1=0;
  var arr=[], flag;
  for (var i=0; i<a.length; i++){
    if (a[i][k]==="0"){
      cont0++;
    }
    if (a[i][k]==="1"){
      cont1++;
    }
  }
  if (cont1>=cont0){
    flag=1
  }else{
    flag=0
  }
  for (var i=0; i<a.length; i++){
    if (a[i][k]==flag){
      arr.push(a[i])
    }
  }
  return mostCommon(arr,k+1);
}

function leastCommon(a,k){
  if (a.length==1){
    return a[0];
  }
  var cont0=0; cont1=0;
  var arr=[], flag;
  for (var i=0; i<a.length; i++){
    if (a[i][k]==="0"){
      cont0++;
    }
    if (a[i][k]==="1"){
      cont1++;
    }
  }
  if (cont0<=cont1){
    flag=0
  }else{
    flag=1
  }
  for (var i=0; i<a.length; i++){
    if (a[i][k]==flag){
      arr.push(a[i])
    }
  }
  return leastCommon(arr,k+1);
}
