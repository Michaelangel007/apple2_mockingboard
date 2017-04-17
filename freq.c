/*
    Frequency To/From Mockingboard Tones
    by Michael Pohoreski
    GitHub: https://github.com/Michaelangel007/apple2_mockingboard


The Mockingboard document at:

* ftp://ftp.apple.asimov.net/pub/apple_II/documentation/hardware/sound/Mockingboard%20Docs.pdf

has several incorrect values:

APPENDIX E

                             Course & Fine
    Note  Octave  Frequency  Decimal  Hex.  Notes
    A     0         27.500   9  20    09 14 Exact 27.5 Hz -- bottom key on Piano
    A#    0         29.135   8 145    08 91
    B     0         30.868   8  22    08 16

    C     1         32.703   7 163    07 A3 <-- should be 7A2
    C#    1         34.648   7  53    07 35 <-- should be 734
    D     1         36.708   6 205    06 CD
    D#    1         38.891   6 108    06 6C <-- should be 66B
    E     1         41.203   6  15    06 0F
    F     1         43.654   5 184    05 B8
    F#    1         46.249   5 102    05 66
    G     1         48.999   5  24    05 18
    G#    1         51.913   4 207    04 CF
    A     1         55.000   4 138    04 8A Exact 55.0 Hz
    A#    1         58.270   4  73    04 49 <-- should be 448
    B     1         61.735   4  11    04 0B

    C     2         65.406   3 209    03 D1
    C#    2         69.296   3 154    03 9A
    D     2         73.416   3 102    03 66
    D#    2         77.782   3  54    03 36 <-- should be 335
    E     2         82.406   3   7    03 07
    F     2         87.308   2 220    02 DC
    F#    2         92.498   2 179    02 B3
    G     2         97.998   2 140    02 8C
    G#    3        103.826   2 103    02 67
    A     3        110.000   2  69    02 45 Exact 110.0 Hz
    A#    3        116.540   2  36    02 24
    B     3        123.470   2   5    02 05

    C     3        130.812   1 232    01 E8
    C#    3        138.592   1 205    01 CD
    D     3        146.832   1 179    01 B3
    D#    3        155.564   1 155    01 9B <-- should be 19A
    E     3        164.812   1 131    01 83
    F     3        174.616   1 110    01 6E
    F#    3        184.996   1  89    01 59
    G     3        195.996   1  70    01 46
    G#    3        207.652   1  51    01 33
    A     3        220.000   1  34    01 22
    A#    3        233.080   1  18    01 12
    B     3        246.940   1   2    01 02

    C     4        261.624   0 244    00 F4 -- Middle C4 --
    C#    4        277.184   0 230    00 E6
    D     4        293.664   0 217    00 D9
    D#    4        311.128   0 205    00 CD
    E     4        329.624   0 193    00 C1 <-- 329.628 Hz
    F     4        349.232   0 183    00 B7 <-- 349.228 Hz
    F#    4        369.992   0 172    00 AC
    G     4        391.992   0 163    00 A3
    G#    4        415.304   0 153    00 99
    A     4        440.000   0 145    00 91 Exact 440 Hz -- Concert Tuning A440
    A#    4        466.160   0 137    00 89
    B     4        493.880   0 129    00 81

    C     5        523.248   0 122    00 7A
    C#    5        554.368   0 115    00 73
    D     5        587.328   0 108    00 6C
    D#    5        622.256   0 102    00 66
    E     5        659.248   0  96    00 60 <-- 659.255 Hz
    F     5        698.464   0  91    00 58 <-- Should be 5B
    F#    5        739.984   0  86    00 56
    G     5        783.984   0  81    00 51
    G#    5        830.608   0  76    00 4C
    A     5        880.000   0  72    00 48 Exact 880 Hz
    A#    5        932.320   0  68    00 44 <-- 932.328 Hz
    B     5        987.760   0  64    00 40 <-- 987.767 Hz

    C     6       1046.496   0  61    00 3D -- every frequency
    C#    6       1108.736   0  57    00 39 -- from this point
    D     6       1174.656   0  54    00 36 -- forward is slightly
    D#    6       1244.512   0  51    00 33 -- off except for 'A'
    E     6       1318.496   0  48    00 30
    F     6       1396.928   0  45    00 2D <--1396.913 Hz
    F#    6       1479.968   0  43    00 2B
    G     6       1567.968   0  40    00 2B <-- Should be 28
    G#    6       1661.216   0  38    00 26
    A     6       1760.000   0  36    00 24 Exact 1760 Hz
    A#    6       1864.640   0  34    00 22
    B     6       1975.520   0  32    00 20

    C     7       2092.992   0  30    00 1E <-- 2093.005 Hz
    C#    7       2217.472   0  28    00 1C
    D     7       2349.312   0  27    00 1B
    D#    7       2489.024   0  25    00 19
    E     7       2636.992   0  24    00 18
    F     7       2793.856   0  22    00 16
    F#    7       2959.936   0  21    00 15
    G     7       3135.936   0  20    00 14
    G#    7       3322.432   0  19    00 13
    A     7       3520.000   0  18    00 12 Exact 3520 Hz
    A#    7       3729.280   0  17    00 11
    B     7       3951.040   0  16    00 10

    C     8       4185.984   0  15    00 0F -- top key on Piano
    C#    8       4434.944   0  14    00 0E
    D     8       4698.624   0  13    00 0D
    D#    8       4978.048   0  12    00 0C
    E     8       5273.984   0  12    00 0C <-- 5274.041 Hz
    F     8       5587.712   0  11    00 0B
    F#    8       5919.872   0  10    00 0A
    G     8       6271.872   0  10    00 0A
    G#    8       6644.864   0   9    00 09
    A     8       7040.000   0   9    00 09 Exact 7040 Hz
    A#    8       7458.560   0   8    00 08
    B     8       7902.080   0   8    00 08


Here are the correct frequencies and tones
along with the relative error:

    Note  Frequency     Tone   reproduced  Relative Error

    A0    27.500 Hz -> $090F ~  27.503 Hz  (0.012 %)
    A0#   29.135 Hz -> $088D ~  29.137 Hz  (0.005 %)
    B0    30.868 Hz -> $0812 ~  30.871 Hz  (0.012 %)

    C1    32.703 Hz -> $079E ~  32.708 Hz  (0.014 %)
    C1#   34.648 Hz -> $0730 ~  34.663 Hz  (0.044 %)
    D1    36.708 Hz -> $06C9 ~  36.719 Hz  (0.029 %)
    D1#   38.891 Hz -> $0667 ~  38.914 Hz  (0.060 %)
    E1    41.203 Hz -> $060B ~  41.228 Hz  (0.060 %)
    F1    43.654 Hz -> $05B5 ~  43.655 Hz  (0.004 %)
    F1#   46.249 Hz -> $0563 ~  46.251 Hz  (0.004 %)
    G1    48.999 Hz -> $0515 ~  49.024 Hz  (0.050 %)
    G1#   51.913 Hz -> $04CC ~  51.938 Hz  (0.049 %)
    A1    55.000 Hz -> $0487 ~  55.030 Hz  (0.055 %)
    A1#   58.270 Hz -> $0446 ~  58.300 Hz  (0.051 %)
    B1    61.735 Hz -> $0409 ~  61.743 Hz  (0.012 %)

    C2    65.406 Hz -> $03CF ~  65.416 Hz  (0.014 %)
    C2#   69.296 Hz -> $0398 ~  69.326 Hz  (0.044 %)
    D2    73.416 Hz -> $0364 ~  73.480 Hz  (0.086 %)
    D2#   77.782 Hz -> $0333 ~  77.876 Hz  (0.121 %)
    E2    82.407 Hz -> $0305 ~  82.510 Hz  (0.125 %)
    F2    87.307 Hz -> $02DA ~  87.370 Hz  (0.072 %)
    F2#   92.499 Hz -> $02B1 ~  92.569 Hz  (0.076 %)
    G2    97.999 Hz -> $028A ~  98.123 Hz  (0.127 %)
    G2#  103.826 Hz -> $0266 ~ 103.877 Hz  (0.049 %)
    A2   110.000 Hz -> $0243 ~ 110.156 Hz  (0.142 %)
    A2#  116.541 Hz -> $0223 ~ 116.600 Hz  (0.051 %)
    B2   123.471 Hz -> $0204 ~ 123.605 Hz  (0.109 %)

    C3   130.813 Hz -> $01E7 ~ 130.966 Hz  (0.117 %)
    C3#  138.591 Hz -> $01CC ~ 138.653 Hz  (0.044 %)
    D3   146.832 Hz -> $01B2 ~ 146.959 Hz  (0.086 %)
    D3#  155.563 Hz -> $0199 ~ 155.942 Hz  (0.243 %)
    E3   164.814 Hz -> $0182 ~ 165.234 Hz  (0.255 %)
    F3   174.614 Hz -> $016D ~ 174.740 Hz  (0.072 %)
    F3#  184.997 Hz -> $0158 ~ 185.408 Hz  (0.222 %)
    G3   195.998 Hz -> $0145 ~ 196.247 Hz  (0.127 %)
    G3#  207.652 Hz -> $0133 ~ 207.753 Hz  (0.049 %)
    A3   220.000 Hz -> $0121 ~ 220.693 Hz  (0.315 %)
    A3#  233.082 Hz -> $0111 ~ 233.627 Hz  (0.234 %)
    B3   246.942 Hz -> $0102 ~ 247.210 Hz  (0.109 %)

    C4   261.626 Hz -> $00F3 ~ 262.470 Hz  (0.323 %)
    C4#  277.183 Hz -> $00E6 ~ 277.306 Hz  (0.044 %)
    D4   293.665 Hz -> $00D9 ~ 293.918 Hz  (0.086 %)
    D4#  311.127 Hz -> $00CC ~ 312.648 Hz  (0.489 %)
    E4   329.628 Hz -> $00C1 ~ 330.468 Hz  (0.255 %)
    F4   349.228 Hz -> $00B6 ~ 350.441 Hz  (0.347 %)
    F4#  369.994 Hz -> $00AC ~ 370.816 Hz  (0.222 %)
    G4   391.995 Hz -> $00A2 ~ 393.705 Hz  (0.436 %)
    G4#  415.305 Hz -> $0099 ~ 416.865 Hz  (0.376 %)
    A4   440.000 Hz -> $0090 ~ 442.919 Hz  (0.663 %)
    A4#  466.164 Hz -> $0088 ~ 468.973 Hz  (0.603 %)
    B4   493.883 Hz -> $0081 ~ 494.421 Hz  (0.109 %)

    C5   523.251 Hz -> $0079 ~ 527.110 Hz  (0.737 %)
    C5#  554.365 Hz -> $0073 ~ 554.611 Hz  (0.044 %)
    D5   587.330 Hz -> $006C ~ 590.558 Hz  (0.550 %)
    D5#  622.254 Hz -> $0066 ~ 625.297 Hz  (0.489 %)
    E5   659.255 Hz -> $0060 ~ 664.378 Hz  (0.777 %)
    F5   698.456 Hz -> $005B ~ 700.882 Hz  (0.347 %)
    F5#  739.989 Hz -> $0056 ~ 741.631 Hz  (0.222 %)
    G5   783.991 Hz -> $0051 ~ 787.411 Hz  (0.436 %)
    G5#  830.609 Hz -> $004C ~ 839.214 Hz  (1.036 %)
    A5   880.000 Hz -> $0048 ~ 885.837 Hz  (0.663 %)
    A5#  932.328 Hz -> $0044 ~ 937.945 Hz  (0.603 %)
    B5   987.767 Hz -> $0040 ~ 996.567 Hz  (0.891 %)

    C6  1046.502 Hz -> $003C ~1063.005 Hz  (1.577 %)
    C6# 1108.731 Hz -> $0039 ~1118.952 Hz  (0.922 %)
    D6  1174.659 Hz -> $0036 ~1181.116 Hz  (0.550 %)
    D6# 1244.508 Hz -> $0033 ~1250.594 Hz  (0.489 %)
    E6  1318.510 Hz -> $0030 ~1328.756 Hz  (0.777 %)
    F6  1396.913 Hz -> $002D ~1417.339 Hz  (1.462 %)
    F6# 1479.978 Hz -> $002B ~1483.262 Hz  (0.222 %)
    G6  1567.982 Hz -> $0028 ~1594.507 Hz  (1.692 %)
    G6# 1661.219 Hz -> $0026 ~1678.428 Hz  (1.036 %)
    A6  1760.000 Hz -> $0024 ~1771.674 Hz  (0.663 %)
    A6# 1864.655 Hz -> $0022 ~1875.890 Hz  (0.603 %)
    B6  1975.533 Hz -> $0020 ~1993.133 Hz  (0.891 %)

    C7  2093.005 Hz -> $001E ~2126.009 Hz  (1.577 %)
    C7# 2217.461 Hz -> $001C ~2277.867 Hz  (2.724 %)
    D7  2349.318 Hz -> $001B ~2362.232 Hz  (0.550 %)
    D7# 2489.016 Hz -> $0019 ~2551.211 Hz  (2.499 %)
    E7  2637.020 Hz -> $0018 ~2657.511 Hz  (0.777 %)
    F7  2793.826 Hz -> $0016 ~2899.103 Hz  (3.768 %)
    F7# 2959.955 Hz -> $0015 ~3037.156 Hz  (2.608 %)
    G7  3135.963 Hz -> $0014 ~3189.014 Hz  (1.692 %)
    G7# 3322.438 Hz -> $0013 ~3356.856 Hz  (1.036 %)
    A7  3520.000 Hz -> $0012 ~3543.348 Hz  (0.663 %)
    A7# 3729.310 Hz -> $0011 ~3751.781 Hz  (0.603 %)
    B7  3951.066 Hz -> $0010 ~3986.267 Hz  (0.891 %)

    C8  4186.009 Hz -> $000F ~4252.018 Hz  (1.577 %)
    C8# 4434.922 Hz -> $000E ~4555.734 Hz  (2.724 %)
    D8  4698.636 Hz -> $000D ~4906.175 Hz  (4.417 %)
    D8# 4978.032 Hz -> $000C ~5315.023 Hz  (6.770 %)
    E8  5274.041 Hz -> $000C ~5315.023 Hz  (0.777 %)
    F8  5587.652 Hz -> $000B ~5798.206 Hz  (3.768 %)
    F8# 5919.911 Hz -> $000A ~6378.027 Hz  (7.739 %)
    G8  6271.927 Hz -> $000A ~6378.027 Hz  (1.692 %)
    G8# 6644.875 Hz -> $0009 ~7086.697 Hz  (6.649 %)



Reference:

* https://en.wikipedia.org/wiki/Piano_key_frequencies
* http://www.sciencebuddies.org/Fi les/3443/5/Phys_img024.jpg

*/

