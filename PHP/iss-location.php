<?php

$mylat = "39.360095";
$mylon = "-84.58558";
$loop = "1";
$fl = "0";

print chr(27) . "[2J";

while ($loop = 1) {

print chr(27) . "[;H";

$iss = file_get_contents("http://api.open-notify.org/iss-now.json");
$isslocation = json_decode($iss, TRUE);
$isslat = $isslocation["iss_position"]["latitude"];
$isslon = $isslocation["iss_position"]["longitude"];

echo "This ISS is currently at ". round($isslat,3).",".round($isslon,3)."\n";

$distance = round(distance ($mylat, $mylon, $isslat, $isslon, "M"),3);

//$distance = trim(fgets(STDIN));

echo "The ISS is about $distance miles from you now!\n And Moving Fast! \n";

if ($distance <= 1350 AND $distance >= 1201) {echo "LED: RED   \n"; $fl = ledredon($fl);}
if ($distance <= 1200 AND $distance >= 1151) {echo "LED: ORANGE\n"; $fl = ledorangeon($fl);}
if ($distance <= 1150 AND $distance >= 951) {echo "LED: YELLOW\n"; $fl = ledyellowon($fl);}
if ($distance <= 950) {echo "LED: GREEN  \n"; $fl = ledgreenon($fl);}
if ($distance >= 1351) {echo "LED: OFF   \n"; $fl = ledoff($fl);}

sleep(5);
}

function ledredon($flag) {
$blink = file_get_contents("http://www.blinkstick.com/d/0c70cbf31503/red.json"); $flag = "1";
return $flag;
}

function ledorangeon($flag) {
$blink = file_get_contents("http://www.blinkstick.com/d/0c70cbf31503/orange.json"); $flag = "1";
return $flag;
}

function ledyellowon($flag) {
$blink = file_get_contents("http://www.blinkstick.com/d/0c70cbf31503/yellow.json"); $flag = "1";
return $flag;
}

function ledgreenon($flag) {
$blink = file_get_contents("http://www.blinkstick.com/d/0c70cbf31503/green.json"); $flag = "1";
return $flag;
}

function ledoff($flag) {
$blink = file_get_contents("http://www.blinkstick.com/d/0c70cbf31503/000000.json"); $flag = "0";
return $flag;
}

function distance($lat1, $lon1, $lat2, $lon2, $unit) {
	 
	  $theta = $lon1 - $lon2;
	  $dist = sin(deg2rad($lat1)) * sin(deg2rad($lat2)) +  cos(deg2rad($lat1)) * cos(deg2rad($lat2)) * cos(deg2rad($theta));
	  $dist = acos($dist);
	  $dist = rad2deg($dist);
	  $miles = $dist * 60 * 1.1515;
	  $unit = strtoupper($unit);
	 
	  if ($unit == "K") {
	    return ($miles * 1.609344);
	  } else if ($unit == "N") {
	      return ($miles * 0.8684);
	    } else {
	        return $miles;
	      }
	}

?>
