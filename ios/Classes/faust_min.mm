/*
 * Copyright (c) 2026 Shashank Khare
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#import <Flutter/Flutter.h>
#import <Foundation/Foundation.h>
#include "../../src/faust_min.h"

__attribute__((used)) static void* const faust_min_ios_force_link_ptrs[] = {
    // Mixer singleton + lifecycle (all declared in faust_min.h)
    (void*)mixer_get_instance,
    (void*)mixer_init,
    (void*)mixer_start,
    (void*)mixer_start_async,
    (void*)mixer_stop,
    (void*)mixer_clear_all,
    (void*)mixer_get_sample_rate,
    (void*)mixer_set_master_gain,
    (void*)mixer_set_instrument_weight,
    (void*)mixer_register_instrument,
    (void*)mixer_unregister_instrument,
    (void*)mixer_add_track,
    (void*)mixer_remove_track,
    (void*)mixer_set_track_weight,
    (void*)mixer_get_track_weight,
    (void*)mixer_mute_track,
    (void*)mixer_unmute_track,
    (void*)mixer_set_track_envelope,
    (void*)mixer_set_track_reverb,
    (void*)mixer_set_track_echo,
    (void*)mixer_set_track_eq,
    (void*)mixer_set_track_mid,
    (void*)mixer_set_track_bypass_eq,
    (void*)mixer_set_track_bypass_echo,
    (void*)mixer_set_fx_return,
    (void*)mixer_master_fade_in,
    (void*)mixer_master_fade_out,
    (void*)mixer_add_instrument_to_track,
    (void*)mixer_remove_instrument_from_track,
    (void*)mixer_register_waveform_callback,

    // Instrument factory
    (void*)instrument_create,
    (void*)instrument_destroy,
    (void*)instrument_get_sample_rate,
    (void*)instrument_set_parameter,
    (void*)instrument_get_parameters_json,
    (void*)instrument_free_json,
    (void*)instrument_note_on,
    (void*)instrument_note_off,
    (void*)instrument_render,

    // Sequence orchestrator
    (void*)orchestrator_create,
    (void*)orchestrator_destroy,
    (void*)orchestrator_add_sequence,
    (void*)orchestrator_play,
    (void*)orchestrator_stop,
    (void*)orchestrator_pause,
    (void*)orchestrator_resume,
    (void*)orchestrator_set_song_looping,
    (void*)orchestrator_set_weight,
    (void*)orchestrator_set_parameter,
    (void*)orchestrator_poll_finished,
    (void*)orchestrator_set_asset_base_path,
    (void*)orchestrator_load_song,
    (void*)orchestrator_unload_song,
    (void*)orchestrator_play_song,
    (void*)orchestrator_stop_song,
    (void*)orchestrator_register_tick_callback,

    // UML Sequence
    (void*)sequence_create,
    (void*)sequence_destroy,
    (void*)sequence_get_bpm,
    (void*)sequence_set_bpm,
    (void*)sequence_get_grid,
    (void*)sequence_get_basefreq,
    (void*)sequence_set_basefreq,
    (void*)sequence_prepare,
    (void*)sequence_is_dirty,
    (void*)sequence_add_note,
    (void*)sequence_remove_note,
    (void*)sequence_clear_notes,
    (void*)sequence_get_notes,
    (void*)sequence_get_instrument,

    // Instrument mapper
    (void*)instrument_mapper_get_name,
    (void*)instrument_mapper_get_id,
    (void*)instrument_mapper_is_percussion,
    (void*)instrument_mapper_get_polyphony,
    (void*)instrument_mapper_get_class,
    (void*)instrument_mapper_get_origin,
    (void*)instrument_mapper_get_available,
};

@interface FaustMinPlugin : NSObject<FlutterPlugin>
@end

@implementation FaustMinPlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
    (void)faust_min_ios_force_link_ptrs;
}
@end

// Forwarder includes for C++ implementation files because CocoaPods ignores ../src/*.cpp relative paths.
#include "../../src/faust_min.cpp"
#include "../../src/FaustMixer.cpp"
#include "../../src/FaustInstrument.cpp"
#include "../../src/SequenceOrchestrator.cpp"
#include "../../src/UMLSequence.cpp"
#include "../../src/UMLParser.cpp"
#include "../../src/InstrumentMapper.cpp"
#include "../../src/FaustAcousticGuitar.cpp"
#include "../../src/FaustBansuri.cpp"
#include "../../src/FaustBayan.cpp"
#include "../../src/FaustBell.cpp"
#include "../../src/FaustBowl.cpp"
#include "../../src/FaustCowbell.cpp"
#include "../../src/FaustDayan.cpp"
#include "../../src/FaustFlute.cpp"
#include "../../src/FaustHiHat.cpp"
#include "../../src/FaustKick.cpp"
#include "../../src/FaustPiano.cpp"
#include "../../src/FaustRide.cpp"
#include "../../src/FaustSax.cpp"
#include "../../src/FaustShakuhachi.cpp"
#include "../../src/FaustSitar.cpp"
#include "../../src/FaustSnare.cpp"
#include "../../src/FaustTanpura.cpp"
#include "../../src/FaustTom.cpp"
#include "../../src/FaustTrumpet.cpp"
#include "../../src/FaustViolin.cpp"
