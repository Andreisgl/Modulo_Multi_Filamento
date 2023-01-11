import utime
import time
import machine

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
        print("Init Motor Class")
        
    def step_stepper(self, direction):        
        dir_pin.value(direction)
        step_pin.value(0)
        step_pin.value(1)
   
    def move_motor(self, dist_unit, vel_UpS, direction):
        #print("###")
        
        total_steps = dist_unit * steps_unit
        steps_psec = vel_UpS * steps_unit
        tim = total_steps/steps_psec
        #
        sec_pstep = tim/total_steps
        
        ###
        for i in range(total_steps):
            self.step_stepper(direction)
            time.sleep(sec_pstep)