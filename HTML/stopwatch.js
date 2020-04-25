$(document).ready(function() {
	var jc = new Array();
	var nownumber = 1;
	jc[1] = 0;
  	var startt;
  	function record(){
  	  nownumber = nownumber + 1;
  	  let newnode = document.createElement("p");
  	  let id = document.createAttribute("id");
  	  id.value = ("id" + nownumber);
  	  newnode.setAttribute(id);
  	  let text = document.createTextNode("");
  	  newnode.appendChild(text);
 	   document.getElementById("times").appendChild(newnode);
 	 }
	function start() {
		let dat = new Date();
	    startt = dat.getTime();
	    record();
	}
	function outputtime() {
		for (let i = nownumber; i > 0; i = i - 1) {
			let id = "id" + i;
			document.getElementById(id).innerHTML = jc[i];
		}
	}
	var pausetime = 0;
	$("#start").click(function() {
	    start();
	    document.getElementById("information").innerHTML="Press 1 to recoud,press 2 to pause";
	    var pause=false;
            $("#key").keydown(function(event) {
   	   document.getElementById("key").value="";
 	   var key = event.witch;
	   key = key - 48;
	   if (key == 1) {
				if (pause) {
					start();
				} else {
			          record();
				}
			} else {
				pause = !pause;
				if (pause) {
					let dat = new Date();
					pausetime = dat.getTime();
          document.getElementById("information").innerHTML="Press 2 to continue, press 1 to reset";
				} else {
					let dat = new Date();
					startt = startt + (dat.getTime() - pausetime);
          document.getElementById("information").innerHTML="Press 1 to recoud,press 2 to pause";
				}
			}
		});
		$("#key").keyup(function() {
			let dat = new Date();
			jc[nownumber] = dat.getTime();
			outputtime();
		});
	});
	//As you can see, I'm mimicking the C++ version
});
