; func cw_priv_ap_trunk_free @ 0x005a8b40 size=0x3c
  5a8b40:	27bdffe0 	addiu	sp,sp,-32
  5a8b44:	afb00018 	sw	s0,24(sp)
  5a8b48:	00808021 	move	s0,a0
  5a8b4c:	afbf001c 	sw	ra,28(sp)
  5a8b50:	8c840010 	lw	a0,16(a0)
  5a8b54:	10800005 	beqz	a0,0x5a8b6c
  5a8b58:	8fbf001c 	lw	ra,28(sp)
  5a8b5c:	0c101f7c 	jal	0x407df0
  5a8b60:	00000000 	nop
  5a8b64:	ae000010 	sw	zero,16(s0)
  5a8b68:	8fbf001c 	lw	ra,28(sp)
  5a8b6c:	00001021 	move	v0,zero
  5a8b70:	8fb00018 	lw	s0,24(sp)
  5a8b74:	03e00008 	jr	ra
  5a8b78:	27bd0020 	addiu	sp,sp,32
