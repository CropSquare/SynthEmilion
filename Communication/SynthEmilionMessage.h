#pragma once
#include <memory>
#include "types.h"

namespace SQU {
	namespace Comm {

		enum ComponentType {
			Main = 0,
			Operator,
			Envelope,
			Filter,
			LFO
		};

		enum ParameterType {
			//====================
			// Main
			ComponentActivation = 256,
			Volume,
			MonoLegato,
			Portamento,
			//====================
			// Operator
			Pitch,
			Pan,
			WaveTable,
			//====================
			// Envelope
			Attack,
			AttackBend,
			Decay,
			DecayBend,
			Sustain,
			Release,
			ReleaseBend,
			//====================
			// Filter
			Type,
			Slope,
			Frequency,
			Quality
		};

		struct SynthEmilionMessage
		{
			SynthEmilionMessage() {}
			~SynthEmilionMessage() {}

			union ParameterValue {
				ParameterValue() {}
				~ParameterValue() {}
				int		intValue;
				double	doubleValue;
				bool	boolValue;
				wavetable_ptr wavetableType;
			};

			ComponentType component;
			int componentNumber;
			ParameterType parameter;
			ParameterValue parameterValue;
		};

	}
}

