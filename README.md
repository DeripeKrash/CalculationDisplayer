# Calculation Displayer

A simple over-engeenired app for pre established calculation.

- I made it to learn how to build for android and as a way to have fun with Unreal properties (also to help someone in my family but that's another subject).
- The project allows to define a class c++ and it will generated a widget to display the calculation for the users.
- I put a few mecanic calculation I had to to as an exemple
- It's as I said : Over-engeenired. You probably don't need to go through all the trouble of interpreting class parameters. A simpler version with a custom parameter map would probably do the job just as well.
- But hey ! Over-engeeniring is fun !  :D 

# How to use it

## First you create your class
- It has to inherit UCalculationData (which itself inherit from UDataAsset)
- You add "ProccessedValue" in the meta for the parameter to be visible and "CalculationFunction="{YourCppFunction}"" to determine which function will setup its value

<div align="center">
    <img src="Screenshots/CodeExemple.png" width=50% height=50% />
</div>

## Second you create a DataAsset to setup the display parameter
- You create a DataAsset from your created class
- You click on GenerateProcessedValueData
- You do your setup
- You can click on ComputeAllCalculationParamter to check if your calculations works

<div align="center">
    <img src="Screenshots/AssetExemple.png" width=50% height=50% />
</div>

## Then you add the CalculationData to a MenuAsset
- Create the MenuAsset if it's not already done 
- SetupMenuChildren will setup the parent for all the menu in the SubMenu list

<div align="center">
    <img src="Screenshots/MainMenuExemple.png" width=49% height=49% />
    <img src="Screenshots/SubMenuExemple.png" width=49% height=49% />
</div>

## You make sure you MenuWidget is setup
- You can setup it in different way. Here it's already defined in the parameter for convenience
<div align="center">
    <img src="Screenshots/WidgetMenuExemple.png" width=50% height=50% />
</div>

## Magic !

<div align="center">
    <img src="Screenshots/VisualExemple.png" width=50% height=50% />
</div>
