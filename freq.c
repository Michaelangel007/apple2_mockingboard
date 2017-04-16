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

    A0    27.500 Hz -> $0914 ~  27.504 Hz  (0.016 %)
    A0#   29.135 Hz -> $0891 ~  29.147 Hz  (0.042 %)
    B0    30.868 Hz -> $0816 ~  30.879 Hz  (0.038 %)

    C1    32.703 Hz -> $07A2 ~  32.713 Hz  (0.029 %)
    C1#   34.648 Hz -> $0734 ~  34.664 Hz  (0.047 %)
    D1    36.708 Hz -> $06CD ~  36.715 Hz  (0.018 %)
    D1#   38.891 Hz -> $066B ~  38.905 Hz  (0.036 %)
    E1    41.203 Hz -> $060F ~  41.212 Hz  (0.022 %)
    F1    43.654 Hz -> $05B8 ~  43.662 Hz  (0.018 %)
    F1#   46.249 Hz -> $0566 ~  46.252 Hz  (0.006 %)
    G1    48.999 Hz -> $0518 ~  49.019 Hz  (0.039 %)
    G1#   51.913 Hz -> $04CF ~  51.926 Hz  (0.024 %)
    A1    55.000 Hz -> $048A ~  55.009 Hz  (0.016 %)
    A1#   58.270 Hz -> $0448 ~  58.322 Hz  (0.088 %)
    B1    61.735 Hz -> $040B ~  61.759 Hz  (0.038 %)

    C2    65.406 Hz -> $03D1 ~  65.425 Hz  (0.029 %)
    C2#   69.296 Hz -> $039A ~  69.328 Hz  (0.047 %)
    D2    73.416 Hz -> $0366 ~  73.472 Hz  (0.076 %)
    D2#   77.782 Hz -> $0335 ~  77.857 Hz  (0.097 %)
    E2    82.407 Hz -> $0307 ~  82.478 Hz  (0.086 %)
    F2    87.307 Hz -> $02DC ~  87.323 Hz  (0.018 %)
    F2#   92.499 Hz -> $02B3 ~  92.504 Hz  (0.006 %)
    G2    97.999 Hz -> $028C ~  98.037 Hz  (0.039 %)
    G2#  103.826 Hz -> $0267 ~ 103.936 Hz  (0.105 %)
    A2   110.000 Hz -> $0245 ~ 110.018 Hz  (0.016 %)
    A2#  116.541 Hz -> $0224 ~ 116.643 Hz  (0.088 %)
    B2   123.471 Hz -> $0205 ~ 123.637 Hz  (0.135 %)

    C3   130.813 Hz -> $01E8 ~ 130.985 Hz  (0.131 %)
    C3#  138.591 Hz -> $01CD ~ 138.656 Hz  (0.047 %)
    D3   146.832 Hz -> $01B3 ~ 146.944 Hz  (0.076 %)
    D3#  155.563 Hz -> $019A ~ 155.904 Hz  (0.219 %)
    E3   164.814 Hz -> $0183 ~ 165.169 Hz  (0.216 %)
    F3   174.614 Hz -> $016E ~ 174.646 Hz  (0.018 %)
    F3#  184.997 Hz -> $0159 ~ 185.277 Hz  (0.151 %)
    G3   195.998 Hz -> $0146 ~ 196.075 Hz  (0.039 %)
    G3#  207.652 Hz -> $0133 ~ 208.210 Hz  (0.269 %)
    A3   220.000 Hz -> $0122 ~ 220.415 Hz  (0.189 %)
    A3#  233.082 Hz -> $0112 ~ 233.286 Hz  (0.088 %)
    B3   246.942 Hz -> $0102 ~ 247.754 Hz  (0.329 %)

    C4   261.626 Hz -> $00F4 ~ 261.969 Hz  (0.131 %)
    C4#  277.183 Hz -> $00E6 ~ 277.915 Hz  (0.264 %)
    D4   293.665 Hz -> $00D9 ~ 294.564 Hz  (0.306 %)
    D4#  311.127 Hz -> $00CD ~ 311.807 Hz  (0.219 %)
    E4   329.628 Hz -> $00C1 ~ 331.194 Hz  (0.475 %)
    F4   349.228 Hz -> $00B7 ~ 349.292 Hz  (0.018 %)
    F4#  369.994 Hz -> $00AC ~ 371.631 Hz  (0.442 %)
    G4   391.995 Hz -> $00A3 ~ 392.150 Hz  (0.039 %)
    G4#  415.305 Hz -> $0099 ~ 417.781 Hz  (0.596 %)
    A4   440.000 Hz -> $0091 ~ 440.831 Hz  (0.189 %)
    A4#  466.164 Hz -> $0089 ~ 466.573 Hz  (0.088 %)
    B4   493.883 Hz -> $0081 ~ 495.507 Hz  (0.329 %)

    C5   523.251 Hz -> $007A ~ 523.938 Hz  (0.131 %)
    C5#  554.365 Hz -> $0073 ~ 555.830 Hz  (0.264 %)
    D5   587.330 Hz -> $006C ~ 591.856 Hz  (0.771 %)
    D5#  622.254 Hz -> $0066 ~ 626.671 Hz  (0.710 %)
    E5   659.255 Hz -> $0060 ~ 665.838 Hz  (0.999 %)
    F5   698.456 Hz -> $005B ~ 702.422 Hz  (0.568 %)
    F5#  739.989 Hz -> $0056 ~ 743.261 Hz  (0.442 %)
    G5   783.991 Hz -> $0051 ~ 789.141 Hz  (0.657 %)
    G5#  830.609 Hz -> $004C ~ 841.059 Hz  (1.258 %)
    A5   880.000 Hz -> $0048 ~ 887.784 Hz  (0.885 %)
    A5#  932.328 Hz -> $0044 ~ 940.007 Hz  (0.824 %)
    B5   987.767 Hz -> $0040 ~ 998.757 Hz  (1.113 %)

    C6  1046.502 Hz -> $003D ~1047.876 Hz  (0.131 %)
    C6# 1108.731 Hz -> $0039 ~1121.411 Hz  (1.144 %)
    D6  1174.659 Hz -> $0036 ~1183.712 Hz  (0.771 %)
    D6# 1244.508 Hz -> $0033 ~1253.342 Hz  (0.710 %)
    E6  1318.510 Hz -> $0030 ~1331.676 Hz  (0.999 %)
    F6  1396.913 Hz -> $002D ~1420.454 Hz  (1.685 %)
    F6# 1479.978 Hz -> $002B ~1486.522 Hz  (0.442 %)
    G6  1567.982 Hz -> $0028 ~1598.011 Hz  (1.915 %)
    G6# 1661.219 Hz -> $0026 ~1682.117 Hz  (1.258 %)
    A6  1760.000 Hz -> $0024 ~1775.568 Hz  (0.885 %)
    A6# 1864.655 Hz -> $0022 ~1880.013 Hz  (0.824 %)
    B6  1975.533 Hz -> $0020 ~1997.514 Hz  (1.113 %)

    C7  2093.005 Hz -> $001E ~2130.682 Hz  (1.800 %)
    C7# 2217.461 Hz -> $001C ~2282.873 Hz  (2.950 %)
    D7  2349.318 Hz -> $001B ~2367.424 Hz  (0.771 %)
    D7# 2489.016 Hz -> $0019 ~2556.818 Hz  (2.724 %)
    E7  2637.020 Hz -> $0018 ~2663.352 Hz  (0.999 %)
    F7  2793.826 Hz -> $0016 ~2905.475 Hz  (3.996 %)
    F7# 2959.955 Hz -> $0015 ~3043.831 Hz  (2.834 %)
    G7  3135.963 Hz -> $0014 ~3196.022 Hz  (1.915 %)
    G7# 3322.438 Hz -> $0013 ~3364.234 Hz  (1.258 %)
    A7  3520.000 Hz -> $0012 ~3551.136 Hz  (0.885 %)
    A7# 3729.310 Hz -> $0011 ~3760.026 Hz  (0.824 %)
    B7  3951.066 Hz -> $0010 ~3995.028 Hz  (1.113 %)

    C8  4186.009 Hz -> $000F ~4261.363 Hz  (1.800 %)
    C8# 4434.922 Hz -> $000E ~4565.746 Hz  (2.950 %)
    D8  4698.636 Hz -> $000D ~4916.957 Hz  (4.646 %)
    D8# 4978.032 Hz -> $000C ~5326.704 Hz  (7.004 %)
    E8  5274.041 Hz -> $000C ~5326.704 Hz  (0.999 %)
    F8  5587.652 Hz -> $000B ~5810.950 Hz  (3.996 %)
    F8# 5919.911 Hz -> $000A ~6392.045 Hz  (7.975 %)
    G8  6271.927 Hz -> $000A ~6392.045 Hz  (1.915 %)
    G8# 6644.875 Hz -> $0009 ~7102.272 Hz  (6.883 %)


Reference:

* https://en.wikipedia.org/wiki/Piano_key_frequencies
* http://www.sciencebuddies.org/Fi les/3443/5/Phys_img024.jpg

*/

#include <stdio.h>
#include <math.h>

    const double _1MHz_NTSC = 14318180.0 / 14.0; // 1,022,727 Hz
    //const double _1MHz_PAL  = 14250000.0 / 14.0;
    //const double A2_FREQ    = 1023000.0; // common incorrect value

/*
Mockingboard:
    Tone Freq = A2 Clock Freq / ((256*Course + Fine) * 16)

6502:
    Master = 14.31818 MHz
    NTSC Cycle = 14.31818 / 14 = 1.0227271429... MHz = 1022727 Hz
    PAL  Cycle = 14.25    / 14 = 1.0178571429... MHz = 1017857 Hz

    n = 1,022,727 / freq
    Course = n / 4096
    Fine   = (n - (4069*Course)) / 16
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
int main()
{
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

            printf( "%c%d%c %8.3f Hz -> $%04X ~%8.3f Hz  (%5.3f %%)\n"
                , names[ half_step ][0]
                , octave + (half_step > 2)
                , names[ half_step ][1]
                , actual
                , tone
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
