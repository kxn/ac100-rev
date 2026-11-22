; func apupd_hwid_hash_obj @ 0x00650074 size=0x6c
  650074:	27bdffe0 	addiu	sp,sp,-32
  650078:	10800006 	beqz	a0,0x650094
  65007c:	afbf001c 	sw	ra,28(sp)
  650080:	8fbf001c 	lw	ra,28(sp)
  650084:	24050010 	li	a1,16
  650088:	00003021 	move	a2,zero
  65008c:	081020f4 	j	0x4083d0
  650090:	27bd0020 	addiu	sp,sp,32
  650094:	3c020076 	lui	v0,0x76
  650098:	8c428c08 	lw	v0,-29688(v0)
  65009c:	14400004 	bnez	v0,0x6500b0
  6500a0:	8fbf001c 	lw	ra,28(sp)
  6500a4:	00001021 	move	v0,zero
  6500a8:	03e00008 	jr	ra
  6500ac:	27bd0020 	addiu	sp,sp,32
  6500b0:	0c16276a 	jal	0x589da8
  6500b4:	00000000 	nop
  6500b8:	5040fffa 	beqzl	v0,0x6500a4
  6500bc:	8fbf001c 	lw	ra,28(sp)
  6500c0:	3c040071 	lui	a0,0x71
  6500c4:	3c050072 	lui	a1,0x72
  6500c8:	24840720 	addiu	a0,a0,1824
  6500cc:	24a5a1bc 	addiu	a1,a1,-24132
  6500d0:	0c101b74 	jal	0x406dd0
  6500d4:	240601e7 	li	a2,487
  6500d8:	08194029 	j	0x6500a4
  6500dc:	8fbf001c 	lw	ra,28(sp)
