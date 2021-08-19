#!/usr/bin/env python3
import pdfkit

options = {
    'page-size': 'A4',
    'margin-top': '0.10in',
    'margin-right': '0.10in',
    'margin-bottom': '0.10in',
    'margin-left': '0.10in',
    'orientation': 'Landscape'
}
pdfkit.from_url('http://10.44.0.145/viewAttendance.php', '/home/pi/Desktop/BlairwinAttendanceCurrentWeek.pdf', options=options)
