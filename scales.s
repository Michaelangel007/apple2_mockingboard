; Mockingboard Demo Scales
; Clean up by Michael Pohoreski
; http: https://github.com/Michaelangel007/apple2_mockingboard.git
; Assembler: cc65

            __MAIN = $8000

; Uncomment next 2 lines for ProDOS
            .word __MAIN                ; 2 byte BLOAD address
            .word __END - __MAIN        ; 2 byte BLOAD size

; Mockingboard Base Address
            ADDR6522        = $C400     ; *** Default Mockingboard to slot 4 ***

; Programmable Sound Generator
            MOCK_TONE_LOW   = $0        ; Tone Control Fine   Reg 0/2/4: lo 8-bit
            MOCK_TONE_HIGH  = $1        ; Tone Control Coarse Reg 1/3/5: hi 4-bit

            MOCK_TONE_A_LO  = $0        ; 12-bit
            MOCK_TONE_A_HI  = $1

            MOCK_TONE_B_LO  = $2        ; 12-bit
            MOCK_TONE_B_HI  = $3

            MOCK_TONE_C_LO  = $4        ; 12-bit
            MOCK_TONE_C_HI  = $5

            MOCK_NOISE      = $6        ; Noise Period        Reg 6    : 5-bit

            ; a b x x x y y y
            ;           \___/
            ;           C B A
            ;           0=Tone Disabled
            ;     \___/
            ;     C B A
            ;     0=Noise Disabled
            ;   B input=0
            ; A input=0
            DISABLE_TONE_A  = %000001 ; $01
            DISABLE_TONE_B  = %000010 ; $02
            DISABLE_TONE_C  = %000100 ; $04
            DISABLE_NOISE_A = %001000 ; $08
            DISABLE_NOISE_B = %010000 ; $10
            DISABLE_NOISE_C = %100000 ; $20
            MOCK_CHANNELS   = $7        ; Disabled Chans Mask Reg 7    : 6-bit

            ; D s s s s
            ;   \_____/
            ;    Static
            ; 1=Dynamic
            AMP_STATIC      = %01111
            AMP_DYNAMIC     = %10000
            MOCK_AMPLITUDE  = $8        ; Amplitude           Reg 8/9/A: 5-bit
            MOCK_AMP_A      = $8
            MOCK_AMP_B      = $9
            MOCK_AMP_C      = $A

            MOCK_ENV_LOW    = $B        ; Envelope Fine       Reg B    : lo 8-bit
            MOCK_ENV_HIGH   = $C        ; Envelope Coarse     Reg C    : hi 8-bit

            ; C K A H
            ; Continue 
            ;   Attack
            ;     Alternate
            ;       Hold
            ENV_CONT        = %0001
            ENV_ATTACK      = %0010
            ENV_ALT         = %0100
            ENV_HOLD        = %1000
            MOCK_ENV_TYPE   = $D        ; Envelope Shape      Reg D    : 4-bit

            MOCK_REG_FIRST  = $0
            MOCK_REG_LAST   = $D
            MOCK_REG_NUM    = $E

; Left Speaker
            MOCK1_OR_B      = ADDR6522+0 ; OR Register B
            MOCK1_OR_A      = ADDR6522+1 ; OR Register A
            MOCK1_DIR_B     = ADDR6522+2 ; Data Direction Reg B
            MOCK1_DIR_A     = ADDR6522+3 ; Data Direction Reg A
; Right Speaker
            MOCK2_OR_B      = ADDR6522+0+$80
            MOCK2_OR_A      = ADDR6522+1+$80
            MOCK2_DIR_B     = ADDR6522+2+$80
            MOCK2_DIR_A     = ADDR6522+3+$80

            ; 6522 Commands
            ;                      DIR BC1 BC0
            _6522_RESET      = $0   ; 0 0 0
            _6522_PORT_B     = $4   ; 1 0 0
            _6522_WRITE      = $6   ; 1 1 0
            _6522_LATCH      = $7   ; 1 1 1

            _6522_PORT_A_OUT = $07  ; TODO: is $FF safe?
            _6522_PORT_B_OUT = $FF


            note_index = $FF

; === CODE  ===

            .org  __MAIN                ; .org must come after header else offsets are wrong

; Cleaned up code
            jsr MOCK1_Init
            jsr MOCK2_Init

            lda #0
            sta note_index

            ldx #<demo_regs_1
            ldy #>demo_regs_1
            jsr MOCK1_Play

play_loop:
            ldy note_index
            ldx demo_half_notes,y
            bmi play_done

            jsr MOCK1_ANoteX
            lda #0
            jsr DelayA

            inc note_index
            bne play_loop

play_done:
            jmp MOCK1_Stop

; === DATA ===

