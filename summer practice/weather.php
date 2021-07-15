<?php
  $apiKey = "cc181af6b6743cd5162f4914f382c990";
  $lat='52.6031';
  $lon='39.5708';
  $url='https://api.openweathermap.org/data/2.5/onecall?lat='.$lat.'&lon='.$lon.'&lang=ru&exclude=current,minutely,hourly,alerts&units=metric&appid='. $apiKey;
  $ch=curl_init();
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
  curl_setopt($ch, CURLOPT_URL, $url);
  $data = json_decode(curl_exec($ch));
  curl_close($ch);
  $date=getdate();
  $day=$date['mday'];
  $month=$date['month'];
?>
<html lang="rus">
<head>
<link rel="preconnect" href="https://fonts.gstatic.com">
<link href="https://fonts.googleapis.com/css2?family=Montserrat&display=swap" rel="stylesheet">
<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    <script type="text/javascript">
      google.charts.load('current', {'packages':['corechart']});
      google.charts.setOnLoadCallback(drawChart);
      function drawChart() {
        var info = google.visualization.arrayToDataTable([
          ['Day', 'Max T', 'Ave T', 'Min T'],
          <?php
            foreach($data->daily as $row){
              if($day>30){
                $day=1;
              }
              echo "['".$day." ".$month."', ".$row->temp->max.", ".$row->temp->day.", ".$row->temp->min."],";
              $day++;
            }
          ?>
        ]);
        var options = {
          title: 'Weathercast',
          hAxis: {title: 'Day',  titleTextStyle: {color: '#333'}},
          vAxis: {minValue: 0}
        };
        var chart = new google.visualization.AreaChart(document.getElementById('chart_div'));
        google.visualization.events.addListener(chart, 'ready', function () {
            chart_div.innerHTML = '<img id="chart" src=' + chart.getImageURI() + '>';
            document.getElementById("download_link").setAttribute("href", chart.getImageURI())
            //document.getElementById("download_link").click();
        });
        chart.draw(info, options);
      }
    </script>
</head>
<body>
  <style>
    *{
      font-family: 'Montserrat', sans-serif;
    }
  </style>
  <div id="chart_div" style="width: 100%; height: 500px;"></div>
  <div>
    <?php
        $text=" info \n";
        $max=$data->daily[0]->temp->day;
        $day=$date["mday"];
        $maxTDay=$day;
        $month=$date["month"];
        foreach($data->daily as $row){
          if($day>30){
            $day=1;
          }
          $text =$text."Day: ".$day." ".$month."  Max temp: ".$row->temp->max." °C  Ave temp: ".$row->temp->day." °C  Min temp: ".$row->temp->min." °C"."\n";
          //echo '<p>Day: '.$day.' '.$month.'<br>Max temp: '.$row->temp->max.' °C<br>Ave temp: '.$row->temp->day.' °C<br>Min temp: '.$row->temp->min.' °C</p>';
          if($row->temp->day>$max){
            $max=$row->temp->day;
            $maxTDay=$day;
          }
          $day++;
        }
        $text =$text."Max temp day: ".$maxTDay." ".$month."  Max temp: ".$max." °C";
        echo '<p style="font-size:1.5vw">Max temp day: '.$maxTDay.' '.$month.'  Max temp: '.$max.' °C</p>';
        $var_str = var_export($text, true);
        file_put_contents('info.txt', $var_str);
    ?>
  </div>
  <a style='text-decoration:none; font-weight:bold; font-size:1.5vw; text-transform:uppercase; color:black;' id="download_link" href="/" download>download graph</a>
  <p> </p>
  <a style='text-decoration:none; font-weight:bold; font-size:1.5vw; text-transform:uppercase; color:black;' href="/">download text</a>
</body>
