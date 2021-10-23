# xlhash
Function to generate Excel format hashes used for worksheet and workbook protection


**How to find hash used for workbook and worksheet protection in Excel documents**

Rename the spreadsheet to a .zip file, unzip it, and grep the /xl/worksheets/sheet1.xml file for password. At this point you can just delete the protection XML, save the file, rezip the whole folder, rename back to xlsx and have access to the protected content, but you can also crack the hash. However, due to the nature of the low quality hash method that Microsoft chose, there can be multiple passwords that result in the same hash.

![screenshot showing results of mv test.xlsx test.zip;unzip test.zip;grep password xl/worksheets/sheet1.xml | tail -c 2000 |grep password](https://raw.githubusercontent.com/MikeKozlowicz/xlhash/main/images/Screenshot%20from%202021-10-23%2011-52-47.png?raw=true "screenshot of finding hash")


See page 115 of http://www.openoffice.org/sc/excelfileformat.pdf for a description of the hash algorithm.

**How to crack Excel hash**

Compile: `gcc xlhash.c -o xlhash; chmod +x xlhash`

Crack hash with dictionary: `cat wordlist| while read input; do if [ '83af' = $(echo $input |./xlhash) ]; then echo "Password is $input"; fi; done`

(change `83af` to whatever hash you find in the sheet xml document)
