<html>
<head>
<title>Vaughn Spark</title>
<font style="font-size:25px" face="verdana">
<?php
include 'myJavascript.js';
include 'myStyle.css';
?>
</head>

<script type="text/javascript">
</script>

<body onload="{pageStart()}" bgcolor="blue">

<!-- <input id="myDeviceId" name="myCoreID" type=hidden size=50 value="55ff6f066678505540361367"> -->
<!-- <input id="myFunctionName" name="myFunction"  type=hidden size=50 value="my-main" > -->

<form name="myForm" method="POST" id="myCoolForm" >
<input id="myParameter" name="params" type=text  style="display:none" size=50 placeholder="d7-send-high">
<input id="myToken" name="access_token" type=hidden size=50 value="6e8c919136e2a43db6f88e6e4c216661d5ac7f5c">
</form>
<h1>
<p> WIFI CAR</p>
</h1>
<div>

<style type="text/css">
.btn{
background-color:red;
 border: none;
    color: white;
-moz-border-radius: 15px;
  -webkit-border-radius: 15px;
   border: 2px solid ;
    padding: 10px ;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 16px;


}
</style>

<style type="text/css">
.btn2{
text-align: center;
 border: none;
    color: black;
	-moz-border-radius: 15px;
  -webkit-border-radius: 15px;
   border: 2px solid ;
    padding: 10px ;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 16px;


}
</style>
LCD Intro: <input type="button" class="btn" value="Try me!" onClick="javascript:sendToSpark('INTRO');"><br><br>
<input type="button" class="btn" value="Forward" onClick="javascript:sendToSpark('FORWARD');" style="margin-left: 37px; margin-bottom: 10px" ><br>
<input type="button" class="btn" value="Left" onClick="javascript:sendToSpark('LEFT');" style="margin-right: 30px; margin-left: 10px" >
<input type="button" class="btn" value="Right"  onClick="javascript:sendToSpark('RIGHT');"><br>
<input type="button" class="btn" value="Reverse" onClick="javascript:sendToSpark('BACKWARD');"style="margin-left: 36px; margin-top: 10px"><br> </br>

<input type="button" class="btn" value="Stop" onClick="javascript:sendToSpark('STOP');"style="margin-left: 10px;">
<input type="button" class="btn" value="Horn" onClick="javascript:sendToSpark('HORN');"style="margin-left: 10px;"> <br> </br>
<h3>
<div id="Head Lights" style="font">Head Lights</div>
<input type="button" class="btn2" value="ON"  onClick="javascript:sendToSpark('FON');" style="margin-left: 10px;">
<input type="button"  class="btn2" value="OFF" onClick="javascript:sendToSpark('FOFF');" style="margin-right: 10px;">
</div><br>
</h3>
<h3>
<div id="Brake Lights" style="color:red">Brake Lights</div>
<input type="button"  class="btn2" value="ON"  onClick="javascript:sendToSpark('BON');"style="margin-left: 10px">
<input type="button"  class="btn2" value="OFF" onClick="javascript:sendToSpark('BOFF');"style="margin-left: 10px"><br><br>
<br><span style="color:green">Fan Control</span><br>
<input type="button" class="btn2" value="ON" onClick="javascript:sendToSpark('FAON')" style="margin-left: 10px">
<input type="button" class="btn2" value="OFF" onClick="javascript:sendToSpark('FAOFF')" style="margin-left: 10px">
</div><br>
</h3>
<h3>

<!--
<div id="FAN" style="font">Fan Speed</div>
<input id="slider3" style="width:175px" min="0" max="100" step="1" type="range" onChange="javascript:getSize()" value=50><br><br>
-->

Core 1 Return Val: <div width="400" height="200" name="testSpot" id="testSpot">output</div>
Core 2 Return Val: <div width="400" height="200" name="testSpot" id="testSpot2">output</div>

</font>
</body>
</htaml>
