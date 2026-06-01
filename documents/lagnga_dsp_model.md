# Lagnga DSP Physical Model Architecture

The Lagnga is a tight, two-sided closed barrel drum struck with a hard wooden stick. It is modeled using modal synthesis (parallel bandpass resonators) representing the symmetric and antisymmetric coupling of the two skins.

```mermaid
graph TD
    %% Inputs
    Gate[Gate Trigger]
    Vel[Velocity]
    Freq[Fundamental Freq]
    Soft[Mallet Softness]
    
    %% Excitation (Hard Stick)
    Gate --> Imp[Impulsify]
    Imp --> HPF[Highpass 80Hz]
    Soft --> Cutoff[Stick Cutoff 700-2800Hz]
    HPF --> LPF_Stick[Dynamic Lowpass]
    Cutoff --> LPF_Stick
    Vel --> LPF_Stick
    
    LPF_Stick --> Excitation[Excitation Pulse]
    
    %% Modal Resonators
    subgraph Membrane & Air Coupling
        Excitation --> Sym1[Symmetric T01 1.00x]
        Excitation --> Sym2[Symmetric T11 1.59x]
        Excitation --> Sym3[Symmetric T21 2.14x]
        Excitation --> Sym4[Symmetric T02 2.30x]
        
        Excitation --> Ant1[Antisymmetric T01 1.18x]
        Excitation --> Ant2[Antisymmetric T11 1.72x]
        
        Excitation --> Body[Shallow Air Cavity 3.80x]
    end
    
    %% Output Stage
    Sym1 --> Mix[Summing Bus]
    Sym2 --> Mix
    Sym3 --> Mix
    Sym4 --> Mix
    Ant1 --> Mix
    Ant2 --> Mix
    Body --> Mix
    
    Mix --> Sat[Soft Tanh Saturation]
    Freq --> LPF_Body[Wood Absorption 3x Fundamental]
    Sat --> LPF_Body
    LPF_Body --> Out[Stereo Output]
```
