# Lemon Gain

This is the repository for the Lemon Gain Plugin. Here you will find the source code and resources needed to build the plugin.

## Prerequisites

- A C++ compiler compatible with C++14 or later.
- CMake 3.16 or later.
- Steinberg VST3 SDK
- A DAW for testing the plugin, like Ableton Live or Reaper.
- Xcode (if on MacOS)

## Setup

1. **Clone the repository**

   Use Git to clone this repository to your local machine.

2. **Set up the VST3 SDK**

Download the VST3 SDK from the Steinberg website and extract it. You may want to move the extracted SDK to a suitable location on your machine.

Set the `VST3_SDK_ROOT` environment variable to point to the root directory of the VST3 SDK. This allows CMake to find the SDK.

3. **Build the plugin**

Open your terminal, navigate to the project root directory, and create a new directory named `build`. Then, navigate into this directory:

```
cd my-vst3-plugin
mkdir build
cd build
```

Run CMake to configure the project and generate a build system:

```
cmake ..
```

Then, build the project:

```
make
```

If you're using Xcode, you can generate an Xcode project using CMake, then open that project in Xcode:

```
cmake -G Xcode ..
open my-vst3-plugin.xcodeproj
```

Then, you can build the project from within Xcode.

4. **Test the plugin**

After building the project, the resulting VST3 plugin will be placed in the `build/VST3` directory. You can now load this plugin into your DAW for testing.

Please note that you might need to configure your DAW to recognize the location of the new plugin.

<!-- ## Contributing

If you're a contributor, please see our contributing guidelines (link to CONTRIBUTING.md or similar).

## License

This project is licensed under the MIT License (or whichever license you're using) - see the [LICENSE.md](LICENSE.md) file for details. -->