; $3E = Only enable Tone A
channels = DISABLE_NOISE_C | DISABLE_NOISE_B | DISABLE_NOISE_A | DISABLE_TONE_C | DISABLE_TONE_B 

demo_regs_1:
            .byte $80,$00       ; [0] Tone A
            .byte $80,$00       ; [2] Tone B
            .byte $80,$00       ; [4] Tone C
            .byte $00           ; [6] Noise
            .byte channels      ; [7] Disable
            .byte $0F,$0F,$0F   ; [8] Amp A, B, C
            .byte $00           ; [B] Env Lo
            .byte $00           ; [C] Env Hi
            .byte $00           ; [D] Env Type

demo_half_notes:
            .byte $00 ; C4
            .byte $02 ; D4
            .byte $04 ; E4
            .byte $05 ; F4
            .byte $07 ; G4
            .byte $09 ; A4
            .byte $0B ; B4
            .byte $0C ; C5
            .byte $FF ; end-of-music

            ;Tone Control Fine  128 ($80) Register 0/2/4
            ;Tone Control Coarse  0       Register 1/3/5
            ;Noise Period         0       Register 6
            ;Enable Mask         62 ($3E) Register 7
            ;Amplitude           15 ($0F) Register 8/9/A
            ;Envelope Fine        0       Register B
            ;Envelope Coarse      0       Register C
            ;Envelope Shape       0       Register D

; ____________________ Utility ____________________ 

