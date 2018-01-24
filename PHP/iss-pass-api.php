<?php

$mylat = "39.360095";
$mylon = "-84.58558";
$passapi = "http://api.open-notify.org/iss-pass.json?lat=".$mylat."&lon=".$mylon;
$pass = file_get_contents($passapi);
$json = json_decode($pass, TRUE);

$count = $json['request']['passes'];
for ($i = 0; $i <= ($count-1); $i++) {
$risetime = $json['response'][$i]['risetime']; 
$duration = $json['response'][$i]['duration'];
echo "Risetime: [". date('D M d,Y g:i:s A', $risetime)."] Duration [" . round($duration/60, 2) ." mins.]\n";
}
?>
