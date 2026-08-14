# Copyright (c) 2026 Shashank Khare
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.


#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint faust_min.podspec` to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'faust_min'
  s.version          = '0.0.1'
  s.summary          = 'High-fidelity physical modeling music synthesis engine powered by Faust'
  s.description      = <<-DESC
A high-fidelity physical modeling music synthesis engine powered by Faust, featuring 50+ dynamic instruments, polyphonic support, and an advanced UML multi-notation sequencer.
                       DESC
  s.homepage         = 'https://github.com/shashankkhare/faust_min'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Shashank Khare' => 'shashank.skhare@gmail.com' }

  # This will ensure the source files in Classes/ are included in the native
  # builds of apps using this FFI plugin. Podspec does not support relative
  # paths, so Classes contains a forwarder C file that relatively imports
  # `../src/*` so that the C sources can be shared among all target platforms.
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*', '../src/*.cpp', '../src/*.hpp', '../src/*.h', '../src/faust_arch/faust/dsp/dsp.h'
  s.dependency 'Flutter'
  s.frameworks = 'AVFoundation', 'AudioToolbox'
  s.platform = :ios, '13.0'

  # Flutter.framework does not contain a i386 slice.
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386',
    'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) FAUST_DISABLE_INTERPRETER=1',
    'HEADER_SEARCH_PATHS' => '$(inherited) "${PODS_TARGET_SRCROOT}/../src/faust_arch" "${PODS_ROOT}/../src/faust_arch"',
    'LLVM_LTO' => 'YES',
    'OTHER_CPLUSPLUSFLAGS' => '$(inherited) -O3 -ffast-math -ftree-vectorize',
    'DEAD_CODE_STRIPPING' => 'NO',
    'OTHER_LDFLAGS' => '$(inherited) -all_load' }
  s.swift_version = '5.0'
end
