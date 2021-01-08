# wifi-remote-control
A simple wifi-based remote control, raspberry pi as web server

**TODO: image and video go here.**

Keywords: embedded systems, raspberry pi, iot

## Description
Any device can access the webpage hosted on the Raspberry Pi when it's in the same Wifi with the Pi. An LED is controlled by a GPIO pin on the Pi. The webpage displays the LED status (ON or OFF) and allows the user to toggle the LED.

## Try It Out
You'll need:
- Raspberry Pi (running Linux)
- Circuit Supplies (LED, resistor, wires, etc.)
- Wifi Access (hotspot works, too)
- Device with a browser (other than the Pi)

Steps:
1. Turn your Raspberry Pi into a web server. Follow [this tutorial](https://www.youtube.com/watch?v=9pn1KKhxwdM) by Make Tech Easier.
2. Put the files in `src/html/` in `/var/www/html/` on your Pi.
3. Build the circuit. Use GPIO2 on the Pi to turn the LED on and off.
4. Open a terminal for `src/` and do the following:
    - `make`
    - `sudo insmod switch.ko` The LED will blink and stay on after this.
    - While unlikely, make sure there's no file named `sw` under `/dev/`. (`ls /dev/sw` gives no console output)
    - `sudo mknod "/dev/sw" c 60 0` **Do not `cat` the device file created.** Due to my hasty implementation, doing so will result in infinite printing of nothing.
5. Get the ip address of your Pi. Run `hostname -I` in a terminal, and the first address would be it.
6. Go to the other device. Put the ip address of the Pi into the browser and press enter. You should see the web interface.
7. Let me know if there's any issues. Otherwise, enjoy turning on and off the LED with the remote controller you just built.
