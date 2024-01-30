const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE HTML><html>
<head>
  <title>ESP Web Server</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
 <style>
    h2 {font-size: 3.0rem;}
    h3 {font-size: 2.0rem;}
    p {font-size: 3.0rem;}
    body {max-width: 600px; margin:0px auto; padding-bottom: 25px;}

    button {
      padding: 10px;
      margin: 5px;
      font-size: 16px;
      cursor: pointer;
    }

    .selected {
      color: white;
      background-color: red;
    }


  </style>
</head>
<body>

  <h2>F1ZGM Remote IP Switch</h2>
   

  <h3>Selection Entree</h3>

  <button onclick="toggleCheckbox(this)" id="IN1"  value="81">Mire TV</button>
  <button onclick="toggleCheckbox(this)" id="IN2"  value="82">Menu</button>
  <button onclick="toggleCheckbox(this)" id="IN3"  value="83">Diaporama</button>
  <button onclick="toggleCheckbox(this)" id="IN4"  value="84">Camera</button>
  <button onclick="toggleCheckbox(this)" id="IN5"  value="85">Rx 10G Aigoual</button>
  <button onclick="toggleCheckbox(this)" id="IN6"  value="86">Rx 10G Bouquet</button>
  <button onclick="toggleCheckbox(this)" id="IN7"  value="87">Rx 2.3G Nimes</button>
  <button onclick="toggleCheckbox(this)" id="IN8"  value="88">DATV Aigoual</button>
  <button onclick="toggleCheckbox(this)" id="IN9"  value="89">Rx 10G Ventoux</button>
  <button onclick="toggleCheckbox(this)" id="IN10" value="8A">Rx 10G Lure</button>
  <button onclick="toggleCheckbox(this)" id="IN11" value="8B">Quadra</button>
  <button onclick="toggleCheckbox(this)" id="IN12" value="8C">N/A</button>
  <button onclick="toggleCheckbox(this)" id="IN13" value="8D">N/A</button>
  <button onclick="toggleCheckbox(this)" id="IN14" value="8E">N/A</button>
  <button onclick="toggleCheckbox(this)" id="IN15" value="8F">N/A</button>
  <button onclick="toggleCheckbox(this)" id="IN16" value="90">N/A</button>

   <h3>Selection Sortie</h3>


  <button onclick="toggleCheckboxOUT(this)" id="OUT1" value="81">Tx 10G Bouquet</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT2" value="82">Tx 10G Lure</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT3" value="83">Tx 1.2G DATV</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT4" value="84">Tx 2.3G Aigoual</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT5" value="85">IP</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT6" value="86">N/A</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT7" value="87">N/A</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT8" value="88">N/A</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT9" value="89">N/A</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT10" value="8A">N/A</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT11" value="8B">N/A</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT12" value="8C">N/A</button>
	<button onclick="toggleCheckboxOUT(this)" id="OUT13" value="8D">N/A</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT14" value="8E">N/A</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT15" value="8F">N/A</button>
  <button onclick="toggleCheckboxOUT(this)" id="OUT16" value="90">N/A</button>
	
<script>function toggleCheckbox(element) {
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/update?output="+element.id+"&value="+element.value, true); 
  xhr.send();
  document.getElementById('IN1').classList.remove('selected');
  document.getElementById('IN2').classList.remove('selected');
  document.getElementById('IN3').classList.remove('selected');
  document.getElementById('IN4').classList.remove('selected');
  document.getElementById('IN5').classList.remove('selected');
  document.getElementById('IN6').classList.remove('selected');
  document.getElementById('IN7').classList.remove('selected');
  document.getElementById('IN8').classList.remove('selected');
  document.getElementById('IN9').classList.remove('selected');
  document.getElementById('IN10').classList.remove('selected');
  document.getElementById('IN11').classList.remove('selected');
  document.getElementById('IN12').classList.remove('selected');
  document.getElementById('IN13').classList.remove('selected');
  document.getElementById('IN14').classList.remove('selected');
  document.getElementById('IN15').classList.remove('selected');
  document.getElementById('IN16').classList.remove('selected');
  document.getElementById(element.id).classList.add('selected');
}
</script>

<script>function toggleCheckboxOUT(element) {
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/update?output="+element.id+"&value="+element.value, true); 
  xhr.send();
  document.getElementById('OUT1').classList.remove('selected');
  document.getElementById('OUT2').classList.remove('selected');
  document.getElementById('OUT3').classList.remove('selected');
  document.getElementById('OUT4').classList.remove('selected');
  document.getElementById('OUT5').classList.remove('selected');
  document.getElementById('OUT6').classList.remove('selected');
  document.getElementById('OUT7').classList.remove('selected');
  document.getElementById('OUT8').classList.remove('selected');
  document.getElementById('OUT9').classList.remove('selected');
  document.getElementById('OUT10').classList.remove('selected');
  document.getElementById('OUT11').classList.remove('selected');
  document.getElementById('OUT12').classList.remove('selected');
  document.getElementById('OUT13').classList.remove('selected');
  document.getElementById('OUT14').classList.remove('selected');
  document.getElementById('OUT15').classList.remove('selected');
  document.getElementById('OUT16').classList.remove('selected');
  document.getElementById(element.id).classList.add('selected');
}
</script>


</body>
</html>



)=====";