# Ngachen DSP Physical Model Architecture

The Ngachen is a large single-headed drum placed over a rigid hemispherical metal/clay pot. The defining characteristic is the Helmholtz pot resonance and the thick padded mallet.

```mermaid
graph TD
    %% Inputs
    Gate[Gate Trigger]
    Vel[Velocity]
    Freq[Fundamental Freq]
    Soft[Mallet Softness]
    
    %% Excitation (Padded Mallet)
    Gate --> Imp[Impulsify]
    Soft --> Cutoff[Mallet Cutoff 50-450Hz]
    Imp --> LPF_Mallet[Heavy Lowpass]
    Cutoff --> LPF_Mallet
    Vel --> LPF_Mallet
    
    LPF_Mallet --> Excitation[Deep Bloom Pulse]
    
    %% Modal Resonators
    subgraph Membrane & Pot Cavity
        Excitation --> Mem1[Membrane T01 1.00x]
        Excitation --> Mem2[Membrane T11 1.59x]
        Excitation --> Mem3[Membrane T21 2.14x]
        Excitation --> Mem4[Membrane T02 2.30x]
        Excitation --> Mem5[Membrane T31 2.65x]
        
        Excitation --> Pot[Helmholtz Pot 0.93x \n 3.5s Decay]
        Excitation --> Air[Sub-octave Air 0.50x]
    end
    
    %% Output Stage
    Mem1 --> Mix[Summing Bus]
    Mem2 --> Mix
    Mem3 --> Mix
    Mem4 --> Mix
    Mem5 --> Mix
    Pot --> Mix
    Air --> Mix
    
    Mix --> Sat[Light Tanh Saturation]
    Sat --> HPF[Highpass 18Hz DC Block]
    Freq --> LPF_Body[Natural Body Roll-off 4.5x]
    HPF --> LPF_Body
    LPF_Body --> Out[Stereo Output]
```
