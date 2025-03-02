from tkinter import *
from tkinter import messagebox
from tkinter import ttk
import serial
import time

global song_number

def song_chooser():
    global song_number
    if selected_song.get() == 'Style (Taylor\'s Version) - Taylor Swift':
        song_number = '1'
    elif selected_song.get() == 'Kahoot Theme Song':
        song_number = '2'
    elif selected_song.get() == 'All I Want For Christmas is You - Mariah Carey':
        song_number = '3'


def play_song():
    song_chooser()
    ser.write(song_number.encode())

def stop_song():
    quitcode = '0'
    ser.write(quitcode.encode())

# establish connection!
try:
    ser = serial.Serial('COM6', 9600)  
    time.sleep(2)
    print("Serial connection established")
except Exception as e:
    messagebox.showerror("Error", str(e))
    exit()

def quit_tk():
    quitcode = '0'
    ser.write(quitcode.encode())
    ser.close()
    root.destroy()

root = Tk()
root.geometry("450x200")
root.title("Song Selection Menu")

info_label = Label(root, text='Select a song from the drop down list, then click play!')
info_label.grid(row=1, column=1, padx=20, pady=10, sticky='news')

songs = ('Style (Taylor\'s Version) - Taylor Swift',
         'Kahoot Theme Song',
         'All I Want For Christmas is You - Mariah Carey')

selected_song = StringVar()
song_combobox = ttk.Combobox(root, textvariable=selected_song, width=40)
song_combobox.grid(row=2, column=1, columnspan=3, padx=20, pady=10)
song_combobox['values'] = songs
song_combobox['state'] = "readonly"

buttons_frame = Frame(root)
buttons_frame.grid(row=3, column=1)

play_button = Button(buttons_frame, text='Play', command=play_song)
play_button.grid(column=1, row=1, padx=10)

stop_button = Button(buttons_frame, text='Stop', command=stop_song)
stop_button.grid(column=2,row=1,padx=10)

quit_button = Button(buttons_frame, text='Quit', command=quit_tk)
quit_button.grid(column=3, row=1, padx=10)

root.mainloop()
