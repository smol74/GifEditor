# GifEditor
C++ GUI Application to Manipulate GIF Files

## Goals for Gif Editor:

- Import and parse GIFs.
- Implement LZW Compression to parse image data from GIFs.
- View, pause, and play GIFs from parsed data.
- Edit GIFs with a GUI and export them.
- Show a timeline containing frames of GIFs.
- Remove frames from a GIF.
- Crop frames of a GIF.
- Resize frames of a GIF.
- Trim the length of a GIF.
- Change the speed of the GIF.
- Import mp4 files and convert them to GIFs for editing.

## Things to learn:

- How to parse GIFs.
- How LZW Compression works.
- How to manipulate GIF data.

## Roadmap:

1. Create a basic GUI for the application.
	- allow for the importing of GIF files.
1. Add the ability to parse a GIF file.
	- reference: https://www.w3.org/Graphics/GIF/spec-gif89a.txt
	- Implement LZW Compression to extract image data from GIFs.
2. View and Display the GIF using parsed data.
3. Flesh out the GUI.
	- show a timeline containing the gifs frames.
	- show controls to pause and play the gif.
4. Add editing functionality.
	- start with the ability to remove frames from the timeline and export as a new GIF.
