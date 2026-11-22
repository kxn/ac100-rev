; func uac_arp_defend_uninit @ 0x00476cfc size=0x68
  476cfc:	27bdffe0 	addiu	sp,sp,-32
  476d00:	afb00018 	sw	s0,24(sp)
  476d04:	afbf001c 	sw	ra,28(sp)
  476d08:	0c11f971 	jal	0x47e5c4
  476d0c:	00008021 	move	s0,zero
  476d10:	10400008 	beqz	v0,0x476d34
  476d14:	3c020073 	lui	v0,0x73
  476d18:	8c4214c0 	lw	v0,5312(v0)
  476d1c:	10400005 	beqz	v0,0x476d34
  476d20:	2410ffff 	li	s0,-1
  476d24:	0c16276a 	jal	0x589da8
  476d28:	00000000 	nop
  476d2c:	14400006 	bnez	v0,0x476d48
  476d30:	3c040069 	lui	a0,0x69
  476d34:	8fbf001c 	lw	ra,28(sp)
  476d38:	02001021 	move	v0,s0
  476d3c:	8fb00018 	lw	s0,24(sp)
  476d40:	03e00008 	jr	ra
  476d44:	27bd0020 	addiu	sp,sp,32
  476d48:	3c050069 	lui	a1,0x69
  476d4c:	24840828 	addiu	a0,a0,2088
  476d50:	24a50a78 	addiu	a1,a1,2680
  476d54:	0c101b74 	jal	0x406dd0
  476d58:	240605e2 	li	a2,1506
  476d5c:	0811db4e 	j	0x476d38
  476d60:	8fbf001c 	lw	ra,28(sp)
	...
