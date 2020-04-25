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
var pausetime=0;
$("#start").click(function(){
  start();
  $("#key").keydown(function(event){
    var key=event.witch;
    key=key-48;
    var pause=false;
    if(key==1){
      if(pause){
        start();
      }
      else{
        nownumber=nownumber+1;
        var newnode=document.createElement("p");
        var id=document.createAttribute("id");
        id.value=("id"+nownumner);
        newnode.setAttribute(id);
        var text=document.createTextNode("");
        newnode.appendChild(text);
        document.getElementById("times").appendChild(newnode);
      }
    }
    else{
      pause=!pause;
      if(pause){
        let dat=new Date();
        pausetime=dat.getTime();
      }
      else{
        let dat=new Date();
        startt=startt+(dat.getTime()-pausetime);
      }
    }
  });
  $("#key").keyup(function(){
    let dat=new Date();
    jc[nownumber]=dat.getTime();
    outputtime();
  });
});
//As you can see, I'm mimicking the C++ version
