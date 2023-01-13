import utime
import time
import Stepper



def command_parser(inc):
    return inc.split()

def mmf_switch(args):
    print(args)
    
def mmf_move(args):
    args.pop(0)
    print(args)
    if args[0] == "A":
            motorA.move_motor(int(args[1]), 1, 0)



motorA = Stepper.Motor(3, 2, 93) #Motor for filament A

from machine import Pin, PWM
selector_AB = PWM(Pin(6))
selector_AB.freq(50)

print("set servo")
selector_AB.duty_u16(40000)

   
        
        
from machine import UART, Pin
uart1 = UART(1, baudrate=9600, tx=Pin(4), rx=Pin(5))
#uart1.write('hello\n')  # write 5 bytes

master_command = "MMF:"

#while True:
#    uart1.write('hello\n')

while False:
    incoming = uart1.read()
    incoming = str(incoming)
    if incoming != 'None': #Only continue if something was received
        incoming = incoming[2:-1] #Strip byte stuff
        if incoming[:len(master_command)] == master_command: #See if master command is present
            incoming = incoming[len(master_command):]
            
            
            
            incoming = command_parser(incoming)
            print( incoming )
            #uart1.write(str(incoming))
            
            # The commands to be executed
            command = incoming[0]
            if command == "SWITCH":
                mmf_switch(incoming)
            elif command == "MOVE":
                mmf_move(incoming)
            
        else: #If no master command is present, pass command to printer:
            pass #TODO: Implement pass to printer
    
    uart1.write('\n')
    time.sleep(0.1)




    


#motorA.move_motor(25, 25, 0)

