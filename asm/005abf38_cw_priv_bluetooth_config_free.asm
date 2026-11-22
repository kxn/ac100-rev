; func cw_priv_bluetooth_config_free @ 0x005abf38 size=0x3c
  5abf38:	27bdffe0 	addiu	sp,sp,-32
  5abf3c:	afb00018 	sw	s0,24(sp)
  5abf40:	00808021 	move	s0,a0
  5abf44:	afbf001c 	sw	ra,28(sp)
  5abf48:	8c840010 	lw	a0,16(a0)
  5abf4c:	10800005 	beqz	a0,0x5abf64
  5abf50:	8fbf001c 	lw	ra,28(sp)
  5abf54:	0c101f7c 	jal	0x407df0
  5abf58:	00000000 	nop
  5abf5c:	ae000010 	sw	zero,16(s0)
  5abf60:	8fbf001c 	lw	ra,28(sp)
  5abf64:	00001021 	move	v0,zero
  5abf68:	8fb00018 	lw	s0,24(sp)
  5abf6c:	03e00008 	jr	ra
  5abf70:	27bd0020 	addiu	sp,sp,32
