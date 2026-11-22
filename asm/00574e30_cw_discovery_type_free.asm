; func cw_discovery_type_free @ 0x00574e30 size=0x3c
  574e30:	27bdffe0 	addiu	sp,sp,-32
  574e34:	afb00018 	sw	s0,24(sp)
  574e38:	00808021 	move	s0,a0
  574e3c:	afbf001c 	sw	ra,28(sp)
  574e40:	8c840010 	lw	a0,16(a0)
  574e44:	10800005 	beqz	a0,0x574e5c
  574e48:	8fbf001c 	lw	ra,28(sp)
  574e4c:	0c101f7c 	jal	0x407df0
  574e50:	00000000 	nop
  574e54:	ae000010 	sw	zero,16(s0)
  574e58:	8fbf001c 	lw	ra,28(sp)
  574e5c:	00001021 	move	v0,zero
  574e60:	8fb00018 	lw	s0,24(sp)
  574e64:	03e00008 	jr	ra
  574e68:	27bd0020 	addiu	sp,sp,32
