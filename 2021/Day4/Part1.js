const fs = require('fs')
fs.readFile('inputd4.txt', (err, data) => 
{
  if (err) throw err;
  var d=data.toString().split("\n");
  var number=[d.shift()], tables=[], res=0;
  number=number[0].split(",");
  d.shift();  
  for(var i=0; i<d.length; i=i+5){
    if (d[i]==''){continue}
    var arr=[];
    arr.push(d[i],d[i+1],d[i+2],d[i+3],d[i+4]);
    d.shift();
    tables.push(arr);
  }
  for(var e=0;e<tables.length;e++){tables[e]=matrix(tables[e])}
  for(var j=0;j<number.length;j=j+5){
    var arr2=[];
    arr2.push(number[j],number[j+1],number[j+2],number[j+3],number[j+4])
    res=segna(arr2,tables);
    if (res!=0){
      console.log(res);
      return res;
    }
  }
})

function matrix(a){
  var arr=[];
  var row2=[];
  for (var i=0; i<a.length; i++){
    var row=(a[i].split(" "));
    row2=[];
    for (var e=0; e<row.length; e++){
      if(row[e]===""){
        continue
      }
      row2.push(row[e]);
    }
    arr.push(row2);
  }
  return arr;
}


function segna(a,b){
  var elem,copy=b
  var res=undefined;
  var result=0;
  for(var i=0; i<a.length; i++){
    elem=a[i];
    if (elem===undefined){break}

    for (var e=0; e<b.length; e++){
      for (var k=0; k<5; k++){
        if (b[e][k].includes(elem)==false){
          continue;
        }
        if (b[e][k].includes(elem)==true){
          for(var j=0; j<5; j++){
            if(b[e][k][j]===elem){
              b[e][k][j]=" ";
              res=check(elem,b[e],e);
              if (res!=undefined){
                return sum(b[e],elem);
              }
            }
          }
        }
      }
    }
  }
  return result;
}

function check(num,b,matrix){
  var flag, res=undefined;
  for (var e=0; e<b.length; e++){ //row i-esima
    if (b[0][e]===" " && b[1][e]===" " && b[2][e]===" " && b[3][e]===" " && b[4][e]===" "){
      res=["c",matrix,e,num];
      return res;
    }
    for (var k=0; k<b[e].length; k++){ //elem row 
      if(b[e][k]!==" " ){
        flag=false;
        break;
      }
      flag=true;
    }
    if (flag===true){
      res=["r",matrix,e,num];
      return res;;
    }
  }
  return res;
}

function sum(table,elem){
  var sum=0;
  for (var i=0; i<5; i++){
    for (var e=0; e<5; e++){
      if(table[i][e]!=" "){
        sum=sum+parseInt(table[i][e]);
      }
    }
  }
  return sum*elem;
}
