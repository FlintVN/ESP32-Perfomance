
import esp.machine.*;

public class main {
    public static void main(String[] args) throws Exception {
        System.out.println("Start testing");
        testForLoop();
        testWhileLoop();
        testGpio();
    }

    private static void testForLoop() {
        long start = System.currentTimeMillis();
        for(int i = 0; i < 10_000_000; i++) {

        }
        long end = System.currentTimeMillis();
        System.out.println("Test \"for loop\": " + (end - start));
    }

    private static void testWhileLoop() {
        long start = System.currentTimeMillis();
        int j = 0;
        while(j < 10_000_000) {
            j++;
        }
        long end = System.currentTimeMillis();
        System.out.println("Test \"while loop\": " + (end - start));
    }

    private static void testGpio() {
        Pin pin = new Pin(2, PinMode.OUTPUT);
        while(true) {
            pin.set();
            pin.reset();
            pin.set();
            pin.reset();
            pin.set();
            pin.reset();
            pin.set();
            pin.reset();
        }
    }
}
