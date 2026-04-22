class FaustHiHat {
public:
    FaustHiHat(float sampleRate);
    void strike(float velocity);
    void setOpenness(float amount);
    void render(int numFrames, float* buffer);

private:
    float _sampleRate;
    float _decay;
    float _env;
    float _filterState;
};
