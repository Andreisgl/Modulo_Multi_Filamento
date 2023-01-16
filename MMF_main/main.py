import utime
import time
import Stepper
import serial_parser


def command_parser(inc):
    return inc.split()

def mmf_switch(args):
    print(args)
    
def mmf_move(args):
    args.pop(0)
    print(args)
    if args[0] == "A":
            motorA.move_motor(int(args[1]), 1, 0)



motorA = Stepper.Stepper(3, 2, 93) #Direction pin, Step pin, steps/Unit.

from machine import Pin, PWM
selector_AB = PWM(Pin(6))
selector_AB.freq(50)

print("set servo")
selector_AB.duty_u16(40000)

   
        
        


while False:
    motorA.move_motor(1, 1, 0)
    
    motorA.move_motor(1, 1, 1)
    time.sleep(1)
    print("aa")
    


#motorA.move_motor(25, 25, 0)

