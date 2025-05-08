# RimworldResearchTreePositionPatchGenerator
Turns the output of the copy-paste from the dev-mode research tree in Rimworld into an XML patch file that works.

I made this for myself, but anyone is free to make use of it too.

# Usage
First, open RimWor and enable Devmode. Then, go open a save or a dev quicktest colony and open the research menu. Enable the edit mode in the top right of the research menu. Now, you can drag nodes around as you see fit.

Once you are done reorganizing, press the two paper icon near the edit mode toggle to get the information needed to make these changes. Close the game.

Create an "input.txt" and paste the clipboard contents you got from the game. It should look something like this example:

(WARNING: do NOT remove blank lines. This file is parsed in a way that requires a very consistent format that you get from the copy button in Rimworld).
```xml
Stonecutting
  <researchViewX>0.00</researchViewX>
  <researchViewY>4.00</researchViewY>

ComplexClothing
  <researchViewX>1.00</researchViewX>
  <researchViewY>2.50</researchViewY>

CarpetMaking
  <researchViewX>1.00</researchViewX>
  <researchViewY>1.90</researchViewY>

PlateArmor
  <researchViewX>2.00</researchViewX>
  <researchViewY>2.20</researchViewY>

Electricity
  <researchViewX>4.00</researchViewX>
  <researchViewY>3.20</researchViewY>

```
then you can build the program, and run it like so:

```
> g++ ./treeparse.cpp
> ./a.out
```
and you should get a patch.xml file that looks something like this:
```xml
<?xml version="1.0" encoding="utf-8"?>
<Patch>
	<Operation Class="PatchOperationReplace">
		<xpath>Defs/ResearchProjectDef[defName="Stonecutting"]/researchViewX</xpath>
		<value>
		    <researchViewX>0.00</researchViewX>
		</value>
	</Operation>
	<Operation Class="PatchOperationReplace">
		<xpath>Defs/ResearchProjectDef[defName="Stonecutting"]/researchViewY</xpath>
		<value>
		    <researchViewY>4.00</researchViewY>
		</value>
	</Operation>
	<Operation Class="PatchOperationReplace">
		<xpath>Defs/ResearchProjectDef[defName="ComplexClothing"]/researchViewX</xpath>
		<value>
		    <researchViewX>1.00</researchViewX>
		</value>
	</Operation>
	<Operation Class="PatchOperationReplace">
		<xpath>Defs/ResearchProjectDef[defName="ComplexClothing"]/researchViewY</xpath>
		<value>
		    <researchViewY>2.50</researchViewY>
		</value>
	</Operation>
	<Operation Class="PatchOperationReplace">
		<xpath>Defs/ResearchProjectDef[defName="CarpetMaking"]/researchViewX</xpath>
		<value>
		    <researchViewX>1.00</researchViewX>
		</value>
	</Operation>
	<Operation Class="PatchOperationReplace">
		<xpath>Defs/ResearchProjectDef[defName="CarpetMaking"]/researchViewY</xpath>
		<value>
		    <researchViewY>1.90</researchViewY>
		</value>
	</Operation>
	<Operation Class="PatchOperationReplace">
		<xpath>Defs/ResearchProjectDef[defName="PlateArmor"]/researchViewX</xpath>
		<value>
		    <researchViewX>2.00</researchViewX>
		</value>
	</Operation>
	<Operation Class="PatchOperationReplace">
		<xpath>Defs/ResearchProjectDef[defName="PlateArmor"]/researchViewY</xpath>
		<value>
		    <researchViewY>2.20</researchViewY>
		</value>
	</Operation>
	<Operation Class="PatchOperationReplace">
		<xpath>Defs/ResearchProjectDef[defName="Electricity"]/researchViewX</xpath>
		<value>
		    <researchViewX>4.00</researchViewX>
		</value>
	</Operation>
	<Operation Class="PatchOperationReplace">
		<xpath>Defs/ResearchProjectDef[defName="Electricity"]/researchViewY</xpath>
		<value>
		    <researchViewY>3.20</researchViewY>
		</value>
	</Operation>
</Patch>
```
Your patch file is now ready to be included in a mod. Make sure it loads after any mod that adds or modifies research nodes you are modifying.
