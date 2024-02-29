<Qucs Schematic 0.0.19>
<Properties>
  <View=0,-60,1396,1115,1,0,0>
  <Grid=10,10,1>
  <DataSet=divider.dat>
  <DataDisplay=divider.dpl>
  <OpenDisplay=1>
  <Script=divider.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <Vdc V1 1 320 330 18 -26 0 1 "10 V" 1>
  <GND * 1 460 420 0 0 0 0>
  <.DC DCsim 1 90 330 0 47 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <R R1 1 600 350 15 -26 0 1 "5 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R2 1 600 270 15 -26 0 1 "5 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
</Components>
<Wires>
  <320 360 320 400 "" 0 0 0 "">
  <320 400 460 400 "" 0 0 0 "">
  <460 400 460 420 "" 0 0 0 "">
  <600 380 600 400 "" 0 0 0 "">
  <460 400 600 400 "" 0 0 0 "">
  <320 180 320 300 "" 0 0 0 "">
  <320 180 600 180 "" 0 0 0 "">
  <600 180 600 240 "" 0 0 0 "">
  <600 300 600 320 "mid_voltage" 420 260 9 "">
</Wires>
<Diagrams>
  <Tab 320 674 314 214 3 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 1 315 0 225 "" "" "">
	<"mid_voltage.V" #0000ff 0 3 1 0 0>
	<"V1.I" #0000ff 0 3 1 0 0>
  </Tab>
</Diagrams>
<Paintings>
</Paintings>