#include <stdio.h>
#include <math.h>

    // Every 64th cycle is stretched to be a 65th cycle
    //const double _1MHz_NTSC = 14318180.0 / 14.0; // 1,022,727 Hz
      const double _1MHz_NTSC =  1020484.32; // Avg Hz, Table 3.1, Page 3-5, UtA2E, Jim Sather
    //const double _1MHz_PAL  = 14250000.0 / 14.0;
    //const double A2_FREQ    = 1023000.0; // common incorrect value

/*
Mockingboard:
    Tone Freq = A2 Clock Freq / ((256*Course + Fine) * 16)

6502:
    Master = 14.31818 MHz
    NTSC Cycle = 14.31818 / 14 = 1.0227271429... MHz = 1022727 Hz
    PAL  Cycle = 14.25    / 14 = 1.0178571429... MHz = 1017857 Hz

    n      = Floor( 1,022,727 / freq )
    Course = Floor( n / 4096 )
    Fine   = (n - (4096*Course)) / 16
*/



// Convert Frequency into Mockingboard Tone Period
// ========================================================================
int MockingboardGetTone( double freq_hz )
{
    const int n  = (int) (_1MHz_NTSC / freq_hz);
    const int hi = n / 4096;
    const int lo = (n  - (hi * 4096)) / 16;

    return (hi*256) + lo;
}

