
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  <style type="text/css" media="screen">
  body, html {
    padding: 3px 3px 3px 3px;

    background-color: #F0F0F0;
    color: #FF8000;

    font-family: courier new;
    font-size: 50pt;
    text-align: center;
  }
  button {
    padding: 15px 90px;
    
    background-color: #666666;
    color: #FFFF00;

    font-family: times new roman;
    font-size: 50px;
    text-align: center;
  }
  </style>
  <body>
    <div>LED SWITCH</div>
    <br/>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script>
    function func() {
      var light_on;
      $.post("check.php", {}, function(data) {
        light_on = (data[0] == 'H') ? false : true; // toggle LED status 
        if (light_on) {
          document.getElementById("foo").innerHTML = "ON";
          $.post("control.php", { status: 1 }, function(){});
        } else {
          document.getElementById("foo").innerHTML = "OFF";
          $.post("control.php", { status: 0 }, function(){});
        }
      });
    }
    </script>
    <button onclick="func()">ON/OFF</button>
    <p id="foo"></p>
  </body>
</html>
