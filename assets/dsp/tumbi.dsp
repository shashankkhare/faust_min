import("stdfaust.lib");

freq = hslider("freq", 329.63, 80, 2000, 0.1);
gate = button("gate");
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gain = hslider("gain", 1.0, 0, 1, 0.01);

vibratoRate = hslider("vibrato_rate", 5.0, 3.0, 10.0, 0.1) : si.smoo;
vibratoDepth = hslider("vibrato_depth", 0.003, 0.0, 0.05, 0.001) : si.smoo;
vibrato = os.osc(vibratoRate) * vibratoDepth;

trig = gate > gate';

toinEnv = trig : + ~ *(0.9995);
toinBend = toinEnv * 0.005;

humanizedFreq = freq * (1.0 + vibrato + toinBend);

nailEnv = trig : + ~ *(0.995);
strike = hslider("strike", 0.5, 0, 1, 0.01);

snap = trig * velocity;
nail = no.noise * nailEnv * velocity * 0.5;
exc = (snap * (1.0 - strike * 0.8) + nail * strike) * 1.5 : ma.tanh;

del = ma.SR / humanizedFreq;
linear_fdelay(maxDel, d, x) = (1.0 - frac) * x1 + frac * x2
with {
    int_del = int(d);
    frac = d - int_del;
    x1 = de.delay(maxDel, int_del, x);
    x2 = de.delay(maxDel, int_del + 1, x);
};

bridge(x) = x * (1.0 - 0.005 * abs(x));

membrane(x) = x + fi.resonbp(200.0, 2.0, 0.01, x);

stringLoop = exc : (+ : linear_fdelay(4096, del - 1.0)) ~ (bridge : membrane : _ * 0.9997);

bodyHP = fi.highpass(2, 150.0);

process = stringLoop * 0.6 : bodyHP : ma.tanh : *(gain) : min(1.0) : max(-1.0);
