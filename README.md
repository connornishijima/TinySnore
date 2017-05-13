# TinySnore
Library for putting ATtiny25/45/85 to timed deep sleep in one line of code!

----------
# Disclaimer

This is the simplest possible way to make an ATtiny enter deep sleep, using only one simple function: **snore(*sleep_ms*)**. It will disable brownout detection and the ADC during the downtime, and there are currently no options to change this. It's just a quick "all guns go" to put the Tiny in a coma for a custom amount of time with a quick function call!

----------
# Explanation

If your ATtiny25/45/85 project runs on a battery, you'll quickly find out that optimizing your power consumption is **extremely** important. TinySnore is a quick way to do this! Let's see what you can do to lower your power consumption:

- *Can your project run on a lower voltage than 5 volts?* **Lower the voltage!** Use a 3V coin cell instead of 4 AAs! (6V)
- *Can your project run with a clock speed lower than 16MHz?* **Lower the clock speed!** Use 1MHz instead for the leanest power consumption!
- *Does your project sit idle for any amount of time?* **Use TinySnore to put it in a deep sleep during these times!**
 
If you have a **delay()** call anywhere in your code - try replacing with with **snore()**! Your ATtiny will enter a deep sleep during that time, and this can bring the power consumption all the way down to ***0.0047 mA***!
