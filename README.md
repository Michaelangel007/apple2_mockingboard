# Apple 2 Mockingboard Test

Play a single note on both the left and right channels A.

Source: 6502 Assembly


# Mockingboard Tone <-> Frequency Table

See `freq.c`

```
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
```
