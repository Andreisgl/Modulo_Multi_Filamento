import utime
import time

class Motor:
    dir_pin = ""
    step_pin = ""
    steps_unit = ""
    def __init__(self, d, s, u):
        global dir_pin
        global step_pin
        global steps_unit
        self.d = d
        self.s = s
        self.u = u
        
        step_pin = machine.Pin(s, machine.Pin.OUT)
        dir_pin = machine.Pin(d, machine.Pin.OUT)
        steps_unit = u
        
        step_pin.value(0)
        dir_pin.value(0)
        print("!!!")
        
    def step_stepper(self, direction):        
        dir_pin.value(direction)
        step_pin.value(0)
        step_pin.value(1)
   
    def move_motor(self, dist_unit, vel_UpS, direction):
        print("###")
        
        total_steps = dist_unit * steps_unit
        steps_psec = vel_UpS * steps_unit
        tim = total_steps/steps_psec
        #
        sec_pstep = tim/total_steps
        
        ###
        for i in range(total_steps):
            self.step_stepper(direction)
            time.sleep(sec_pstep)


def command_parser(inc):
    return inc.split()

def mmf_switch(args):
    print(args)
    
def mmf_move(args):
    args.pop(0)
    print(args)
    if args[0] == "A":
            motorA.move_motor(int(args[1]), 1, 0)


motorA = Motor(3, 2, 93) #Motor for filament A


   
        
        
from machine import UART, Pin
uart1 = UART(1, baudrate=9600, tx=Pin(4), rx=Pin(5))
#uart1.write('hello\n')  # write 5 bytes

master_command = "MMF:"

#while True:
#    uart1.write('hello\n')

while True:
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

