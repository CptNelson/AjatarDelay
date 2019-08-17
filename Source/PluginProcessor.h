/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#define M_PI 3.14159265f

#define DELAYTIME_ID "delaytime"
#define DELAYTIME_NAME "DelayTime"
#define FEEDBACK_ID "feedback"
#define FEEDBACK_NAME "Feedback"
#define DRYWET_ID "drywet"
#define DRYWET_NAME "DryWet"
#define SMOOTH_ID "smooth"
#define SMOOTH_NAME "Smooth"

//==============================================================================
/**
*/
class AjatarDelayAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AjatarDelayAudioProcessor();
    ~AjatarDelayAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	float lerp(float v0, float v1, float t);

	float cosineInterpolate(float x0, float x1, float phase);

	float cubicInterpolate(float x0, float x1, float x2, float x3, float mu);


	AudioProcessorValueTreeState treeState;
	AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

private:

	std::unique_ptr<float[]> mDelayBufferLeft;
	std::unique_ptr<float[]> mDelayBufferRight;

	float mDelayReadPosition{ 0.0f };
	float mDelayTimeInSamples{ 0.0f };
	float mDelayTimeSmoothed{ 0.0f };

	float mFeedBackLeft{ 0.0f };
	float mFeedBackRight{ 0.0f };

	int mDelayBufferWritePosition{ 0 };
	int mDelayBufferLength{ 0 };

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AjatarDelayAudioProcessor)
};
