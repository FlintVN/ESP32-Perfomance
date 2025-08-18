import time
from machine import Pin

print("Start testing")

# Test for loop
start = time.ticks_ms()
for i in range(10_000_000):
    pass
end = time.ticks_ms()
print("Test \"for loop\": ", time.ticks_diff(end, start))

# Test while loop
start = time.ticks_ms()
j = 0
while j < 10_000_000:
    j += 1
end = time.ticks_ms()
print("Test \"while loop\": ", time.ticks_diff(end, start))

# Test GPIO
pin = Pin(2, Pin.OUT)
while True:
    pin.on()
    pin.off()
    pin.on()
    pin.off()
    pin.on()
    pin.off()
    pin.on()
    pin.off()
