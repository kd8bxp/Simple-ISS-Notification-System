<?php

$peopleapi = "http://api.open-notify.org/astros.json";

$json = file_get_contents($peopleapi);
$people = json_decode($json, TRUE);

//print_r($people);

$number = $people['number'];
echo "There are $number of people in space right now.\n\n";
for ($i = 0; $i <= ($number-1); $i++) {
echo $people['people'][$i]['name'] . " on board " . $people['people'][$i]['craft'] . "\n";
}

?>
