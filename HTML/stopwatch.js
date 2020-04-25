$(document).ready(function() {
	var jc = new Array();
	var nownumner = 1;
	jc[1] = 0;
	var startt;
	function start() {
		let dat = new Date();
		startt = dat.getTime();
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
    document.getElementById("information").innerHTML="press 1 to"
    var pause=false;
		$("#key").keydown(function(event) {
			var key = event.witch;
			key = key - 48;
			if (key == 1) {
				if (pause) {
					start();
				} else {
					nownumber = nownumber + 1;
					let newnode = document.createElement("p");
					let id = document.createAttribute("id");
					id.value = ("id" + nownumner);
					newnode.setAttribute(id);
					let text = document.createTextNode("");
					newnode.appendChild(text);
					document.getElementById("times").appendChild(newnode);
				}
			} else {
				pause = !pause;
				if (pause) {
					let dat = new Date();
					pausetime = dat.getTime();
				} else {
					let dat = new Date();
					startt = startt + (dat.getTime() - pausetime);
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