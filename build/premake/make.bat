rem
rem set premake location
rem
@SET Premake=..\..\..\OpenEaagles3rdParty\bin\premake4.exe
rem
rem delete old solution/workspace files
rem
rmdir /S /Q ..\codeblocks
rmdir /S /Q ..\vs2008
rmdir /S /Q ..\vs2010
rem
rem create solution/workspace files
rem
%Premake% codeblocks
%Premake% vs2008
%Premake% vs2010

