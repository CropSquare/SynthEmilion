#pragma once
#include <string>
#include <vector>
#include <memory>
#include <map>

using wavetable_t = std::vector<double>;
using wavetable_ptr = std::shared_ptr<wavetable_t>;

typedef struct
{
	double attack;
	double decay;
	double sustain;
	double release;
} envelope_params_t;


typedef struct
{
	size_t samplerate;
	unsigned char midi_note;
	unsigned char velocity;
	envelope_params_t envelope;
	wavetable_ptr wavetable;
} voice_params_t;