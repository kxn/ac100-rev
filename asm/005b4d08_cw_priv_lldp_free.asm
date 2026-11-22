; func cw_priv_lldp_free @ 0x005b4d08 size=0x2c
  5b4d08:	27bdffe0 	addiu	sp,sp,-32
  5b4d0c:	afbf001c 	sw	ra,28(sp)
  5b4d10:	8c840010 	lw	a0,16(a0)
  5b4d14:	10800004 	beqz	a0,0x5b4d28
  5b4d18:	8fbf001c 	lw	ra,28(sp)
  5b4d1c:	0c101f7c 	jal	0x407df0
  5b4d20:	00000000 	nop
  5b4d24:	8fbf001c 	lw	ra,28(sp)
  5b4d28:	00001021 	move	v0,zero
  5b4d2c:	03e00008 	jr	ra
  5b4d30:	27bd0020 	addiu	sp,sp,32
