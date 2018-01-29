# ICS-Shifter
A workaround for the following bug: https://gitlab.gnome.org/GNOME/gnome-calendar/issues/143

Instead of fixing the bug in the GNOME-Calendar this code allows you to shift all the dates in the calendar file to match with your timezone.
The code can ofcourse also be used to move all dates in a given file around by an integer amound of hours - for whatever reason you'd like to do that.
However i higly recommend saving an original copy of the .ics File for later use.

I'm not a trained programmer - therefore, if you spot an error, please let me know I'd love to learn.

# How to use ICS-Shifter
- compile the code
- put your .ics-file in the same directory as the compiled programm
- run the programm & enter your timezone and teh name of the file
- the programm will generate a second file with the name "SHIFTED-" + your filename
