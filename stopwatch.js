x = 0  
var startt,stops=0;
  
function count1( )  
{　
  var d=new Date();
    x = d.getTime();
    document.getElementById("box1").value= x-startt;  
    meter1=setTimeout("count1()", 0);
}
// 执行函数
function start(){
var alld=new Date();
  startt=alld.getTime();
    count1();
}
function retart(){
  var alld=new Date();
  startt+=(alld.getTime()-stops);
  count1();
}
function stop(){
  var alld=new Date();
  startt=alld.getTime();
  clearTimeout(meter1);
}
