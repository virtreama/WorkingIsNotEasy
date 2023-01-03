:: remove editor ue5 project binaries, intermediate and build folder and files
cd WorkingIsNotEasy
rmdir .vs /q /s
rmdir Binaries /q /s
rmdir Build /q /s
rmdir DerivedDataCache /q /s
rmdir Intermediate /q /s
rmdir Platforms /q /s
rmdir Saved /q /s
rmdir Script /q /s
del /q /s /f .vsconfig
del /q /s /f WorkingIsNotEasy.sln