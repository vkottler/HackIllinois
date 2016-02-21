<script type="text/javascript">

//String being sent:
//params='____'&access_token=6e8c919136e2a43db6f88e6e4c216661d5ac7f5c


var loadingmessage = 'Processing...';
function setAjax(){
	var xmlHttp;
	try{
		xmlHttp=new XMLHttpRequest(); // Firefox, Opera 8.0+, Safari
		return xmlHttp;
	}
	catch (e){
		try{
			xmlHttp=new ActiveXObject("Msxml2.XMLHTTP"); // Internet Explorer
			return xmlHttp;
		}
		catch (e){
			try{
				xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
				return xmlHttp;
			}
			catch (e){
				alert("Your browser does not support AJAX!");
				return false;
			}
		}
	}
}
function myAjax(f, url, myDivToChange) {
	var poststr = getFormValues(f);
	postData(url, poststr, myDivToChange);
	//document.getElementById('testSpot').innerHTML = poststr;
}
function postData(url, parameters, myDivToChange2){
	var xmlHttp = setAjax();
	xmlHttp.onreadystatechange =  function(){
		if(xmlHttp.readyState > 0 && xmlHttp.readyState < 4){
			document.getElementById(myDivToChange2).innerHTML=loadingmessage;
		}
		if (xmlHttp.readyState == 4) {
			// this is where the magic occcurs
			var myJsonObject = JSON.parse(xmlHttp.responseText);
			document.getElementById(myDivToChange2).innerHTML= myJsonObject.return_value;
		}
	}
	xmlHttp.open("POST", url, true);
	xmlHttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xmlHttp.send(parameters);
}
function getFormValues(fobj){
	var str = "";
	var valueArr = null;
	var val = "";
	var cmd = "";
	for(var i = 0;i < fobj.elements.length;i++){
		switch(fobj.elements[i].type){
		case "text":
		case "hidden":
			str += fobj.elements[i].name +"=" + escape(fobj.elements[i].value) + "&";
			break;
		case "password":
			str += fobj.elements[i].name +"=" + escape(fobj.elements[i].value) + "&";
			break;
		case "textarea":
			str += fobj.elements[i].name +"=" + escape(fobj.elements[i].value) + "&";
			break;
		case "select-one":
			str += fobj.elements[i].name +"=" + fobj.elements[i].options[fobj.elements[i].selectedIndex].value + "&";
			break;
		}
	}
	str = str.substr(0,(str.length - 1));
	return str;
}
function sendToSpark(myIn){
	document.all.myParameter.value = myIn;
	document.myForm.action = 'https://api.spark.io/v1/devices/55ff6f066678505540361367/my-main';
	myAjax(document.all.myCoolForm, document.myForm.action, 'testSpot');
	sendToSpark2(myIn);
}

function sendToSpark2(myIn) {
	document.all.myParameter.value = myIn;
	document.myForm.action = 'https://api.spark.io/v1/devices/55ff70066678505552540667/my-main';
	myAjax(document.all.myCoolForm, document.myForm.action, 'testSpot2');
}

function pageStart() {
	myStorage1 = localStorage.getItem('myStoredText1');
	if(myStorage1  != null) document.getElementById('myToken').value = myStorage1;
	myStorage2 = localStorage.getItem('myStoredText2');
	if(myStorage2  != null) document.getElementById('myDeviceId').value = myStorage2;
}

function getSize() {
	var size = document.getElementById('slider3').value;
	//document.getElementById('S3place').innerHTML = size;
	var toSend = "x" + size;
	sendToSpark(toSend);
}
</script>
