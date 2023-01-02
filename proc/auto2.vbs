set fso=createobject("scripting.filesystemobject")
set file=fso.opentextfile("D:\PoriaHua\Poria'sGarbageCan\Cpp\cssj\proc\user2.txt")
strCopy = file.readall
file.close
Dim Word
Set Word = CreateObject("Word.Application")
Word.Documents.Add
Word.Selection.Text = strCopy
Word.Selection.Copy
Word.Quit False
Dim WshShell 
Set WshShell = WScript.CreateObject("WScript.Shell")
WshShell.run """D:\PoriaHua\Poria'sGarbageCan\Cpp\cssj\ServiceBot\x64\Debug\ServiceBot.exe"""
WScript.Sleep 2000
WshShell.sendKeys "^v"