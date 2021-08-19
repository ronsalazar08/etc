#!/usr/bin/env python
import pdfkit

options = {
    'page-size': 'A4',
    'margin-top': '0.10in',
    'margin-right': '0.10in',
    'margin-bottom': '0.10in',
    'margin-left': '0.10in',
    'orientation': 'Landscape'
}
pdfkit.from_url('localhost/viewAttendanceLastWeek.php', 'BlairwinAttendanceLastWeek.pdf', options=options)


