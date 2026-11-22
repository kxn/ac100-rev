; func balance_cnt_wtp_entry_delete @ 0x0045ace8 size=0x7c
  45ace8:	27bdffe0 	addiu	sp,sp,-32
  45acec:	afb00018 	sw	s0,24(sp)
  45acf0:	00808021 	move	s0,a0
  45acf4:	1080000b 	beqz	a0,0x45ad24
  45acf8:	afbf001c 	sw	ra,28(sp)
  45acfc:	0c102140 	jal	0x408500
  45ad00:	00000000 	nop
  45ad04:	02002021 	move	a0,s0
  45ad08:	0c101f7c 	jal	0x407df0
  45ad0c:	00008021 	move	s0,zero
  45ad10:	8fbf001c 	lw	ra,28(sp)
  45ad14:	02001021 	move	v0,s0
  45ad18:	8fb00018 	lw	s0,24(sp)
  45ad1c:	03e00008 	jr	ra
  45ad20:	27bd0020 	addiu	sp,sp,32
  45ad24:	3c020073 	lui	v0,0x73
  45ad28:	8c4213e0 	lw	v0,5088(v0)
  45ad2c:	1040fff8 	beqz	v0,0x45ad10
  45ad30:	2410ffff 	li	s0,-1
  45ad34:	0c16276a 	jal	0x589da8
  45ad38:	00000000 	nop
  45ad3c:	5040fff5 	beqzl	v0,0x45ad14
  45ad40:	8fbf001c 	lw	ra,28(sp)
  45ad44:	3c040068 	lui	a0,0x68
  45ad48:	3c050069 	lui	a1,0x69
  45ad4c:	24847440 	addiu	a0,a0,29760
  45ad50:	24a5a738 	addiu	a1,a1,-22728
  45ad54:	0c101b74 	jal	0x406dd0
  45ad58:	24060204 	li	a2,516
  45ad5c:	08116b45 	j	0x45ad14
  45ad60:	8fbf001c 	lw	ra,28(sp)
