This is a template project for people who want to use the PJRC [Teensy](https://www.pjrc.com/teensy/) 4.0 or Teensy 4.1 controllers to drive multiple strands of WS281x-type pixels ("[Neopixels](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels)") in parallel using the [FastLED](https://fastled.io/) library. It assumes that you are using [PlatformIO](https://platformio.org/) with VS Code.

The Teensy 4.0/4.1 development boards are incredibly powerful, and can drive multiple LED strips in parallel using any pin. You can easily drive 32 separate strips of LEDs from a single Teensy 4.1. Using the code examples shown in this template project, RGB data is sent to the LED strips using direct memory access rather than bit banging, so almost no CPU cycles are used to maintain an arbitrarily high refresh rate limited only by the 800khz speed of the WS281x protocol.

This template gets you set up with FastLED, a standard and fast library for addressing pixel strips that includes a wide variety of functions to make cool RGB patterns. Unfortunately, off-the-shelf FastLED is not currently set up to take advantage of the Teensy 4.x parallel direct memory output mode, which is why you want to start from this code example which provides a custom FastLED Controller class that does.

Learn more about the technique used here: [https://blinkylights.blog/2021/02/03/using-teensy-4-1-with-fastled/](https://blinkylights.blog/2021/02/03/using-teensy-4-1-with-fastled/)
