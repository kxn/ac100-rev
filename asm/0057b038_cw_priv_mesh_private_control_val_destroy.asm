; func cw_priv_mesh_private_control_val_destroy @ 0x0057b038 size=0x7c
  57b038:	27bdffe0 	addiu	sp,sp,-32
  57b03c:	afb00018 	sw	s0,24(sp)
  57b040:	00808021 	move	s0,a0
  57b044:	1080000b 	beqz	a0,0x57b074
  57b048:	afbf001c 	sw	ra,28(sp)
  57b04c:	0c15eba0 	jal	0x57ae80
  57b050:	00000000 	nop
  57b054:	02002021 	move	a0,s0
  57b058:	0c101f7c 	jal	0x407df0
  57b05c:	00008021 	move	s0,zero
  57b060:	8fbf001c 	lw	ra,28(sp)
  57b064:	02001021 	move	v0,s0
  57b068:	8fb00018 	lw	s0,24(sp)
  57b06c:	03e00008 	jr	ra
  57b070:	27bd0020 	addiu	sp,sp,32
  57b074:	3c020075 	lui	v0,0x75
  57b078:	8c42cf58 	lw	v0,-12456(v0)
  57b07c:	1040fff8 	beqz	v0,0x57b060
  57b080:	2410ffff 	li	s0,-1
  57b084:	0c16276a 	jal	0x589da8
  57b088:	00000000 	nop
  57b08c:	5040fff5 	beqzl	v0,0x57b064
  57b090:	8fbf001c 	lw	ra,28(sp)
  57b094:	3c04006d 	lui	a0,0x6d
  57b098:	3c05006e 	lui	a1,0x6e
  57b09c:	24847cb0 	addiu	a0,a0,31920
  57b0a0:	24a5a3f8 	addiu	a1,a1,-23560
  57b0a4:	0c101b74 	jal	0x406dd0
  57b0a8:	2406008b 	li	a2,139
  57b0ac:	0815ec19 	j	0x57b064
  57b0b0:	8fbf001c 	lw	ra,28(sp)
