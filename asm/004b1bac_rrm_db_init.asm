; func rrm_db_init @ 0x004b1bac size=0x74
  4b1bac:	3c04006a 	lui	a0,0x6a
  4b1bb0:	27bdffe0 	addiu	sp,sp,-32
  4b1bb4:	24841738 	addiu	a0,a0,5944
  4b1bb8:	afbf001c 	sw	ra,28(sp)
  4b1bbc:	0c101fc0 	jal	0x407f00
  4b1bc0:	24050001 	li	a1,1
  4b1bc4:	00401821 	move	v1,v0
  4b1bc8:	3c020076 	lui	v0,0x76
  4b1bcc:	ac437c34 	sw	v1,31796(v0)
  4b1bd0:	10600004 	beqz	v1,0x4b1be4
  4b1bd4:	00001021 	move	v0,zero
  4b1bd8:	8fbf001c 	lw	ra,28(sp)
  4b1bdc:	03e00008 	jr	ra
  4b1be0:	27bd0020 	addiu	sp,sp,32
  4b1be4:	3c020073 	lui	v0,0x73
  4b1be8:	804219b0 	lb	v0,6576(v0)
  4b1bec:	14400005 	bnez	v0,0x4b1c04
  4b1bf0:	3c04006a 	lui	a0,0x6a
  4b1bf4:	0c12c6dc 	jal	0x4b1b70
  4b1bf8:	00000000 	nop
  4b1bfc:	0812c6f6 	j	0x4b1bd8
  4b1c00:	2402ffff 	li	v0,-1
  4b1c04:	3c05006a 	lui	a1,0x6a
  4b1c08:	24841744 	addiu	a0,a0,5956
  4b1c0c:	24a518e0 	addiu	a1,a1,6368
  4b1c10:	0c101b74 	jal	0x406dd0
  4b1c14:	2406007d 	li	a2,125
  4b1c18:	0812c6fd 	j	0x4b1bf4
  4b1c1c:	00000000 	nop
