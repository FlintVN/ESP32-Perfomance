using System;
using System.Diagnostics;
using System.Threading;
using System.Device.Gpio;

namespace NanoFramework {
    public class Program {
        public static void Main() {
            Debug.WriteLine("Start testing");
            testForLoop();
            testWhileLoop();
            testGpio();
        }

        private static void testForLoop() {
            long start = DateTime.UtcNow.Ticks;
            for(int i = 0; i < 10_000_000; i++) {

            }
            long end = DateTime.UtcNow.Ticks;
            Debug.WriteLine("Test \"for loop\": " + (end - start) / 10000.0);
        }

        private static void testWhileLoop() {
            long start = DateTime.UtcNow.Ticks;
            int j = 0;
            while(j < 10_000_000) {
                j++;
            }
            long end = DateTime.UtcNow.Ticks;
            Debug.WriteLine("Test \"for loop\": " + (end - start) / 10000.0);
        }

        private static void testGpio() {
            GpioController gpioController = new GpioController();
            GpioPin pin = gpioController.OpenPin(2, PinMode.Output);
            while(true) {
                pin.Write(PinValue.High);
                pin.Write(PinValue.Low);
                pin.Write(PinValue.High);
                pin.Write(PinValue.Low);
                pin.Write(PinValue.High);
                pin.Write(PinValue.Low);
                pin.Write(PinValue.High);
                pin.Write(PinValue.Low);
            }
        }
    }
}
