; func cw_priv_spec_rssi_free @ 0x005c1080 size=0x3c
  5c1080:	27bdffe0 	addiu	sp,sp,-32
  5c1084:	afb00018 	sw	s0,24(sp)
  5c1088:	00808021 	move	s0,a0
  5c108c:	afbf001c 	sw	ra,28(sp)
  5c1090:	8c840010 	lw	a0,16(a0)
  5c1094:	10800005 	beqz	a0,0x5c10ac
  5c1098:	8fbf001c 	lw	ra,28(sp)
  5c109c:	0c101f7c 	jal	0x407df0
  5c10a0:	00000000 	nop
  5c10a4:	ae000010 	sw	zero,16(s0)
  5c10a8:	8fbf001c 	lw	ra,28(sp)
  5c10ac:	00001021 	move	v0,zero
  5c10b0:	8fb00018 	lw	s0,24(sp)
  5c10b4:	03e00008 	jr	ra
  5c10b8:	27bd0020 	addiu	sp,sp,32
