var jc=new Array();
var nownumner=1;
jc[1]=0;
var startt;
function start(){
  var dat=new Date();
  startt=dat.getTime();
}
function outputtime(){
  for(let i=nownumber;i>0;i=i-1){
    let id="id"+i;
    document.getElementById(id).innerHTML=jc[i];
  }
}
$("#start").click(function(){
  start();
  $("#key").keydown(function(event){
    var key=event.witch;
    key=key-48;
    if(key==1){
      nownumber=nownumber+1;
      document.createElement("p")
    }
    else{
    }
  });
  $("#key").keyup(function(){
    var dat=new Date();
    jc[nownumber]=dat.getTime();
    outputtime();
  });
});
//As you can see, I'm mimicking the C++ version
