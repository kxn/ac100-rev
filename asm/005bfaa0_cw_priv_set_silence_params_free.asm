; func cw_priv_set_silence_params_free @ 0x005bfaa0 size=0x2c
  5bfaa0:	27bdffe0 	addiu	sp,sp,-32
  5bfaa4:	afbf001c 	sw	ra,28(sp)
  5bfaa8:	8c840010 	lw	a0,16(a0)
  5bfaac:	10800004 	beqz	a0,0x5bfac0
  5bfab0:	8fbf001c 	lw	ra,28(sp)
  5bfab4:	0c101f7c 	jal	0x407df0
  5bfab8:	00000000 	nop
  5bfabc:	8fbf001c 	lw	ra,28(sp)
  5bfac0:	00001021 	move	v0,zero
  5bfac4:	03e00008 	jr	ra
  5bfac8:	27bd0020 	addiu	sp,sp,32
