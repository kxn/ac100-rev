; func apupd_model_hash_key @ 0x006501bc size=0x6c
  6501bc:	27bdffe0 	addiu	sp,sp,-32
  6501c0:	10800006 	beqz	a0,0x6501dc
  6501c4:	afbf001c 	sw	ra,28(sp)
  6501c8:	8fbf001c 	lw	ra,28(sp)
  6501cc:	24050004 	li	a1,4
  6501d0:	00003021 	move	a2,zero
  6501d4:	081020f4 	j	0x4083d0
  6501d8:	27bd0020 	addiu	sp,sp,32
  6501dc:	3c020076 	lui	v0,0x76
  6501e0:	8c428c08 	lw	v0,-29688(v0)
  6501e4:	14400004 	bnez	v0,0x6501f8
  6501e8:	8fbf001c 	lw	ra,28(sp)
  6501ec:	00001021 	move	v0,zero
  6501f0:	03e00008 	jr	ra
  6501f4:	27bd0020 	addiu	sp,sp,32
  6501f8:	0c16276a 	jal	0x589da8
  6501fc:	00000000 	nop
  650200:	5040fffa 	beqzl	v0,0x6501ec
  650204:	8fbf001c 	lw	ra,28(sp)
  650208:	3c040071 	lui	a0,0x71
  65020c:	3c050072 	lui	a1,0x72
  650210:	24840720 	addiu	a0,a0,1824
  650214:	24a5a224 	addiu	a1,a1,-24028
  650218:	0c101b74 	jal	0x406dd0
  65021c:	240601b4 	li	a2,436
  650220:	0819407b 	j	0x6501ec
  650224:	8fbf001c 	lw	ra,28(sp)