; ====================
; Delay ((A * ?  + ?) * (A * ? + ?)
; ====================
DelayA:
            tax
            tay
@1:         inx
            bne @1
            iny
            bne @1
            rts

; ____________________ Mockingboard 1 ____________________ 

; ====================
; Initialize Mockingboard
; ====================
MOCK1_Init:
            lda #_6522_PORT_B_OUT
            sta MOCK1_DIR_B
;           lda #_6522_PORT_A_OUT
            sta MOCK1_DIR_A
            ; NOTE: Intentional fall-into reset!
MOCK1_Reset:
            lda #_6522_RESET        ;      -->+
            .byte $2C               ;         |
MOCK1_SetReg:                       ;         |
            lda #_6522_LATCH        ;-->+     |
            .byte $2C               ;   |     |
MOCK1_SetData:                      ;   |     |
            lda #_6522_WRITE        ;   |     |
            sta MOCK1_OR_B          ;<--+  <--+
            lda #_6522_PORT_B
            sta MOCK1_OR_B
            rts

; ====================
; IN:
;   X = Note Index
; OUT:
;   A = trash
;   X = trash
;   Y = trash
; ====================
MOCK1_ANoteX:
            lda #MOCK_TONE_A_LO
            .byte $2c
MOCK1_BNoteX:
            lda #MOCK_TONE_B_LO
            .byte $2c
MOCK1_CNoteX:
            lda #MOCK_TONE_C_LO

MOCK1_nNoteX:
            sta _mock_note+1        ; X = Mockingboard Register, 0=Tone A, 2=Tone B, 4=Tone C

            lda note_to_tone_hi,x
            pha
            lda note_to_tone_lo,x
_mock_note:
            ldx #MOCK_TONE_A_LO     ; *** SELF-MODIFIED!
            jsr MOCK1_PokeXA
            inx                     ; X = MOCK_TONE_A_HI
            pla
            ; NOTE: Intentional fall-into MOCK1_PokeXA  !

; ====================
; Plays one note
; IN:
;   X = Register: $0 .. $D
;   A = Value
; OUT:
;   A = trash
;   X = unchanged
;   Y = trash
; ====================
MOCK1_PokeXA:
            TAY
            ; NOTE: Intentional fall-into!

; ====================
; Poke (set) byte to Mockingboard
; IN:
;   X = Register: $0 .. $D
;   Y = Value
; OUT:
;   A = trash
;   X = unchanged
;   Y = unchanged
; ====================
MOCK1_PokeXY:
            stx MOCK1_OR_A
            jsr MOCK1_SetReg
            sty MOCK1_OR_A
            jmp MOCK1_SetData

; ====================
; Stop all sounds by setting all regs to zero
; ====================
MOCK1_Stop:
            LDX #<mockN_off_data         ; *** SELF-MODIFIES!
            LDY #>mockN_off_data
            ; NOTE: Intentional fall-into!

; ====================
; Plays one note by setting all Mockingboard registers
; IN:
;   X = Low  Address of registers
;   Y = High Address of
; ====================
MOCK1_Play:
            STX _mock1_load_reg+1        ; *** SELF-MODIFIES!
            STY _mock1_load_reg+2
_mock1all_regs:
            ldy #0
            ldx #MOCK_REG_FIRST
_mock1_load_reg:
            lda mockN_off_data,X    ; *** SELF-MODIFIED!
            jsr MOCK1_PokeXA
            inx
            cpx #MOCK_REG_NUM       ; BUG: $B !
            bcc _mock1_load_reg
            rts

; === DATA ===

note_to_tone_lo:
            .byte $F4 ; C4   261.626 Hz
            .byte $E6 ; C4#  277.183 Hz
            .byte $D9 ; D4   293.665 Hz
            .byte $CD ; D4#  311.127 Hz
            .byte $C1 ; E4   329.628 Hz
            .byte $B7 ; F4   349.228 Hz
            .byte $AC ; F4#  369.994 Hz
            .byte $A3 ; G4   391.995 Hz
            .byte $9A ; G4#  415.305 Hz
            .byte $91 ; A4   440.000 Hz
            .byte $89 ; A4#  466.164 Hz
            .byte $81 ; B4   493.883 Hz
            .byte $7A ; C5   523.251 Hz

note_to_tone_hi:

; NOTE: Intentional Data overlap/re-use
;           .byte $00 ; C4   261.626 Hz
;           .byte $00 ; C4#  277.183 Hz
;           .byte $00 ; D4   293.665 Hz
;           .byte $00 ; D4#  311.127 Hz
;           .byte $00 ; E4   329.628 Hz
;           .byte $00 ; F4   349.228 Hz
;           .byte $00 ; F4#  369.994 Hz
;           .byte $00 ; G4   391.995 Hz
;           .byte $00 ; G4#  415.305 Hz
;           .byte $00 ; A4   440.000 Hz
;           .byte $00 ; A4#  466.164 Hz
;           .byte $00 ; B4   493.883 Hz
;           .byte $00 ; C5   523.251 Hz
;           .byte $00 ; C5#  554.365 Hz

mockN_off_data:
            BRK                     ; Reg 0,1 Tone A
            BRK
            BRK                     ; Reg 2,3 Tone B
            BRK
            BRK                     ; Reg 4,5 Tone C
            BRK
            BRK                     ; Reg 6 Noise
            BRK                     ; Reg 7 Enable
            BRK                     ; Reg 8 Amp A
            BRK                     ; Reg 9 Amp B
            BRK                     ; Reg A Amp C
            BRK                     ; Reg B Env Low

            BRK                     ; Reg C Env Hi
            BRK                     ; Reg D Env Type



; ____________________ Mockingboard 2 ____________________ 

; ====================
; Initialize Mockingboard
; ====================
MOCK2_Init:
            lda #_6522_PORT_B_OUT
            sta MOCK2_DIR_B
;           lda #_6522_PORT_A_OUT
            sta MOCK2_DIR_A
            ; NOTE: Intentional fall-into reset!
MOCK2_Reset:
            lda #_6522_RESET        ;      -->+
            .byte $2C               ;         |
MOCK2_SetReg:                       ;         |
            lda #_6522_LATCH        ;-->+     |
            .byte $2C               ;   |     |
MOCK2_SetData:                      ;   |     |
            lda #_6522_WRITE        ;   |     |
            sta MOCK2_OR_B          ;<--+  <--+
            lda #_6522_PORT_B
            sta MOCK2_OR_B
            rts

; ====================
; Plays one note
; IN:
;   X = Register: $0 .. $D
;   A = Value
; OUT:
;   A = trash
;   X = unchanged
;   Y = trash
; ====================
MOCK2_PokeXA:
            TAY
            ; NOTE: Intentional fall-into!

; ====================
; Poke (set) byte to Mockingboard
; IN:
;   X = Register: $0 .. $D
;   Y = Value
; OUT:
;   A = trash
;   X = unchanged
;   Y = unchanged
; ====================
MOCK2_PokeXY:
            stx MOCK2_OR_A
            jsr MOCK2_SetReg
            sty MOCK2_OR_A
            jmp MOCK2_SetData

; ====================
; Stop all sounds by setting all regs to zero
; ====================
MOCK2_Stop:
            LDX #<mockN_off_data         ; *** SELF-MODIFIES!
            LDY #>mockN_off_data
            ; NOTE: Intentional fall-into!

; ====================
; Plays one note by setting all Mockingboard registers
; IN:
;   X = Low  Address of registers
;   Y = High Address of
; ====================
MOCK2_Play:
            STX _mock2_load_reg+1        ; *** SELF-MODIFIES!
            STY _mock2_load_reg+2
_mock2_all_regs:
            ldy #0
            ldx #MOCK_REG_FIRST
_mock2_load_reg:
            lda mockN_off_data,X    ; *** SELF-MODIFIED!
            jsr MOCK2_PokeXA
            inx
            cpx #MOCK_REG_NUM       ; BUG: $B !
            bcc _mock2_load_reg
            rts

__END:

