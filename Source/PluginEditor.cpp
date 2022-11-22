/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TestAudioProcessorEditor::TestAudioProcessorEditor (TestAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle((juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag));
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 50);
    addAndMakeVisible(gainSlider);
    
    gainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "GAIN", gainSlider);
    setSize (600, 400);
}

TestAudioProcessorEditor::~TestAudioProcessorEditor()
{
}

//==============================================================================
void TestAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void TestAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth() / 2 - 200, getHeight() / 2 - 100, 400, 200); // add slider to canvas
}
