import("stdfaust.lib");
tableData = waveform { 1.0, 2.0, 3.0, 4.0 };
cell(idx) = (tableData, int(idx)) : rdtable;
process = cell(0);
