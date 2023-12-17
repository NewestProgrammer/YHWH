bits 16
org 0x7C00

xor ax,ax
mov ds,ax
mov es,ax
mov fs,ax
mov gs,ax
mov ss,ax

mov esp, 0x7C00
mov ebp, esp

jmp 0x0000:load

load:
    xor ah,ah
    mov al,0x13
    int 0x10

    rdtsc
    mov word [seed],ax
    
    call text
st:
    mov     al, 0xb6            ; snd
    out     0x43, al
    mov     si, notes
    mov     di, durations
    mov     dx, 29               ; len
.p: mov     cl, byte [di]
    inc     di
    lodsw
    out     0x42, al
    mov     al, ah
    out     0x42, al
    in      al, 0x61
    or      al, 3
    out     0x61, al
    mov     ax, 0x8600
    int     0x15
    in      al, 0x61
    and     al, 0xfc
    out     0x61, al
    dec     dx
    jnz     .p
    jmp $

text:
    mov ah,0x02
    xor bh,bh
    xor dl,dl
    int 0x10

    mov si, string
.char_loop:
    lodsb
    or al,al
    jz .text_end

    mov ah,0x0E
    mov bl, 0x0F
    int 0x10
    jmp .char_loop
.text_end:
    ret
seed:
	dw 4096
notes       dw  2031,2711,2415,2711,1,2031,2711,2415,2711,1,2711,2711,2415,2711,1,2711,2711,2415,2711,1,2711,2711,2415,2711,1,2711,2711,2415,2152
durations   db     12,4,4,4,8,12,4,4,4,4,2,2,4,4,4,2,2,4,4,4,2,2,4,4,4,2,2,4,8
string:
    db "But clothe yourself with the Lord Jesus Christ (the Messiah), and make no provision for [indulging] the flesh [put a stop to thinking about the evil cravings of your physical nature] to [gratify its] desires (lusts).", 0
times 510 - ($ - $$) db 0
dw 0xAA55