from machine import UART, Pin
uart1 = UART(1, baudrate=9600, tx=Pin(0), rx=Pin(1))
#uart1.write('hello\n')  # write 5 bytes

master_command = "MMF:"

#while True:
#    uart1.write('hello\n')

class serial_parser:
    def it_loop(self):
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
        print("serial loop")    
        uart1.write('\n')
        time.sleep(0.1)
