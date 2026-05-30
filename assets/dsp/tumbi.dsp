import("stdfaust.lib");

freq = hslider("freq", 329.63, 80, 2000, 0.1);
gate = button("gate");
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gain = hslider("gain", 1.0, 0, 1, 0.01);

vibratoRate = hslider("vibrato_rate", 6.0, 3.0, 10.0, 0.1) : si.smoo;
vibratoDepth = hslider("vibrato_depth", 0.05, 0.0, 0.1, 0.001) : si.smoo;
vibrato = os.osc(vibratoRate) * vibratoDepth;

trig = gate > gate';

toinEnv = trig : + ~ *(0.99936);
toinBend = toinEnv * 0.15;

humanizedFreq = freq * (1.0 + vibrato + toinBend);

nailEnv = trig : + ~ *(0.995);
snap = trig * velocity;
nail = no.noise * nailEnv * velocity * 0.5;
exc = (snap + nail) * 1.5 : ma.tanh;

del = ma.SR / humanizedFreq;
linear_fdelay(maxDel, d, x) = (1.0 - frac) * x1 + frac * x2
with {
    int_del = int(d);
    frac = d - int_del;
    x1 = de.delay(maxDel, int_del, x);
    x2 = de.delay(maxDel, int_del + 1, x);
};

lp = * (0.95) : + ~ * (0.05);

bridge(x) = x * (1.0 - 0.005 * abs(x));

membrane(x) = x * 0.97 + fi.resonbp(200.0, 4.0, 1.0, x) * 0.03;

stringLoop = exc : (+ : linear_fdelay(4096, del - 1.0)) ~ (lp : bridge : membrane : _ * 0.998);

process = stringLoop * 1.5 : ma.tanh : *(gain) : min(1.0) : max(-1.0);
