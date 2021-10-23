# xlhash
Function to generate Excel format hashes used for worksheet and workbook protection


**How to find and remove workboot and worksheet protection from Excel documents**

Rename the spreadsheet to a .zip file, unzip it, and grep the /xl/worksheets/sheet1.xml file for password. At this point you can just delete the protection XML, save the file, rezip the whole folder, rename back to xlsx and have access to the protected content, but you can also crack the hash. However, due to the nature of the low quality hash method that Microsoft chose, there can be multiple passwords that result in the same hash.

See page 115 of http://www.openoffice.org/sc/excelfileformat.pdf for a description of the hash algorithm.

