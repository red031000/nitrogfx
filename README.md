A simple tool to convert between GBA/NDS 2D graphics file types and modern graphics formats.

# Compilation

## Requirements

- gcc
- libpng
- pkg-config
- make

## Build command

```bash
make
```

# Usage

```
./nitrogfx <SRC> <DEST> [OPTIONS]
```

The mode of operation will be chosen automatically from the source and destination file extensions. The table below links to the options available for each conversion mode. For instance, if the command is `nitrogfx image.png image.NCGR.lz [OPTIONS]`, the options are documented at [HandlePngToNtrLzCommand](#HandlePngToNtrLzCommand).

Source    | Dest      | Command
--------- | --------- | -----------------------------
1bpp      | png       | [HandleGbaToPngCommand](#HandleGbaToPngCommand)
4bpp      | png       | [HandleGbaToPngCommand](#HandleGbaToPngCommand)
8bpp      | png       | [HandleGbaToPngCommand](#HandleGbaToPngCommand)
nbfc      | png       | [HandleGbaToPngCommand](#HandleGbaToPngCommand)
NCGR      | png       | [HandleNtrToPngCommand](#HandleNtrToPngCommand)
NCGR.lz   | png       | [HandleNtrLzToPngCommand](#HandleNtrLzToPngCommand)
png       | 1bpp      | [HandlePngToGbaCommand](#HandlePngToGbaCommand)
png       | 4bpp      | [HandlePngToGbaCommand](#HandlePngToGbaCommand)
png       | nbfc      | [HandlePngToGbaCommand](#HandlePngToGbaCommand)
png       | 8bpp      | [HandlePngToGbaCommand](#HandlePngToGbaCommand)
png       | NCGR      | [HandlePngToNtrCommand](#HandlePngToNtrCommand)
png       | NCGR.lz   | [HandlePngToNtrLzCommand](#HandlePngToNtrLzCommand)
png       | gbapal    | [HandlePngToGbaPaletteCommand](#HandlePngToGbaPaletteCommand)
png       | nbfp      | [HandlePngToGbaPaletteCommand](#HandlePngToGbaPaletteCommand)
png       | NCLR      | [HandlePngToNtrPaletteCommand](#HandlePngToNtrPaletteCommand)
gbapal    | pal       | [HandleGbaToJascPaletteCommand](#HandleGbaToJascPaletteCommand)
NCLR      | pal       | [HandleNtrToJascPaletteCommand](#HandleNtrToJascPaletteCommand)
NCPR      | pal       | [HandleNtrToJascPaletteCommand](#HandleNtrToJascPaletteCommand)
pal       | gbapal    | [HandleJascToGbaPaletteCommand](#HandleJascToGbaPaletteCommand)
pal       | NCLR      | [HandleJascToNtrPaletteCommand](#HandleJascToNtrPaletteCommand)
latfont   | png       | [HandleLatinFontToPngCommand](#HandleLatinFontToPngCommand)
png       | latfont   | [HandlePngToLatinFontCommand](#HandlePngToLatinFontCommand)
hwjpnfont | png       | [HandleHalfwidthJapaneseFontToPngCommand](#HandleHalfwidthJapaneseFontToPngCommand)
png       | hwjpnfont | [HandlePngToHalfwidthJapaneseFontCommand](#HandlePngToHalfwidthJapaneseFontCommand)
fwjpnfont | png       | [HandleFullwidthJapaneseFontToPngCommand](#HandleFullwidthJapaneseFontToPngCommand)
png       | fwjpnfont | [HandlePngToFullwidthJapaneseFontCommand](#HandlePngToFullwidthJapaneseFontCommand)
json      | NCER      | [HandleJsonToNtrCellCommand](#HandleJsonToNtrCellCommand)
json      | NCER.lz   | [HandleJsonToNtrCellLzCommand](#HandleJsonToNtrCellLzCommand)
NCER      | json      | [HandleNtrCellToJsonCommand](#HandleNtrCellToJsonCommand)
NCER.lz   | json      | [HandleNtrCellLzToJsonCommand](#HandleNtrCellLzToJsonCommand)
json      | NSCR      | [HandleJsonToNtrScreenCommand](#HandleJsonToNtrScreenCommand)
json      | NANR      | [HandleJsonToNtrAnimationCommand](#HandleJsonToNtrAnimationCommand)
json      | NANR.lz   | [HandleJsonToNtrAnimationLzCommand](#HandleJsonToNtrAnimationLzCommand)
NANR      | json      | [HandleNtrAnimationToJsonCommand](#HandleNtrAnimationToJsonCommand)
NANR.lz   | json      | [HandleNtrAnimationLzToJsonCommand](#HandleNtrAnimationLzToJsonCommand)
json      | NMAR      | [HandleJsonToNtrMulticellAnimationCommand](#HandleJsonToNtrMulticellAnimationCommand)
NMAR      | json      | [HandleNtrAnimationToJsonCommand](#HandleNtrAnimationToJsonCommand)
          | huff      | [HandleHuffCompressCommand](#HandleHuffCompressCommand)
          | lz        | [HandleLZCompressCommand](#HandleLZCompressCommand)
huff      |           | [HandleHuffDecompressCommand](#HandleHuffDecompressCommand)
lz        |           | [HandleLZDecompressCommand](#HandleLZDecompressCommand)
          | rl        | [HandleRLCompressCommand](#HandleRLCompressCommand)
rl        |           | [HandleRLDecompressCommand](#HandleRLDecompressCommand)
NFGR      | png       | [HandleNtrFontToPngCommand](#HandleNtrFontToPngCommand)
png       | NFGR      | [HandlePngToNtrFontCommand](#HandlePngToNtrFontCommand)
          |           |

<a id="HandleGbaToPngCommand"></a>
## HandleGbaToPngCommand

### `-palette <PATH>`

> Path to a palette file. Should be in .gbapal format

### `-cell <PATH>`

> Path to a sprite cell file, either NCER or json

### `-object`

> Sets the color at index 0 to be transparency

### `-palindex`

> Sets the palette slot to use when generating the PNG. Defaults to 0, but this cannot be specified explicitly. Should be used with `-palette`.

### `-width <INT>`

> Set the output width to this many tiles (1 tile = 8 pixels)

### `-mwidth <INT>`, `-cpc <INT>`

> Sets the number of columns per chunk

### `-mheight <INT>`, `-rpc <INT>`

> Sets the number of rows per chunk

<a id="HandleNtrToPngCommand"></a>
## HandleNtrToPngCommand

### `-palette <PATH>`

> Path to a palette file. Should be in .gbapal format

### `-object`

> Sets the color at index 0 to be transparency

### `-width <INT>`

> Set the output width to this many tiles (1 tile = 8 pixels)

### `-mwidth <INT>`, `-cpc <INT>`

> Sets the number of columns per chunk

### `-mheight <INT>`, `-rpc <INT>`

> Sets the number of rows per chunk

### `-scanfronttoback`, `-encodefronttoback`

> Sanned mode, front-to-back as in Pokémon Platinum/HGSS. Used for monster sprites in Pokémon.

### `-encodebacktofront`

> Sanned mode, back-to-front as in Pokémon DP. Used for monster sprites in Pokémon.

### `-handleempty`

> Use fallback logic to write an empty output file if the input is empty

### `-convertTo8Bpp`

> Read up to 256 colors from the palette file (def: 16 colors). Should be used with `-palette`.

<a id="HandleNtrLzToPngCommand"></a>
## HandleNtrLzToPngCommand



<a id="HandlePngToGbaCommand"></a>
## HandlePngToGbaCommand



<a id="HandlePngToNtrCommand"></a>
## HandlePngToNtrCommand



<a id="HandlePngToNtrLzCommand"></a>
## HandlePngToNtrLzCommand



<a id="HandlePngToGbaPaletteCommand"></a>
## HandlePngToGbaPaletteCommand



<a id="HandlePngToNtrPaletteCommand"></a>
## HandlePngToNtrPaletteCommand



<a id="HandleGbaToJascPaletteCommand"></a>
## HandleGbaToJascPaletteCommand



<a id="HandleNtrToJascPaletteCommand"></a>
## HandleNtrToJascPaletteCommand



<a id="HandleJascToGbaPaletteCommand"></a>
## HandleJascToGbaPaletteCommand



<a id="HandleJascToNtrPaletteCommand"></a>
## HandleJascToNtrPaletteCommand



<a id="HandleLatinFontToPngCommand"></a>
## HandleLatinFontToPngCommand



<a id="HandlePngToLatinFontCommand"></a>
## HandlePngToLatinFontCommand



<a id="HandleHalfwidthJapaneseFontToPngCommand"></a>
## HandleHalfwidthJapaneseFontToPngCommand



<a id="HandlePngToHalfwidthJapaneseFontCommand"></a>
## HandlePngToHalfwidthJapaneseFontCommand



<a id="HandleFullwidthJapaneseFontToPngCommand"></a>
## HandleFullwidthJapaneseFontToPngCommand



<a id="HandlePngToFullwidthJapaneseFontCommand"></a>
## HandlePngToFullwidthJapaneseFontCommand



<a id="HandleJsonToNtrCellCommand"></a>
## HandleJsonToNtrCellCommand



<a id="HandleJsonToNtrCellLzCommand"></a>
## HandleJsonToNtrCellLzCommand



<a id="HandleNtrCellToJsonCommand"></a>
## HandleNtrCellToJsonCommand



<a id="HandleNtrCellLzToJsonCommand"></a>
## HandleNtrCellLzToJsonCommand



<a id="HandleJsonToNtrScreenCommand"></a>
## HandleJsonToNtrScreenCommand



<a id="HandleJsonToNtrAnimationCommand"></a>
## HandleJsonToNtrAnimationCommand



<a id="HandleJsonToNtrAnimationLzCommand"></a>
## HandleJsonToNtrAnimationLzCommand



<a id="HandleNtrAnimationToJsonCommand"></a>
## HandleNtrAnimationToJsonCommand



<a id="HandleNtrAnimationLzToJsonCommand"></a>
## HandleNtrAnimationLzToJsonCommand



<a id="HandleJsonToNtrMulticellAnimationCommand"></a>
## HandleJsonToNtrMulticellAnimationCommand



<a id="HandleHuffCompressCommand"></a>
## HandleHuffCompressCommand



<a id="HandleLZCompressCommand"></a>
## HandleLZCompressCommand



<a id="HandleHuffDecompressCommand"></a>
## HandleHuffDecompressCommand



<a id="HandleLZDecompressCommand"></a>
## HandleLZDecompressCommand



<a id="HandleRLCompressCommand"></a>
## HandleRLCompressCommand



<a id="HandleRLDecompressCommand"></a>
## HandleRLDecompressCommand



<a id="HandleNtrFontToPngCommand"></a>
## HandleNtrFontToPngCommand



<a id="HandlePngToNtrFontCommand"></a>
## HandlePngToNtrFontCommand