// Convert Mockingboard Tone Period into Frequency
// ========================================================================
double MockingboardGetFreq( int tone_period )
{
    // / 256  = >>  8
    // * 4096 = << 12
    // int n = ((tone_period & 0xFF00) << 4) + ((tone_period & 0x00FF) << 4);
    return _1MHz_NTSC / (double) (tone_period << 4);
}


// ========================================================================
int main( const int nArg, const char *aArg[] )
{
    (void) nArg;

    // 0freq = asm low  byte
    // 1freq = asm high byte
    int is_asm = 1*(aArg[0][0] == '0') +
                 2*(aArg[0][0] == '1') ;
    const char *names[ 12 ] =
    {
        "A ", // 2^( 0/12)
        "A#", // 2^( 1/12)
        "B ", // 2^( 2/12)
        "C ", // 2^( 3/12)
        "C#", // 2^( 4/12)
        "D ", // 2^( 5/12)
        "D#", // 2^( 6/12)
        "E ", // 2^( 7/12)
        "F ", // 2^( 8/12)
        "F#", // 2^( 9/12)
        "G ", // 2^(10/12)
        "G#"  // 2^(11/12)
    };

    double halfstep_freq[12];

    for( int half_step = 0; half_step < 12; half_step++ )
        halfstep_freq[ half_step ] = pow( 2.0, (half_step / 12.0) );

    for( int octave = 0; octave < 8; octave++ )
    {
        double octave_freq = 440.0 * pow( 2.0, (octave - 4.0));

        for( int half_step = 0; half_step < 12; half_step++ )
        {
            double actual  = octave_freq * halfstep_freq[ half_step ];
            int    tone    = MockingboardGetTone( actual );
            double measure = MockingboardGetFreq( tone );
            double rel_err = (measure - actual) / actual * 100.0;

if( is_asm )
            printf( "%*s.byte $%02X ; %c%d%c %8.3f Hz\n"
                , 8, " "
                ,(tone >> ((is_asm-1) * 8)) & 0xFF
                , names[ half_step ][0]
                , octave + (half_step > 2)
                , names[ half_step ][1]
                , actual
            );
else
            printf( "%c%d%c %8.3f Hz -> $%04X (%3d %3d) ~%8.3f Hz  (%5.3f %%)\n"
                , names[ half_step ][0]
                , octave + (half_step > 2)
                , names[ half_step ][1]
                , actual
                , tone
                , (tone >> 8) & 0xFF
                , (tone >> 0) & 0xFF
                , measure
                , rel_err
            );

            if( half_step == 2 )
                printf( "\n" );
        }
    }
    printf( "\n" );

    return 0;
}
