import serial
import keyboard

ser = serial.Serial('COM7', 9600, timeout=1)  # Replace with your port

print("Listening for NodeMCU commands...")

while True:
    try:
        line = ser.readline().decode().strip()
        if not line:
            continue
        print(f"Received: {line}")

        if line == "COPY_ACTION":
            keyboard.press_and_release('ctrl+c')
        elif line == "PASTE_ACTION":
            keyboard.press_and_release('ctrl+v')
        elif line == "UNDO_ACTION":
            keyboard.press_and_release('ctrl+z')
        elif line == "REDO_ACTION":
            keyboard.press_and_release('ctrl+y')
        elif line == "PRINT_ACTION":
            keyboard.press_and_release('ctrl+p')
        elif line == "SS_ACTION":
            keyboard.press_and_release('win+shift+s')
        elif line == "VOLUME_UP":
            keyboard.press_and_release('volume up')
        elif line == "VOLUME_DOWN":
            keyboard.press_and_release('volume down')

    except KeyboardInterrupt:
        print("Exiting...")
        break

