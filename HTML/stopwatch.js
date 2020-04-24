var jc=new Array();
var nownumner=0;
jc[1]=0;
var startt;
function start(){
  var dat=new Date();
  startt=dat.getTime();
}
function outputtime(){
}
$("#start").click(function(){
  start();
  $("input").keydown(function(event){
    var key=event.witch;
    key=key-48;
    if(key==1){
    }
    else{
    }
  });
  $("input").keyup(function(){
    outputtime();
  });
});
//As you can see, I'm mimicking the C++ version
